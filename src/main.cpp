#include "core/core.h"

using namespace DEngine; 
int main(void)
{   
    EngineCore* engine = new EngineCore();
    engine->run();
    delete engine;
    return 0;
}
