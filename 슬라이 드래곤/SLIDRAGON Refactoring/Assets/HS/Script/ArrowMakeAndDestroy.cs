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

    void Awake()
    {
        FindArrowsOriginal();
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
        int Normal = GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>().getNormalFreq();
        int Double = GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>().getDoubleFreq();
        int Reverse= GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>().getReverseFreq();

        int RandomNumber = Random.Range(0, Normal + Double + Reverse);

        if (RandomNumber < Normal)                                           //노말노트 
        {
            MakeCloneArrow(Random.Range(0, 4));
        }
        else if (RandomNumber >= Normal && RandomNumber < Normal + Double)    //더블노트
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
        switch (i)
        {
            case 0://UpArrow
                GameObject clone0;
                clone0 = (GameObject)Instantiate(upArrow, upArrow.transform.position, upArrow.transform.rotation);
                clone0.name = "UpArrow";
                clone0.tag = "Arrows";
                arrowSequence[0] = clone0;
                break;
            case 1://LeftArrow
                GameObject clone1;
                clone1 = (GameObject)Instantiate(leftArrow, leftArrow.transform.position, leftArrow.transform.rotation);
                clone1.name = "LeftArrow";
                clone1.tag = "Arrows";
                arrowSequence[0] = clone1;
                break;
            case 2://DownArrow
                GameObject clone2;
                clone2 = (GameObject)Instantiate(downArrow, downArrow.transform.position, downArrow.transform.rotation);
                clone2.name = "DownArrow";
                clone2.tag = "Arrows";
                arrowSequence[0] = clone2;
                break;
            case 3://RightArrow
                GameObject clone3;
                clone3 = (GameObject)Instantiate(rightArrow, rightArrow.transform.position, rightArrow.transform.rotation);
                clone3.name = "RightArrow";
                clone3.tag = "Arrows";
                arrowSequence[0] = clone3;
                break;


            //Double//
            case 4://UpArrow
                GameObject clone4;
                clone4 = (GameObject)Instantiate(doubleUpArrow, doubleUpArrow.transform.position, doubleUpArrow.transform.rotation);
                clone4.name = "DoubleUpArrow";
                clone4.tag = "Arrows";
                arrowSequence[0] = clone4;
                break;
            case 5://LeftArrow
                GameObject clone5;
                clone5 = (GameObject)Instantiate(doubleLeftArrow, doubleLeftArrow.transform.position, doubleLeftArrow.transform.rotation);
                clone5.name = "DoubleLeftArrow";
                clone5.tag = "Arrows";
                arrowSequence[0] = clone5;
                break;
            case 6://DownArrow
                GameObject clone6;
                clone6 = (GameObject)Instantiate(doubleDownArrow, doubleDownArrow.transform.position, doubleDownArrow.transform.rotation);
                clone6.name = "DoubleDownArrow";
                clone6.tag = "Arrows";
                arrowSequence[0] = clone6;
                break;
            case 7://RightArrow
                GameObject clone7;
                clone7 = (GameObject)Instantiate(doubleRightArrow, doubleRightArrow.transform.position, doubleRightArrow.transform.rotation);
                clone7.name = "DoubleRightArrow";
                clone7.tag = "Arrows";
                arrowSequence[0] = clone7;
                break;


            //Reverse//
            case 8://UpArrow
                GameObject clone8;
                clone8 = (GameObject)Instantiate(reverseUpArrow, reverseUpArrow.transform.position, reverseUpArrow.transform.rotation);
                clone8.name = "ReverseUpArrow";
                clone8.tag = "Arrows";
                arrowSequence[0] = clone8;
                break;
            case 9://LeftArrow
                GameObject clone9;
                clone9 = (GameObject)Instantiate(reverseLeftArrow, reverseLeftArrow.transform.position, reverseLeftArrow.transform.rotation);
                clone9.name = "ReverseLeftArrow";
                clone9.tag = "Arrows";
                arrowSequence[0] = clone9;
                break;
            case 10://DownArrow
                GameObject clone10;
                clone10 = (GameObject)Instantiate(reverseDownArrow, reverseDownArrow.transform.position, reverseDownArrow.transform.rotation);
                clone10.name = "ReverseDownArrow";
                clone10.tag = "Arrows";
                arrowSequence[0] = clone10;
                break;
            case 11://RightArrow
                GameObject clone11;
                clone11 = (GameObject)Instantiate(reverseRightArrow, reverseRightArrow.transform.position, reverseRightArrow.transform.rotation);
                clone11.name = "ReverseRightArrow";
                clone11.tag = "Arrows";
                arrowSequence[0] = clone11;
                break;
        }

        //push arrows
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
