using UnityEngine;
using System.Collections;

public class GameManager : MonoBehaviour {
    public GameObject PlayerObj;
    public GameObject DoubleAttackEffect;
    RaycastHit hit;
    bool isGameOvered;
    bool isLocked;
    bool isInvoked;
    public bool isFever;

    //복사용 원본 오브젝트 선언
    GameObject UpArrow;
    GameObject LeftArrow;
    GameObject DownArrow;
    GameObject RightArrow;
    GameObject DoubleUpArrow;
    GameObject DoubleLeftArrow;
    GameObject DoubleDownArrow;
    GameObject DoubleRightArrow;
    GameObject ReverseUpArrow;
    GameObject ReverseLeftArrow;
    GameObject ReverseDownArrow;
    GameObject ReverseRightArrow;


    //화면 화살표 순서. 터치판정하는건 4번
    GameObject[] ArrowSequence=new GameObject[6];          
    GameObject[] ArrowCount;//화살표갯수 확인용

    //슬라이드 판정용 변수들
    Vector2 StartPos;

    GameObject Timer;
    

    void Start () {
        isGameOvered = false;
        isLocked = false;
        isInvoked = false;
        isFever = false;

        //복사용 원본 오브젝트 찾기
        UpArrow = GameObject.FindWithTag("UpArrow");
        LeftArrow= GameObject.FindWithTag("LeftArrow");
        DownArrow = GameObject.FindWithTag("DownArrow");
        RightArrow = GameObject.FindWithTag("RightArrow");
        DoubleUpArrow = GameObject.FindWithTag("DoubleUpArrow");
        DoubleLeftArrow = GameObject.FindWithTag("DoubleLeftArrow");
        DoubleDownArrow = GameObject.FindWithTag("DoubleDownArrow");
        DoubleRightArrow = GameObject.FindWithTag("DoubleRightArrow");
        ReverseUpArrow = GameObject.FindWithTag("ReverseUpArrow");
        ReverseLeftArrow = GameObject.FindWithTag("ReverseLeftArrow");
        ReverseDownArrow = GameObject.FindWithTag("ReverseDownArrow");
        ReverseRightArrow = GameObject.FindWithTag("ReverseRightArrow");

        //초기 4개화살표 생성

        for (int i=0;i<4;i++)
        {
            MakeArrow(Random.Range(0, 12));
        }

        
    }
	
	void Update () {
        if(isGameOvered == false && isLocked == false && PlayerObj.GetComponent<PlayerScript>().IsAttackAble)
        {
            check();
        }
        if(isGameOvered == true)
        {
            if (Input.GetKey(KeyCode.RightArrow) || SlideCheck() == "Right")
                Application.LoadLevel(Application.loadedLevel);
        }
        if(isLocked == true && isInvoked == false)
        {
            Invoke("Unlock", 1.0f);
            isInvoked = true;
        }
    }

    public void check()
    {
        
        if (Input.touchCount > 0 || Input.anyKeyDown)
        {
            if (isFever)
                FeverCheck(ArrowSequence[4].name);
            else
                ArrowCheck(ArrowSequence[4].name);
        }
    }


