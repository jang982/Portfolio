using System.Collections;
using UnityEngine;

public class MonsterScript : MonoBehaviour {
    public int HP;
    public GameObject DamageEffectPrefab;
    public GameObject AttackMissilePrefab;
    GameObject StageManager;
    GameObject DifficultyManager;
    GameObject HPBar;
    
    float AttackTimer;
    float AttackDelay;

    Animator animator;
    bool IsAttacking;
    bool IsDying = false;

    public AudioClip missile_fire;

    void Start()
    {
        DifficultyManager = GameObject.Find("DifficultyManager");
        //HP = DifficultyManager.GetComponent<DifficultyManager>().GetMonsterHP(this.name);


        animator = GetComponent<Animator>();
        HPBar = transform.Find("HPBar").gameObject;

        //공격시간타이머 설정
        AttackDelay = DifficultyManager.GetComponent<DifficultyManager>().MissileFireDelay;
        AttackTimer = AttackDelay;

        Appear();
        StartCoroutine(Attack());
    }
    void SetHP(int _hp) { HP = _hp; }

    void SetStageManager()
    {
        StageManager = GameObject.Find("ModeSelector").GetComponent<ModeSelector>().GetStageManager();
    }

    void Appear()
    {
        animator.SetTrigger("Appear");
        HPBar.SendMessage("SetMaxHP",HP);
    }

    void Damage(int dHP)
    {
        Camera.main.GetComponent<Animation>().Play();
        HP -= dHP;
        HPBar.SendMessage("SetHP", HP);
        animator.SetTrigger("Damage");
        if (HP <= 0 && !IsDying)
        {
            GameObject.Find("InfiniteStageManager").GetComponent<InfiniteModeStageManager>().Slime_Die();
            Destroy(Instantiate(DamageEffectPrefab, transform.position, transform.rotation), 1.0f);
            animator.SetTrigger("Die");
            StageManager.SendMessage("NextMonster");
            Destroy(gameObject, 0.6f);
            IsDying = true;
        }
    }

    IEnumerator Attack()
    {
        while(StageManager.GetComponent<InfiniteModeStageManager>().IsGameEnded == false)
        {
            if(AttackTimer>=0)
            {
                AttackTimer -= Time.deltaTime;
            }
            else
            {
                AttackTimer = AttackDelay;
                if (Random.Range(0, 10) <= DifficultyManager.GetComponent<DifficultyManager>().MissileFrequency)
                {
                    MissileFire();
                    GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(missile_fire);
                
                }
            }

            yield return new WaitForEndOfFrame();
        }

    }


    void MissileFire()
    {
        animator.SetTrigger("Attack");
        Instantiate(AttackMissilePrefab);
        //GameObject.FindWithTag("MonsterMissile").SendMessage("Fire");

    }
    //void Attack()
    //{
    //    Debug.Log("Attack Call");
    //    IsAttacking = true;
    //    //StartCoroutine(AttackLoop());
    //    Instantiate(AttackMissilePrefab);
    //    GameObject.FindWithTag("MonsterMissile").SendMessage("Fire");
        
    //}

    

    //IEnumerator AttackLoop()
    //{
    //    while(IsAttacking)
    //    {
    //        animator.SetTrigger("Attack");
    //        Instantiate(GreenMissilePrefab);
    //        yield return new WaitForSeconds(1.1f);
    //    }
    //}
    void AttackStop()
    {
        IsAttacking = false;
    }
}
