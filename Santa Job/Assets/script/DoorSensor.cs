using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DoorSensor : MonoBehaviour {
    Door door;
	// Use this for initialization
	void Start () {
        door = GetComponentInChildren<Door>();
	}

    private void OnTriggerEnter(Collider other)
    {
        door.Open();
    }


    private void OnTriggerExit(Collider other)
    {
        door.Close();
    }
}
