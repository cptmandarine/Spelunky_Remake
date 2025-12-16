#pragma once

class CBaseLevel abstract 
{
public:
    CBaseLevel() = default;
    virtual ~CBaseLevel() = default;

public:
    virtual bool Initialize() = 0;
    virtual void Update(float fTimeDelta) = 0;
    virtual void Late_Update(float fTimeDelta) = 0;

    virtual void Clear_Scene();

};





