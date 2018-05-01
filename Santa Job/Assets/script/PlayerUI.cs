using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

public class PlayerUI : MonoBehaviour {

    public Image HPBar;
    public Text stun;
    public Text dmg;
    public Text evilValue;
    public float max_health;
    public float value;
    float now_hp;

    CharacterStatus characterStat;

	// 케릭터 스테이터스를 얻어서 체력이 얼만지 받습니다.
	void Start() {

        characterStat = this.GetComponent<CharacterStatus>();
        max_health = characterStat.getHP();
        stun.text = characterStat.getStunPercentage().ToString();
        dmg.text = characterStat.getCharacterPower().ToString();
        evilValue.text = characterStat.getEvil().ToString();
    }
	
	// 케릭터 체력바를 업데이트 합니다.
	void Update () {
        now_hp = characterStat.getHP();
        HPBar.fillAmount = now_hp / max_health;
        stun.text = characterStat.getStunPercentage().ToString();
        dmg.text = characterStat.getCharacterPower().ToString();
        evilValue.text = characterStat.getEvil().ToString();
    }
}
