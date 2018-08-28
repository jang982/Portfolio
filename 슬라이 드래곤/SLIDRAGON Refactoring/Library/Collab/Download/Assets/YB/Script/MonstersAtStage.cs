using System.Collections.Generic;
using UnityEngine;

public class MonstersAtStage : MonoBehaviour
{
    public GameObject[] BossList;
    public GameObject[] Stage1;
    public GameObject[] Stage2;
    public GameObject[] Stage3;
    public GameObject[] Stage4;
    public GameObject[] Stage5;
    public GameObject[] Stage6;
    public GameObject[] Stage7;
    public GameObject[] Stage8;
    public GameObject[] Stage9;
    public GameObject[] Stage10;
    public GameObject[] Stage11;
    public GameObject[] Stage12;
    public GameObject[] Stage13;
    public GameObject[] Stage14;
    public GameObject[] Stage15;
    public GameObject[] Stage16;
    public GameObject[] Stage17;
    public GameObject[] Stage18;
    public GameObject[] Stage19;
    public GameObject[] Stage20;
    public List<GameObject[]> StageMonsterList;

    public GameObject GetBossAtStage(int StageN)
    {
        if (StageN >= 10) {
            if ((StageN-1) % 20 == 19)
                return BossList[19];
            else if ((StageN-1) % 10 == 9)
                return BossList[9];
        }
        if (StageN < 10)
            return BossList[Random.Range(0, 9)];
        else if (StageN <= 20)
            return BossList[Random.Range(10, 19)];
        return BossList[Random.Range(0, 20)];
    }
    void Start()
    {
        StageMonsterList = new List<GameObject[]>(20);
        StageMonsterList.Add(Stage1);
        StageMonsterList.Add(Stage2);
        StageMonsterList.Add(Stage3);
        StageMonsterList.Add(Stage4);
        StageMonsterList.Add(Stage5);
        StageMonsterList.Add(Stage6);
        StageMonsterList.Add(Stage7);
        StageMonsterList.Add(Stage8);
        StageMonsterList.Add(Stage9);
        StageMonsterList.Add(Stage10);
        StageMonsterList.Add(Stage11);
        StageMonsterList.Add(Stage12);
        StageMonsterList.Add(Stage13);
        StageMonsterList.Add(Stage14);
        StageMonsterList.Add(Stage15);
        StageMonsterList.Add(Stage16);
        StageMonsterList.Add(Stage17);
        StageMonsterList.Add(Stage18);
        StageMonsterList.Add(Stage19);
        StageMonsterList.Add(Stage20);
    }
}
