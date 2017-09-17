using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour {
    public static SoundManager Instance = null;

    public AudioSource EffectSound;
    public AudioSource EffectSound2;
    public AudioSource BackGroundSound;
    
    public AudioClip BGM;

    public bool BGM_state;
    public bool SE_state;

	void Awake () {
        BGM_state = true;
        SE_state = true;

        if (Instance == null)                   //게임시작시 이 instance가 없으면 생성
            Instance = this;
        else if (Instance != this)
            Destroy(gameObject);
        DontDestroyOnLoad(gameObject);
    }

    private void Start()
    {
        PlayBGM(BGM);
    }
	
	public void PlaySingle(AudioClip clip)
    {
        if (SE_state == true)
        {
            EffectSound.clip = clip;
            EffectSound.Play();
        }
    }

    public void PlaySingle2(AudioClip clip2)      //같은 프레임에 두 가지 소리가 나는 경우 해결 (안 그러면 한 가지 소리가 씹힘)
    {
        if (SE_state == true)
        {
            EffectSound2.clip = clip2;
            EffectSound2.Play();
        }
    }

    public void PlayBGM(AudioClip clip,bool loop=true)
    {
        if (BGM_state == true)
        {
            BackGroundSound.clip = clip;
            BackGroundSound.loop = loop;
            BackGroundSound.Play();
        }
    }

    public void StopBGM()
    {
        BackGroundSound.Stop();
    }
}
