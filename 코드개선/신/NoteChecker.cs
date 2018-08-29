using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NoteChecker : MonoBehaviour {
    Vector2 startPos;

    NoteManager noteManager;

    void Start()
    {
        noteManager = this.GetComponent<NoteManager>();
    }

    public void Check()
    {
        if (IsInputExist())
        {
            if (noteManager.GetFeverFlag())
                ArrowCheckFeverMode(noteManager.FindFrontArrow());
            else
                ArrowCheckNormalMode(noteManager.FindFrontArrow());
        }
    }

    bool IsInputExist()
    {
        return Input.touchCount > 0 || Input.anyKeyDown;
    }

    void ArrowCheckNormalMode(string inputArrow)
    {
        float arrowLockTime = 1.0f;

        if(IsNormalNote(inputArrow))
            SlideRoutineInNormalNote(inputArrow, arrowLockTime);

        else if(IsDoubleNote(inputArrow))
            SlideRoutineInDoubleNote(inputArrow, arrowLockTime);

        else if(IsReverseNote(inputArrow))
            SlideRoutineInReverseNote(inputArrow, arrowLockTime);

    }

    bool IsNormalNote(string inputArrow)
    {
        return inputArrow == "UpArrow" || inputArrow == "LeftArrow" || inputArrow == "DownArrow" || inputArrow == "RightArrow";
    }

    bool IsDoubleNote(string inputArrow)
    {
        return inputArrow == "DoubleUpArrow" || inputArrow == "DoubleLeftArrow" || inputArrow == "DoubleDownArrow" || inputArrow == "DoubleRightArrow";
    }

    bool IsReverseNote(string inputArrow)
    {
        return inputArrow == "ReverseUpArrow" || inputArrow == "ReverseLeftArrow" || inputArrow == "ReverseDownArrow" || inputArrow == "ReverseRightArrow";
    }

    void ArrowCheckFeverMode(string inputArrow)
    {
        SlideRoutineInFeverMode(inputArrow);
    }

    void SlideRoutineInNormalNote(string arrow,float lockTime)
    {
        if (IsCorrectInput(arrow))
        {
            noteManager.NormalNoteSuccess(arrow);
        }
        else if (IsDifferentInput(arrow))
        {
            noteManager.NormalNoteFail(lockTime);
        }
    }

    void SlideRoutineInDoubleNote(string arrow, float lockTime)
    {
        if (IsCorrectInput(arrow))
        {
            noteManager.DoubleNoteSuccess(arrow);
        }
        else if (IsDifferentInput(arrow))
        {
            noteManager.DoubleNoteFail(lockTime);
        }
    }

    void SlideRoutineInReverseNote(string arrow, float lockTime)
    {
        if (IsCorrectInput(arrow))
        {
            noteManager.ReverseNoteSuccess(arrow);
        }
        else if (IsDifferentInput(arrow))
        {
            noteManager.ReverseNoteFail(lockTime);
        }
    }

    void SlideRoutineInFeverMode(string arrow)
    {
        if (IsSometingInputed())
        {
            noteManager.FeverNoteSuccess(arrow);
        }
    }
    
    bool IsCorrectInput(string arrowName)
    {
        bool ret = false;

        arrowName = ConvertArrowName(arrowName);

        switch (arrowName)
        {
            case "UpArrow":
                ret = Input.GetKey(KeyCode.UpArrow) || SlideCheck() == "Up";
                break;
            case "LeftArrow":
                ret = Input.GetKey(KeyCode.LeftArrow) || SlideCheck() == "Left";
                break;
            case "DownArrow":
                ret= Input.GetKey(KeyCode.DownArrow) || SlideCheck() == "Down";
                break;
            case "RightArrow":
                ret= Input.GetKey(KeyCode.RightArrow) || SlideCheck() == "Right";
                break;
        }

        return ret;
    }

    bool IsDifferentInput(string arrowName)
    {
        bool ret = false;

        arrowName = ConvertArrowName(arrowName);

        switch (arrowName)
        {
            case "UpArrow":
                ret = Input.GetKey(KeyCode.DownArrow) || Input.GetKey(KeyCode.RightArrow) || Input.GetKey(KeyCode.LeftArrow) 
                    || SlideCheck() == "Down" || SlideCheck() == "Right" || SlideCheck() == "Left";
                break;
            case "LeftArrow":
                ret = Input.GetKey(KeyCode.DownArrow) || Input.GetKey(KeyCode.RightArrow) || Input.GetKey(KeyCode.UpArrow)
                    || SlideCheck() == "Down" || SlideCheck() == "Right" || SlideCheck() == "Up";
                break;
            case "DownArrow":
                ret = Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.RightArrow) || Input.GetKey(KeyCode.LeftArrow)
                    || SlideCheck() == "Up" || SlideCheck() == "Right" || SlideCheck() == "Left";
                break;
            case "RightArrow":
                ret = Input.GetKey(KeyCode.DownArrow) || Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.LeftArrow)
                    || SlideCheck() == "Down" || SlideCheck() == "Up" || SlideCheck() == "Left";
                break;
        }

        return ret;
    }

    string ConvertArrowName(string name)
    {
        if (name == "DoubleUpArrow" || name == "ReverseDownArrow")
            name = "UpArrow";
        else if (name == "DoubleLeftArrow" || name == "ReverseRightArrow")
            name = "LeftArrow";
        else if (name == "DoubleDownArrow" || name == "ReverseUpArrow")
            name = "DownArrow";
        else if (name == "DoubleRightArrow" || name == "ReverseLeftArrow")
            name = "RightArrow";

        return name;
    }

    bool IsSometingInputed()
    {
        return Input.anyKeyDown || SlideCheck() == "Touched";
    }

    public string SlideCheck()
    {
        if (Input.touchCount > 0)
        {
            Touch NowTouch = Input.GetTouch(0);
            switch (NowTouch.phase)
            {
                case TouchPhase.Began:
                    startPos = NowTouch.position;
                    break;

                case TouchPhase.Ended:
                    Vector2 deltaPos = NowTouch.position - startPos;
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
    


    
}
