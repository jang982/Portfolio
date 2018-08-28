using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour {
    public int score;
    public Text score_text;

    // Use this for initialization
    void Start()
    {
        score = 0;
        score_text.text = score.ToString();
    }

    // Update is called once per frame
    void Update()
    {
       score_text.text = score.ToString();
    }

    void AddScore()
    {
        score += 10;
    }
}
