using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour {
    GameObject EnteredObject;
    GameObject Player;
    GameObject EquipSpot;
    GameObject test;

    float dmg;
    float stunPercentage;

    bool isPlayerEntered;

	// Use this for initialization
	void Start () {
        EnteredObject = null;
        Player = GameObject.FindGameObjectWithTag("Player");
        EquipSpot = GameObject.Find("Melee_spot");
        test = Player.transform.Find("Root_jnt").gameObject;

        loadWholeStatus(this.name);
        
	}

    void loadWholeStatus(string itemName)
    {
        //케릭터의 이름에따라 스텟을 불러옵니다.
        switch (itemName)
        {
            case "Cane":
                dmg = 5f;
                stunPercentage = 10f;

                break;

            case "FryPan":
                dmg = 10f;
                stunPercentage = 20f;

                break;

            case "Plunger":
                dmg = 5f;
                stunPercentage = 15f;

                break;

            case "Bat":
                dmg = 15f;
                stunPercentage = 10f;

                break;
        }
    }

    //아이템을 집을떄 위치를 이동시켜줍니다.
    void ItemPickUp()
    {

        //플레이어가 아이템의 콜리전에 들어왔을때 실행가능합니다
        if(isPlayerEntered)
        {
            if(EnteredObject==Player)
                this.gameObject.tag = "PlayerWeapon";

            //콜라이더와 강체옵션을 조정합니다
            this.GetComponent<MeshCollider>().enabled = false;
            this.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.FreezeAll;
            //this.GetComponent<Rigidbody>().isKinematic = true;

            //스텟추가
            Player.GetComponent<CharacterStatus>().itemDMG = dmg;
            Player.GetComponent<CharacterStatus>().itemStun = stunPercentage;

            //부모를 집은 케릭터의 장착부위로 변경합니다
            this.transform.SetParent(EquipSpot.transform);
            this.transform.localPosition = Vector3.zero;

            //지팡이의 경우 세부위치조절
            //if (this.name == "Cane")
            //    this.transform.Translate(0.12f, 0, 0);
            Reposition(this.name);

            //transform.rotation = new Quaternion(0, 0, 0, 0);

            Debug.Log(this.transform.parent);

            isPlayerEntered = false;
        }

    }

    void Reposition(string name)
    {
        switch (name)
        {
            case "Cane":
                this.transform.Translate(0.12f, 0, 0);
                transform.rotation = new Quaternion(0, 0, 0, 0);
                break;

            case "FryPan":
                transform.localEulerAngles=new Vector3(-90f, 180f, 0);
                //transform.localRotation = new Quaternion(90f,180f,0,0);
                this.transform.Translate(0, 0, 0.5f);


                break;

            case "Plunger":
                transform.localEulerAngles = new Vector3(-90f, 180f, 0);
                //transform.localRotation = new Quaternion(90f,180f,0,0);
                this.transform.Translate(0, 0, 0.5f);


                break;

            case "Bat":
                transform.localEulerAngles = new Vector3(-90f, 180f, 0);
                //transform.localRotation = new Quaternion(90f,180f,0,0);
                this.transform.Translate(0, 0, 0.5f);

                break;
        }
    }



    //아이템을 드랍하는 부분입니다.
    void ItemUnequip()
    {
        this.gameObject.tag = "GroundedItem";

        this.GetComponent<MeshCollider>().enabled = true;
        this.GetComponent<Rigidbody>().constraints = RigidbodyConstraints.None;
        //this.GetComponent<Rigidbody>().isKinematic = false;

        Player.GetComponent<CharacterStatus>().itemDMG = 0f;
        Player.GetComponent<CharacterStatus>().itemStun = 0f;

        transform.SetParent(null);
        
    }

    //아이템에 일정범위의 콜리전 부분입니다.
    private void OnTriggerEnter(Collider other)
    {
        EnteredObject = other.gameObject;
        //Debug.Log("something in");
        if (other.gameObject == Player)
        {
            Player.GetComponent<PlayerController>().setNearbyItem(this.gameObject);
            isPlayerEntered = true;
        }

    }

    //아이템의 범위 밖에 나갔을때
    private void OnTriggerExit(Collider other)
    {
        //들어왔던 오브젝트를 null로 바꿉니다
        EnteredObject = null;

        if (other.gameObject == Player)
        {
            //케릭터에 있는 주위에 있는 아이템을 표시하는 부분을 null로 바꿉니다.
            Player.GetComponent<PlayerController>().setNearbyItem(null);
            isPlayerEntered = false;
        }
    }

    public float getItemDmg()
    {
        return dmg;
    }

    public float getItemStunPercentage()
    {
        return stunPercentage;
    }
    
}
