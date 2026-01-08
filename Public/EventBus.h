#pragma once
template<typename T>
class CEventBus
{
public:
	using Handler = function<void(const T&)>;
public:
	void Subscribe(Handler handler);
	void Publish(const T& event) const;

private:
	vector<Handler> m_Handler;
};

template<typename T>
inline void CEventBus<T>::Subscribe(Handler handler)
{
	m_Handler.push_back(handler);
}

template<typename T>
inline void CEventBus<T>::Publish(const T& event) const
{
	for (auto& elem : m_Handler) elem(event);
}
