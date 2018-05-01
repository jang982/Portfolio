using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MarksControl : MonoBehaviour {

    public SpriteRenderer Detect;
    public SpriteRenderer Miss;


    GameObject parent;
    
    private void Start()
    {
        Detect.enabled = false;
        Miss.enabled = false;
        parent = this.transform.root.gameObject;
    }


    // 마크가 항상 위쪽에 위치하도록 합니다.
    void Update () {
        this.transform.localEulerAngles = -parent.transform.eulerAngles;
        this.transform.position = new Vector3(parent.transform.position.x, 0, parent.transform.position.z + 1.6f);
	}

    void DetectEnable()
    {
        Detect.enabled = true;
    }

    void MissEnable()
    {
        Miss.enabled = true;
    }

    void DetectDisable()
    {
        Detect.enabled = false;
    }

    void MissDisable()
    {
        Miss.enabled = false;
    }
}
