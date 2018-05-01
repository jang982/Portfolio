using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {
    public float walkSpeed = 2;
    public float runSpeed = 6;
    public float gravity = -12;
    public float jumpHeight = 1;

    public AudioClip[] footstepSouond;
    public AudioClip AttackSound;
    public AudioClip HittedSound;
    public AudioClip ScreamBytrapSound;


    public float turnSmoothTime = 0.0f;
    float turnSmoothVelocity;

    public float speedSmoothTime = 0.1f;
    float speedSmoothVelocity;
    float currentSpeed;
    float velocityY;

    bool isCrouching;
    bool running;
    bool isScreaming;
    bool isPause;

    public List<string> attackedEnermy;

    GameObject pauseCanvas;

    GameObject NearbyItem;
    GameObject nearBySwitch;
    GameObject PickedItem;
    LastPlayerSighted lastPlayerSighted;

    public GameObject RightHandPunch;       //오른손 오브젝트

    public GameObject SoundManager;


    Animator animator;
    CharacterController controller;
    CharacterStatus characterStat;
    GameManagerScript gameManagerScript;


    // Use this for initialization
    void Start () {
        isCrouching = false;
        NearbyItem=null;
        isPause = false;

        animator = this.GetComponent<Animator>();
        controller = this.GetComponent<CharacterController>();
        characterStat = this.GetComponent<CharacterStatus>();
        lastPlayerSighted = GameObject.FindGameObjectWithTag("GameManager").GetComponent<LastPlayerSighted>();
        gameManagerScript = GameObject.FindGameObjectWithTag("GameManager").GetComponent<GameManagerScript>();
        pauseCanvas = GameObject.FindGameObjectWithTag("PauseCanvas");
        pauseCanvas.SetActive(false);


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

        //일시정지 안풀릴때
        if (!isPause && Time.timeScale == 0)
            Time.timeScale = 1;

        //일시정지
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if (!isPause)
            {
                pauseCanvas.SetActive(true);
                SoundManager.GetComponent<AudioListener>().enabled = false;
                Time.timeScale = 0;
                isPause = true;
            }
            else
            {
                pauseCanvas.SetActive(false);
                SoundManager.GetComponent<AudioListener>().enabled = true;
                Time.timeScale = 1;
                isPause = false;
            }
        }


        //아이템 잡기
        if (Input.GetKeyDown(KeyCode.S))
            PickItem();

        //전구스위치
        if (Input.GetKeyDown(KeyCode.F))
            LightOnOff();

        //발자국
        playerFootstepSoundPlay();

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

    //전구 온오프
    void LightOnOff()
    {
        if (nearBySwitch)
            nearBySwitch.SendMessage("SwithToggle");
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


    private void OnCollisionEnter(Collision other)
    {
        //Debug.Log("Attacked");
        if (animator.GetBool("isDying"))
            return;

        //1번의 공격당 1번의 피격이 이루어지도록 합니다
        if (other.transform.root.gameObject.tag == "People" && other.transform.root.gameObject.GetComponent<PeopleController>().attackedEnermy.Contains(this.name))
        {
            //Debug.Log("중복됨");
            return;
        }

        if (other.gameObject.transform.root.tag == "People")
        {
            characterStat.damaged(other.transform.root.GetComponent<CharacterStatus>().getCharacterPower());
            animator.SetTrigger("damaged");
            playerHittedSoundPlay();

            ScreamingOn();
            Invoke("ScreamingOff", 0.2f);

            other.transform.root.gameObject.GetComponent<PeopleController>().attackedEnermy.Add(this.name);
        }
        else if (other.gameObject.tag == "Trap")
        {
            Debug.Log("트랩");
            characterStat.damaged(10.0f);
            animator.SetTrigger("damaged");
            lastPlayerSighted.position = transform.position;
            Debug.Log("마지막목격" + lastPlayerSighted.position);
        }




        //if (other.gameObject.tag == "PlayerWeapon")
        //{
        //    characterStat.damaged(other.transform.root.tag);
        //    animator.SetTrigger("damaged");

        //    other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Add(this.name);
        //    Debug.Log("Added = " + this.name);
        //    Debug.Log(other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy[0]);
        //}
    }

    

    //산타에게 들어오는 콜리전이 무엇이냐에 따라, 메시지를 보냅니다.
    private void OnTriggerEnter(Collider other)
    {
        
        if (other.gameObject.tag == "Trap")
        {
            characterStat.damaged(10.0f);
            animator.SetTrigger("damaged");

            playerScreamSoundPlay();

            lastPlayerSighted.position = transform.position;

            ScreamingOn();
            Invoke("ScreamingOff", 0.2f);
        }

    }

    //주변에 있는 아이템이 뭐엇인지에 대한것입니다.
    public void setNearbyItem(GameObject Item)
    {
        NearbyItem = Item;
    }

    //주변스위치가 무엇인지 세팅합니다
    public void setNearBySwitch(GameObject lightSwitch)
    {
        nearBySwitch = lightSwitch;
    }

    //죽을때
    void Die()
    {
        animator.SetTrigger("DyingTrigger");
        animator.SetBool("isDying",true);
        gameManagerScript.CallGameOver();
    }

    public bool isRunning()
    {
        return running;
    }


    //일시정지메뉴 콜
    public void callBackToMain()
    {
        gameManagerScript.BackToMain();
    }

    public void callRestart()
    {
        gameManagerScript.GameOver();
    }

    public void callExitGame()
    {
        gameManagerScript.ExitGame();
    }

    //사운드 리스너로 발자국소리 클립을 보내 재생시킵니다.
    void playerFootstepSoundPlay()
    {


        if (!controller.isGrounded)
            return;

        if(animator.GetFloat("speedPercent")>0.6f)
        {
            if(!SoundManager.GetComponent<SoundListenser>().footStepSFX.isPlaying)
            {
                SoundManager.GetComponent<SoundListenser>().footStepSFX.pitch = 1f;
                SoundManager.GetComponent<SoundListenser>().footStepSFX.volume = 1f;
                SoundManager.GetComponent<SoundListenser>().playFootStepSound(footstepSouond[Random.Range(0,3)]);
            }
        }
        else if(animator.GetFloat("speedPercent") < 0.6f && animator.GetFloat("speedPercent") > 0.2f)
        {
            if(!SoundManager.GetComponent<SoundListenser>().footStepSFX.isPlaying)
            {
                SoundManager.GetComponent<SoundListenser>().footStepSFX.pitch = 0.6f;
                SoundManager.GetComponent<SoundListenser>().footStepSFX.volume = 0.5f;
                SoundManager.GetComponent<SoundListenser>().playFootStepSound(footstepSouond[Random.Range(0, 3)]);
            }
        }
        else
            SoundManager.GetComponent<SoundListenser>().footStepSFX.Stop();
    }

    void playerHittedSoundPlay()
    {
        SoundListenser soundPlayer = SoundManager.GetComponent<SoundListenser>();

        if (!soundPlayer.HittedSFX.isPlaying)
        {
            soundPlayer.playHittedSound(HittedSound);
        }

    }

    void playerScreamSoundPlay()
    {
        SoundListenser soundPlayer = SoundManager.GetComponent<SoundListenser>();

        if (!soundPlayer.HittedSFX.isPlaying)
        {
            soundPlayer.playHittedSound(ScreamBytrapSound);
        }
    }
    void ScreamingOff()
    {
        isScreaming = false;
    }    void ScreamingOn()
    {
        isScreaming = true;
    }    public bool GetIsScreaming()
    {
        return isScreaming;
    } 
}
