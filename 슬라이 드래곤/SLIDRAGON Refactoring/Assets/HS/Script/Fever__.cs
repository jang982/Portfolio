using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Fever__ : MonoBehaviour {
    public float fever_count;
    public bool feverLocked;

    float MAX_FEVER_SCALE;
    float MIN_FEVER_SCALE;
    float MAX_FEVER;
    float MIN_FEVER;

    public AudioClip fever_start;

    // Use this for initialization
    void Start()
    {
        fever_count = 0;
        feverLocked = false;
        gameObject.GetComponent<Image>().fillAmount = 0;
        
        MIN_FEVER_SCALE = 0;
        MAX_FEVER_SCALE = 1.0f;
        MAX_FEVER = 30.0f;
        MIN_FEVER = 0;
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
    void FixedUpdate()
    {
        
        if (gameObject.GetComponent<Image>().fillAmount >= 0.99f)
        {
            //GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever = true;
            GameObject.Find("NoteManager").GetComponent<NoteManager>().SetFeverFlag(true);
            GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(fever_start);
        }

        if (GameObject.Find("NoteManager").GetComponent<NoteManager>().GetFeverFlag() == true && feverLocked == false)
            gameObject.GetComponent<Image>().fillAmount -= (1.0f / 200.0f);
            //transform.localScale = new Vector3(transform.localScale.x - MAX_FEVER_SCALE * (1.0f / 208.0f), transform.localScale.y, transform.localScale.z);

        if (GameObject.Find("NoteManager").GetComponent<NoteManager>().GetFeverFlag() == true && gameObject.GetComponent<Image>().fillAmount <= 0.01f)
            FeverEnd();
        
    }
    void FeverEnd()
    {
        fever_count = 0;
        gameObject.GetComponent<Image>().fillAmount = 0;
        //GameObject.Find("NoteManager").GetComponent<NoteManager>().isFever = false;
        GameObject.Find("NoteManager").GetComponent<NoteManager>().SetFeverFlag(false);
    }

    void SlideFail()
    {
        fever_count = 0;
        gameObject.GetComponent<Image>().fillAmount = MIN_FEVER_SCALE;
    }

    void SlideSuccess()
    {
        float delta_Scale = MAX_FEVER_SCALE * (1 / MAX_FEVER);
        if (fever_count < MAX_FEVER)
        {
            gameObject.GetComponent<Image>().fillAmount += delta_Scale;
            //transform.localScale = new Vector3(transform.localScale.x + delta_Scale, transform.localScale.y, transform.localScale.z);
        }
        fever_count++;
    }
}
