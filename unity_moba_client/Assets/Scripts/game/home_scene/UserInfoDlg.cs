﻿using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UserInfoDlg : MonoBehaviour
{
    public InputField unickEdit;
    public GameObject guestUpgrade;
    public Image avatorImg;
    public Sprite[] avatorSprites;
    public GameObject femaleCheck;
    public GameObject maleCheck;
    public GameObject faceDlg;
    

    private int _uSex = 0;
    private int _uFace = 1;
    
    private void Start()
    {
        //是否显示账号升级按钮。如果是游客显示。
        if (UGame.Instance.isGuest)
        {
            this.guestUpgrade.SetActive(true);
        }
        else
        {
            this.guestUpgrade.SetActive(false);
        }

        if (UGame.Instance.uNick!=null)
        {
            this.unickEdit.text = UGame.Instance.uNick;
        }

        if (UGame.Instance.uFace>=1&&UGame.Instance.uFace<=9)
        {
            this._uFace = UGame.Instance.uFace;
        }
        this.avatorImg.sprite = this.avatorSprites[this._uFace - 1];
        
        if (UGame.Instance.uSex==0||UGame.Instance.uSex==1)
        {
            this._uSex = UGame.Instance.uSex;
        }

        if (this._uSex==0)
        {//man
            this.maleCheck.SetActive(true);
            this.femaleCheck.SetActive(false);
        }
        else
        {//woman
            this.maleCheck.SetActive(false);
            this.femaleCheck.SetActive(true);
        }
    }


    public void OnSexChange(int usex)
    {
        this._uSex = usex;
        if (this._uSex==0)
        {//man
            this.maleCheck.SetActive(true);
            this.femaleCheck.SetActive(false);
        }
        else
        {//woman
            this.maleCheck.SetActive(false);
            this.femaleCheck.SetActive(true);
        }
    }

    public void OnAvatorClick()
    {
        this.faceDlg.SetActive(true);
    }

    public void OnFaceSelectClose()
    {
        this.faceDlg.SetActive(false);
    }

    public void OnFaceSelectClick(int uface)
    {
        this._uFace = uface;
        this.avatorImg.sprite = this.avatorSprites[this._uFace - 1];
        this.faceDlg.SetActive(false);
    }

    public void OnCloseUInfoDlgClick()
    {
        //this.gameObject.SetActive(false);
        GameObject.Destroy(this.gameObject);
    }

    public void OnEditProfileCommit()
    {
        //unick,usex,uface
        if (this.unickEdit.text.Length<=0)
        {
            OnCloseUInfoDlgClick();
            return;
        }
        //提交修改资料请求到服务器
        UserLogin.Instance.EditProfile(this.unickEdit.text,this
        ._uFace,this._uSex);
    }

}