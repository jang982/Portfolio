using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExitSpot : MonoBehaviour {

    bool playerIn;

	// Use this for initialization
	void Awake () {
        playerIn = false;
	}

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
            playerIn = true;
    }

    public bool IsPlayerIn()
    {
        return playerIn;
    }
}
