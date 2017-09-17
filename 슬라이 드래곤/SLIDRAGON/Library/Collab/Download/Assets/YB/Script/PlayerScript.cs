using UnityEngine;

public class PlayerScript : MonoBehaviour {
    public int HP;
    public GameObject DieEffectPrefab;
    GameObject StageManager;
    Animator animator;
    public bool IsAttackAble = false;
    public bool IsPlayerDying = false;
    public AudioClip upAttack;
    public AudioClip downAttack;
    public AudioClip sideAttack;
    public AudioClip destroy_missile;
    public AudioClip player_die;

    void Awake()
    {
        animator = GetComponent<Animator>();
    }

    void SetStageManager()
    {
        StageManager = GameObject.Find("ModeSelector").GetComponent<ModeSelector>().GetStageManager();
    }

    void SetAttackAble(bool b) { IsAttackAble = b; }
    void Appear()
    {
        animator.SetTrigger("Appear");
        //HPBar.SendMessage("SetMaxHP", HP);
    }
    void Move(float seconds)
    {
        animator.SetBool("Move", true);
        Invoke("DontMove", seconds);
    }
    void DontMove()
    {
        animator.SetBool("Move", false);
    }
	void UpAttack()
    {
        if (!IsAttackAble) return;
        Camera.main.GetComponent<Animation>().Play();
        animator.SetTrigger("Upatk");
        GameObject.FindWithTag("Enemy").SendMessage("Damage", 1);
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(upAttack);
    }
    void DownAttack()
    {
        if (!IsAttackAble) return;
        Camera.main.GetComponent<Animation>().Play();
        animator.SetTrigger("Downatk");
        GameObject.FindWithTag("Enemy").SendMessage("Damage", 1);
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(downAttack);
    }
    void SideAttack()
    {
        if (!IsAttackAble) return;
        Camera.main.GetComponent<Animation>().Play();
        animator.SetTrigger("Sideatk");
        GameObject.FindWithTag("Enemy").SendMessage("Damage", 1);
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(sideAttack);
    }
    void RandomAttackAnimation()
    {
        Camera.main.GetComponent<Animation>().Play();
        int r = Random.Range(0, 3);
        switch (r)
        {
            case 0:
                animator.SetTrigger("Upatk"); break;
            case 1:
                animator.SetTrigger("Downatk"); break;
            case 2:
                animator.SetTrigger("Sideatk"); break;
        }
    }

    void Damage(int dHP)
    {
        HP -= dHP;
        animator.SetTrigger("Damage");
        //Debug.Log("dying?"+IsPlayerDying);
        if (HP <= 0 && IsPlayerDying == false)
        {
            animator.SetTrigger("Die");
            StageManager.SendMessage("PlayerDie");
            IsPlayerDying = true;
        }
    }
    
    public void PlayerDieEffect()
    {
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(player_die);
        Destroy(Instantiate(DieEffectPrefab), 2.0f);
    }

    public void Destroy_Missile()
    {
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(destroy_missile);
    }
}
