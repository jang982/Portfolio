using System.Collections;
using UnityEngine;
using UnityEngine.UI;

public class InfiniteModeStageManager : MonoBehaviour
{
    public ColorChangeScript ColorChanger;
    public GameObject PlayerObject;
    public GameObject BGObject;
    public Text FloorUI;
    public GameObject NoteManager;
    public GameObject DifficultyManager;
    GameObject MonsterObject;
    public bool IsGameEnded = false;

    public int MonsterCount = 0;
    public int MonsterCount_all = 0;
    bool BossTime = false;
    int StageN = 1;

    public AudioClip slime_die;

    void Start()
    {
        NoteManager = GameObject.Find("NoteManager");

        PlayerObject.SendMessage("SetStageManager");                                                //플레이어스크립트가 먼저 로드되서 여기서 나중에 스테이지세팅
        PlayerObject.SendMessage("SetAttackAble", false);
        PlayerObject.SendMessage("Appear");
        BGObject.SendMessage("StageMove");
        PlayerObject.SendMessage("Move", 2.0f);

        GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(1.5f);
        NoteManager.GetComponent<NoteManager>().LockAllArrows(1.5f);
        Invoke("MonsterSpawn", 1.5f);
    }
    void NextMonster()
    {
        float HoldTime;
        MonsterCount++;
        MonsterCount_all++;

        PlayerObject.SendMessage("SetAttackAble", false);
        if (MonsterCount == 3) BossTime = true;
        if (MonsterCount == 4)
        {
            NextStage();
            if (StageN == 21) return;
        }


        if (!GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever)
        {
            if (MonsterCount == 0)
            {
                BGObject.SendMessage("StageMove");
                PlayerObject.SendMessage("Move", 2.5f);
                Invoke("MonsterSpawn", 2.5f);
                HoldTime = 2.5f;
            }
            else {
                BGObject.SendMessage("NormalMove");
                PlayerObject.SendMessage("Move", 0.7f);
                Invoke("MonsterSpawn", 0.7f);
                HoldTime = 0.7f;
            }
        }
        else {
            Invoke("MonsterSpawn", 0.2f);
            HoldTime = 0.2f;
        }
        GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(HoldTime);      //인자는 락거는시간
        GameObject.Find("Fever__").GetComponent<Fever__>().FeverHold(HoldTime);
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(HoldTime);
    }
    void NextStage()
    {
        BossTime = false;
        MonsterCount = 0;
        
        StageN++;

        if (StageN == 21)
        {
            Victory();
            return;
        }

        DifficultyManager.GetComponent<DifficultyManager>().DecRecovery();                          //난이도 상승.

        FloorUI.text = StageN.ToString();
        FloorUI.GetComponent<Animation>().Play();
        int StageNDiv = StageN % 20;
        switch(StageNDiv)
        {
            case 1:
                ColorChanger.SendMessage("ColorChange", 1);
                BGObject.SendMessage("ImageChange");
                break;
            case 4:
                ColorChanger.SendMessage("ColorChange", 2);
                BGObject.SendMessage("ImageChange");
                break;
            case 7:
                ColorChanger.SendMessage("ColorChange", 3);
                BGObject.SendMessage("ImageChange");
                break;
            case 10:
                ColorChanger.SendMessage("ColorChange", 4);
                BGObject.SendMessage("ImageChange");
                break;
            case 13:
                ColorChanger.SendMessage("ColorChange", 5);
                BGObject.SendMessage("ImageChange");
                break;
            case 16:
                ColorChanger.SendMessage("ColorChange", 6);
                BGObject.SendMessage("ImageChange");
                break;
        }
           
        if(StageN % 4 ==0)//특수노트 빈도증가
        {
            DifficultyManager.SendMessage("IncNoteFreq", 1);
        }
    }
    
    void MonsterSpawn()
    {
        GameObject[] NowStageMonsters;
        if (StageN <= 20) NowStageMonsters = GetComponent<MonstersAtStage>().StageMonsterList[StageN - 1];
        else NowStageMonsters = GetComponent<MonstersAtStage>().StageMonsterList[19];
        int i;
        if (BossTime)
        {
            MonsterObject = Instantiate(GetComponent<MonstersAtStage>().GetBossAtStage(StageN));
        }
        else {
            i = Random.Range(0, NowStageMonsters.Length);
            MonsterObject = Instantiate(NowStageMonsters[i]);
            MonsterObject.SendMessage("SetHP", 4);
        }
        MonsterObject.SendMessage("SetStageManager");                                       //몬스터 스크립트가 먼저 로드되기때문에 여기서 스테이지 설정
        PlayerObject.SendMessage("SetAttackAble", true);
    }

    void PlayerDie()
    {
        Debug.Log("PlayerDie Call");
        Invoke("DieCall", 1.0f);
        GameObject.Find("Fever__").GetComponent<Fever__>().feverLocked = true;
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;
        NoteManager.SendMessage("IsGameOvered");                                            //게임오버 설정
        if (IsGameEnded) return;
        IsGameEnded = true;
        StartCoroutine(GameEnd());
    }
    void Victory()
    {
        GameObject.Find("GameOver").SendMessage("SetVictory");
        GameObject.Find("Fever__").GetComponent<Fever__>().feverLocked = true;
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;       //사실상 그냥 락거는거임 변수이름만 이런거지
        if (IsGameEnded) return;
        IsGameEnded = true;
        StartCoroutine(GameEnd());
    }
    void DieCall()
    {
        PlayerObject.GetComponent<PlayerScript>().PlayerDieEffect();
    }

   
    IEnumerator GameEnd()
    {
        yield return new WaitForSeconds(1.1f);
        GameObject.Find("GameOver").SendMessage("Appear");
    }

    public int GetMonsterCount()
    {
        return MonsterCount;
    }
    public int GetStageCount()
    {
        return StageN;
    }
    
    public void Slime_Die()
    {
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle2(slime_die);
    }
}
