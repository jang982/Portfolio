using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CanvasFader : MonoBehaviour {

	public void CallFadeIn()
    {
        StartCoroutine(DoFadeIn());
    }

    public void CallFadeOut()
    {
        StartCoroutine(DoFadeOut());
    }

    IEnumerator DoFadeIn()
    {
        CanvasGroup canvasGroup = GetComponent<CanvasGroup>();
        while(canvasGroup.alpha!=1)
        {
            canvasGroup.alpha += Time.deltaTime / 2;
            yield return null;
        }
        canvasGroup.interactable = true;
        yield return null;
    }

    IEnumerator DoFadeOut()
    {
        CanvasGroup canvasGroup = GetComponent<CanvasGroup>();
        canvasGroup.interactable = false;
        while (canvasGroup.alpha != 0)
        {
            canvasGroup.alpha -= Time.deltaTime / 2;
            yield return null;
        }
        
        yield return null;
    }
}
