using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ComboCount : MonoBehaviour {

    int count;
    public int maxCombo;
    public Text count_text;

	// Use this for initialization
	void Start () {
        count = 0;
        maxCombo = 0;
        count_text.text = count.ToString();
        gameObject.GetComponent<Text>().enabled = false;
    }

    // Update is called once per frame
    void Update () {
        count_text.text = count.ToString();
        if(count >= 5)
        {
            gameObject.GetComponent<Text>().enabled = true;
            GameObject.Find("Combo").SendMessage("TextEnable");
        }
        else
        {
            gameObject.GetComponent<Text>().enabled = false;
            GameObject.Find("Combo").SendMessage("TextDisable");
        }
    }

    void IncreaseCount ()
    {
        count++;
        if (maxCombo <= count)
            maxCombo = count;
    }

    void ResetCount ()
    {
        count = 0;
    }
}
