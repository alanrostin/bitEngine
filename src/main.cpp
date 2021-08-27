#include "Engine.hpp"

int main() {
    Engine engine;

    while (engine.isRunning())
    {
        engine.update();
        engine.lateUpdate();
        engine.render();
    }
}