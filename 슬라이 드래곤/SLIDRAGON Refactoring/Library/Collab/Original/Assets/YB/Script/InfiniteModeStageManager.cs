using System.Collections;
using UnityEngine;

public class InfiniteModeStageManager : MonoBehaviour
{
    public ColorChangeScript ColorChanger;
    public GameObject PlayerObject;
    public GameObject BGObject;
    public GameObject[] MonsterPrefabs;
    public GameObject BossMonsterPrefab;
    public GameObject NoteManager;
    GameObject MonsterObject;
    bool IsGameEnded = false;

    public int MonsterCount = 0;
    bool BossTime = false;
    void Start()
    {
        NoteManager = GameObject.Find("NoteManager");

        PlayerObject.SendMessage("SetStageManager");                                                //플레이어스크립트가 먼저 로드되서 여기서 나중에 스테이지세팅
        PlayerObject.SendMessage("SetAttackAble", false);
        PlayerObject.SendMessage("Appear");
        BGObject.SendMessage("Move");

        GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(1.5f);
        Invoke("MonsterSpawn", 1.5f);
    }
    void NextMonster()
    {
        MonsterCount++;
        PlayerObject.SendMessage("SetAttackAble", false);
        if (MonsterCount == 3) BossTime = true;
        if (MonsterCount == 4) { Victory(); return; }
        if (!GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever)
        {
            if(BossTime)
            {
                GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(3.0f);      //인자는 락거는시간
                GameObject.Find("Fever_Gauge").GetComponent<Fever>().FeverHold(3.0f);
                GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(3.0f);
            }
            else
            {
                GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(0.5f);      //인자는 락거는시간
                GameObject.Find("Fever_Gauge").GetComponent<Fever>().FeverHold(0.5f);
                GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(0.5f);               //마찬가지
            }
            
            PlayerObject.SendMessage("Move", 0.7f);
            BGObject.SendMessage("Move");
            Invoke("MonsterSpawn", 0.5f);
        }
        else
        {
            if (BossTime)
            {
                GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(3.0f);
                GameObject.Find("Fever_Gauge").GetComponent<Fever>().FeverHold(3.0f);
                GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(3.0f);
            }
            else
            {
                GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(0.2f);
                GameObject.Find("Fever_Gauge").GetComponent<Fever>().FeverHold(0.2f);
                GameObject.Find("Timer_Gauge").GetComponent<Timer>().TimerHold(0.2f);
            }

            Invoke("MonsterSpawn", 0.2f);
        }
    }
    void MonsterSpawn()
    {
        //ColorChanger.SendMessage("ColorChange", Random.Range(1, 3));

        int i = Random.Range(0, MonsterPrefabs.Length);
        if(BossTime) MonsterObject = Instantiate(BossMonsterPrefab);
        else MonsterObject = Instantiate(MonsterPrefabs[i]);
        MonsterObject.SendMessage("SetStageManager");                                       //몬스터 스크립트가 먼저 로드되기때문에 여기서 스테이지 설정
        PlayerObject.SendMessage("SetAttackAble", true);
    }
    void PlayerDie()
    {
        Debug.Log("PlayerDie Call");
        GameObject.Find("Fever_Gauge").GetComponent<Fever>().feverLocked = true;
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;
        NoteManager.SendMessage("IsGameOvered");                                            //게임오버 설정
        if (IsGameEnded) return;
        IsGameEnded = true;
        PlayerObject.SendMessage("Die");
        StartCoroutine(GameEnd());
    }
    void Victory()
    {
        GameObject.Find("Fever_Gauge").GetComponent<Fever>().feverLocked = true;
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;       //사실상 그냥 락거는거임 변수이름만 이런거지
        if (IsGameEnded) return;
        IsGameEnded = true;
        PlayerObject.SendMessage("Victory");
        StartCoroutine(GameEnd());
    }
    IEnumerator GameEnd()
    {
        yield return new WaitForSeconds(1.1f);
        GameObject.Find("GameOver").SendMessage("Appear");
    }
}
