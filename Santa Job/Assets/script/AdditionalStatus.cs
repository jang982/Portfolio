using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class AdditionalStatus : MonoBehaviour {

    float additionalHP;
    float additionalDamage;
    float additionalStunPercent;
    float evilValue;


    int additionalStatus;
    int additionalStatusHP;
    int additionalStatusDMG;
    int additionalStatusStun;

    GameObject HP;
    GameObject DMG;
    GameObject Stun;
    GameObject Evil;
    GameObject RewardStatus;

    bool NVGPossible;

    GameManagerScript gameManagerScript;
    


	public void Start () {
        gameManagerScript = GetComponent<GameManagerScript>();
        additionalHP = 0f;
        additionalDamage = 5f;
        additionalStunPercent = 0f;

        additionalStatusHP = 0;
        additionalStatusDMG = 0;
        additionalStatusStun = 0;
        additionalStatus = 0;

        evilValue = 0f;
        NVGPossible = false;
        
	}

    private void Update()
    {
        if (SceneManager.GetActiveScene().name != "Reward")
            return;

        RewardStatus.GetComponent<Text>().text = additionalStatus.ToString();
        HP.GetComponent<Text>().text = additionalStatusHP.ToString();
        DMG.GetComponent<Text>().text = additionalStatusDMG.ToString();
        Stun.GetComponent<Text>().text = additionalStatusStun.ToString();
    }

    //화면불러올때 초기화
    public void initializeRewardStats()
    {
        Debug.Log("초기화");
        HP = GameObject.FindGameObjectWithTag("HpStat");
        DMG= GameObject.FindGameObjectWithTag("DmgStat");
        Stun= GameObject.FindGameObjectWithTag("StunStat");
        RewardStatus= GameObject.FindGameObjectWithTag("RewardStat");


        additionalStatusHP = 0;
        additionalStatusDMG = 0;
        additionalStatusStun = 0;
        additionalStatus = gameManagerScript.getRewardStat();
    }

    public float getAdditionalHP()
    {
        return additionalHP;
    }

    public float getAdditionalDamage()
    {
        return additionalDamage;
    }

    public float getAdditionalStunPercent()
    {
        return additionalStunPercent;
    }

    public float GetEvilValue()
    {
        return evilValue;
    }

    public bool getNVGPossible()
    {
        return NVGPossible;
    }


    public void IncAdditionalHP()
    {
        if (additionalStatus == 0)
            return;

        additionalHP = additionalHP + 5f;
        additionalStatusHP++;
        additionalStatus--;
        
    }

    public void IncAdditionalDamage()
    {
        if (additionalStatus == 0)
            return;

        additionalDamage = additionalDamage + 5f;
        additionalStatusDMG++;
        additionalStatus--;


        Debug.Log("공격 수치 = " + additionalDamage);
    }

    public void IncAdditionalStunPercent()
    {
        if (additionalStatus == 0)
            return;

        additionalStunPercent = additionalStunPercent + 5f;
        additionalStatusStun++;
        additionalStatus--;
    }

    public void DecAdditionalHP()
    {
        if (additionalStatusHP == 0)
            return;

        additionalHP = additionalHP - 5;
        additionalStatusHP--;
        additionalStatus++;
    }

    public void DecAdditionalDamage()
    {
        if (additionalStatusDMG == 0)
            return;

        additionalDamage = additionalDamage - 5;
        additionalStatusDMG--;
        additionalStatus++;

    }

    public void DecAdditionalStunPercent()
    {
        if (additionalStatusStun == 0)
            return;

        additionalStunPercent = additionalStunPercent - 5;
        additionalStatusStun--;
        additionalStatus++;
    }

    public void setPlusEvilValue(float input)
    {
        evilValue += input;
    }

    void setNVGPossible(bool input)
    {
        NVGPossible = input;
    }

}
