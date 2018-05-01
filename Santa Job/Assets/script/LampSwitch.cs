using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LampSwitch : MonoBehaviour {

    GameObject player;
    GameObject EnteredObject;
    LampLight lampLight;
	// Use this for initialization
	void Start () {
        player = GameObject.FindGameObjectWithTag("Player");
        lampLight = GetComponentInChildren<LampLight>();
	}
	
    void SwithToggle()
    {
        if (lampLight.isLigthOn)
            lampLight.LampLightOff();
        else
            lampLight.LampLightOn();
    }
    

    private void OnTriggerEnter(Collider other)
    {
        EnteredObject = other.gameObject;
        Debug.Log("something in");
        if (other.gameObject == player)
        {
            player.GetComponent<PlayerController>().setNearBySwitch(this.gameObject);
            //isPlayerEntered = true;
        }

    }
    

    private void OnTriggerExit(Collider other)
    {
        //들어왔던 오브젝트를 null로 바꿉니다
        EnteredObject = null;

        if (other.gameObject == player)
        {
            //케릭터에 있는 주위에 있는 아이템을 표시하는 부분을 null로 바꿉니다.
            player.GetComponent<PlayerController>().setNearBySwitch(null);
            //isPlayerEntered = false;
        }
    }
}
