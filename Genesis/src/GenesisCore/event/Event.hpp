#pragma once
#include "GenesisCore/Defines.hpp"

namespace ge {
	enum class EventType {
		None = 0,

		// Window Events
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowFocusLost,
		WindowMoved,

		// Key Events
		KeyDown,
		KeyUp,
		KeyTyped,

		// Mouse Events
		MouseButtonDown,
		MouseButtonUp,
		MouseMoved,
		MouseScrolled,
	};
	enum EventCategory {
		None = 0,
		EventCategoryWindow = GE_Bit(0),
		EventCategoryInput = GE_Bit(1),
		EventCategoryKeyboard = GE_Bit(2),
		EventCategoryMouse = GE_Bit(3)
	};

#define EVENT_CLASS_TYPE(type)                                                                                                                       \
	static EventType getStaticType() { return EventType::##type; }                                                                                   \
	virtual EventType getEventType() const override { return getStaticType(); }                                                                      \
	virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)                                                                                                               \
	virtual int32 getCategoryFlags() const override { return category; }

	class Event {
		friend class EventDispatcher;

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int32 getCategoryFlags() const = 0;

		inline bool isInCategory(EventCategory category) { return getCategoryFlags() & category; }

		inline bool isHandled() { return handled; }

	protected:
		bool handled = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& e): e(e) {}

		template<typename T>
		bool dispatch(EventFunc<T> func) {
			if(e.getEventType() == T::getStaticType()) {
				e.handled = func(*(T*) &e);
				return true;
			}
			return false;
		}

	private:
		Event& e;
	};
}
