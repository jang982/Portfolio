using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MainUIController : MonoBehaviour {

    public static MainUIController instance;

    // Use this for initialization
    void Start () {

        if (instance != null)
        {
            Destroy(this.gameObject);
            return;
        }

        instance = this;

        DontDestroyOnLoad(this);
	}
	
}
