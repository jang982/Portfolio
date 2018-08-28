using UnityEngine.EventSystems;
using UnityEngine;

public class NormalModeButton : MonoBehaviour, IPointerClickHandler
{
    public void OnPointerClick(PointerEventData EventData)
    {
        GameObject.Find("ModeSelector").SendMessage("NormalModeSelect");
    }
}
