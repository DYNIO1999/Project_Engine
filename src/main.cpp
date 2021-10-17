#define SFML_STATIC
#include "core/core.h"
int main()
{
    Engine* engine = new Engine();
    engine->run();
    delete engine;
}