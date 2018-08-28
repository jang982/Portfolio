using UnityEngine;

public class StageManager : MonoBehaviour {
    public GameObject PlayerObject;
    public GameObject BGObject;
    public GameObject MonsterPrefab;
    GameObject MonsterObject;

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
        PlayerObject.SendMessage("SetAttackAble", false);
        PlayerObject.SendMessage("Move",2.0f);
        BGObject.SendMessage("Move", 2.0f);
        Invoke("MonsterSpawn",2.0f);
    }
    void MonsterSpawn()
    {
        MonsterObject = Instantiate(MonsterPrefab);
        PlayerObject.SendMessage("SetAttackAble", true);
    }
}
