#pragma once
/**  
* Klasa przetrzymujaca czas potrzebny do deltatime
*/
class TimeStep
{
private:
public:
    TimeStep(float time=0.0f):m_time(time){};
    ~TimeStep(){};
    float m_time;
};
