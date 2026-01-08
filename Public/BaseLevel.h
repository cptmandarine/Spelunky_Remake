#pragma once
#include "GameContext.h"
#include "EventBus.h"

enum class LEVEL_ID { MAIN, STAGE_1, STAGE_2 };

typedef struct tagLevelevent
{
    LEVEL_ID  nextLevel;
}LEVEL_EVENT;

class CBaseLevel abstract 
{
public:
    CBaseLevel(const LEVELCONTEXT& tLevelContext, const CEventBus<LEVEL_EVENT>& eventBus);
    virtual ~CBaseLevel() = default;
public:
    virtual bool Initialize() = 0;
    virtual void Release();

    virtual void Update(float fTimeDelta) = 0;
    virtual void Late_Update(float fTimeDelta) = 0;

protected:
    const IInputService&          m_Input;
    const CEventBus<LEVEL_EVENT>& m_EventBus;
};





