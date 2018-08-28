using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ArrowControl : MonoBehaviour {

    public bool IsSuccessed = false;

    public Sprite s_up;
    public Sprite s_left;
    public Sprite s_down;
    public Sprite s_right;

    Color gray_color = new Color(0.35f, 0.35f, 0.35f, 1.0f);
    Color original_color = new Color(1.0f, 1.0f, 1.0f, 1.0f);
    //스프라이트 로딩
    void Start()
    {
        
    }
    

    public void DestroyArrow()
    {
        Destroy(this.gameObject);
    }

    public void ChangeDAImage(string name)
    {
        Debug.Log(name);
        switch (name) {
            case "DoubleUpArrow":
                //spr = (Sprite)Resources.Load("note_up",typeof(Sprite));
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_up;
                break;
            case "DoubleLeftArrow":
                //spr = (Sprite)Resources.Load("note_left", typeof(Sprite));
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_left;
                break;
            case "DoubleDownArrow":
                //spr = (Sprite)Resources.Load("note_down", typeof(Sprite));
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_down;
                break;
            case "DoubleRightArrow":
                //spr = (Sprite)Resources.Load("note_right", typeof(Sprite));
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_right;
                break;
        }

    }

    public void MoveForward(int i)
    {
        //Debug.Log("Sended");
        StartCoroutine(MoveLerp(i));//코루틴
        StartCoroutine(ScaleLerp(i));
    }

   
    IEnumerator MoveLerp(int i)
    {
        Vector3 NewPos = ArrowPosition(i);                                                                  //화살표 위치 받기
        while (this.transform.position.z - NewPos.z>0.1f)
        {
            this.transform.position = Vector3.Lerp(this.transform.position, NewPos, Time.deltaTime * 15);  //화살표위치로 이동
            yield return new WaitForFixedUpdate();                                                         //중단점.중지되면 여기서부터 다시 시작됨
        }

    }
    IEnumerator ScaleLerp(int i)
    {
        Vector3 NewSize = ArrowScale(i);
        while (NewSize.x - this.transform.localScale.x > 0.01f)
        {
            Vector3 objectScale = Vector3.Scale(this.transform.localScale, new Vector3(1.1f, 1.1f, 1f));
            this.transform.localScale = objectScale; 
            yield return new WaitForFixedUpdate();                                                         //중단점.중지되면 여기서부터 다시 시작됨
        }

    }

    Vector3 ArrowPosition(int i)                                                                           //각 화살표의 위치.0이 제일멀고 3이 제일 가깝다.
    {
        Vector3 Pos = new Vector3(0,0,0);
        switch (i)
        {
            case 0:
                Vector3 Pos0 = new Vector3(0f, 0f, -1f);
                Pos = Pos0;
                break;
            case 1:
                Vector3 Pos1 = new Vector3(0f, -1f, -2f);
                Pos = Pos1;
                break;
            case 2:
                Vector3 Pos2 = new Vector3(0f, -2.2f, -3f);
                Pos = Pos2;
                break;
            case 3:
                Vector3 Pos3 = new Vector3(0f, -3.6f, -4f);
                Pos = Pos3;
                break;

        }
        return Pos;
    }

    Vector3 ArrowScale(int i)                                                                           //각 화살표의 위치.0이 제일멀고 3이 제일 가깝다.
    {
        Vector3 Size = new Vector3(0, 0, 0);
        switch (i)
        {
            case 0:
                Vector3 Size0 = new Vector3(2.2f, 2.2f, 0.1f);
                Size = Size0;
                break;
            case 1:
                Vector3 Size1 = new Vector3(2.8f, 2.8f, 0.1f);
                Size = Size1;
                break;
            case 2:
                Vector3 Size2 = new Vector3(3.4f, 3.4f, 0.1f);
                Size = Size2;
                break;
            case 3:
                Vector3 Size3 = new Vector3(4f, 4f, 0.1f);
                Size = Size3;
                break;

        }
        return Size;
    }

    void Locked ()
    {
        gameObject.GetComponent<SpriteRenderer>().color = gray_color;
        Invoke("Unlocked", 1.0f);
    }

    void MonsterLoadingLocked ()
    {
        gameObject.GetComponent<SpriteRenderer>().color = gray_color;
        Invoke("Unlocked", 0.5f);
    }

    void Unlocked()
    {
        gameObject.GetComponent<SpriteRenderer>().color = original_color;
    }
}
