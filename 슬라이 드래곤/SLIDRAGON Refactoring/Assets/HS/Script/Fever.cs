using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fever : MonoBehaviour {
    public float fever_count;
    public bool feverLocked;

    float MAX_FEVER_SCALE;
    float MIN_FEVER_SCALE;
    float MAX_FEVER;
    float MIN_FEVER;

    // Use this for initialization
    void Start () {
        fever_count = 0;
        feverLocked = false;

        MIN_FEVER_SCALE = 0;
        MAX_FEVER_SCALE = 1.0f;
        MAX_FEVER = 25.0f;
        MIN_FEVER = 0;

        transform.localScale = new Vector3(MAX_FEVER_SCALE * (MIN_FEVER / MAX_FEVER), transform.localScale.y, transform.localScale.z);
    }

    //피버 락거는거
    public void FeverHold(float LockTime)
    {
        feverLocked = true;
        Invoke("FeverRelease", LockTime);
    }
    void FeverRelease()
    {
        feverLocked = false;
    }

    // Update is called once per frame
    void FixedUpdate () {
        //Debug.Log("feverLocked : " + feverLocked);
        if (transform.localScale.x >= 0.99f)
        {
            //GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever = true;
            GameObject.Find("NoteManager").GetComponent<NoteManager>().SetFeverFlag(true);
        }
        
        if (GameObject.Find("NoteManager").GetComponent<NoteManager>().GetFeverFlag() == true && feverLocked == false)
            transform.localScale = new Vector3(transform.localScale.x - MAX_FEVER_SCALE * (1.0f/208.0f), transform.localScale.y, transform.localScale.z);

        if (GameObject.Find("NoteManager").GetComponent<NoteManager>().GetFeverFlag() == true && transform.localScale.x <= 0.01f )
            FeverEnd();

    }
    void FeverEnd()
    {
        fever_count = 0;
        transform.localScale = new Vector3(MAX_FEVER_SCALE * (MIN_FEVER / MAX_FEVER), transform.localScale.y, transform.localScale.z);
        //GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever = false;
        GameObject.Find("NoteManager").GetComponent<NoteManager>().SetFeverFlag(false);
    }

    void SlideFail()
    {
        fever_count = 0;
        transform.localScale = new Vector3(MIN_FEVER_SCALE, transform.localScale.y, transform.localScale.z);
    }

    void SlideSuccess()
    {
        float delta_Scale = MAX_FEVER_SCALE * (1 / MAX_FEVER);
        if(fever_count < 25.0f)
        {
            transform.localScale = new Vector3(transform.localScale.x + delta_Scale, transform.localScale.y, transform.localScale.z);
        }
        fever_count++;
    }
}
