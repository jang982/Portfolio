using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class changecolor : MonoBehaviour {

    public Color a = new Vector4(0, 0, 0, 0);

	// Use this for initialization
	void Start () {
        gameObject.GetComponent<SpriteRenderer>().color = a;
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
