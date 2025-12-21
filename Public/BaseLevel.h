#pragma once

class IInputService;

class CBaseLevel abstract 
{
public:
    CBaseLevel(const IInputService& inputService);
    virtual ~CBaseLevel() = default;
public:
    bool Is_End() { return m_bEnd; };
public:
    virtual bool Initialize() = 0;
    virtual void Update(float fTimeDelta) = 0;
    virtual void Late_Update(float fTimeDelta) = 0;

    virtual void Clear_Scene();

protected:
    const IInputService& m_Input;

protected:
    bool m_bEnd = { false };
};





