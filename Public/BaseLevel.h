#pragma once
#include "EventBus.h"

enum class LEVEL_ID { MAIN, STAGE_1, STAGE_2 };

typedef struct tagLevelevent
{
    LEVEL_ID  nextLevel;
}LEVEL_EVENT;

class CBaseLevel abstract 
{
public:
    CBaseLevel(const CEventBus<LEVEL_EVENT>& eventBus);
    virtual ~CBaseLevel() = default;
public:
    virtual bool Initialize() = 0;
    virtual void Release();

    virtual void Update(float fTimeDelta) = 0;
    virtual void Late_Update(float fTimeDelta) = 0;

protected:
    virtual optional<LEVEL_ID> Evaluate_NextScene() = 0;

protected:
    const CEventBus<LEVEL_EVENT>& m_EventBus;
};





