using UnityEngine.UI;
using UnityEngine;
using UnityEngine.EventSystems;

public class BGM_Check : MonoBehaviour, IPointerClickHandler
{
    public Sprite check;
    public Sprite uncheck;

    public AudioClip BGM;

    GameObject SoundManager;

    void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }

    private void Start()
    {
        SoundManager = GameObject.Find("SoundManager");
        if (SoundManager.GetComponent<SoundManager>().BGM_state == true)
            gameObject.GetComponent<Image>().sprite = check;
        else
            gameObject.GetComponent<Image>().sprite = uncheck;
    }

    public void OnPointerClick(PointerEventData EventData)
    {
        if (SoundManager.GetComponent<SoundManager>().BGM_state == true)
        {
            SoundManager.GetComponent<SoundManager>().BGM_state = false;
            gameObject.GetComponent<Image>().sprite = uncheck;
            SoundManager.GetComponent<SoundManager>().StopBGM();
        }
        else if (SoundManager.GetComponent<SoundManager>().BGM_state == false)
        {
            SoundManager.GetComponent<SoundManager>().BGM_state = true;
            gameObject.GetComponent<Image>().sprite = check;
            SoundManager.GetComponent<SoundManager>().PlayBGM(BGM);
        }
    }
}
