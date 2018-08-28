using UnityEngine;
using UnityEngine.UI;

public class ColorChangeScript : MonoBehaviour {
    public Color[] ColorPalettes;
    public Material[] ChangeMaterials;
    public Text[] UITexts;

    void ColorChange(int index)
    {
        index--;
        for (int i = 0; i < ChangeMaterials.Length; i++)
        {
            ChangeMaterials[i].SetColor("_Color1", ColorPalettes[index * 3]);
            ChangeMaterials[i].SetColor("_Color2", ColorPalettes[index * 3 + 1]);
            ChangeMaterials[i].SetColor("_Color3", ColorPalettes[index * 3 + 2]);
        }
        for (int i = 0; i < UITexts.Length; i++)
        {
            UITexts[i].color = ColorPalettes[index * 3 + 2];
        }
        Camera.main.backgroundColor = ColorPalettes[index * 3];
    }
}
