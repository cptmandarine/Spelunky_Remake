#include "pch.h"
#include "PrototypeRegistry.h"
#include "Prototype.h"
#include "GameObject.h"


void CPrototypeRegistry::Insert_Prototype(string key, unique_ptr<IPrototype> pPrototype)
{
	if (Find_Prototpye(key)) return;
	
	m_Prototypes[key] = move(pPrototype);
}

unique_ptr<CGameObject> CPrototypeRegistry::Clone_Prototpye(string key)
{
	if (!Find_Prototpye(key)) return nullptr;

	return m_Prototypes[key]->Clone();
}

bool CPrototypeRegistry::Find_Prototpye(string key)
{
	auto iter = m_Prototypes.find(key);
	return (iter != m_Prototypes.end());
}
