using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class PeopleController : MonoBehaviour {

    public AudioSource footstepAudioSource;
    public AudioSource attackAudioSource;
    public AudioSource hittedAudioSource;
    public AudioSource surprisedAudioSource;
    public AudioSource deadAndStunAudioSource;

    public float walkSpeed = 2;
    public float runSpeed = 6;
    public bool isFemale;


    public float fieldOfViewAngle = 110f;
    public bool playerInSight;
    public Vector3 personalLastSighting;
    public AudioClip[] footstepSound;
    public AudioClip attackSound;
    public AudioClip[] hittedSound;
    public AudioClip weirdFellingManAudioSound;
    public AudioClip weirdFellingWomanAudioSound;
    public AudioClip surprisedManAudioSound;
    public AudioClip surprisedWomanAudioSound;
    public AudioClip manStunAudioSound;
    public AudioClip womanStunAudioSound;

    private GameObject player;
    private NavMeshAgent nav;
    private SphereCollider spCol;
    private LastPlayerSighted lastPlayerSighting;
    private Vector3 previousSighting;

    public float speedSmoothTime = 0.1f;
    public  float currentSpeed;
    float speedSmoothVelocity;
    float velocityY;

    bool isCrouching;
    bool running;

    public List<string> attackedEnermy;

    GameObject PickedItem;
    GameObject NearbyItem;
    GameManagerScript gameManagerScript;
    public GameObject RightHandPunch;       //오른손 오브젝트

    Animator animator;
    CharacterController controller;
    CharacterStatus characterStat;

    // Use this for initialization
    void Start()
    {
        isCrouching = false;
        NearbyItem = null;

        player = GameObject.FindGameObjectWithTag("Player");
        animator = GetComponent<Animator>();
        characterStat = this.GetComponent<CharacterStatus>();
        nav = GetComponent<NavMeshAgent>();
        spCol = GetComponent<SphereCollider>();
        lastPlayerSighting = GameObject.FindGameObjectWithTag("GameManager").GetComponent<LastPlayerSighted>();
        gameManagerScript = GameObject.FindGameObjectWithTag("GameManager").GetComponent<GameManagerScript>();

        personalLastSighting = lastPlayerSighting.resetPosition;
        previousSighting = lastPlayerSighting.resetPosition;
    }

    // Update is called once per frame
    void Update()
    {
        if (animator.GetBool("isDying") || animator.GetBool("isStunned"))
            return;

        AttackColliderOnOff();

        //플레이어가 목격된 위치 업데이트
        if (lastPlayerSighting.position != previousSighting)
            personalLastSighting = lastPlayerSighting.position;

        previousSighting = lastPlayerSighting.position;

        //발자국소리 재생
        PeopleFootstepSoundPlay();


        //죽으면 시야에서 제거
        if (player.GetComponent<CharacterStatus>().getHP() == 0f)
        {
            playerInSight = false;
        }
        
        
        currentSpeed = nav.velocity.magnitude;


        float animationSpeedPercent = ((running) ? currentSpeed / runSpeed : currentSpeed / walkSpeed * .5f);
        animator.SetFloat("speedPercent", animationSpeedPercent, speedSmoothTime, Time.deltaTime);
    }



    void Attack()
    {

        animator.SetTrigger("attack");
    }

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


        if (!animator.GetBool("duringAttack"))
        {

            //중복공격방지 초기화

            attackedEnermy.Clear();

        }
    }



    private void OnCollisionEnter(Collision other)
    {
        if (animator.GetBool("isDying") || animator.GetBool("isStunned"))
            return;

        //1번의 공격당 1번의 피격이 이루어지도록 합니다
        if (other.transform.root.gameObject.tag == "Player" && other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Contains(this.name))
        {
            return;
        }




        if (other.gameObject.tag == "PlayerWeapon")
        {
            float stunPercentage = other.transform.root.gameObject.GetComponent<CharacterStatus>().getStunPercentage();

            if(Random.Range(0f,100f)<=stunPercentage && !playerInSight)
            {


                GetComponent<CapsuleCollider>().enabled = false;
                this.GetComponentInChildren<BoxCollider>().enabled = false;

                animator.SetTrigger("stunTrigger");
                animator.SetBool("isStunned", true);
                
                Invoke("PeopleStunedSoundPlay", 0.3f);

                other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Add(this.name);
            }
            else
            {
                characterStat.damaged(other.transform.root.GetComponent<CharacterStatus>().getCharacterPower());
                animator.SetTrigger("damaged");

                PeopleAttackSoundPlay();

                personalLastSighting = player.transform.position;

                other.transform.root.gameObject.GetComponent<PlayerController>().attackedEnermy.Add(this.name);
            }
            
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


    private void OnTriggerStay(Collider other)
    {
        if(other.gameObject==player)
        {
            playerInSight = false;

            //플레이어 전방과 이루는 각도구함
            Vector3 direction = other.transform.position - transform.position;
            float angle = Vector3.Angle(direction, transform.forward);
            
            //플레이어가 시야각에 들어오면
            if(angle < fieldOfViewAngle*0.5f)
            {
                RaycastHit hit;
                //레이캐스트로 hit를 판정함
                if (Physics.Raycast(transform.position + transform.up, direction.normalized, out hit, spCol.radius))
                {
                    if (hit.collider.gameObject == player)
                    {
                        playerInSight = true;
                        lastPlayerSighting.position = player.transform.position;
                    }
                }

            }

            //발자국소리를 들을경우를 처리합니다
            if(player.GetComponent<PlayerController>().isRunning())
            {
                if(CalculatePathLength(player.transform.position) <= spCol.radius)
                {
                    personalLastSighting = player.transform.position;
                }
            }
        }


    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject == player)
            playerInSight = false;
    }

    //소리가 이동하는 총 거리를 계산합니다.
    float CalculatePathLength(Vector3 targetPosition)
    {
        NavMeshPath path = new NavMeshPath();

        if (nav.enabled)
            nav.CalculatePath(targetPosition, path);

        //각 코너를 저장합니다.
        Vector3[] allWayPoints = new Vector3[path.corners.Length + 2];

        //처음과 끝은 플레이어와 NPC의 위치
        allWayPoints[0] = transform.position;
        allWayPoints[allWayPoints.Length - 1] = targetPosition;


        for(int i=0;i<path.corners.Length;i++)
        {
            allWayPoints[i + 1] = path.corners[i];
        }

        float pathLength = 0f;

        //거리를 더합니다
        for(int i=0;i<allWayPoints.Length-1;i++)
        {
            pathLength += Vector3.Distance(allWayPoints[i], allWayPoints[i + 1]);
        }

        return pathLength;
    }


    public void setNearbyItem(GameObject Item)
    {
        NearbyItem = Item;
        Debug.Log(NearbyItem);
    }

    void PeopleFootstepSoundPlay()
    {


        if (animator.GetFloat("speedPercent") > 0.6f)
        {
            if (!footstepAudioSource.isPlaying)
            {
                footstepAudioSource.pitch = 1f;
                footstepAudioSource.clip= footstepSound[Random.Range(0, 3)];
                footstepAudioSource.Play();
            }
        }
        else if (animator.GetFloat("speedPercent") < 0.6f && animator.GetFloat("speedPercent") > 0.2f)
        {
            if (!footstepAudioSource.isPlaying)
            {
                footstepAudioSource.pitch = 0.6f;
                footstepAudioSource.clip= footstepSound[Random.Range(0, 3)];
                footstepAudioSource.Play();
            }
        }
        else
            footstepAudioSource.Stop();
    }

    public void PeopleSurprisedSoundPlay()
    {
        if(!surprisedAudioSource.isPlaying)
        {
            if (isFemale)
                surprisedAudioSource.clip = surprisedWomanAudioSound;
            else
                surprisedAudioSource.clip = surprisedManAudioSound;
            surprisedAudioSource.Play();
        }
    }

    public void PeopleAttackSoundPlay()
    {
        attackAudioSource.clip = attackSound;
        attackAudioSource.Play();
    }

    public void PeopleWeirdFeelSoundPlay()
    {
        if (!surprisedAudioSource.isPlaying)
        {
            if (isFemale)
                surprisedAudioSource.clip = weirdFellingWomanAudioSound;
            else
                surprisedAudioSource.clip = weirdFellingManAudioSound;
            surprisedAudioSource.Play();
        }
    }

    public void InvokePeopleWeirdFeelSoundPlay()
    {
        Invoke("PeopleWeirdFeelSoundPlay", 0.7f);
    }

    public void PeopleStunedSoundPlay()
    {

        if (!deadAndStunAudioSource.isPlaying)
        {
            if (isFemale)
                deadAndStunAudioSource.clip = womanStunAudioSound;
            else
                deadAndStunAudioSource.clip = manStunAudioSound;
            deadAndStunAudioSource.Play();
        }
    }
    

    void Die()
    {
        GameObject.FindGameObjectWithTag("GameManager").GetComponent<AdditionalStatus>().setPlusEvilValue(30f);
        GetComponent<CapsuleCollider>().enabled = false;
        this.GetComponentInChildren<BoxCollider>().enabled = false;
        animator.SetTrigger("DyingTrigger");
        animator.SetBool("isDying", true);
    }
}
