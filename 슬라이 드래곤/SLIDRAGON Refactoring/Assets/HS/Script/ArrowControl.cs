using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ArrowControl : MonoBehaviour {

    bool isSuccessed = false;

    Sprite current_note;

    Color gray_color = new Color(0.35f, 0.35f, 0.35f, 1.0f);
    Color original_color = new Color(1.0f, 1.0f, 1.0f, 1.0f);

    public Sprite s_up;
    public Sprite s_left;
    public Sprite s_down;
    public Sprite s_right;
    public Sprite locked_note;

    

    public void DestroyArrow()
    {
        Destroy(this.gameObject);
    }

    public void ChangeDAImage(string name)
    {
        switch (name) {
            case "DoubleUpArrow":
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_up;
                break;
            case "DoubleLeftArrow":
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_left;
                break;
            case "DoubleDownArrow":
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_down;
                break;
            case "DoubleRightArrow":
                this.gameObject.GetComponent<SpriteRenderer>().sprite = s_right;
                break;
        }

    }

    //각각의 위치로 크기와 위치 변환
    public void MoveForward(int i)
    {
        StartCoroutine(MoveLerp(i));
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

    //각 화살표의 위치.0이 제일멀고 3이 제일 가깝다.
    Vector3 ArrowPosition(int i)                                                                          
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

    //각 화살표의 위치.0이 제일멀고 3이 제일 가깝다.
    Vector3 ArrowScale(int i)                                                                          
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

    public void MarkAsSuccess()
    {
        isSuccessed = true;
    }

    public void MarkAsFail()
    {
        isSuccessed = false;
    }

    public bool GetIsSuccessedArrow()
    {
        return isSuccessed;
    }

    public void Locked (float LockTime)
    {
        current_note = this.GetComponent<SpriteRenderer>().sprite;
        gameObject.GetComponent<SpriteRenderer>().sprite = locked_note;
        Invoke("Unlocked", LockTime);
    }

    void MonsterLoadingLocked ()
    {
        current_note = this.GetComponent<SpriteRenderer>().sprite;
        gameObject.GetComponent<SpriteRenderer>().sprite = locked_note;
        Invoke("Unlocked", 0.5f);
    }

    void Unlocked()
    {
        gameObject.GetComponent<SpriteRenderer>().sprite = current_note;
    }
}
