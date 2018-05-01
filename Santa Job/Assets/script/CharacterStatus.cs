using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterStatus : MonoBehaviour {
    float HP;
    float attackPower;
    float stunPercentage;
    float evil;

    public float itemDMG;
    public float itemStun;

    bool isPlayer;

    AdditionalStatus additionalStatus;

    //스텟을 초기화합니다.
	void Start () {
        if (this.tag == "Player")
            isPlayer = true;
        else
            isPlayer = false;

        itemDMG = 0;
        itemStun = 0;

        //additionalStatus = GameObject.FindGameObjectWithTag("GameManager").GetComponent<AdditionalStatus>();
        
        //loadWholeStatus(this.tag);

        Debug.Log(this.tag+"evil:" + evil);
	}

    public void initializeStatus()
    {
        Debug.Log("추가스텟 로딩");
        additionalStatus = GameObject.FindGameObjectWithTag("GameManager").GetComponent<AdditionalStatus>();
        Debug.Log("추가스텟 공격 " + additionalStatus.getAdditionalDamage());
        loadWholeStatus(this.tag);
    }

    //업데이트 부분
    void Update()
    {
        if (HP <= 0 )//체력0이하면
        {
            if(!this.GetComponent<Animator>().GetBool("isDying"))//애니메이터 bool이 false면
            {
                //죽는부분을 호출합니다
                if (isPlayer)
                    this.GetComponent<PlayerController>().SendMessage("Die");
                else
                    this.GetComponent<PeopleController>().SendMessage("Die");
            }
            
        }
            
            
    }


    //케릭터의 스텟을 불러오는 부분입니다.
    void loadWholeStatus(string CharacterName)
    {
        //케릭터의 이름에따라 스텟을 불러옵니다.
        switch(CharacterName)
        {
            case "Player":
                HP = 100f + additionalStatus.getAdditionalHP();
                attackPower = 5f + additionalStatus.getAdditionalDamage();
                stunPercentage = 30f + additionalStatus.getAdditionalStunPercent();
                evil = additionalStatus.GetEvilValue();

                break;

            case "People":
                HP = 120f;
                attackPower = 15f;
                stunPercentage = 0f;
                evil = 0f;

                break;
        }
    }

    

    public void addCharacterDmg(float addDmg)
    {
        attackPower = attackPower + addDmg;
    }

    public void addStunPercentage(float addStun)
    {
        stunPercentage = stunPercentage + addStun;
    }


    //케릭터의 데미지를 불러옵니다.
    public float getEnermyAttackPower(string tag)
    {
        float EnermyAttackPower = GameObject.FindGameObjectWithTag(tag).GetComponent<CharacterStatus>().attackPower;
        return EnermyAttackPower;
    }

    //특정 태그로 데미지를 입힙니다.
    //public void damaged(string tag)
    //{
    //    if (this.GetComponent<Animator>().GetBool("isDying"))
    //        return;
    //    Debug.Log("Attcked character: " + tag);
    //    Debug.Log("character Damage: " + getCharacterPower());
    //    //Debug.Log("character Damage: " + getEnermyAttackPower(tag));
    //    //float damage = getEnermyAttackPower(tag);
    //    HP -= getCharacterPower();
    //    Debug.Log("HP:" + HP);
    //}


    //특정 수치로 데미지를 입힙니다.
    public void damaged(float value)
    {
        if (this.GetComponent<Animator>().GetBool("isDying"))
            return;
        float damage = value;
        HP -= damage;

    }


    public float getCharacterPower()
    {
        return attackPower + itemDMG;
    }

    public float getHP()
    {
        return HP;
    }


    public float getStunPercentage()
    {
        if (stunPercentage + itemStun <= 100f)
            return stunPercentage + itemStun;
        else
            return 100f;
    }

    public void PlusEvilValue(float val)
    {
        evil += val;
    }

    public float getEvil()
    {
        return evil;
    }
}
