using UnityEngine.EventSystems;
using UnityEngine;

public class BackToMain : MonoBehaviour, IPointerClickHandler
{
    public AudioClip click_sound;

    public void OnPointerClick(PointerEventData EventData)
    {
        GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(click_sound);
        Time.timeScale = 1.0f;
        Application.LoadLevel("Play");
    }
}
