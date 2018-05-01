using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PausButton : MonoBehaviour {

    GameObject gameManager;
    
	
    public void callRestartGame()
    {
        gameManager = GameObject.FindGameObjectWithTag("GameManager");
        gameManager.GetComponent<GameManagerScript>().ReStartGame();
    }
}
