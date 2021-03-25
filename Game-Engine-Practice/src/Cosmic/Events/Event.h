#ifndef EVENT_H
#define EVENT_H

#include <functional>

namespace Cosmic{

    enum class EventType{
        None=0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory{
        None = 1 << 0,
        EventCategoryApplication = 1 << 1,
        EventCategoryInput = 1 << 2,
        EventCategoryKeyboard = 1 << 3,
        EventCategoryMouse = 1 << 4,
        EventCategoryMouseButton = 1 << 5
    };


    class Event
    {
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
    public:
        
    };
}

#endif