#include "InputManager.hpp"

void InputManager::update()
{
    lastFrameKeys.setMask(thisFrameKeys);
    thisFrameKeys.setBit((int)Key::Left, 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));
    thisFrameKeys.setBit((int)Key::Right, 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));
    thisFrameKeys.setBit((int)Key::Up, 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
    thisFrameKeys.setBit((int)Key::Down, 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || 
        (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));
    thisFrameKeys.setBit((int)Key::Esc, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
    
    thisFrameKeys.setBit((int)Key::LBracket, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket));
    thisFrameKeys.setBit((int)Key::RBracket, 
        sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket));
}

// Return true if the specified key is currently being pressed
bool InputManager::isKeyPressed(Key keycode)
{
    return thisFrameKeys.getBit((int)keycode);
}

// Return true if the key was just pressed
// (i.e. registered as pressed this frame but not the previous)
bool InputManager::isKeyDown(Key keycode)
{
    bool lastFrame = lastFrameKeys.getBit((int)keycode);
    bool thisFrame = thisFrameKeys.getBit((int)keycode);

    return thisFrame && !lastFrame;
}

// Return true if the key was just released
// (i.e. registered as pressed last frame but not the current frame)
bool InputManager::isKeyUp(Key keycode)
{
    bool lastFrame = lastFrameKeys.getBit((int)keycode);
    bool thisFrame = thisFrameKeys.getBit((int)keycode);

    return !thisFrame && lastFrame;
}
