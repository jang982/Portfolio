using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour {
    private Animator animator;

    private void Start()
    {
        animator = GetComponent<Animator>();
    }


    //private void OnTriggerEnter(Collider other)
    //{
    //    if(!animator.GetBool("isOpened"))
    //    {
    //        animator.SetTrigger("DoorOpen");
    //        animator.SetBool("isOpened", true);
    //    }

    //}

    //private void OnTriggerExit(Collider other)
    //{
    //    if(animator.GetBool("isOpened"))
    //    {
    //        animator.SetTrigger("DoorClose");
    //        animator.SetBool("isOpened", false);
    //    }

    //}

    public void Open()
    {
        if (!animator.GetBool("isOpened"))
        {
            animator.SetTrigger("DoorOpen");
            animator.SetBool("isOpened", true);
        }
    }

    public void Close()
    {
        if (animator.GetBool("isOpened"))
        {
            animator.SetTrigger("DoorClose");
            animator.SetBool("isOpened", false);
        }
    }
}
