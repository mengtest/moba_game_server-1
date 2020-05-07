﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum TowerType
{
    Main=1,
    Normal=2,
}

public class Tower : MonoBehaviour
{
    protected int type;
    protected int side;//0:sideA  1:sideB

    protected TowerConfig config;
    
    /// <summary>
    /// 初始化塔属性
    /// </summary>
    /// <param name="side">0:sideA  1:sideB</param>
    /// <param name="type">TowerType</param>
    public virtual void Init(int side,int type)
    {
        this.side = side;
        this.type = type;
        switch (type)
        {
            case (int)TowerType.Normal:
                this.config = GameConfig.NormalTowerConfig;
                break;
            case (int)TowerType.Main:
                this.config = GameConfig.MainTowerConfig;
                break;
        }
    }

    public virtual void OnLogicUpdate(int deltaTime)
    {
        
    }
}