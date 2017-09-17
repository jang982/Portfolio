using UnityEngine.EventSystems;
using UnityEngine;

public class Option : MonoBehaviour, IPointerClickHandler
{
    GameObject option_panel;

    private void Start()
    {
        option_panel = GameObject.Find("Option_Panel");
        option_panel.SetActive(false);
    } 

    public void OnPointerClick(PointerEventData EventData)
    {
        option_panel.SetActive(true);
        Time.timeScale = 0;
    }
}
