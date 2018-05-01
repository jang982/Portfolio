using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QuestSpot : MonoBehaviour {

    bool isQuestCompleted;

    private void Awake()
    {
        isQuestCompleted = false;
    }


    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
            isQuestCompleted = true;
    }

    public bool QuestCompleted()
    {
        return isQuestCompleted;
    }

}
