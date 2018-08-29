using UnityEngine;
using System.Collections;

public class NoteManager : MonoBehaviour
{
    public GameObject PlayerObj;
    public GameObject DoubleAttackEffect;
    bool isGameOvered;
    public bool isLocked;
    public bool isFever;


    void Start()
    {
        isGameOvered = false;
        isLocked = false;
        isFever = false;

        //난이도 설정
        this.GetComponent<NoteChecker>().NormalFreq = 10;
        this.GetComponent<NoteChecker>().DoubleFreq = 0;
        this.GetComponent<NoteChecker>().ReverseFreq = 0;


        //초기 4개화살표 생성
        for (int i = 0; i < 4; i++)
        {
            this.GetComponent<NoteChecker>().ArrowFrequency(this.GetComponent<NoteChecker>().NormalFreq, this.GetComponent<NoteChecker>().DoubleFreq, this.GetComponent<NoteChecker>().ReverseFreq);
        }

        GameObject[] temp = GameObject.FindGameObjectsWithTag("Arrows");
        for (int i = 0; i < temp.Length; i++)
        {
            //Debug.Log(i + "번쨰ArrowName=" + temp[i].name);
            temp[i].GetComponent<ArrowControl>().Locked(1.5f);
        }
    }

    void Update()
    {

        if (isGameOvered == false && isLocked == false && PlayerObj.GetComponent<PlayerScript>().IsAttackAble)
        {
            this.GetComponent<NoteChecker>().check();
        }


    }



    public void LockAllArrows(float LockTime)
    {
        GameObject[] temp = GameObject.FindGameObjectsWithTag("Arrows");
        isLocked = true;
        Invoke("Unlock", LockTime);
        for (int i = 0; i < temp.Length; i++)
        {
            //Debug.Log(i + "번쨰ArrowName=" + temp[i].name);
            temp[i].GetComponent<ArrowControl>().Locked(LockTime);
        }

    }

    void IsGameOvered()
    {
        isGameOvered = true;
    }


    void Unlock()
    {
        isLocked = false;
    }
}



