using UnityEngine.EventSystems;
using UnityEngine;

public class BackToGame : MonoBehaviour, IPointerClickHandler
{
    GameObject option_panel;

    private void Start()
    {
        option_panel = GameObject.Find("Option_Panel");
    }

    public void OnPointerClick(PointerEventData EventData)
    {
        option_panel.SetActive(false);
        Time.timeScale = 1.0f;
    }
}
