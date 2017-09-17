using UnityEngine;

public class GameOverTouch : MonoBehaviour
{
    GameObject gameOver;
	// Use this for initialization
	void Start () {
        gameOver = GameObject.Find("GameOver");
	}
    void Update()
    {
        if ((Input.touchCount > 0 || Input.anyKeyDown) && gameOver.GetComponent<GameOver>().isGameOvered == true)
        {
            gameOver.GetComponent<GameOver>().isTouched = true;
        }
    } 
}
