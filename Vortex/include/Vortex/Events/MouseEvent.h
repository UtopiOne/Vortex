#pragma once

#include "Vortex/Events/Event.h"

#include <sstream>

namespace Vortex {

class MouseMovedEvent : public Event {
public:
    MouseMovedEvent(int x, int y) : m_Xpos(x), m_Ypos(y) {
    }

    inline const int GetX() const {
        return m_Xpos;
    }
    inline const int GetY() const {
        return m_Ypos;
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseMoved: " << m_Xpos << ", " << m_Ypos;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

private:
    int m_Xpos, m_Ypos;
};

class MouseButtonPressedEvent : public Event {
public:
    MouseButtonPressedEvent(int button) : m_Button(button) {
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseButtonPressed: " << m_Button;
        return ss.str();
    }

    inline const int GetButton() const {
        return m_Button;
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

private:
    int m_Button;
};

class MouseButtonReleasedEvent : public Event {
public:
    MouseButtonReleasedEvent(int button) : m_Button(button) {
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseButtonReleased: " << m_Button;
        return ss.str();
    }

    inline const int GetButton() const {
        return m_Button;
    }

    EVENT_CLASS_TYPE(MouseButtonReleased)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

private:
    int m_Button;
};

class MouseScrolledEvent : public Event {
public:
    MouseScrolledEvent(int x, int y) : m_XOffset(x), m_YOffset(y) {
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseScrolled: " << m_XOffset << ", " << m_YOffset;
        return ss.str();
    }

    inline const int GetXOffset() const {
        return m_XOffset;
    }
    inline const int GetYOffset() const {
        return m_YOffset;
    }

    EVENT_CLASS_TYPE(MouseScrolled)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

private:
    int m_XOffset, m_YOffset;
};

} // namespace Vortex
