using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LampLight : MonoBehaviour {
    Light lampLight;
    public bool isLigthOn;
	// Use this for initialization
	void Start () {
        lampLight = GetComponent<Light>();
        isLigthOn = lampLight.enabled;
	}

    public void LampLightOn()
    {
        lampLight.enabled = true;
        isLigthOn = true;
    }

    public void LampLightOff()
    {
        lampLight.enabled = false;
        isLigthOn = false;
    }
	
}
