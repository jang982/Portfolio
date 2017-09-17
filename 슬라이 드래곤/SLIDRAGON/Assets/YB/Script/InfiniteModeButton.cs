﻿using UnityEngine.EventSystems;
using UnityEngine;
using UnityEngine.UI;

public class InfiniteModeButton : MonoBehaviour, IPointerClickHandler, IPointerDownHandler, IPointerExitHandler
{
    public Texture button_down;
    public Texture button_up;
    public AudioClip click_sound;

    public void OnPointerClick(PointerEventData EventData)
    {
        GameObject.Find("ModeSelector").SendMessage("InfiniteModeSelect");
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(click_sound);
    }

    public void OnPointerDown(PointerEventData EventData)
    {
        this.gameObject.GetComponent<RawImage>().texture = button_down;
    }

    public void OnPointerExit(PointerEventData EventData)
    {
        //Debug.Log("clicked");
        this.gameObject.GetComponent<RawImage>().texture = button_up;
    }
}
