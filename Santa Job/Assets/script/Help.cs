using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Help : MonoBehaviour {

    public GameObject[] images;
    int index;

	// Use this for initialization
	void Start () {
        index = 0;
        for (int i = 0; i < images.Length; i++)
            images[i].SetActive(false);

        toggle(index);
	}
	
    void toggle(int j)
    {
        for (int i = 0; i < images.Length; i++)
        {
            if(i==j)
                images[i].SetActive(true);
            else
                images[i].SetActive(false);
        }

    }



    public void next()
    {
        if (index < images.Length-1)
        {
            index++;
            toggle(index);
        }
        else
        {
            index = 0;
            toggle(index);
        }
    }

    public void reset()
    {
        Debug.Log("리셋호출");
        index = 0;
        for (int i = 0; i < images.Length; i++)
            images[i].SetActive(false);
        toggle(index);
    }
}
