using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMove : MonoBehaviour {

    public float smoothSpeed = 0.125f;
    public Vector3 offset;
    GameObject player;
	// Use this for initialization
	void Start () {
        player = GameObject.FindGameObjectWithTag("Player");
	}
	
	// Update is called once per frame
	void LateUpdate () {
        Vector3 desirePosition = player.transform.position + offset;
        Vector3 smoothPosition = Vector3.Lerp(transform.position, desirePosition, smoothSpeed);
        transform.position = new Vector3(smoothPosition.x, 20f, smoothPosition.z);
	}
}
