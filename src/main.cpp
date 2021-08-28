#include "Engine.hpp"

int main() {
    Engine engine;

    while (engine.isRunning())
    {
        engine.processInput();
        engine.update();
        engine.lateUpdate();
        engine.render();
        engine.calculateDeltaTime();
    }
}