using UnityEngine.EventSystems;
using UnityEngine;

public class Option : MonoBehaviour, IPointerClickHandler
{
    GameObject option_panel;
    public AudioClip click_sound;

    bool is_active;

    private void Start()
    {
        is_active = false;
        option_panel = GameObject.Find("Option_Panel");
        option_panel.SetActive(false);
    } 

    public void OnPointerClick(PointerEventData EventData)
    {
        if (!is_active)
        {
            GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(click_sound);
            option_panel.SetActive(true);
            is_active = !is_active;
            Time.timeScale = 0f;
        }
        else
        {
            GameObject.Find("SoundManager").GetComponent<SoundManager>().PlaySingle(click_sound);
            option_panel.SetActive(false);
            is_active = !is_active;
            Time.timeScale = 1.0f;
        }
    }
}
