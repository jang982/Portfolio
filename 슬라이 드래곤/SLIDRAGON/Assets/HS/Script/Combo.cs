using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Combo : MonoBehaviour {

	// Use this for initialization
	void Start () {
        gameObject.GetComponent<Text>().enabled = false;
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    void TextEnable ()
    {
        gameObject.GetComponent<Text>().enabled = true;
    }

    void TextDisable ()
    {
        gameObject.GetComponent<Text>().enabled = false;
    }
}
