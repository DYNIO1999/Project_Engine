#pragma once
namespace DEngine{
class TimeStep
{
private:
public:
    TimeStep(float time=0.0f):m_time(time){};
    ~TimeStep(){};
    float m_time;
};
};