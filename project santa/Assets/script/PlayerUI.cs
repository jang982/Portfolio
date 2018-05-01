﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

public class PlayerUI : MonoBehaviour {

    public Image HPBar;
    public float max_health;
    public float value;
    float now_hp;

    CharacterStatus characterStat;

	// 케릭터 스테이터스를 얻어서 체력이 얼만지 받습니다.
	void Awake() {

        characterStat = this.GetComponent<CharacterStatus>();
        max_health = characterStat.getHP();

    }
	
	// 케릭터 체력바를 업데이트 합니다.
	void Update () {
        now_hp = characterStat.getHP();
        HPBar.fillAmount = now_hp / max_health;
    }
}
