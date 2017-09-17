using System.Collections;
using UnityEngine;

public class ModeSelector : MonoBehaviour {
    public ColorChangeScript ColorChanger;
    public GameObject[] MenuObjects;
    public GameObject[] ModeSelectObjects;
    public GameObject[] NormalModeObjects;
    public GameObject[] InfiniteModeObjects;
    public GameObject[] CommonGameObjects;
    public enum Phase { Menu, ModeSelect, NormalMode, InfiniteMode };
    public Phase phase = Phase.Menu;
    public GameObject SoundManager;

    GameObject NowStageManager;
    void Start()
    {
        ColorChanger.SendMessage("ColorChange", 1);
        MenuSelect();
    }

    public GameObject GetStageManager()
    {
        return NowStageManager;
    }

    void MenuSelect()
    {
        for (int i = 0; i < ModeSelectObjects.Length; i++)
            ModeSelectObjects[i].SetActive(false);
        for (int i = 0; i < MenuObjects.Length; i++)
            MenuObjects[i].SetActive(true);
        phase = Phase.Menu;
    }
    void ModeSelect()
    {
        for (int i = 0; i < MenuObjects.Length; i++)
            MenuObjects[i].SetActive(false);
        for (int i = 0; i < NormalModeObjects.Length; i++)
            NormalModeObjects[i].SetActive(false);
        for (int i = 0; i < InfiniteModeObjects.Length; i++)
            InfiniteModeObjects[i].SetActive(false);
        for (int i = 0; i < CommonGameObjects.Length; i++)
            CommonGameObjects[i].SetActive(false);
        for (int i = 0; i < ModeSelectObjects.Length; i++)
            ModeSelectObjects[i].SetActive(true);
        phase = Phase.ModeSelect;
    }
    void NormalModeSelect()
    {
        for (int i = 0; i < ModeSelectObjects.Length; i++)
            ModeSelectObjects[i].SetActive(false);
        for (int i = 0; i < MenuObjects.Length; i++)
            MenuObjects[i].SetActive(false);
        for (int i = 0; i < InfiniteModeObjects.Length; i++)
            InfiniteModeObjects[i].SetActive(false);
        for (int i = 0; i < NormalModeObjects.Length; i++)
            NormalModeObjects[i].SetActive(true);
        for (int i = 0; i < CommonGameObjects.Length; i++)
            CommonGameObjects[i].SetActive(true);
        NowStageManager = GameObject.Find("NormalStageManager");
        phase = Phase.NormalMode;
    }
    void InfiniteModeSelect()
    {
        for (int i = 0; i < ModeSelectObjects.Length; i++)
            ModeSelectObjects[i].SetActive(false);
        for (int i = 0; i < MenuObjects.Length; i++)
            MenuObjects[i].SetActive(false);
        for (int i = 0; i < NormalModeObjects.Length; i++)
            NormalModeObjects[i].SetActive(false);
        for (int i = 0; i < InfiniteModeObjects.Length; i++)
            InfiniteModeObjects[i].SetActive(true);
        for (int i = 0; i < CommonGameObjects.Length; i++)
            CommonGameObjects[i].SetActive(true);
        NowStageManager = GameObject.Find("InfiniteStageManager");
        phase = Phase.InfiniteMode;
    }
}
