using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PeopleController : MonoBehaviour {

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
    

    GameObject NearbyItem;

    Animator animator;
    CharacterController controller;
    CharacterStatus characterStat;

    // Use this for initialization
    void Start()
    {
        isCrouching = false;
        NearbyItem = null;

        animator = GetComponent<Animator>();
        //controller = GetComponent<CharacterController>();
        characterStat = this.GetComponent<CharacterStatus>();
    }

    // Update is called once per frame
    void Update()
    {
        if (animator.GetBool("isDying"))
            return;

        //Vector2 input = new Vector2(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"));
        //Vector2 inputDir = input.normalized;

        //if (!isCrouching) running = Input.GetKey(KeyCode.LeftShift);




        ////애니메이터
        ////달리는중일때, 걷는중일때 애니메이션 speedpercent설정
        //float animationSpeedPercent = ((running) ? currentSpeed / runSpeed : currentSpeed / walkSpeed * .5f);
        //animator.SetFloat("speedPercent", animationSpeedPercent, speedSmoothTime, Time.deltaTime);

    }



    //void Move(Vector2 inputDir, bool running)
    //{
    //    //0,0이 아닐때 방향처리
    //    if (inputDir != Vector2.zero)
    //    {
    //        float targetRotation = Mathf.Atan2(inputDir.x, inputDir.y) * Mathf.Rad2Deg;
    //        transform.eulerAngles = Vector3.up * Mathf.SmoothDampAngle(transform.eulerAngles.y, targetRotation, ref turnSmoothVelocity, turnSmoothTime);
    //    }

    //    //뛰기 설정
    //    float targetSpeed = ((running) ? runSpeed : walkSpeed) * inputDir.magnitude;
    //    currentSpeed = Mathf.SmoothDamp(currentSpeed, targetSpeed, ref speedSmoothVelocity, speedSmoothTime);

    //    //중력,이동 설정
    //    velocityY += Time.deltaTime * gravity;
    //    Vector3 velocity = transform.forward * currentSpeed + Vector3.up * velocityY;


    //    controller.Move(velocity * Time.deltaTime);
    //    currentSpeed = new Vector2(controller.velocity.x, controller.velocity.z).magnitude;


    //    //땅에닿으면 높이초기화
    //    if (controller.isGrounded)
    //    {
    //        animator.SetBool("isJump", false);
    //        velocityY = 0;
    //    }

    //}

    //void Jump()
    //{

    //    if (controller.isGrounded && isCrouching == false)
    //    {
    //        animator.SetTrigger("triggerJump");
    //        float jumpVelocity = Mathf.Sqrt(-2 * gravity * jumpHeight);
    //        velocityY = jumpVelocity;

    //    }
    //}

    //void Crouch()
    //{
    //    if (controller.isGrounded)
    //    {
    //        if (isCrouching)
    //        {
    //            isCrouching = false;
    //            animator.SetBool("isCrouched", false);
    //        }
    //        else
    //        {
    //            isCrouching = true;
    //            animator.SetBool("isCrouched", true);
    //        }
    //    }
    //}

    void Attack()
    {

        animator.SetTrigger("attack");
    }

    

    private void OnCollisionEnter(Collision other)
    {
        Debug.Log("Attacked");
        if (animator.GetBool("isDying"))
            return;

        //1번의 공격당 1번의 피격이 이루어지도록 합니다
        if (other.transform.root.gameObject.name == "Player" && other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Contains(this.name))
        {
            Debug.Log("중복됨");
            return;
        }




        if (other.gameObject.tag == "PlayerWeapon")
        {
            characterStat.damaged(other.transform.root.tag);
            animator.SetTrigger("damaged");

            other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Add(this.name);
            Debug.Log("Added = " + this.name);
            Debug.Log(other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy[0]);
        }
    }

    //private void OnTriggerEnter(Collider other)
    //{
    //    if (animator.GetBool("isDying"))
    //        return;

    //    //1번의 공격당 1번의 피격이 이루어지도록 합니다
    //    if (other.transform.root.gameObject.name == "Player" && other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Contains(this.name))
    //    {
    //        Debug.Log("중복됨");
    //        return;
    //    }




    //    if (other.gameObject.tag == "PlayerWeapon")
    //    {
    //        characterStat.damaged(other.transform.root.tag);
    //        animator.SetTrigger("damaged");

    //        other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Add(this.name);
    //        Debug.Log("Added = " + this.name);
    //        Debug.Log(other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy[0]);
    //    }

    //}


    public void setNearbyItem(GameObject Item)
    {
        NearbyItem = Item;
        Debug.Log(NearbyItem);
    }

    void Die()
    {
        animator.SetTrigger("DyingTrigger");
        animator.SetBool("isDying", true);
    }
}
