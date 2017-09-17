using UnityEngine;

public class NormalModeStageManager : MonoBehaviour {
    public GameObject PlayerObject;
    public GameObject BGObject;
    public GameObject MonsterPrefab;
    GameObject MonsterObject;
    GameObject[] temp;

    public int turn = 0;
    void Start()
    {
        PlayerObject.SendMessage("SetAttackAble", false);
        PlayerObject.SendMessage("Appear");
        BGObject.SendMessage("Move");
        Invoke("MonsterSpawn", 1.5f);
    }
    void PlayerTurnEnd()
    {
        PlayerObject.SendMessage("SetAttackAble", false);
        MonsterObject.SendMessage("Attack");
    }
    void EnemyTurnEnd()
    {
        PlayerObject.SendMessage("SetAttackAble", true);
        MonsterObject.SendMessage("AttackStop");
    }
    void PlayerDie()
    {
        PlayerObject.SendMessage("Die");
    }
    void NextMonster()
    {
        PlayerObject.SendMessage("SetAttackAble", false);
        if (!GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever)
        {
            GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(0.5f);
            GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;
            PlayerObject.SendMessage("Move", 0.7f);
            BGObject.SendMessage("Move");
            Invoke("MonsterSpawn", 0.5f);
        }
        else {
            GameObject.Find("NoteManager").GetComponent<NoteManager>().LockAllArrows(0.2f);
            GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;
            Invoke("MonsterSpawn", 0.2f);
        }
    }
    void MonsterSpawn()
    {
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = false;

        MonsterObject = Instantiate(MonsterPrefab);
        PlayerObject.SendMessage("SetAttackAble", true);
    }
}
