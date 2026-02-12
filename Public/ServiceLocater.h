#pragma once
#include "InputService.h"

class CServiceLocater
{
public:
	CServiceLocater() = default;
	~CServiceLocater() = default;

private:
	CServiceLocater(const CServiceLocater& other) = delete;
	CServiceLocater& operator=(const CServiceLocater& other) = delete;

public:
	template<typename T>
	static void Register_Service(T* service)
	{
		m_ServiceMap[type_index(typeid(T))] = service;
	}
	
	template<typename T>
	static void Unregister_Service()
	{
		m_ServiceMap.erase(type_index(typeid(T)));
	}

	template<typename T>
	static const T& Get_Service()
	{
		const auto& iter = m_ServiceMap.find(typeid(T));
		assert(iter != m_ServiceMap.end() && "inValid Service");
		assert(iter->second != nullptr && "Unregistered Service");
		return *static_cast<T*>(iter->second);
	}


private:
	static unordered_map<type_index, void*> m_ServiceMap;
};

