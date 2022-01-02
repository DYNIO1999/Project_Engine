#pragma once

/**  
* ENGINE_DEMO - silnik
* ENGINE_GAME - gra 
*/
enum ENGINE_STATES{
    ENGINE_DEMO,
    ENGINE_GAME,
};

/**  
* Klasa z danymi potrzebnymio do inicjacji okna i silniku
*/
class EngineConfig
{
    public:
    EngineConfig(){
    }

    int getEngineMode(){
        return m_engineMode;
    }
    unsigned int getWindowWidth(){
        return m_windowWidth;   
    }
    unsigned int getWindowHeight(){
        return m_windowHeight;
    }
    bool isFullscreen(){
        return m_fullscreenAllowed;
    }

    void setEngineMode(int mode)
    {
        m_engineMode = mode;
    }
    void setWindowHeight(unsigned int height)
    {
        m_windowHeight = height;
    }
    void setWindowWidth(unsigned int width)
    {
        m_windowWidth = width;
    }
    void setFullscreen(bool fullscreen)
    {
        m_fullscreenAllowed = fullscreen;
    }
    void setSound(bool soundON){
        m_soundON = soundON;
    }
    bool isSound(){
        return m_soundON;
    }
    private:
    int m_engineMode;
    bool m_fullscreenAllowed;
    unsigned int m_windowWidth;
    unsigned int m_windowHeight;
    bool m_soundON;
};
