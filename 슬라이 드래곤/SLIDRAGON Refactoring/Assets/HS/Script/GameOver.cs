using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameOver : MonoBehaviour {

    public bool isGameOvered;
    public bool isTouched;
    public bool isVictory;

    float flow_time;

    public Text game_over_text;
    public Text kill_text;
    public Text maxCombo_text;
    public Text time_text;

    public Text score_text;
    public Text kill_count_text;
    public Text maxCombo_count_text;
    public Text time_value_text;

    public int score_value;
    public int kill_count;
    public int maxCombo_count;
    public int time_value;

    GameObject Victory;
    GameObject[] gameOver;
    GameObject[] score;
    GameObject[] kill;
    GameObject[] maxCombo;
    GameObject[] time;
    GameObject[] backToMain;


    void Start ()
    {
        isGameOvered = false;
        isTouched = false;
        isVictory = false;
        flow_time = 0;

        score_value = 123523;
        kill_count = 0;
        maxCombo_count = 0;
        time_value = 0;

        Victory = GameObject.FindGameObjectWithTag("Victory");
        gameOver = GameObject.FindGameObjectsWithTag("GameOver");
        score = GameObject.FindGameObjectsWithTag("Score");
        kill = GameObject.FindGameObjectsWithTag("Kill");
        maxCombo = GameObject.FindGameObjectsWithTag("MaxCombo");
        time = GameObject.FindGameObjectsWithTag("Time");
        backToMain = GameObject.FindGameObjectsWithTag("BackToMain");

        Victory.SetActive(false);
        for (int i = 0; i < gameOver.Length; i++)
            gameOver[i].SetActive(false);
        for (int i = 0; i < score.Length; i++)
            score[i].SetActive(false);
        for (int i = 0; i < kill.Length; i++)
            kill[i].SetActive(false);
        for (int i = 0; i < maxCombo.Length; i++)
            maxCombo[i].SetActive(false);
        for (int i = 0; i < time.Length; i++)
            time[i].SetActive(false);
        for (int i = 0; i < backToMain.Length; i++)
            backToMain[i].SetActive(false);
    } 

    void Update ()
    {
        if (isGameOvered == true)
        {
            flow_time += Time.deltaTime;
            if(flow_time >= 0.8f && flow_time < 1.6f)
            {
                if (isVictory) Victory.SetActive(true);             //승리시 빅토리 텍스트
                else                                                //그외 게임오버 텍스트
                {
                    for (int i = 0; i < gameOver.Length; i++)
                    {
                        gameOver[i].SetActive(true);
                    }
                }
            }
            else if (flow_time >= 1.6f && flow_time < 2.4f)
            {
                for (int i = 0; i < score.Length; i++)
                {
                    score[i].SetActive(true);
                }
            }
            else if (flow_time >= 2.4f && flow_time < 3.2f)
            {

                for (int i = 0; i < kill.Length; i++)
                {
                    kill[i].SetActive(true);
                }
            }
            else if (flow_time >= 3.2f && flow_time < 4.0f)
            {
                for (int i = 0; i < maxCombo.Length; i++)
                {
                    maxCombo[i].SetActive(true);
                }
            }
            else if (flow_time >= 4.0f && flow_time < 4.8f)
            {
                for (int i = 0; i < time.Length; i++)
                {
                    time[i].SetActive(true);
                }
            }
            else if (flow_time >= 4.8f)
            {
                for (int i = 0; i < backToMain.Length; i++)
                {
                    backToMain[i].SetActive(true);
                }
                isGameOvered = false;
                isTouched = false;
            }
        }
        if (isTouched == true)
            flow_time += (Time.deltaTime * 6);
    } 

    void Appear ()
    {
        score_value = GameObject.Find("Score").GetComponent<Score>().score;
        maxCombo_count = GameObject.Find("Combo_Count").GetComponent<ComboCount>().maxCombo;
        time_value = (int)GameObject.Find("Timer_Gauge").GetComponent<Timer>().flowedTime;
        kill_count = GameObject.Find("InfiniteStageManager").GetComponent<InfiniteModeStageManager>().MonsterCount_all;

        score_text.text = score_value.ToString();
        maxCombo_count_text.text = maxCombo_count.ToString();
        time_value_text.text = (time_value / 60).ToString() + "M " + (time_value % 60).ToString() + "S";
        kill_count_text.text = kill_count.ToString();

        GameObject[] arrows = GameObject.FindGameObjectsWithTag("Arrows");
        for (int i = 0; i < arrows.Length; i++)
            arrows[i].SetActive(false);
        GameObject.Find("Fever__").SetActive(false);
        GameObject.Find("Timer").SetActive(false);

        if (isVictory) { }
        else GameObject.Find("Player").SetActive(false);

        GameObject.Find("ComboBox").SetActive(false);
        GameObject.Find("Score").SetActive(false);

        isGameOvered = true;
    }

    void SetVictory()
    {
        isVictory = true;
    }

}
