#pragma once

class IPrototype;
class CGameObject;

class CPrototypeRegistry
{
public:
	void				    Insert_Prototype(string key, unique_ptr<IPrototype> pPrototype);
	unique_ptr<CGameObject> Clone_Prototpye(string key);

private:
	bool					Find_Prototpye(string key);

private:
	unordered_map<string, unique_ptr<IPrototype>> m_Prototypes;
};

