#include "pch.h"
#include "MainLevel.h"
#include "Player.h"

CMainLevel::CMainLevel()
	: m_Player(make_unique<CPlayer>())
{
}

CMainLevel::~CMainLevel()
{
	m_Player.reset();
}

void CMainLevel::Initialize()
{
	cout << "¾À ÁØºñÁß.." << "\n";
	m_Player->Initialize();
}


void CMainLevel::Update(float fTimeDelta)
{
	m_Player->Update();

}

void CMainLevel::Late_Update(float fTimeDelta)
{
}
