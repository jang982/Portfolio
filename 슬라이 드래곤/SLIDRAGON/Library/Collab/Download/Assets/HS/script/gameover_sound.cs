using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class gameover_sound : MonoBehaviour {

    public AudioClip appear_sound;

    bool sound_on;

	// Use this for initialization
	void Start () {
        sound_on = false;
	}
	
	// Update is called once per frame
	void Update () {
        if (this.gameObject.activeSelf == true && sound_on == false)
        {
            GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(appear_sound);
            sound_on = true;
        }
    }
}