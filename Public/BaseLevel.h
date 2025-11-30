#pragma once

class CBaseLevel abstract 
{
public:
    CBaseLevel() = default;
    virtual ~CBaseLevel() = default;

public:
    virtual void Initialize() = 0;
    virtual void Ready_Level() = 0;
    virtual void Update(float fTimeDelta) = 0;
    virtual void Late_Update(float fTimeDelta) = 0;

};





