#include "keyInput.h"

// Copilot: use PDCurses library for "event-driven" input handling.

KeyInput::Action KeyInput::get()
{
    while (true)
    {
        for (size_t i = 0; i < static_cast<size_t>(Key::max_key); ++i)
        {
            Key key = static_cast<Key>(i);
            if (isKeyPressed(key))
            {
                return s_actionArray[i];
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(KEY_GET_SLEEP_TIME)); // Sleep to reduce CPU usage
    }
}

std::ostream& operator<< (std::ostream& out, const KeyInput::Key& key)
{
    out << KeyInput::s_keyMap[key];
    return out;
}

bool KeyInput::isKeyPressed(Key key)
{
    static std::map<Key, bool> isKeyPressedMap;

    if (GetAsyncKeyState(s_keyMap.at(key)) & SHIFTED)
    {
        if (!isKeyPressedMap[key])
        {
            isKeyPressedMap[key] = true;
        }
    }
    else if (isKeyPressedMap[key])
    {
        isKeyPressedMap[key] = false;
        return true;
    }

    return false;
}