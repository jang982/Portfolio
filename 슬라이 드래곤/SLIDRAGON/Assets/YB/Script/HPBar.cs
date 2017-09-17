using UnityEngine;

public class HPBar : MonoBehaviour {
    int MaxHP; float MaxScale;
    int NowHP;
	void SetMaxHP(int h)
    {
        MaxHP = h; MaxScale = transform.localScale.x;
        SetHP(h);
    }
	
	void SetHP(int h)
    {
        NowHP = h;
        //Debug.Log(NowHP);
        transform.localScale = new Vector3(((float)NowHP / MaxHP) * MaxScale , transform.localScale.y, transform.localScale.z);
    }
}
