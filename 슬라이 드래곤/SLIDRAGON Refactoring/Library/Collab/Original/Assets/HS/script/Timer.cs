using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Timer : MonoBehaviour {
    public GameObject StageManager;
    float time;
    float timer_inc;
    float timer_dec;
    //float time_accum;

    float MAX_TIME;
    float MIN_TIME;
    float MAX_TIMER_SCALE;
    float MIN_TIMER_SCALE;

    int frame_count;
    //float RATIO;
	// Use this for initialization
    void PlayerTurnTimerStart()
    {
        MAX_TIME = 4.0f;
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
    }
    void EnemyTurnTimerStart()
    {
        time = MAX_TIME;
        transform.localScale = new Vector3(MAX_TIMER_SCALE * (time / MAX_TIME), transform.localScale.y, transform.localScale.z);
    }
	void Start () {
        PlayerTurnTimerStart();
    }
	
	// Update is called once per frame
	void Update () {

        /*time_accum += Time.deltaTime;
        if(time_accum >= 10)
        {
            timer_inc *= RATIO;
            time_accum = 0;
            Debug.Log(timer_inc);
        }*/

        if (time > 0)
        {
            //Debug.Log(time);
            time -= Time.deltaTime;
            float delta_Scale = MAX_TIMER_SCALE * (Time.deltaTime / MAX_TIME);
            transform.localScale = new Vector3(transform.localScale.x - delta_Scale, transform.localScale.y, transform.localScale.z);

        }
        if (time <= 0)
        {
            if (StageManager.GetComponent<StageManager>().turn == 0)
            {
                StageManager.SendMessage("PlayerTurnEnd");
                EnemyTurnTimerStart();
            }
            else {
                StageManager.SendMessage("EnemyTurnEnd");
                PlayerTurnTimerStart();
            }
        }

    }
    public void SlideFail()
    {
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
}
