using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManagerScript : MonoBehaviour {

    public AudioClip MainBGM;
    public AudioClip[] BGM;
    public AudioClip whipSound;

    static public GameManagerScript instance;

    bool missionFail;
    //public string peopleState;
    bool questComplete;
    bool isDetected;
    bool isPause;
    int scenloaded;
    int currentLevel;
    int rewardStat;

    GameObject rewardCanvas;
    GameObject mainCanvas;
    GameObject pauseCanvas;

    GameObject mainImage;
    GameObject mainButtons;
    GameObject mainCamera;
    GameObject mainSanta;
    GameObject santaSleigh;
    GameObject[] elfs;
    GameObject[] peoples;
    PeopleAI[] peopleAIs;

    GameObject soundManager;
    GameObject questSpot;
    GameObject exitSpot;
    GameObject player;
    


	// Use this for initialization
	void Start () {

        if(instance!=null)
        {
            Destroy(this.gameObject);
            instance.initializeSetting();
            return;
        }

        instance = this;


        if(SceneManager.GetActiveScene().buildIndex == 0)
        {
            mainCamera = GameObject.FindGameObjectWithTag("MainCamera");
            santaSleigh = GameObject.FindGameObjectWithTag("SantaSleigh");
            elfs = GameObject.FindGameObjectsWithTag("Elf");
            mainSanta = GameObject.FindGameObjectWithTag("MainSanta");
            mainCanvas= GameObject.FindGameObjectWithTag("MainCanvas");
            rewardCanvas=GameObject.FindGameObjectWithTag("RewardCanvas");
            pauseCanvas= GameObject.FindGameObjectWithTag("PauseCanvas");

            mainCanvas.SetActive(true);
            rewardCanvas.SetActive(false);
            pauseCanvas.SetActive(false);

            mainCanvas.GetComponent<CanvasGroup>().alpha = 0;
            mainCanvas.GetComponent<CanvasGroup>().interactable = false;
            mainCanvas.GetComponent<CanvasFader>().CallFadeIn();

            missionFail = false;
            isDetected = false;
            isPause = false;
            rewardStat = 0;

            currentLevel = SceneManager.GetActiveScene().buildIndex;

            soundManager = GameObject.FindGameObjectWithTag("SoundManager");
            BGMStart();

            DontDestroyOnLoad(this.gameObject);
        }
        else
        {
            Debug.Log("로딩레벨" + currentLevel);

            questSpot = GameObject.FindGameObjectWithTag("QuestSpot");
            exitSpot = GameObject.FindGameObjectWithTag("ExitSpot");
            player = GameObject.FindGameObjectWithTag("Player");
            peoples = GameObject.FindGameObjectsWithTag("People");

            mainCanvas.SetActive(false);
            rewardCanvas.SetActive(false);

            questSpot.SetActive(true);
            exitSpot.SetActive(false);
            questComplete = false;
            currentLevel = SceneManager.GetActiveScene().buildIndex;

            missionFail = false;
            isDetected = false;
            rewardStat = 0;

            soundManager = GameObject.FindGameObjectWithTag("SoundManager");
            BGMStart();

            DontDestroyOnLoad(this.gameObject);
        }


    }

    private void Update()
    {
        //메인이나 리워드화면일때는 업데이트를 수행하지 않습니다.
        if (SceneManager.GetActiveScene().buildIndex == 0 || SceneManager.GetActiveScene().buildIndex==1)
            return;

        if (questSpot.GetComponent<QuestSpot>().QuestCompleted())
        {
            questComplete = true;

            questSpot.SetActive(false);
            exitSpot.SetActive(true);
        }


        bool isMissing = true;
        for (int i = 0; i < peoples.Length; i++)
        {
            isMissing &= peoples[i].GetComponent<PeopleAI>().missing;
        }


        //플레이어 탐지상태에따라 탈출과 퀘스트마크 온오프


        //Debug.Log(peopleState);
        //if (peopleState=="Attacking" || peopleState=="Chasing")
        if(!isMissing)
        {
            //if (questSpot.GetComponent<QuestSpot>().QuestCompleted())
            //    exitSpot.SetActive(false);

            //else
            //    questSpot.SetActive(false);
            isDetected = true;
            questSpot.SetActive(false);
            exitSpot.SetActive(false);
        }
        else
        {
            if (questSpot.GetComponent<QuestSpot>().QuestCompleted() || missionFail)
            {
                questSpot.SetActive(false);
                exitSpot.SetActive(true);
            }
            else
            {
                questSpot.SetActive(true);
                exitSpot.SetActive(false);
            }

        }


        //일시정지
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            if(!isPause)
            {
                pauseCanvas.SetActive(true);
                soundManager.GetComponent<AudioListener>().enabled = false;
                //Time.timeScale = 0;
                isPause = true;
            }
            else
            {
                pauseCanvas.SetActive(false);
                soundManager.GetComponent<AudioListener>().enabled = true;
                //Time.timeScale = 1;
                isPause = false;
            }
        }




        //클리어
        if(exitSpot.GetComponent<ExitSpot>().IsPlayerIn())
        {
            LoadRewardScene();
            //LoadNextScene();
        }

    }

    void initializeSetting()
    {



        Debug.Log("로딩" + SceneManager.GetActiveScene().name);
        Debug.Log("로딩" + SceneManager.GetActiveScene().buildIndex);

        //메인화면 로딩
        if (SceneManager.GetActiveScene().name == "Main")
        {
            //santaSleigh = GameObject.FindGameObjectWithTag("SantaSleigh");
            //elfs = GameObject.FindGameObjectsWithTag("Elfs");

            mainCamera = GameObject.FindGameObjectWithTag("MainCamera");
            santaSleigh = GameObject.FindGameObjectWithTag("SantaSleigh");
            elfs = GameObject.FindGameObjectsWithTag("Elf");
            mainSanta = GameObject.FindGameObjectWithTag("MainSanta");

            mainCanvas.SetActive(true);
            rewardCanvas.SetActive(false);
            pauseCanvas.SetActive(false);

            mainCanvas.GetComponent<CanvasGroup>().alpha = 0;
            mainCanvas.GetComponent<CanvasGroup>().interactable = false;
            mainCanvas.GetComponent<CanvasFader>().CallFadeIn();

            rewardStat = 0;
            isDetected = false;

            currentLevel = SceneManager.GetActiveScene().buildIndex;

            soundManager = GameObject.FindGameObjectWithTag("SoundManager");
            BGMStart();

        }
        else if(SceneManager.GetActiveScene().buildIndex == 1)
        {
            mainCamera = GameObject.FindGameObjectWithTag("MainCamera");
            santaSleigh = GameObject.FindGameObjectWithTag("SantaSleigh");
            elfs = GameObject.FindGameObjectsWithTag("Elf");
            mainSanta = GameObject.FindGameObjectWithTag("MainSanta");

            mainCanvas.SetActive(false);
            rewardCanvas.SetActive(true);
            pauseCanvas.SetActive(false);

            rewardCanvas.GetComponent<CanvasGroup>().alpha = 0;
            rewardCanvas.GetComponent<CanvasGroup>().interactable = false;
            rewardCanvas.GetComponent<CanvasFader>().CallFadeIn();

            Debug.Log("초기화");
            GetComponent<AdditionalStatus>().initializeRewardStats();

            soundManager = GameObject.FindGameObjectWithTag("SoundManager");
            BGMStart();
        }
        else
        {
            questSpot = GameObject.FindGameObjectWithTag("QuestSpot");
            exitSpot = GameObject.FindGameObjectWithTag("ExitSpot");
            player = GameObject.FindGameObjectWithTag("Player");
            peoples = GameObject.FindGameObjectsWithTag("People");

            //스텟로딩
            player.GetComponent<CharacterStatus>().initializeStatus();

            for(int i=0;i<peoples.Length;i++)
            {
                peoples[i].GetComponent<CharacterStatus>().initializeStatus();
            }

            mainCanvas.SetActive(false);
            rewardCanvas.SetActive(false);
            pauseCanvas.SetActive(false);

            this.GetComponent<LastPlayerSighted>().ResetPosition();

            questSpot.SetActive(true);
            exitSpot.SetActive(false);
            questComplete = false;
            isDetected = false;
            rewardStat = 0;

            currentLevel = SceneManager.GetActiveScene().buildIndex;

            //peopleState = "Patrolling";

            soundManager = GameObject.FindGameObjectWithTag("SoundManager");
            BGMStart();
        }



    }
    

    public void GameStart()
    {
        for(int i=0;i<elfs.Length;i++)
        {
            elfs[i].GetComponent<Animator>().SetTrigger("GameStart");
        }

        santaSleigh.GetComponent<Animator>().SetTrigger("GameStart");
        mainCamera.GetComponent<Animator>().SetTrigger("GameStart");
        mainSanta.GetComponent<Animator>().SetTrigger("GameStart");

        mainCanvas.GetComponent<CanvasFader>().CallFadeOut();

        soundManager.GetComponent<SoundListenser>().AttackSFX.clip = whipSound;
        soundManager.GetComponent<SoundListenser>().AttackSFX.pitch = 0.55f;
        soundManager.GetComponent<SoundListenser>().AttackSFX.Play();

        Invoke("initialGameStart", 5.0f);
    }

    void BGMStart()
    {
        if(SceneManager.GetActiveScene().name =="Main")
        {
            soundManager.GetComponent<SoundListenser>().BGM.volume = 1f;
            soundManager.GetComponent<SoundListenser>().playBGM(MainBGM);
        }

        else
        {
            soundManager.GetComponent<SoundListenser>().BGM.volume = 0.1f;
            soundManager.GetComponent<SoundListenser>().playBGM(BGM[Random.Range(0, BGM.Length)]);
        }

        
    }

    public void MissionFail()
    {
        missionFail = true;
    }

    public int calRewardStat()
    {
        if(questComplete)
        {
            if (!isDetected)
                rewardStat = 2;
            else
                rewardStat = 1;
        }
        else
        {
            rewardStat = 0;
        }

        return rewardStat;
    }

    public int getRewardStat()
    {
        return rewardStat;
    }

    public void CallGameOver()
    {
        Invoke("GameOver",3f);
    }

    public bool getIsPause()
    {
        return isPause;
    }

    void GameOver()
    {
        scenloaded++;
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    void LoadRewardScene()
    {
        soundManager.GetComponent<SoundListenser>().AttackSFX.pitch = 1f;
        Debug.Log("퀘스트" + questComplete);
        calRewardStat();

        Debug.Log("보상 " + rewardStat);
        //Debug.Log("초기화");
        SceneManager.LoadScene(1);
        //initializeSetting();
        GetComponent<AdditionalStatus>().initializeRewardStats();
    }

    public void LoadNextScene()
    {
        Debug.Log("지금레벨" + currentLevel);
        //피치 원래대로
        soundManager.GetComponent<SoundListenser>().AttackSFX.pitch = 1f;
        currentLevel++;
        SceneManager.LoadScene(currentLevel);
        //initializeSetting();
    }

    public void initialGameStart()
    {
        Debug.Log("지금레벨" + currentLevel);
        //피치 원래대로
        soundManager.GetComponent<SoundListenser>().AttackSFX.pitch = 1f;
        SceneManager.LoadScene(2);
        currentLevel = 2;
        //initializeSetting();
    }

    public void BackToMain()
    {

        Debug.Log("메인으로");
        //피치 원래대로
        Time.timeScale = 1f;
        soundManager.GetComponent<SoundListenser>().AttackSFX.pitch = 1f;
        SceneManager.LoadScene(0);
        //initializeSetting();
    }

    public void ExitGame()
    {
        Application.Quit();
    }
}
