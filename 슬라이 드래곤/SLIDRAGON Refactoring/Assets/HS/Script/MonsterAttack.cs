using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterAttack : MonoBehaviour {
    bool IsDying = false;
    Vector2 TouchPos;
    Vector2 ClickPos;
    public AudioClip missile_destroy;


    /*public void Fire()
    {
        Debug.Log("Fire");
        StartCoroutine(MissileMove());
    }

    //미사일 이동
    IEnumerator MissileMove()
    {
        Vector3 NewPos = GameObject.Find("MissileEraser").GetComponent<Transform>().position;
        NewPos.y = this.transform.position.y;
        while (this.transform.position.x - NewPos.x > 0.1f)
        {
            this.transform.position = Vector3.MoveTowards(this.transform.position, NewPos, Time.deltaTime * 3);  //화살표위치로 이동
            yield return new WaitForEndOfFrame();                                                         //중단점.중지되면 여기서부터 다시 시작됨
        }
    }*/

    void Update()
    {
        //터치용
        if (Input.touchCount > 0 )
        {
            TouchPos = Camera.main.ScreenToWorldPoint(Input.GetTouch(0).position);
            if (this.GetComponent<Collider2D>() == Physics2D.OverlapPoint(TouchPos))
            {
                DestroyMissile();
                GameObject.Find("Player").GetComponent<PlayerScript>().Destroy_Missile();
            }
        }
        //마우스용
        if (Input.GetMouseButtonDown(0))
        {
            ClickPos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            if (this.GetComponent<Collider2D>() == Physics2D.OverlapPoint(ClickPos))
            {
                DestroyMissile();
                GameObject.Find("Player").GetComponent<PlayerScript>().Destroy_Missile();
            }
        }

    }


    //플레이어와 충돌판정
    void OnTriggerEnter2D(Collider2D other)
    {
        if (IsDying) return;
        if (other.gameObject.tag == "Player")
        {
            IsDying = true;
            //Debug.Log("Player Hit");
            GameObject.Find("Timer_Gauge").SendMessage("SlideFail");
            GetComponent<Animator>().SetTrigger("Explode");
            Destroy(this.gameObject, 0.7f);
        }
        else
        {
            GetComponent<Animator>().SetTrigger("Explode");
            Destroy(this.gameObject,0.7f);
        }
    }

    //클릭,터치판정
    //private void OnMouseDown()
    //{
    //    if (IsDying) return;
    //    IsDying = true;
    //    GetComponent<Animator>().SetTrigger("Explode");
    //    GameObject.Find("Player").SendMessage("RandomAttackAnimation");
    //    Destroy(this.gameObject, 0.7f);
    //}
    
    private void DestroyMissile()
    {
        if (IsDying) return;
        IsDying = true;
        GetComponent<Animator>().SetTrigger("Explode");
        GameObject.Find("Player").SendMessage("RandomAttackAnimation");
        Destroy(this.gameObject, 0.7f);
    }
}
