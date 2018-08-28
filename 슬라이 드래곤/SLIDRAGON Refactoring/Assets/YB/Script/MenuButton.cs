using UnityEngine.EventSystems;
using UnityEngine;

public class MenuButton : MonoBehaviour, IPointerClickHandler {

	public void OnPointerClick(PointerEventData EventData)
    {
        GameObject.Find("ModeSelector").SendMessage("MenuSelect");
    }
}
