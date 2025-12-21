#include "pch.h"
#include "KeyboardInputSystem.h"

CKeyboardInputSystem::CKeyboardInputSystem()
	: m_mapCurKey{ 0 }
	, m_mapPreKey{ 0 }
{
}

bool CKeyboardInputSystem::Initialize()
{
	if (!m_mapCurKey[0])
		return false;

	return true;
}

void CKeyboardInputSystem::Update()
{
	size_t lastIndex = static_cast<size_t>(KeyCode::Last);
	for (int bi = 0; bi < lastIndex; ++bi)
	{
		m_mapPreKey[bi] = m_mapCurKey[bi]();
	}
}

void CKeyboardInputSystem::SetInputButton(KeyCode eCode, function<bool()> inPressFunc)
{
	m_mapCurKey[static_cast<size_t>(eCode)] = inPressFunc;
}

bool CKeyboardInputSystem::IsPressed(KeyCode eCode) const
{
	assert(eCode < KeyCode::Last);

	size_t targetKey = static_cast<size_t>(eCode);
	return (!m_mapPreKey[targetKey] && m_mapCurKey[targetKey]());
}

bool CKeyboardInputSystem::IsPressing(KeyCode eCode) const
{
	assert(eCode < KeyCode::Last);

	size_t targetKey = static_cast<size_t>(eCode);
	return (m_mapPreKey[targetKey] && m_mapCurKey[targetKey]());
}

bool CKeyboardInputSystem::IsReleased(KeyCode eCode) const
{
	assert(eCode < KeyCode::Last);

	size_t targetKey = static_cast<size_t>(eCode);
	return (m_mapPreKey[targetKey] && !(m_mapCurKey[targetKey]()));
}


