using UnityEngine;
public class StageBGScroll : MonoBehaviour {
    public AnimationCurve StageMoveAnimation;
    public AnimationCurve NormalMoveAnimation;
    public float StageMoveAnimationLength;
    public float NormalMoveAnimationLength;
    public Sprite[] BackgroundImages;
    float StartTime = 0.0f;
    int MoveType = 0;
	
    void NormalMove()
    {
        MoveType = 1;
        StartTime = Time.time;
    }
    void StageMove()
    {
        MoveType = 2;
        StartTime = Time.time;
    }

    void Update () {
		if(MoveType == 1)
        {
            transform.Translate(new Vector3(-NormalMoveAnimation.Evaluate(Time.time - StartTime) * Time.deltaTime, 0f, 0f), Space.World);
            if (NormalMoveAnimationLength < Time.time - StartTime) MoveType = 0;
        }
        else if (MoveType == 2)
        {
            transform.Translate(new Vector3(-StageMoveAnimation.Evaluate(Time.time - StartTime) * Time.deltaTime, 0f, 0f), Space.World);
            if (StageMoveAnimationLength < Time.time - StartTime) MoveType = 0;
        }
    }

    void ImageChange()
    {
        int i = Random.Range(0, BackgroundImages.Length);
        GetComponent<SpriteRenderer>().sprite = BackgroundImages[i];
    }
}
