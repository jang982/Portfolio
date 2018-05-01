using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Children : MonoBehaviour {

    public AudioSource cryingAuidoSource;
    public AudioClip cryingSound;

    Animator animator;
    GameObject player;
    GameObject gameManager;

	// Use this for initialization
	void Start () {
        animator = GetComponent<Animator>();
        player = GameObject.FindGameObjectWithTag("Player");
        gameManager = GameObject.FindGameObjectWithTag("GameManager");
	}

    private void OnTriggerStay(Collider other)
    {
        if(other.transform.root.tag=="Player")
        {

            //소리를 내면
            if (player.GetComponent<PlayerController>().isRunning() || player.GetComponent<PlayerController>().GetIsScreaming())
            {

                //일어나게함
                if (!animator.GetBool("WakeUp"))
                {
                    animator.SetBool("WakeUp", true);
                    Debug.Log("Evil:" + player.GetComponent<CharacterStatus>().getEvil());
                    if (Random.Range(1, 101f) <= player.GetComponent<CharacterStatus>().getEvil())
                    {
                        Debug.Log("실패");
                        gameManager.GetComponent<GameManagerScript>().MissionFail();
                        Invoke("Crying", 3f);
                    }

                }
                else
                    return;



            }
                
        }
    }

    void Crying()
    {
        if(!cryingAuidoSource.isPlaying)
        {
            cryingAuidoSource.loop = true;
            cryingAuidoSource.clip = cryingSound;
            cryingAuidoSource.Play();
        }

    }
}
