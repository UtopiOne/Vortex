#pragma once

#include "Event.h"

#include <sstream>

namespace Vortex {

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {
    }

    inline unsigned int GetWidth() const {
        return m_Width;
    }
    inline unsigned int GetHeight() const {
        return m_Height;
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "WindowResized: " << m_Width << ", " << m_Height;
        return ss.str();
    }

    EVENT_CLASS_TYPE(WindowResized)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
private:
    unsigned int m_Width, m_Height;
};

class WindowCloseEvent : public Event {
public:
    WindowCloseEvent() {
    }

    EVENT_CLASS_TYPE(WindowClosed)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class WindowFocusedEvent : public Event {
public:
    WindowFocusedEvent() {
    }

    EVENT_CLASS_TYPE(WindowFocused)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class WindowUnfocusedEvent : public Event {
public:
    WindowUnfocusedEvent() {
    }

    EVENT_CLASS_TYPE(WindowUnfocused)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

} // namespace Vortex
