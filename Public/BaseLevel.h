#pragma once

class IInputService;

class CBaseLevel abstract 
{
public:
    CBaseLevel(const IInputService& inputService);
    virtual ~CBaseLevel() = default;

public:
    virtual bool Initialize() = 0;
    virtual void Update(float fTimeDelta) = 0;
    virtual void Late_Update(float fTimeDelta) = 0;

    virtual void Clear_Scene();

protected:
    const IInputService& m_Input;

};





