#define SFML_STATIC

#include "core/core.h"

int main()
{
    Engine *engine = new Engine(); // Glowny obiekt naszego silnika

    engine->run(); // Glowna metoda silnika odpowiada za cala gre/silnik

    delete engine; //To usuwa silnik
}