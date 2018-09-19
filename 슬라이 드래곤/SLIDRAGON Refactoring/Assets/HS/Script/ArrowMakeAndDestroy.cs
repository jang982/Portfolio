using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArrowMakeAndDestroy : MonoBehaviour {

    //화면 화살표 순서. 터치판정하는건 4번
    GameObject[] arrowSequence = new GameObject[6];

    //화살표갯수 확인용
    GameObject[] arrowCount;

    //복사용 원본 오브젝트 선언
    GameObject upArrow;
    GameObject leftArrow;
    GameObject downArrow;
    GameObject rightArrow;
    GameObject doubleUpArrow;
    GameObject doubleLeftArrow;
    GameObject doubleDownArrow;
    GameObject doubleRightArrow;
    GameObject reverseUpArrow;
    GameObject reverseLeftArrow;
    GameObject reverseDownArrow;
    GameObject reverseRightArrow;

    //오브젝트 할당용 배열
    GameObject[] arrowObjects;

    void Awake()
    {
        FindArrowsOriginal();
        arrowObjects = new GameObject[12]   {upArrow,leftArrow,downArrow,rightArrow,
                                            doubleUpArrow,doubleLeftArrow,doubleDownArrow,doubleRightArrow,
                                            reverseUpArrow,reverseLeftArrow,reverseDownArrow,reverseRightArrow };
    }

    public string GetFrontArrowName()
    {
        return arrowSequence[4].name;
    }

    public void DestroyFrontArrow()
    {
        arrowSequence[4].SendMessage("DestroyArrow");
    }

    public void MarkFrontArrowAsFail()
    {
        arrowSequence[4].gameObject.GetComponent<ArrowControl>().MarkAsFail();
    }

    public void ChangeArrowSprite(string direction)
    {
        arrowSequence[4].SendMessage("ChangeDAImage", direction);
        arrowSequence[4].gameObject.GetComponent<ArrowControl>().MarkAsSuccess();
    }

    public bool IsSpriteChanged()
    {
        return arrowSequence[4].gameObject.GetComponent<ArrowControl>().GetIsSuccessedArrow() == true;
    }

    //복사용 원본 오브젝트 찾기
    public void FindArrowsOriginal()
    {
        upArrow = GameObject.FindWithTag("UpArrow");
        leftArrow = GameObject.FindWithTag("LeftArrow");
        downArrow = GameObject.FindWithTag("DownArrow");
        rightArrow = GameObject.FindWithTag("RightArrow");
        doubleUpArrow = GameObject.FindWithTag("DoubleUpArrow");
        doubleLeftArrow = GameObject.FindWithTag("DoubleLeftArrow");
        doubleDownArrow = GameObject.FindWithTag("DoubleDownArrow");
        doubleRightArrow = GameObject.FindWithTag("DoubleRightArrow");
        reverseUpArrow = GameObject.FindWithTag("ReverseUpArrow");
        reverseLeftArrow = GameObject.FindWithTag("ReverseLeftArrow");
        reverseDownArrow = GameObject.FindWithTag("ReverseDownArrow");
        reverseRightArrow = GameObject.FindWithTag("ReverseRightArrow");
    }

    public void MakeArrowByDifficulty()
    {
        int normalNote = GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>().getNormalFreq();
        int doubleNote = GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>().getDoubleFreq();
        int reverseNote= GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>().getReverseFreq();

        int randomNumber = Random.Range(0, normalNote + doubleNote + reverseNote);

        if (randomNumber < normalNote)                                           //노말노트 
        {
            MakeCloneArrow(Random.Range(0, 4));
        }
        else if (randomNumber >= normalNote && randomNumber < normalNote + doubleNote)    //더블노트
        {
            MakeCloneArrow(Random.Range(4, 8));
        }
        else
        {
            MakeCloneArrow(Random.Range(8, 12));                                 //반대 노트
        }
    }

    public void MakeCloneArrow(int i)
    {
        GameObject clone;
        clone = (GameObject)Instantiate(arrowObjects[i], arrowObjects[i].transform.position, arrowObjects[i].transform.rotation);
        clone.name = arrowObjects[i].tag;
        clone.tag = "Arrows";
        arrowSequence[0] = clone;
        ArrowPush();

    }

    void ArrowPush()
    {
        arrowCount = GameObject.FindGameObjectsWithTag("Arrows");           //화살표 갯수 받기
        for (int i = arrowCount.Length - 1; i > -1; i--)                            //1개씩 밀어주기
        {
            arrowSequence[i + 1] = arrowSequence[i];
            arrowSequence[i + 1].SendMessage("MoveForward", i);

        }
    }
}
