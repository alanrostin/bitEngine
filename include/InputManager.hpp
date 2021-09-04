#ifndef InputManager_hpp
#define InputManager_hpp

#include <SFML/Graphics.hpp>
#include "Bitmask.hpp"

class InputManager
{
    public:
        enum class Key
        {
            None = 0,
            Left = 1,
            Right = 2,
            Up = 3,
            Down = 4,
            Esc = 5,
            LBracket = 6,
            RBracket = 7
        };
        void update();
        bool isKeyPressed(Key keycode);
        bool isKeyDown(Key keycode);
        bool isKeyUp(Key keycode);
    
    private:
        Bitmask thisFrameKeys;
        Bitmask lastFrameKeys;
};

#endif