using UnityEngine.UI;
using UnityEngine;
using UnityEngine.EventSystems;

public class SE_Check : MonoBehaviour, IPointerClickHandler
{
    public Sprite check;
    public Sprite uncheck;
    GameObject SoundManager;

    void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }

    private void Start()
    {
        SoundManager = GameObject.Find("SoundManager");
        if(SoundManager.GetComponent<SoundManager>().SE_state == true)
            gameObject.GetComponent<Image>().sprite = check;
        else
            gameObject.GetComponent<Image>().sprite = uncheck;
    }

    public void OnPointerClick (PointerEventData EventData)
    {
        if (SoundManager.GetComponent<SoundManager>().SE_state == true)
        {
            SoundManager.GetComponent<SoundManager>().SE_state = false;
            gameObject.GetComponent<Image>().sprite = uncheck;
        }
        else if (SoundManager.GetComponent<SoundManager>().SE_state == false)
        {
            SoundManager.GetComponent<SoundManager>().SE_state = true;
            gameObject.GetComponent<Image>().sprite = check;
        }
    }
}
