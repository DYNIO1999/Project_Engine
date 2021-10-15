#define SFML_STATIC
#include "core/core.h"
int main()
{
    DEngine::Engine* engine = new DEngine::Engine();
    engine->run();
    delete engine;
}