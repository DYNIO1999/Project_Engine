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
    /**
     * Konstruktor klasy EngineConfig
     */
    EngineConfig(){
    }

    /**
     * Metoda podaje aktualny tryb silnika
     */
    int getEngineMode(){
        return m_engineMode;
    }
    /**
     * Metoda podaje aktualna szerokosc okna
     */
    unsigned int getWindowWidth(){
        return m_windowWidth;   
    }
    /**
     * Metoda podaje aktualna wysokosc okna
     */
    unsigned int getWindowHeight(){
        return m_windowHeight;
    }
    /**
     * Metoda sprawdza czy okno jest w plenym ekranie
     */
    bool isFullscreen(){
        return m_fullscreenAllowed;
    }
    /**
     * Metoda ustwaia aktualny tryb silnika
     * \param mode typ.
     */
    void setEngineMode(int mode)
    {
        m_engineMode = mode;
    }
    /**
     * Metoda ustwaia aktualna wyskosc okna
     * \param height wysokosc.
     */
    void setWindowHeight(unsigned int height)
    {
        m_windowHeight = height;
    }
    /**
     * Metoda ustawia aktualna szerkosc okna
     * \param width szerokosc.
     */
    void setWindowWidth(unsigned int width)
    {
        m_windowWidth = width;
    }
    /**
     * Metoda ustwia pelen ekran
     * \param fullscreen.
     */
    void setFullscreen(bool fullscreen)
    {
        m_fullscreenAllowed = fullscreen;
    }
    /**
     * Metoda ustawia dzwiek
     * \param soundON
     */
    void setSound(bool soundON){
        m_soundON = soundON;
    }
    /**
     * Metoda sprawdza czy dzwiek jest uruchomiony
     */
    bool isSound(){
        return m_soundON;
    }
    private:
    /**
     * Typ silnika
     */
    int m_engineMode;
    /**
     * Pelen ekran
     */
    bool m_fullscreenAllowed;
    /**
     * Szerokosc okna
     */
    unsigned int m_windowWidth;
    /**
     * Wysokosc okna
     */
    unsigned int m_windowHeight;
    /**
     * Dzwiek
     */
    bool m_soundON;
};
