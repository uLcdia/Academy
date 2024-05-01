#ifndef KEY_INPUT_H
#define KEY_INPUT_H

#include <iostream>
#include <array>
#include <map>
#include <thread>
#include <chrono>
#include <Windows.h>

class KeyInput
{
public:
    enum class Key
    {
        A,
        W,
        D,
        S,
        LEFT_KEY,
        UP_Key,
        RIGHT_KEY,
        DOWN_KEY,
        ESC,
        max_key
    };

    enum class Action
    {
        left,
        up,
        right,
        down,
        quit,
        max_action
    };

    static Action get();

    friend std::ostream& operator<< (std::ostream& out, const KeyInput::Key& key);
    
private:
    static constexpr int SHIFTED {0x8000};
    static constexpr int KEY_GET_SLEEP_TIME {50}; // used in sleep_for() in get(), millisecond

    static inline std::map<Key, int> s_keyMap
    {
        {Key::A, 'A'},
        {Key::W, 'W'},
        {Key::D, 'D'},
        {Key::S, 'S'},
        {Key::LEFT_KEY, 0x25},
        {Key::UP_Key, 0x26},
        {Key::RIGHT_KEY, 0x27},
        {Key::DOWN_KEY, 0x28},
        {Key::ESC, 0x1B} // 0x1B for VK_ESCAPE
    };

    static constexpr std::array<Action, static_cast<size_t>(Key::max_key)> s_actionArray {Action::left, Action::up, Action::right, Action::down, Action::left, Action::up, Action::right, Action::down, Action::quit};

    static bool isKeyPressed(Key key);
};

#endif