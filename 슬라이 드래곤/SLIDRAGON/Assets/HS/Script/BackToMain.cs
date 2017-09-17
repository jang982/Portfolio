using UnityEngine.EventSystems;
using UnityEngine;

public class BackToMain : MonoBehaviour, IPointerClickHandler
{
    public void OnPointerClick(PointerEventData EventData)
    {
        Time.timeScale = 1.0f;
        Application.LoadLevel("Play");
    }
}
