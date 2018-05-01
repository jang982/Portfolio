using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterStatus : MonoBehaviour {
    float HP;
    float stamina;
    float attackPower;
    float stunPercentage;

    bool isPlayer;


    //스텟을 초기화합니다.
	void Awake () {
        if (this.tag == "Player")
            isPlayer = true;
        else
            isPlayer = false;
        
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
                HP = 100f;
                stamina = 100f;
                attackPower = 50f;
                stunPercentage = 10f;

                break;

            case "People":
                HP = 100f;
                stamina = 100f;
                attackPower = 5f;
                stunPercentage = 10f;

                break;
        }
    }

    public float getCharacterPower()
    {
        return attackPower;
    }

    public float getHP()
    {
        return HP;
    }

    public float getStamina()
    {
        return stamina;
    }

    //케릭터의 데미지를 불러옵니다.
    public float getEnermyAttackPower(string tag)
    {
        float EnermyAttackPower = GameObject.FindGameObjectWithTag(tag).GetComponent<CharacterStatus>().attackPower;
        return EnermyAttackPower;
    }

    //특정 태그로 데미지를 입힙니다.
    public void damaged(string tag)
    {
        if (this.GetComponent<Animator>().GetBool("isDying"))
            return;
        Debug.Log("Attcked character: " + tag);
        Debug.Log("character Damage: " + getEnermyAttackPower(tag));
        float damage = getEnermyAttackPower(tag);
        HP -= damage;
        Debug.Log("HP:" + HP);
    }


    //특정 수치로 데미지를 입힙니다.
    public void damaged(float value)
    {
        Debug.Log("damaged call");
        if (this.GetComponent<Animator>().GetBool("isDying"))
            return;
        float damage = value;
        HP -= damage;
        Debug.Log("HP:" + HP);
    }
}
