using UnityEngine;

public class StageManager : MonoBehaviour {
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
        BGObject.SendMessage("Move", 2.0f);
        Invoke("MonsterSpawn", 2.0f);
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
    void NextMonster()
    {
        temp = GameObject.FindGameObjectsWithTag("Arrows");
        for(int i =0; i <5; i++)
            Debug.Log(temp[i].name);
        for (int i = 0; i < 5; i++)
        {
            temp[i].SendMessage("MonsterLoadingLocked");
        }
        GameObject.Find("RayShooter").GetComponent<GameManager>().isLocked = true;
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = true;
        PlayerObject.SendMessage("SetAttackAble", false);
        PlayerObject.SendMessage("Move",2.0f);
        BGObject.SendMessage("Move", 2.0f);
        Invoke("MonsterSpawn",2.0f);
    }
    void MonsterSpawn()
    {
        GameObject.Find("RayShooter").GetComponent<GameManager>().isLocked = false;
        GameObject.Find("Timer_Gauge").GetComponent<Timer>().isLoadingMonster = false;
        MonsterObject = Instantiate(MonsterPrefab);
        PlayerObject.SendMessage("SetAttackAble", true);
        GameObject.Find("Timer").GetComponent<Timer>().isLoadingMonster = false;
    }
}