    public void ArrowCheck(string InputArrow)
    {
        GameObject[] temp = GameObject.FindGameObjectsWithTag("Arrows");

        switch (InputArrow)
        {

            //Normal Arrow check
            case "UpArrow":
                if (Input.GetKey(KeyCode.UpArrow) || SlideCheck() == "Up")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("UpAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                    Input.GetKey(KeyCode.RightArrow) ||
                    Input.GetKey(KeyCode.LeftArrow) ||
                    SlideCheck() == "Down" ||
                    SlideCheck() == "Right" ||
                    SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "LeftArrow":
                if (Input.GetKey(KeyCode.LeftArrow) || SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.RightArrow) ||
                     Input.GetKey(KeyCode.UpArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Right" ||
                     SlideCheck() == "Up")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "DownArrow":
                if (Input.GetKey(KeyCode.DownArrow) || SlideCheck() == "Down")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("DownAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.UpArrow) ||
                     Input.GetKey(KeyCode.RightArrow) ||
                     Input.GetKey(KeyCode.LeftArrow) ||
                     SlideCheck() == "Up" ||
                     SlideCheck() == "Right" ||
                     SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "RightArrow":
                if (Input.GetKey(KeyCode.RightArrow) || SlideCheck() == "Right")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.UpArrow) ||
                     Input.GetKey(KeyCode.LeftArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Up" ||
                     SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;



            //Double Arrow Check//

            case "DoubleUpArrow":
                if (Input.GetKey(KeyCode.UpArrow) || SlideCheck() == "Up")
                {
                    if(ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed==true)
                    {
                        GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = false;
                        ArrowSequence[4].SendMessage("DestroyArrow");

                        PlayerObj.SendMessage("UpAttack");
                        Destroy(Instantiate(DoubleAttackEffect), 0.5f);

                        MakeArrow(Random.Range(0, 12));
                    }
                    else
                    {
                        ArrowSequence[4].SendMessage("ChangeDAImage", "DoubleUpArrow");
                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = true;
                    }
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                    Input.GetKey(KeyCode.RightArrow) ||
                    Input.GetKey(KeyCode.LeftArrow) ||
                    SlideCheck() == "Down" ||
                    SlideCheck() == "Right" ||
                    SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "DoubleLeftArrow":
                if (Input.GetKey(KeyCode.LeftArrow) || SlideCheck() == "Left")
                {

                    if (ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed == true)
                    {
                        GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = false;
                        ArrowSequence[4].SendMessage("DestroyArrow");
                        
                        PlayerObj.SendMessage("SideAttack");
                        Destroy(Instantiate(DoubleAttackEffect), 0.5f);

                        MakeArrow(Random.Range(0, 12));
                    }
                    else
                    {
                        ArrowSequence[4].SendMessage("ChangeDAImage", "DoubleLeftArrow");
                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = true;
                    }
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.RightArrow) ||
                     Input.GetKey(KeyCode.UpArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Right" ||
                     SlideCheck() == "Up")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "DoubleDownArrow":
                if (Input.GetKey(KeyCode.DownArrow) || SlideCheck() == "Down")
                {
                    if (ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed == true)
                    {
                        GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = false;
                        ArrowSequence[4].SendMessage("DestroyArrow");

                        PlayerObj.SendMessage("DownAttack");
                        Destroy(Instantiate(DoubleAttackEffect), 0.5f);

                        MakeArrow(Random.Range(0, 12));
                    }
                    else
                    {
                        ArrowSequence[4].SendMessage("ChangeDAImage", "DoubleDownArrow");
                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = true;
                    }
                }
                else if (Input.GetKey(KeyCode.UpArrow) ||
                     Input.GetKey(KeyCode.RightArrow) ||
                     Input.GetKey(KeyCode.LeftArrow) ||
                     SlideCheck() == "Up" ||
                     SlideCheck() == "Right" ||
                     SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "DoubleRightArrow":
                if (Input.GetKey(KeyCode.RightArrow) || SlideCheck() == "Right")
                {
                    if (ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed == true)
                    {
                        GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                        GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = false;
                        ArrowSequence[4].SendMessage("DestroyArrow");

                        PlayerObj.SendMessage("SideAttack");
                        Destroy(Instantiate(DoubleAttackEffect), 0.5f);

                        MakeArrow(Random.Range(0, 12));
                    }
                    else
                    {
                        ArrowSequence[4].SendMessage("ChangeDAImage", "DoubleRightArrow");
                        ArrowSequence[4].gameObject.GetComponent<ArrowControl>().IsSuccessed = true;
                    }
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.UpArrow) ||
                     Input.GetKey(KeyCode.LeftArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Up" ||
                     SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            //Reverse Arrow Check//
            case "ReverseUpArrow":
                if (Input.GetKey(KeyCode.DownArrow) || SlideCheck() == "Down")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("UpAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.UpArrow) ||
                    Input.GetKey(KeyCode.RightArrow) ||
                    Input.GetKey(KeyCode.LeftArrow) ||
                    SlideCheck() == "Up" ||
                    SlideCheck() == "Right" ||
                    SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "ReverseLeftArrow":
                if (Input.GetKey(KeyCode.RightArrow) || SlideCheck() == "Right")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.LeftArrow) ||
                     Input.GetKey(KeyCode.UpArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Left" ||
                     SlideCheck() == "Up")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "ReverseDownArrow":
                if (Input.GetKey(KeyCode.UpArrow) || SlideCheck() == "Up")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("DownAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.RightArrow) ||
                     Input.GetKey(KeyCode.LeftArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Right" ||
                     SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;

            case "ReverseRightArrow":
                if (Input.GetKey(KeyCode.LeftArrow) || SlideCheck() == "Left")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");
                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                else if (Input.GetKey(KeyCode.DownArrow) ||
                     Input.GetKey(KeyCode.UpArrow) ||
                     Input.GetKey(KeyCode.RightArrow) ||
                     SlideCheck() == "Down" ||
                     SlideCheck() == "Up" ||
                     SlideCheck() == "Right")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Fever_Gauge").SendMessage("SlideFail");
                    GameObject.Find("Combo_Count").SendMessage("ResetCount");
                    isLocked = true;
                    for (int i = 0; i < 4; i++)
                    {
                        temp[i].SendMessage("Locked");
                    }
                }
                break;
        }
    }

    //피버판정체크. 조건만 제거한거라 거의 비슷함//

    public void FeverCheck(string InputArrow)
    {
        switch (InputArrow)
        {

            //Normal Arrow check
            case "UpArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("UpAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "LeftArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;


            case "DownArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("DownAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "RightArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;



            //Double Arrow Check//

            case "DoubleUpArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("UpAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "DoubleLeftArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "DoubleDownArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("DownAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "DoubleRightArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            //Reverse Arrow Check//
            case "ReverseUpArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("UpAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "ReverseLeftArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "ReverseDownArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("DownAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;

            case "ReverseRightArrow":
                if (Input.anyKeyDown || SlideCheck() == "Touched")
                {
                    GameObject.Find("Timer_Gauge").SendMessage("SlideSuccess");
                    GameObject.Find("Combo_Count").SendMessage("IncreaseCount");

                    ArrowSequence[4].SendMessage("DestroyArrow");

                    PlayerObj.SendMessage("SideAttack");

                    MakeArrow(Random.Range(0, 12));
                }
                break;
        }
    }

    string SlideCheck()
    {
        if (Input.touchCount > 0)
        {
            Touch NowTouch = Input.GetTouch(0);
            switch (NowTouch.phase)
            {
                case TouchPhase.Began:
                    StartPos = NowTouch.position;
                    break;
                case TouchPhase.Ended:
                    Vector2 deltaPos = NowTouch.position - StartPos;
                    if (deltaPos.magnitude < 100.0f) return "";
                    bool IsMoveX = (Mathf.Abs(deltaPos.x) > Mathf.Abs(deltaPos.y));
                    if (IsMoveX)
                    {
                        if (deltaPos.x > 0) return "Right";
                        else return "Left";
                    }
                    else
                    {
                        if (deltaPos.y > 0) return "Up";
                        else return "Down";
                    }
            }
        }
        
        return "";
    }


    string FeverSlideCheck()
    {
        if (Input.touchCount > 0)
        {
            Touch NowTouch = Input.GetTouch(0);
            switch (NowTouch.phase)
            {
                case TouchPhase.Began:
                    break;
                case TouchPhase.Ended:
                    return "Touched";
            }
        }

        return "";
    }


    //랜덤숫자 받아서 화살표 만들고 자리이동
    public void MakeArrow(int i)
    {


        switch (i)
        {
            case 0://UpArrow
                GameObject clone0;
                clone0 = (GameObject)Instantiate(UpArrow, UpArrow.transform.position, UpArrow.transform.rotation);
                clone0.name = "UpArrow";
                clone0.tag = "Arrows";
                ArrowSequence[0] = clone0;
                break;
            case 1://LeftArrow
                GameObject clone1;
                clone1 = (GameObject)Instantiate(LeftArrow, LeftArrow.transform.position, LeftArrow.transform.rotation);
                clone1.name = "LeftArrow";
                clone1.tag = "Arrows";
                ArrowSequence[0] = clone1;
                break;
            case 2://DownArrow
                GameObject clone2;
                clone2 = (GameObject)Instantiate(DownArrow, DownArrow.transform.position, DownArrow.transform.rotation);
                clone2.name = "DownArrow";
                clone2.tag = "Arrows";
                ArrowSequence[0] = clone2;
                break;
            case 3://RightArrow
                GameObject clone3;
                clone3 = (GameObject)Instantiate(RightArrow, RightArrow.transform.position, RightArrow.transform.rotation);
                clone3.name = "RightArrow";
                clone3.tag = "Arrows";
                ArrowSequence[0] = clone3;
                break;


                //Double//
            case 4://UpArrow
                GameObject clone4;
                clone4 = (GameObject)Instantiate(DoubleUpArrow, DoubleUpArrow.transform.position, DoubleUpArrow.transform.rotation);
                clone4.name = "DoubleUpArrow";
                clone4.tag = "Arrows";
                ArrowSequence[0] = clone4;
                break;
            case 5://LeftArrow
                GameObject clone5;
                clone5 = (GameObject)Instantiate(DoubleLeftArrow, DoubleLeftArrow.transform.position, DoubleLeftArrow.transform.rotation);
                clone5.name = "DoubleLeftArrow";
                clone5.tag = "Arrows";
                ArrowSequence[0] = clone5;
                break;
            case 6://DownArrow
                GameObject clone6;
                clone6 = (GameObject)Instantiate(DoubleDownArrow, DoubleDownArrow.transform.position, DoubleDownArrow.transform.rotation);
                clone6.name = "DoubleDownArrow";
                clone6.tag = "Arrows";
                ArrowSequence[0] = clone6;
                break;
            case 7://RightArrow
                GameObject clone7;
                clone7 = (GameObject)Instantiate(DoubleRightArrow, DoubleRightArrow.transform.position, DoubleRightArrow.transform.rotation);
                clone7.name = "DoubleRightArrow";
                clone7.tag = "Arrows";
                ArrowSequence[0] = clone7;
                break;


            //Reverse//
            case 8://UpArrow
                GameObject clone8;
                clone8 = (GameObject)Instantiate(ReverseUpArrow, ReverseUpArrow.transform.position, ReverseUpArrow.transform.rotation);
                clone8.name = "ReverseUpArrow";
                clone8.tag = "Arrows";
                ArrowSequence[0] = clone8;
                break;
            case 9://LeftArrow
                GameObject clone9;
                clone9 = (GameObject)Instantiate(ReverseLeftArrow, ReverseLeftArrow.transform.position, ReverseLeftArrow.transform.rotation);
                clone9.name = "ReverseLeftArrow";
                clone9.tag = "Arrows";
                ArrowSequence[0] = clone9;
                break;
            case 10://DownArrow
                GameObject clone10;
                clone10 = (GameObject)Instantiate(ReverseDownArrow, ReverseDownArrow.transform.position, ReverseDownArrow.transform.rotation);
                clone10.name = "ReverseDownArrow";
                clone10.tag = "Arrows";
                ArrowSequence[0] = clone10;
                break;
            case 11://RightArrow
                GameObject clone11;
                clone11 = (GameObject)Instantiate(ReverseRightArrow, ReverseRightArrow.transform.position, ReverseRightArrow.transform.rotation);
                clone11.name = "ReverseRightArrow";
                clone11.tag = "Arrows";
                ArrowSequence[0] = clone11;
                break;
        }

        //push arrows
        ArrowPush();

    }

    void ArrowPush()
    {
        ArrowCount = GameObject.FindGameObjectsWithTag("Arrows");           //화살표 갯수 받기
        for (int i=ArrowCount.Length-1;i>-1;i--)                            //1개씩 밀어주기
        {
            ArrowSequence[i+1] = ArrowSequence[i];
            ArrowSequence[i+1].SendMessage("MoveForward", i);
         
        }
    }

    void IsGameOvered ()
    {
        isGameOvered = true;
    }

    void Restart ()
    {
        Application.LoadLevel(Application.loadedLevel);
    }

    void Unlock ()
    {
        isLocked = false;
        isInvoked = false;
    }
}



