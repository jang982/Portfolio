using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Timer : MonoBehaviour {
    public bool isLoadingMonster;

    float time;
    float timer_inc;
    float timer_dec;
    //float time_accum;

    float MAX_TIME;
    float MIN_TIME;
    float MAX_TIMER_SCALE;
    float MIN_TIMER_SCALE;

    public AudioClip slide_fail;

    int frame_count;
    //float RATIO;
    // Use this for initialization

    public float flowedTime;                   // 총 흐른시간


    void Start () {
        //Debug.Log("TimerLoad");
        PlayerTurnTimerStart();
    }


    void PlayerTurnTimerStart()
    {
        isLoadingMonster = true;

        MAX_TIME = 8.0f;
        MIN_TIME = 0;
        MAX_TIMER_SCALE = 1.0f;
        MIN_TIMER_SCALE = 0;
        //RATIO = 0.8f;
        frame_count = 0;

        time = MAX_TIME;
        //time_accum = 0;
        timer_inc = 1.0f;
        timer_dec = 3.0f;
        transform.localScale = new Vector3(MAX_TIMER_SCALE * (time / MAX_TIME), transform.localScale.y, transform.localScale.z);

        flowedTime = 0;
    }
    void EnemyTurnTimerStart()
    {
        time = MAX_TIME;
        transform.localScale = new Vector3(MAX_TIMER_SCALE * (time / MAX_TIME), transform.localScale.y, transform.localScale.z);
    }
	
	
	// Update is called once per frame
	void Update () {
        flowedTime += Time.deltaTime;

        //Debug.Log(isLoadingMonster);
        /*time_accum += Time.deltaTime;
        if(time_accum >= 10)
        {
            timer_inc *= RATIO;
            time_accum = 0;
            Debug.Log(timer_inc);
        }*/

        if (time > 0 && isLoadingMonster == false)
        {
            //Debug.Log(time);
            time -= Time.deltaTime;
            float delta_Scale = MAX_TIMER_SCALE * (Time.deltaTime / MAX_TIME);
            transform.localScale = new Vector3(transform.localScale.x - delta_Scale, transform.localScale.y, transform.localScale.z);

        }
        if (time <= 0)
        {
            GameObject.Find("Player").SendMessage("Damage",100);
            /*if (StageManager.GetComponent<NormalModeStageManager>().turn == 0)
            {
                StageManager.SendMessage("PlayerTurnEnd");
                EnemyTurnTimerStart();
            }
            else {
                StageManager.SendMessage("EnemyTurnEnd");
                PlayerTurnTimerStart();
            }*/
        }

    }
    public void SlideFail()
    {
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(slide_fail);

        float delta_Scale = MAX_TIMER_SCALE * (timer_dec / MAX_TIME);
        if (time > MIN_TIME)
        {
            time -= timer_dec;
            transform.localScale = new Vector3(transform.localScale.x - delta_Scale, transform.localScale.y, transform.localScale.z);
        }
        if (time < MIN_TIME)
        {
            time = MIN_TIME;
            transform.localScale = new Vector3(MIN_TIMER_SCALE, transform.localScale.y, transform.localScale.z);
        }
    }

    public void SlideSuccess()
    {
        float delta_Scale = MAX_TIMER_SCALE * (timer_inc / MAX_TIME);
        if (time <= MAX_TIME)
        {
            time += timer_inc;
            transform.localScale = new Vector3(transform.localScale.x + delta_Scale, transform.localScale.y, transform.localScale.z);
        }
        if (time > MAX_TIME)
        {
            time = MAX_TIME;
            transform.localScale = new Vector3(MAX_TIMER_SCALE, transform.localScale.y, transform.localScale.z);

        }
    }

    public void TimerHold(float LockTime)
    {
        isLoadingMonster = true;
        Invoke("TimerRelease", LockTime);

    }

    void TimerRelease()
    {
        isLoadingMonster = false;
    }


    public float GetTimerInc()
    {
        return timer_inc;
    }

    public void SetTimerInc(float Inc)
    {
        timer_inc = Inc;
    }

    public float GetTimerDec()
    {
        return timer_dec;
    }

    public void SetTimerDec(float Dec)
    {
        timer_dec = Dec;
    }
}
