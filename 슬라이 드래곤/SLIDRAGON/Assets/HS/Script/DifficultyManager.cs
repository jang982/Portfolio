using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DifficultyManager : MonoBehaviour {
    public GameObject InfManager;
    public GameObject Timer;
    public GameObject NoteManager;
    public GameObject[] MenuObjects;
    public GameObject[] MonsterHP;

    public int ImpHP;
    public int SlimeHP;
    public int SkeletonHP;
    public int HatchlingHP;
    public int LizardManHP;
    public int MangDragonHP;
    public int LittleDragonHP;
    public int BossDragonHP;
    public int BossDragon2HP;

    public float MissileFireDelay;
    public int MissileFrequency;

    public Text ImpHP_Text;
    public Text SlimeHP_Text;
    public Text SkeletonHP_Text;
    public Text LittleDragonHP_Text;
    public Text BossDragonHP_Text;
    public Text DecPercent_Text;
    public Text FiveDecPercent_Text;
    public Text MissileFireDelay_Text;
    public Text MissileFrequency_Text;

    float NowRecovery;
    float DecPercent;
    float FiveDecPercent;


	// Use this for initialization
	void Start () {
        

        ImpHP = 10;
        SlimeHP = 10;
        SkeletonHP = 10;
        HatchlingHP = 10;
        LizardManHP = 10;
        MangDragonHP = 10;
        LittleDragonHP = 10;
        BossDragonHP = 20;
        BossDragon2HP = 20;

        DecPercent = 0.95f;
        FiveDecPercent = 0.9f;

        MissileFireDelay = 2.0f;
        MissileFrequency = 1;

        ImpHP_Text.text = ImpHP.ToString();
        SlimeHP_Text.text = SlimeHP.ToString();
        SkeletonHP_Text.text = SkeletonHP.ToString();
        LittleDragonHP_Text.text = LittleDragonHP.ToString();
        BossDragonHP_Text.text = BossDragonHP.ToString();

        DecPercent_Text.text = DecPercent.ToString();
        FiveDecPercent_Text.text = FiveDecPercent.ToString();

        MissileFireDelay_Text.text = MissileFireDelay.ToString();
        MissileFrequency_Text.text = MissileFrequency.ToString()+"0 %";

}
	
	void ShowThanksTo()
    {

        for (int i = 0; i < MenuObjects.Length; i++)
            MenuObjects[i].SetActive(false);
        for (int i = 0; i < MonsterHP.Length; i++)
            MonsterHP[i].SetActive(true);
    }

    public void HideDifficultySetting()
    {
        for (int i = 0; i < MenuObjects.Length; i++)
            MenuObjects[i].SetActive(true);
        for (int i = 0; i < MonsterHP.Length; i++)
            MonsterHP[i].SetActive(false);
    }

    public void DecRecovery()
    {
        //5스테이지별 추가감소
        if(InfManager.GetComponent<InfiniteModeStageManager>().GetStageCount() % 5 == 0)
        {
            //Debug.Log("Before Inc =" + Timer.GetComponent<Timer>().GetTimerInc());
            NowRecovery = Timer.GetComponent<Timer>().GetTimerInc();
            Timer.GetComponent<Timer>().SetTimerInc(NowRecovery * 0.9f);
            //Debug.Log("After Inc =" + Timer.GetComponent<Timer>().GetTimerInc());
        }
        else
        {
            //Debug.Log("Before Inc =" + Timer.GetComponent<Timer>().GetTimerInc());
            NowRecovery = Timer.GetComponent<Timer>().GetTimerInc();
            Timer.GetComponent<Timer>().SetTimerInc(NowRecovery * DecPercent);
            //Debug.Log("After Inc =" + Timer.GetComponent<Timer>().GetTimerInc());
        }
        
    }

    void IncNoteFreq(int i)
    {
        NoteManager.GetComponent<NoteChecker>().DoubleFreq += i;
        NoteManager.GetComponent<NoteChecker>().ReverseFreq += i;
        Debug.Log("노트증가"+NoteManager.GetComponent<NoteChecker>().DoubleFreq + NoteManager.GetComponent<NoteChecker>().ReverseFreq);
    }

    public int GetMonsterHP(string MonsterName)
    {
        int ReturnHP = 2;
        switch (MonsterName)
        {
            case "Imp(Clone)":
                ReturnHP = ImpHP;
                break;
            case "Skeleton(Clone)":
                ReturnHP = SkeletonHP;
                break;
            case "Slime(Clone)":
                ReturnHP = SlimeHP;
                break;
            case "LittleDragon(Clone)":
                ReturnHP = LittleDragonHP;
                break;
            case "Lizardman(Clone)":
                ReturnHP = LizardManHP;
                break;
            case "MangDragon(Clone)":
                ReturnHP = MangDragonHP;
                break;
            case "BossDragon(Clone)":
                ReturnHP = BossDragonHP;
                break;
            case "BossDragon2(Clone)":
                ReturnHP = BossDragon2HP;
                break;
        }
        return ReturnHP;
    }

    //증감버튼
    public void IncImpHP()
    {
        ImpHP++;
        ImpHP_Text.text = ImpHP.ToString();
    }
    public void IncSlimeHP()
    {
        SlimeHP++;
        SlimeHP_Text.text = SlimeHP.ToString();
    }
    public void IncSkeletonHP()
    {
        SkeletonHP++;
        SkeletonHP_Text.text = SkeletonHP.ToString();
    }
    public void IncLittleDragonHP()
    {
        LittleDragonHP++;
        LittleDragonHP_Text.text = LittleDragonHP.ToString();
    }
    public void IncBossDragonHP()
    {
        BossDragonHP++;
        BossDragonHP_Text.text = BossDragonHP.ToString();
    }
    public void IncDecPercent()
    {
        DecPercent += 0.01f;
        DecPercent_Text.text = DecPercent.ToString();
    }
    public void IncFiveDecPercent()
    {
        FiveDecPercent += 0.01f;
        FiveDecPercent_Text.text = FiveDecPercent.ToString();
    }
    public void IncMissileFireDelay()
    {
        MissileFireDelay += 0.1f;
        MissileFireDelay_Text.text = MissileFireDelay.ToString();
    }
    public void IncMissileFrequency()
    {
        MissileFrequency += 1;
        MissileFrequency_Text.text = MissileFrequency.ToString()+"0 %";
    }

    public void DecImpHP()
    {
        ImpHP--;
        ImpHP_Text.text = ImpHP.ToString();
    }
    public void DecSlimeHP()
    {
        SlimeHP--;
        SlimeHP_Text.text = SlimeHP.ToString();
    }
    public void DecSkeletonHP()
    {
        SkeletonHP--;
        SkeletonHP_Text.text = SkeletonHP.ToString();
    }
    public void DecLittleDragonHP()
    {
        LittleDragonHP--;
        LittleDragonHP_Text.text = LittleDragonHP.ToString();
    }
    public void DecBossDragonHP()
    {
        BossDragonHP--;
        BossDragonHP_Text.text = BossDragonHP.ToString();
    }
    public void DecDecPercent()
    {
        DecPercent -= 0.01f;
        DecPercent_Text.text = DecPercent.ToString();
    }
    public void DecFiveDecPercent()
    {
        FiveDecPercent -= 0.01f;
        FiveDecPercent_Text.text = FiveDecPercent.ToString();
    }
    public void DecMissileFireDelay()
    {
        MissileFireDelay -= 0.1f;
        MissileFireDelay_Text.text = MissileFireDelay.ToString();
    }
    public void DecMissileFrequency()
    {
        MissileFrequency -= 1;
        MissileFrequency_Text.text = MissileFrequency.ToString()+"0 %";
    }
}
