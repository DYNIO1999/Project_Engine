#pragma once
class Engine;
//namespace DEngine{

class Scene{
public:
    virtual ~Scene() {}
    virtual void processEvents()=0; //1
    virtual void draw()=0; //2
    Engine* m_Engine_ref;
};
//};