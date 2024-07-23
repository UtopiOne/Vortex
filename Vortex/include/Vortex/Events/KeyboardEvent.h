#pragma once

#include "Vortex/Events/Event.h"

#include <sstream>

namespace Vortex {

class KeyboardKeyPressedEvent : public Event {
public:
    KeyboardKeyPressedEvent(int keycode, int repeats) : m_Keycode(keycode), m_Repeats(repeats) {
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "KeyboardKeyPressed: " << m_Keycode << " (" << m_Repeats << " repeats)";
        return ss.str();
    }

    inline const int GetRepeats() const {
        return m_Repeats;
    }

    EVENT_CLASS_TYPE(KeyboardKeyPressed)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

private:
    int m_Keycode;
    int m_Repeats;
};

class KeyboardKeyReleasedEvent : public Event {
public:
    KeyboardKeyReleasedEvent(int keycode) : m_Keycode(keycode) {
    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "KeyboardKeyReleased: " << m_Keycode;
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyboardKeyReleased)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

private:
    int m_Keycode;
};

} // namespace Vortex
