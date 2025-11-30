#pragma once

class CBaseLevel abstract
{
public:
    CBaseLevel() = default;
    virtual ~CBaseLevel() = default;

public:
    virtual void Ready_Level();
    virtual void Initialize();
    virtual void Update(float fTimeDelta);
    virtual void Late_Update(float fTimeDelta);

private:

};





