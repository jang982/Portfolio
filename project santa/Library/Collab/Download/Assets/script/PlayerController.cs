using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {
    public float walkSpeed = 2;
    public float runSpeed = 6;
    public float gravity = -12;
    public float jumpHeight = 1;

    public float turnSmoothTime = 0.0f;
    float turnSmoothVelocity;

    public float speedSmoothTime = 0.1f;
    float speedSmoothVelocity;
    float currentSpeed;
    float velocityY;

    bool isCrouching;
    bool running;

    public List<string> attackedEnermy;

    GameObject NearbyItem;
    GameObject PickedItem;
    public GameObject RightHandPunch;       //오른손 오브젝트

    Animator animator;
    CharacterController controller;
    CharacterStatus characterStat;


    // Use this for initialization
    void Start () {
        isCrouching = false;
        NearbyItem=null;

        animator = this.GetComponent<Animator>();
        controller = this.GetComponent<CharacterController>();
        characterStat = this.GetComponent<CharacterStatus>();
    }
	
	// Update is called once per frame
	void Update () {
        //죽으면 무반응
        if (animator.GetBool("isDying"))
            return;


        //케릭터입력값을 받습니다.
        Vector2 input = new Vector2(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"));
        Vector2 inputDir = input.normalized;
       
        

        //움직이기
        Move(inputDir, running);

        //각종 움직임의 입력대한 반응
        if (Input.GetKey(KeyCode.Space))
            Jump();
        if (Input.GetKeyDown(KeyCode.C) && !running)
            Crouch();
        if (Input.GetKeyDown(KeyCode.A))
            Attack();
        if(!isCrouching) running = Input.GetKey(KeyCode.LeftShift);


        //아이템 잡기
        if (Input.GetKeyDown(KeyCode.S))
            PickItem();

        //콜라이더 조정
        AttackColliderOnOff();


        //애니메이터 속도조정
        //달리는중일때, 걷는중일때 애니메이션 speedpercent설정
        float animationSpeedPercent = ((running) ? currentSpeed / runSpeed : currentSpeed / walkSpeed * .5f);
        animator.SetFloat("speedPercent", animationSpeedPercent, speedSmoothTime, Time.deltaTime);

    }

   
    //움직이는 부분
    void Move(Vector2 inputDir,bool running)
    {
        //0,0이 아닐때 방향처리
        if (inputDir != Vector2.zero)
        {
            float targetRotation = Mathf.Atan2(inputDir.x, inputDir.y) * Mathf.Rad2Deg;
            transform.eulerAngles = Vector3.up * Mathf.SmoothDampAngle(transform.eulerAngles.y, targetRotation, ref turnSmoothVelocity, turnSmoothTime);
        }

        //뛰기 설정
        float targetSpeed = ((running) ? runSpeed : walkSpeed) * inputDir.magnitude;
        currentSpeed = Mathf.SmoothDamp(currentSpeed, targetSpeed, ref speedSmoothVelocity, speedSmoothTime);

        //중력,이동 설정
        velocityY += Time.deltaTime * gravity;
        Vector3 velocity = transform.forward * currentSpeed + Vector3.up * velocityY;


        controller.Move(velocity * Time.deltaTime);
        currentSpeed = new Vector2(controller.velocity.x, controller.velocity.z).magnitude;


        //땅에닿으면 높이초기화
        if (controller.isGrounded)
        {
            animator.SetBool("isJump",false);
            velocityY = 0;
        }

    }

    //점프
    void Jump()
    {
        
        if (controller.isGrounded   &&  isCrouching==false)
        {
            //트리거 설정과 velocity를 설정해줍니다.
            animator.SetTrigger("triggerJump");
            float jumpVelocity = Mathf.Sqrt(-2 * gravity * jumpHeight);
            velocityY = jumpVelocity;

        }
    }

    //앉기
    void Crouch()
    {
        if (controller.isGrounded)
        {
            if (isCrouching)
            {
                isCrouching = false;
                animator.SetBool("isCrouched", false);
            }
            else
            {
                isCrouching = true;
                animator.SetBool("isCrouched", true);
            }
        }
    }
    
    //공격
    void Attack()
    {
        if(!animator.GetBool("duringAttack"))
        {
            animator.SetTrigger("attack");
        }
    }

    //아이템 줍기
    void PickItem()
    {
        Debug.Log("before " + PickedItem);

        //현재 손에 아이템이 없을때
        if (!PickedItem)
        {
            NearbyItem.SendMessage("ItemPickUp");
            PickedItem = NearbyItem;
            Debug.Log(PickedItem);
        }

        //현재 손에 아이템이 있을때, 드랍한다.
        else
        {

            PickedItem.SendMessage("ItemUnequip");
            PickedItem = null;
        }
        Debug.Log("after " + PickedItem);
    }

    //공격을 하는동안 콜라이더를 켜고 끄는 부분입니다.
    void AttackColliderOnOff()
    {

        if (animator.GetBool("duringAttack"))
        {
            if (PickedItem)
                PickedItem.GetComponent<Collider>().enabled = true;
            else
                RightHandPunch.GetComponent<Collider>().enabled = true;
        }

        else if (!animator.GetBool("duringAttack") && PickedItem)
        {

            if (PickedItem)
                PickedItem.GetComponent<Collider>().enabled = false;
            else
                RightHandPunch.GetComponent<Collider>().enabled = false;

        }
        else
            RightHandPunch.GetComponent<Collider>().enabled = false;


        if(!animator.GetBool("duringAttack"))
        {

            //중복공격방지 초기화

            attackedEnermy.Clear();
            
        }
    }


   
    //산타에게 들어오는 콜리전이 무엇이냐에 따라, 메시지를 보냅니다.
    private void OnTriggerEnter(Collider other)
    {


        if (other.gameObject.tag == "EnermyWeapon")
        {
            characterStat.damaged(other.transform.root.tag);
            animator.SetTrigger("damaged");
        }
        else if (other.gameObject.tag == "Trap")
        {
            characterStat.damaged(10.0f);
            animator.SetTrigger("damaged");
        }

    }

    //주변에 있는 아이템이 뭐엇인지에 대한것입니다.
    public void setNearbyItem(GameObject Item)
    {
        NearbyItem = Item;
        Debug.Log(NearbyItem);
    }

    //죽을때
    void Die()
    {
        animator.SetTrigger("DyingTrigger");
        animator.SetBool("isDying",true);
    }
}
