using UnityEngine;
using System.Collections;

public class NoteManager : MonoBehaviour
{
    public GameObject playerObj;
    public GameObject doubleAttackEffect;

    GameObject UITimerGauge;
    GameObject UIFeverGauge;
    GameObject UIComboCount;
    GameObject UIScore;

    ArrowMakeAndDestroy arrowMakeAndDestroy;
    NoteChecker noteChecker;
    DifficultyManager difficultyManager;

    bool gameOvered;
    bool locked;
    bool fever;


    void Start()
    {
        FindComponentAndManager();
        FindUI();

        InitializeGameState();
        InitializeNoteFrequency();
        Initialize4Arrows();
    }

    void Update()
    {
        if (IsPlayerCanAttackAndNotGameOveredAndNotLocked())
            noteChecker.Check();
    }

    bool IsPlayerCanAttackAndNotGameOveredAndNotLocked()
    {
        return gameOvered == false && locked == false && playerObj.GetComponent<PlayerScript>().IsAttackAble;
    }

    //초기화처리//
    
    void FindComponentAndManager()
    {
        arrowMakeAndDestroy = this.GetComponent<ArrowMakeAndDestroy>();
        noteChecker = this.GetComponent<NoteChecker>();
        difficultyManager = GameObject.Find("DifficultyManager").GetComponent<DifficultyManager>();
    }
    
    void FindUI()
    {
        UITimerGauge = GameObject.Find("Timer_Gauge");
        UIFeverGauge = GameObject.Find("Fever__");
        UIComboCount = GameObject.Find("Combo_Count");
        UIScore = GameObject.Find("Score");
    }

    void InitializeGameState()
    {
        gameOvered = false;
        locked = false;
        fever = false;
    }
    
    void InitializeNoteFrequency()
    {
        difficultyManager.setNormalFreq(5);
        difficultyManager.setDoubleFreq(5);
        difficultyManager.setReverseFreq(5);
    }

    void Initialize4Arrows()
    {
        //초기 4개화살표 생성
        for (int i = 0; i < 4; i++)
        {
            arrowMakeAndDestroy.MakeArrowByDifficulty();
        }

        GameObject[] temp = GameObject.FindGameObjectsWithTag("Arrows");
        for (int i = 0; i < temp.Length; i++)
        {
            temp[i].GetComponent<ArrowControl>().Locked(1.5f);
        }
    }

    //UI관련 처리//

    void SendSuccessInfoToUI()
    {
        UITimerGauge.SendMessage("SlideSuccess");
        UIFeverGauge.SendMessage("SlideSuccess");
        UIComboCount.SendMessage("IncreaseCount");
        UIScore.SendMessage("AddScore");
    }

    void SendSuccessInfoToUIWhenFever()
    {
        UITimerGauge.SendMessage("SlideSuccess");
        UIComboCount.SendMessage("IncreaseCount");
        UIScore.SendMessage("AddScore");
    }

    void SendFailInfoToUI()
    {
        UITimerGauge.SendMessage("SlideFail");
        UIFeverGauge.SendMessage("SlideFail");
        UIComboCount.SendMessage("ResetCount");
    }


    //애니메이션 처리함수//

    void SendAnimatorArrowDirection(string direction)
    {
        string sendAnimation = "";

        if (direction == "UpArrow" || direction == "DoubleUpArrow" || direction == "ReverseUpArrow")
            sendAnimation = "UpAttack";
        else if (direction == "LeftArrow" || direction == "RightArrow" || direction == "DoubleLeftArrow" || direction == "DoubleRightArrow"
                || direction == "ReverseLeftArrow" || direction == "ReverseRightArrow")
            sendAnimation = "SideAttack";
        else
            sendAnimation = "DownAttack";

        playerObj.SendMessage(sendAnimation);
    }


    //노트 락과 언락//

    void Lock()
    {
        locked = true;
    }

    void Unlock()
    {
        locked = false;
    }


    //노트처리관련 함수//

    public void NormalNoteSuccess(string arrow)
    {
        SendSuccessInfoToUI();
        arrowMakeAndDestroy.DestroyFrontArrow();
        arrowMakeAndDestroy.MakeArrowByDifficulty();
        SendAnimatorArrowDirection(arrow);
    }

    public void NormalNoteFail(float LockTime)
    {
        SendFailInfoToUI();
        LockAllArrows(LockTime);
    }

    public void DoubleNoteSuccess(string arrow)
    {
        if (arrowMakeAndDestroy.IsSpriteChanged())
        {
            SendSuccessInfoToUI();
            arrowMakeAndDestroy.MarkFrontArrowAsFail();
            arrowMakeAndDestroy.DestroyFrontArrow();
            Destroy(Instantiate(doubleAttackEffect), 0.5f);
            arrowMakeAndDestroy.MakeArrowByDifficulty();
            SendAnimatorArrowDirection(arrow);
        }
        else
        {
            arrowMakeAndDestroy.ChangeArrowSprite(arrow);
        }
    }

    public void DoubleNoteFail(float LockTime)
    {
        SendFailInfoToUI();
        LockAllArrows(LockTime);
    }

    public void ReverseNoteSuccess(string arrow)
    {
        SendSuccessInfoToUI();
        arrowMakeAndDestroy.DestroyFrontArrow();
        arrowMakeAndDestroy.MakeArrowByDifficulty();
        SendAnimatorArrowDirection(arrow);
    }

    public void ReverseNoteFail(float LockTime)
    {
        SendFailInfoToUI();
        LockAllArrows(LockTime);
    }

    public void FeverNoteSuccess(string arrow)
    {
        SendSuccessInfoToUIWhenFever();
        arrowMakeAndDestroy.DestroyFrontArrow();
        arrowMakeAndDestroy.MakeArrowByDifficulty();
        SendAnimatorArrowDirection(arrow);
    }

    public void LockAllArrows(float LockTime)
        {
            GameObject[] temp = GameObject.FindGameObjectsWithTag("Arrows");
            locked = true;
            Invoke("Unlock", LockTime);
            for (int i = 0; i < temp.Length; i++)
            {
                temp[i].GetComponent<ArrowControl>().Locked(LockTime);
            }

        }

    public string FindFrontArrow()
    {
        return arrowMakeAndDestroy.GetFrontArrowName();
    }

    
    //get,set함수들//

    public bool GetGameOverFlag()
    {
        return gameOvered;
    }

    public bool GetLockFlag()
    {
        return locked;
    }

    public bool GetFeverFlag()
    {
        return fever;
    }

    public void SetGameOverFlag(bool flag)
    {
        gameOvered = flag;
    }

    public void SetFeverFlag(bool flag)
    {
        fever = flag;
    }
}



