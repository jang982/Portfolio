using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NoteChecker : MonoBehaviour {
    Vector2 StartPos;

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

    void ArrowCheckNormalMode(string InputArrow)
    {
        float ArrowLockTime = 1.0f;

        if(IsNormalNote(InputArrow))
            SlideRoutineInNormalNote(InputArrow, ArrowLockTime);

        else if(IsDoubleNote(InputArrow))
            SlideRoutineInDoubleNote(InputArrow, ArrowLockTime);

        else if(IsReverseNote(InputArrow))
            SlideRoutineInReverseNote(InputArrow, ArrowLockTime);

    }

    bool IsNormalNote(string InputArrow)
    {
        return InputArrow == "UpArrow" || InputArrow == "LeftArrow" || InputArrow == "DownArrow" || InputArrow == "RightArrow";
    }

    bool IsDoubleNote(string InputArrow)
    {
        return InputArrow == "DoubleUpArrow" || InputArrow == "DoubleLeftArrow" || InputArrow == "DoubleDownArrow" || InputArrow == "DoubleRightArrow";
    }

    bool IsReverseNote(string InputArrow)
    {
        return InputArrow == "ReverseUpArrow" || InputArrow == "ReverseLeftArrow" || InputArrow == "ReverseDownArrow" || InputArrow == "ReverseRightArrow";
    }

    void ArrowCheckFeverMode(string InputArrow)
    {
        SlideRoutineInFeverMode(InputArrow);
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
    


    
}
