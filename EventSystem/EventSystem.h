#pragma once

#include <functional>
#include <string>
#include <vector>

#include "Event.h"

class EventDispatcher;

////////////////////////////////////////////////////////////////////////////////////
// Manages event listeners and dispatches events to them.
////////////////////////////////////////////////////////////////////////////////////
class EventSystem
{
public:
	////////////////////////////////////////////////////////////////////////////////
	// An event listener function.
	////////////////////////////////////////////////////////////////////////////////
	using Callback = std::function<void(std::shared_ptr<Event>)>;

private:
	////////////////////////////////////////////////////////////////////////////////
	// Stores associated information about an event listener.
	////////////////////////////////////////////////////////////////////////////////
	struct EventListener
	{
		// Created a Constructor for the EventListener so I can pass through a shared pointer without using new.
		EventListener(std::string name, std::shared_ptr<EventDispatcher> disbatch, Callback call)
			: m_eventName(name)
			, m_pTarget(disbatch)
			, m_callback(call)
		{}
		// The kind of event that occurred.
		std::string m_eventName;

		// The object that the event "happened to"
		std::shared_ptr<EventDispatcher> m_pTarget;

		// The function that will be called when the event happens.
		Callback m_callback;
	};

private:
	// Stores all registered listeners.
	std::vector<std::shared_ptr<EventListener>> m_listeners;

public:
	EventSystem() = default;
	~EventSystem() = default;

	void RegisterListener(std::string pEventName, std::shared_ptr<EventDispatcher> pTarget, Callback callback);
	void DispatchEvent(std::shared_ptr<Event> pEvent);
};

