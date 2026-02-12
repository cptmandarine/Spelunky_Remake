#include "pch.h"
#include "ServiceLocater.h"

unordered_map<std::type_index, void*> CServiceLocater::m_ServiceMap;