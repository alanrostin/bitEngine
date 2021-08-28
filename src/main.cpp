#include "Engine.hpp"

int main() {
    Engine engine;

    while (engine.isRunning())
    {
        engine.captureInput();
        engine.update();
        engine.lateUpdate();
        engine.render();
        engine.calculateDeltaTime();
    }
}