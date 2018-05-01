using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class PeopleAI : MonoBehaviour {

    public float patrolSpeed = 2f;
    public float chaseSpeed = 5f;
    public float chaseWaitTime = 5f;
    public float patrolWaitTime = 1f;
    public Transform[] patrolWayPoints;

    private PeopleController peopleController;
    private NavMeshAgent nav;
    private GameObject player;
    private Animator animator;
    private float sprRad;

    private LastPlayerSighted lastPlayerSighting;
    private GameManagerScript gameManagerScript;
    private float chaseTimer;
    private float patrolTimer;
    private int wayPointIndex;
    private string peopleState;

    public bool missing;

    private void Start()
    {
        peopleController = GetComponent<PeopleController>();
        animator = GetComponent<Animator>();
        nav = GetComponent<NavMeshAgent>();
        player = GameObject.FindGameObjectWithTag("Player");
        lastPlayerSighting = GameObject.FindGameObjectWithTag("GameManager").GetComponent<LastPlayerSighted>();
        gameManagerScript = GameObject.FindGameObjectWithTag("GameManager").GetComponent<GameManagerScript>();
        peopleState = "Patrolling";
        missing = true;
        sprRad = GetComponent<SphereCollider>().radius;

    }

    private void Update()
    {
        //if (this.GetComponent<CharacterStatus>().getHP() <= 0f)
        //    return;

        if (animator.GetBool("isDying") || animator.GetBool("isStunned"))
        {
            peopleState = "Patrolling";
            missing = true;
            //gameManagerScript.peopleState = peopleState;
            nav.speed = 0;
            return;
        }
        

        Vector3 sightedDeltaPos = peopleController.personalLastSighting - transform.position;

        //각상태에 따라 행동을 실행합니다
        if (peopleController.playerInSight && player.GetComponent<CharacterStatus>().getHP() > 0f)
            Attacking();
        else if (!peopleController.playerInSight && peopleController.personalLastSighting != lastPlayerSighting.resetPosition && player.GetComponent<CharacterStatus>().getHP() > 0f && sightedDeltaPos.magnitude < sprRad)
            Chasing();
        else if (peopleController.personalLastSighting != lastPlayerSighting.resetPosition && player.GetComponent<CharacterStatus>().getHP() > 0f && sightedDeltaPos.magnitude > sprRad)
            WeirdFeel();
        else
            Patrolling();
    }
    
    void Attacking()
    {
        if(peopleState=="Patrolling" || peopleState=="WeirdFeel")
        {
            peopleController.PeopleSurprisedSoundPlay();
        }

        peopleState = "Attacking";
        missing = false;

        peopleController.personalLastSighting = player.transform.position;

        //일정거리보다 크면 쫓아가고 아니면 때립니다
        Vector3 sightingDeltaPos = peopleController.personalLastSighting - transform.position;
        if (sightingDeltaPos.sqrMagnitude > 3f)
            nav.destination = peopleController.personalLastSighting;
        else
            peopleController.SendMessage("Attack");

        nav.speed = chaseSpeed;
    }

    void Chasing()
    {
        
        if (peopleState == "Patrolling")
        {
            peopleController.PeopleSurprisedSoundPlay();
        }

        peopleState = "Chasing";
        missing = false;

        Vector3 sightingDeltaPos = peopleController.personalLastSighting - transform.position;
        if (sightingDeltaPos.sqrMagnitude > 4f)
            nav.destination = peopleController.personalLastSighting;

        nav.speed = chaseSpeed;

        if (nav.remainingDistance < nav.stoppingDistance)
        {
            chaseTimer += Time.deltaTime;

            //추격시간 초과시 리셋
            if (chaseTimer > chaseWaitTime)
            {
                lastPlayerSighting.position = lastPlayerSighting.resetPosition;
                peopleController.personalLastSighting = lastPlayerSighting.resetPosition;
                chaseTimer = 0f;
            }
        }
        else
            chaseTimer = 0f;
    }

    void WeirdFeel()
    {
        //Debug.Log("Weird");
        if (peopleState == "Patrolling")
        {
            //peopleController.PeopleWeirdFeelSoundPlay();
            peopleController.InvokePeopleWeirdFeelSoundPlay();
        }

        peopleState = "WeirdFeel";
        missing = true;

        Vector3 sightingDeltaPos = peopleController.personalLastSighting - transform.position;

        if (sightingDeltaPos.sqrMagnitude > 2f)
            nav.destination = peopleController.personalLastSighting;

        nav.speed = patrolSpeed;

        if (nav.remainingDistance < nav.stoppingDistance)
        {
            chaseTimer += Time.deltaTime;

            //추격시간 초과시 리셋
            if (chaseTimer > chaseWaitTime)
            {
                lastPlayerSighting.position = lastPlayerSighting.resetPosition;
                peopleController.personalLastSighting = lastPlayerSighting.resetPosition;
                chaseTimer = 0f;
            }
        }
        else
            chaseTimer = 0f;
    }

    void Patrolling()
    {
        peopleState = "Patrolling";
        missing = true;
        nav.speed = patrolSpeed;

        if (nav.destination == lastPlayerSighting.resetPosition || nav.remainingDistance < nav.stoppingDistance)
        {
            patrolTimer += Time.deltaTime;

            if (patrolTimer >= patrolWaitTime)
            {
                if (wayPointIndex == 0)
                    wayPointIndex = Random.Range(1, patrolWayPoints.Length);
                else
                    wayPointIndex = 0;

                patrolTimer = 0f;
            }

            //if (patrolTimer >= patrolWaitTime)
            //{
            //    if (wayPointIndex == patrolWayPoints.Length - 1)
            //        wayPointIndex = 0;
            //    else
            //        wayPointIndex++;

            //    patrolTimer = 0f;
            //}
        }
        else
            patrolTimer = 0f;

        nav.destination = patrolWayPoints[wayPointIndex].position;
    }

    public string getPeopleState()
    {
        return peopleState;
    }
}
