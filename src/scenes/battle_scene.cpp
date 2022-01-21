#include "../core/core.h"
#include "battle_scene.h"
#include "../objects/player.h"
#include "../objects/enemybattle.h"
#include "../scenes/main_menu_scene.h"

Battle_Scene::Battle_Scene(Engine *engine_ref) 
{
    m_Engine_ref = engine_ref;
    initData();
}

Battle_Scene::Battle_Scene(Engine *engine_ref, int battleMapType, int numberEnemies) 
{
    m_Engine_ref = engine_ref;
    m_battleMapType = battleMapType;
    m_numberEnemies = numberEnemies;
    initData();
}

int Battle_Scene::processEvents(TimeStep deltatime) 
{
   
    bool check = false;
    for (int i = 0; i < ((int)m_buttonList.size()); i++)
    {
        check = m_buttonList[i]->ButtonUpdate();
        if(check==true){
            if(i==BATTLE_END_TURN){
                endTurn=true;
                check=false;
            }
        }

    }

    if((currentTurn==BATTLE_PLAYER_TURN)&&(clickedOnEnemy==true)){
        
        if(objMoved==false){
            playerstartPos = m_entitesPtr->getObject("PLAYER_BATTLE")->getPos();


            if (m_entitesPtr->getObject(currentObjName))
            {
                enemystartPos = m_entitesPtr->getObject(currentObjName)->getPos();
            }
           
        }
        m_entitesPtr->getObject("PLAYER_BATTLE")->setPosition(sf::Vector2f(m_Engine_ref->m_window->getSize().x/2+ 
        ((m_entitesPtr->getObject("PLAYER_BATTLE")->getSize().x* m_entitesPtr->getObject("PLAYER_BATTLE")->getScale())/2), m_entitesPtr->getObject("PLAYER_BATTLE")->getPos().y));
        if (m_entitesPtr->getObject(currentObjName)){
            m_entitesPtr->getObject(currentObjName)->setPosition(sf::Vector2f(m_Engine_ref->m_window->getSize().x/2- 
        m_entitesPtr->getObject(currentObjName)->getSize().x* m_entitesPtr->getObject(currentObjName)->getScale(), m_entitesPtr->getObject(currentObjName)->getPos().y));
        }
        objMoved=true;
        m_entitesPtr->getObject("PLAYER_BATTLE")->setTexture(pPlayerAttackTexture);
        m_entitesPtr->getObject("PLAYER_BATTLE")->setAnimationState(PLAYER_ANIMATION_ATTACK);
        if (m_entitesPtr->getObject(currentObjName))
        {     
            if(m_Engine_ref->m_engine_config.isSound()){
            swordHit.play();
            }

            float health =m_entitesPtr->getObject(currentObjName)->getHealth() -  m_entitesPtr->getObject("PLAYER_BATTLE")->getAttack();
            if(health<0){
                health =0;
            }
            m_entitesPtr->getObject(currentObjName)->setHealth(health);
            if(m_entitesPtr->getObject(currentObjName)->getHealth()>0){
            m_entitesPtr->getObject(currentObjName)->setTexture(pEnemyHitTexture);
            m_entitesPtr->getObject(currentObjName)->setAnimationState(ENEMY_ANIMATION_HIT);
            allowEndTurn = true;
            }else{
            if(m_Engine_ref->m_engine_config.isSound()){
            deathSound.play();
            }
            m_entitesPtr->getObject(currentObjName)->setTexture(pEnemyDeathTexture);
            m_entitesPtr->getObject(currentObjName)->setAnimationState(ENEMY_ANIMATION_DEATH);
            isDeath=true;
            allowEndTurn =true;
            enemyKilledObjName = currentObjName;
            deletedIndex.push_back(enemyKilledObjName.at(enemyKilledObjName.length() - 1)-'0');
            }
        }
        inAnimation=true;
        clickedOnEnemy = false;
        }
        else if(currentTurn==BATTLE_ENEMY_TURN&&objMoved==false&&waitToMove==false)
        {   

            if (objMoved == false)
            {
                DiceRoller diceRoll;
                if((currentNumberEnemies<m_numberEnemies)&&(currentNumberEnemies>0)){
                    bool check = true;
                    int temp;
                    do{
                        temp = diceRoll.diceRoll(m_numberEnemies);
                        //std::cout<<temp;
                        int j=0;
                        for(int i=0;i<(int)deletedIndex.size();i++){
                            if(temp==deletedIndex[i]){
                                j++;
                            }
                        }
                        if(j==0){
                            check=false;
                            currentEnemyIndex=temp;
                        }
                    }while(check);
                }else{
                    currentEnemyIndex = diceRoll.diceRoll(m_numberEnemies);
                }
                currentObjName= enemyObjName + std::to_string(currentEnemyIndex);
                

                playerstartPos = m_entitesPtr->getObject("PLAYER_BATTLE")->getPos();
                if (m_entitesPtr->getObject(currentObjName))
                {
                    enemystartPos = m_entitesPtr->getObject(currentObjName)->getPos();
                }
            }
            objMoved=true;
        
        m_entitesPtr->getObject("PLAYER_BATTLE")->setPosition(sf::Vector2f(m_Engine_ref->m_window->getSize().x/2+ 
        ((m_entitesPtr->getObject("PLAYER_BATTLE")->getSize().x* m_entitesPtr->getObject("PLAYER_BATTLE")->getScale())/2), m_entitesPtr->getObject("PLAYER_BATTLE")->getPos().y));
        if (m_entitesPtr->getObject(currentObjName)){
            m_entitesPtr->getObject(currentObjName)->setPosition(sf::Vector2f(m_Engine_ref->m_window->getSize().x/2- 
        m_entitesPtr->getObject(currentObjName)->getSize().x* m_entitesPtr->getObject(currentObjName)->getScale(), m_entitesPtr->getObject(currentObjName)->getPos().y));
        }
        if (m_entitesPtr->getObject(currentObjName))
        {
        m_entitesPtr->getObject(currentObjName)->setTexture(pEnemyAttackTexture);
        m_entitesPtr->getObject(currentObjName)->setAnimationState(ENEMY_ANIMATION_ATTACK);
        m_entitesPtr->getObject("PLAYER_BATTLE")->setHealth(m_entitesPtr->getObject("PLAYER_BATTLE")->getHealth() - m_entitesPtr->getObject(currentObjName)->getAttack());
        }


        if (m_entitesPtr->getObject("PLAYER_BATTLE")->getHealth() > 0)
        {
            if(m_Engine_ref->m_engine_config.isSound()){
            swordHit.play();
            }
            m_entitesPtr->getObject("PLAYER_BATTLE")->setTexture(pPlayerHitTexture);
            m_entitesPtr->getObject("PLAYER_BATTLE")->setAnimationState(PLAYER_ANIMATION_HIT);
        }
        else
        {
            if(m_Engine_ref->m_engine_config.isSound()){
            deathSound.play();
            }
            m_entitesPtr->getObject("PLAYER_BATTLE")->setTexture(pPlayerDeathTexture);
            m_entitesPtr->getObject("PLAYER_BATTLE")->setAnimationState(PLAYER_ANIMATION_DEATH);
            isPlayerDead = true;
        }
        inAnimation = true;
        allowEndTurn =true;
        }


    if(inAnimation){
        testTimer.Start();
        float elapsedTime = testTimer.GetElapsedSeconds();
        if(elapsedTime>1.0f){
            m_entitesPtr->getObject("PLAYER_BATTLE")->setTexture(pPlayerIdleTexture);
            m_entitesPtr->getObject("PLAYER_BATTLE")->setAnimationState(PLAYER_ANIMATION_IDLE);
            m_entitesPtr->getObject(currentObjName)->setTexture(pEnemyIdleTexture);
            m_entitesPtr->getObject(currentObjName)->setAnimationState(ENEMY_ANIMATION_IDLE);
            testTimer.Reset();
            inAnimation=false;
            if(currentTurn ==BATTLE_ENEMY_TURN){
                endTurn = true;
            }
            if(isDeath){
                Potion* temp =  new Potion(pPotionTexture,m_entitesPtr->getObject(currentObjName)->getPos(),sf::Vector2f(60,80),m_Engine_ref,25);
                m_potionList.push_back(temp);
                m_entitesPtr->removeEntity(currentObjName);
                currentNumberEnemies--;
                m_Engine_ref->m_gameSaveData.setPlayerExperience(m_Engine_ref->m_gameSaveData.getPlayerExperience() + 25);
                isDeath=false;
            }
            if (isPlayerDead){
                m_battleSceneState=BATTLE_LOST_STATE;
            }
        }
    }else{
        testTimer.Reset();
        testTimer.Pause();
    }

    if(endTurn&&allowEndTurn){
      
        m_entitesPtr->getObject("PLAYER_BATTLE")->setPosition(playerstartPos);
        if( m_entitesPtr->getObject(currentObjName)){
        m_entitesPtr->getObject(currentObjName)->setPosition(enemystartPos);
        }
        playerstartPos = sf::Vector2f(0, 0);
        enemystartPos = sf::Vector2f(0, 0);
        if(currentTurn ==BATTLE_ENEMY_TURN){
            
            //std::cout<<"PLAYER TURN_CHNAGE";
            currentTurn = BATTLE_PLAYER_TURN;
        }else if(currentTurn == BATTLE_PLAYER_TURN){
            //std::cout << "ENEMY TURN_CHNAGE";
            currentTurn = BATTLE_ENEMY_TURN;
        }
        currentObjName="";
        endTurn =false;
        allowEndTurn=false;
        objMoved =false;
        currentEnemyIndex=-100;
        waitToMove =true;
        allowClickOnEnemy=true;
    }

    if(waitToMove){
        secondTimer.Start();
        float elapsedTime = secondTimer.GetElapsedSeconds();
        if(elapsedTime>0.5f){
            waitToMove=false;
            secondTimer.Reset();
        }
    }else{
        secondTimer.Reset();
        secondTimer.Pause();
    }
    
    if(currentTurn==BATTLE_PLAYER_TURN){
        if(clickedOnPotion){
        delete m_potionList[potionIndexToRemove];
        m_potionList.erase(m_potionList.begin() + potionIndexToRemove);
        clickedOnPotion=false;
        
        potionIndexToRemove=-1;
        scorebaord.AddScore(1);
        m_Engine_ref->m_gameSaveData.setCurrentNumberPotions(m_Engine_ref->m_gameSaveData.getCurrentNumberPotions() + 1);
        }
    }


    if (allowUsePotion && (currentTurn == BATTLE_PLAYER_TURN))
    {
        if(scorebaord.GetScore()>0){
        scorebaord.DecreaseScore(1);
        m_Engine_ref->m_gameSaveData.setCurrentNumberPotions(m_Engine_ref->m_gameSaveData.getCurrentNumberPotions() - 1);
        m_entitesPtr->getObject("PLAYER_BATTLE")->setHealth(m_entitesPtr->getObject("PLAYER_BATTLE")->getHealth()+20);
        }
        allowUsePotion=false;
    }

    m_entitesPtr->processEvents(deltatime);

    scorebaord.Update();

    if(currentNumberEnemies==0){
        wonTimer.Start();
        float elapsedTime = wonTimer.GetElapsedSeconds();
        m_battleSceneState = BATTLE_WON_STATE;

        if(elapsedTime>3.0f){
        m_Engine_ref->m_gameSaveData.setWonBattles(m_Engine_ref->m_gameSaveData.getWonBattles() + 1);

        if (m_Engine_ref->m_engine_config.isSound())
        {
            m_Engine_ref->isMusic = true;
        }
        m_Engine_ref->m_scene_manager->popScene();
        wonTimer.Reset();
        return 0;
        }
    }
    else
    {
        wonTimer.Reset();
        wonTimer.Pause();
    }

    if(m_battleSceneState==BATTLE_LOST_STATE){
        lostTimer.Start();
        float elapsedTime = lostTimer.GetElapsedSeconds();
        if(elapsedTime>2.0f){
            m_Engine_ref->m_scene_manager->changeScene(new MainMenuScene(m_Engine_ref));
            lostTimer.Reset();
            return 0;
        }
    }
    else
    {
        lostTimer.Reset();
        lostTimer.Pause();
    }
    return 0;
    }

void Battle_Scene::draw(TimeStep deltatime) 
{
    m_Engine_ref->m_window->clear(sf::Color::White);
    /*ImGui::Begin("Welcome Battle_Scene");
    if (ImGui::Button("Close Battle scene"))
    {
        m_Engine_ref->m_scene_manager->popScene();
        ImGui::End();
        return;
    }
    ImGui::End();*/
    m_Engine_ref->m_window->draw(m_background);
    m_Engine_ref->m_window->draw(m_GUIbar);
    
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonDraw(*m_Engine_ref->m_window);
    }

    m_entitesPtr->draw((*m_Engine_ref->m_window));

    for (auto it = m_potionList.begin(); it < m_potionList.end();it++){
        (*it)->draw(*m_Engine_ref->m_window);
    }

    scorebaord.Draw((*m_Engine_ref->m_window));
    
    if(m_battleSceneState==BATTLE_WON_STATE){
        m_Engine_ref->m_window->draw(m_wonSprite);
    }
    else if (m_battleSceneState == BATTLE_LOST_STATE)
    {
        m_Engine_ref->m_window->draw(m_lostSprite);
    }
}

void Battle_Scene::input() 
{
    m_mousePosition = m_Engine_ref->m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_Engine_ref->m_window));
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        (*it)->ButtonInput(m_mousePosition, *m_Engine_ref);
    }
    if((currentTurn==BATTLE_PLAYER_TURN)&&allowClickOnEnemy){
    for (auto it = m_entitesPtr->m_entities.begin(); it != m_entitesPtr->m_entities.end(); it++)
    {
        if (it->first != playerObjName)
        {
            
            if(it->second->getBoxCollider().contains(m_mousePosition)){
                if (m_Engine_ref->event.mouseButton.button == sf::Mouse::Left)
                {
                    if (m_Engine_ref->event.type == sf::Event::MouseButtonPressed)
                    {
                        currentObjName = it->first;
                        clickedOnEnemy=true;
                        allowClickOnEnemy =false;
                        return;
                    }
                }
            }
        }
    }
    }
    if(currentTurn==BATTLE_PLAYER_TURN){
    for(int i=0;i<((int)m_potionList.size());i++){

        if (m_potionList[i]->getBoxCollider().contains(m_mousePosition))
        {
            if (m_Engine_ref->event.mouseButton.button == sf::Mouse::Left)
            {
                if (m_Engine_ref->event.type == sf::Event::MouseButtonPressed)
                {
                    potionIndexToRemove = i;
                    clickedOnPotion = true;
                    return;
                }
            }
        }
    }
    }
    if(currentTurn==BATTLE_PLAYER_TURN){
        if (m_Engine_ref->event.type == sf::Event::KeyPressed)
        {
            if (m_Engine_ref->event.key.code == sf::Keyboard::P)
            {   
                allowUsePotion=true;
                return;
            }
        }
    }
}

Battle_Scene::~Battle_Scene() 
{
    
    cleanupData();
    m_entitesPtr->cleanUp();
    delete m_entitesPtr;

}

void Battle_Scene::initData() 
{
    m_entitesPtr = new EntityList();

    sf::View temp = m_Engine_ref->m_window->getView();
    temp.setSize(sf::Vector2f(m_Engine_ref->m_window->getSize().x, m_Engine_ref->m_window->getSize().y));
    temp.setCenter(sf::Vector2f((((float)m_Engine_ref->m_window->getSize().x) / 2.0), ((float)m_Engine_ref->m_window->getSize().y) / 2.0));
    m_Engine_ref->m_window->setView(temp);

    std::shared_ptr<sf::Texture> pbackgroundTexture;

    std::shared_ptr<sf::Font> menuFont = ResourceManager::acquireFont(ASSETS_FONTS_PATH + "mainfont.ttf");

    Button_Colors tempColors;
    tempColors.pressedColor = sf::Color(0, 0, 0, 255);
    tempColors.hoverColor = sf::Color(20, 20, 20, 255);
    tempColors.idleColor = sf::Color(5, 46, 21, 255);

    int buttonwidth = 500;
    int buttonheight = 100;

    Button *endturnButton = new Button();
    endturnButton->initButton(m_Engine_ref->m_window->getSize().x/2-buttonwidth/2, m_Engine_ref->m_window->getSize().y - (buttonheight+2.5), buttonwidth, buttonheight, *menuFont, "END TURN", tempColors, sf::Vector2f(0, -24));

    m_buttonList.push_back(endturnButton);

    if(m_battleMapType ==DESERT_MAP_TYPE){
        pbackgroundTexture = ResourceManager::acquireTexture(ASSETS_BACKGROUND_PATH + "battle1.png");
        m_background.setTexture(*pbackgroundTexture);
        m_background.setPosition(sf::Vector2f(0, 0));
        m_background.setScale(sf::Vector2f(2.5, 2.5));
    }
    else if (m_battleMapType == MOUNTAIN_MAP_TYPE)
    {
        pbackgroundTexture = ResourceManager::acquireTexture(ASSETS_BACKGROUND_PATH + "battle2.png");
        m_background.setTexture(*pbackgroundTexture);
        m_background.setPosition(sf::Vector2f(0, 0));
        m_background.setScale(sf::Vector2f(1,1));
    }

    m_GUIbar.setPosition(sf::Vector2f(0, m_Engine_ref->m_window->getSize().y-105));
    m_GUIbar.setSize(sf::Vector2f(1600, 105));
    m_GUIbar.setFillColor(sf::Color(5, 46, 21, 200));
    m_GUIbar.setOutlineColor(sf::Color::Black);
    m_GUIbar.setOutlineThickness(1.f);

    

    pPlayerAttackTexture = ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_AttackNoMovement.png");
    pPlayerDeathTexture = ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_DeathNoMovement.png");
    pPlayerHitTexture = ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_Hit.png");
    pPlayerIdleTexture =  ResourceManager::acquireTexture(ASSETS_CHARACTER_BATTLE_PATH + "_Idle.png");
    pEnemyIdleTexture = ResourceManager::acquireTexture(ASSETS_ENEMY_BATTLE_PATH + "Idle.png");
    pEnemyHitTexture = ResourceManager::acquireTexture(ASSETS_ENEMY_BATTLE_PATH + "Hit.png");
    pEnemyAttackTexture = ResourceManager::acquireTexture(ASSETS_ENEMY_BATTLE_PATH + "Attack.png");
    pEnemyDeathTexture = ResourceManager::acquireTexture(ASSETS_ENEMY_BATTLE_PATH + "Death.png");
    pPotionTexture = ResourceManager::acquireTexture(ASSETS_ITEMS_PATH + "potion.png");

    m_entitesPtr->addEntity("PLAYER_BATTLE", new Player(pPlayerIdleTexture, sf::Vector2f(1000, m_Engine_ref->m_window->getSize().y), sf::Vector2f(50, 40), m_Engine_ref, PLAYER_BATTLE_TYPE));
    m_entitesPtr->getObject("PLAYER_BATTLE")->setAnimationState(PLAYER_ANIMATION_IDLE);
    m_entitesPtr->getObject("PLAYER_BATTLE")->setScale(5);
    m_entitesPtr->getObject("PLAYER_BATTLE")->setHealth(m_Engine_ref->m_gameSaveData.getPlayerHealth());
    m_entitesPtr->getObject("PLAYER_BATTLE")->setAttack(m_Engine_ref->m_gameSaveData.getPlayerAttack());
    m_entitesPtr->getObject("PLAYER_BATTLE")->setExperience(m_Engine_ref->m_gameSaveData.getPlayerExperience());
    m_entitesPtr->getObject("PLAYER_BATTLE")->setPosition(sf::Vector2f(1400 - (m_entitesPtr->getObject("PLAYER_BATTLE")->getSize().x / 2 * m_entitesPtr->getObject("PLAYER_BATTLE")->getScale()), m_Engine_ref->m_window->getSize().y / 2 - (m_entitesPtr->getObject("PLAYER_BATTLE")->getSize().y / 2 * m_entitesPtr->getObject("PLAYER_BATTLE")->getScale())));

    for(int i=0;i<m_numberEnemies;i++){
        std::string objname = enemyObjName + std::to_string(i);
        m_entitesPtr->addEntity(objname, new EnemyBattle(pEnemyIdleTexture, sf::Vector2f(200, 110+i*250), sf::Vector2f(50, 40), m_Engine_ref));
        m_entitesPtr->getObject(objname)->setAnimationState(ENEMY_ANIMATION_IDLE);
        m_entitesPtr->getObject(objname)->setScale(5);
        m_entitesPtr->getObject(objname)->setHealth(100);
        m_entitesPtr->getObject(objname)->setAttack(20);
    }

    DiceRoller currentDice;
    int diceValue = currentDice.diceRoll_1K10();
    
    if(diceValue>=3){
        currentTurn = BATTLE_PLAYER_TURN;
    }else{
        currentTurn = BATTLE_ENEMY_TURN;
    }
    
    if(currentTurn==1){
    //std::cout<<"ENEMY_TURN"<<'\n';
    }else{
    //std::cout<<"PLAYER_TURN"<<'\n';
    }

    clickedOnEnemy = false;
    endTurn =false;
    objMoved =false;
    allowEndTurn=false;
    inAnimation =false;
    isDeath =false;
    waitToMove =false;
    clickedOnPotion =false;
    allowClickOnEnemy=true;

    allowUsePotion=false;
    isPlayerDead = false;
    testTimer.Start();
    secondTimer.Start();

    scorebaord.InitScoreBoard(m_Engine_ref);
    scorebaord.SetScore(m_Engine_ref->m_gameSaveData.getCurrentNumberPotions());
    scorebaord.SetMaxScore(5);
    scorebaord.SetScorboardPosition(sf::Vector2f(1300, m_Engine_ref->m_window->getSize().y-70));
    
    currentNumberEnemies=m_numberEnemies;
    m_battleSceneState=BATTLE_DEFAULT_STATE;

    

    pWonTexture = ResourceManager::acquireTexture(ASSETS_PATH + "won.png");
    m_wonSprite.setTexture(*pWonTexture);
    m_wonSprite.setPosition(sf::Vector2f(m_Engine_ref->m_window->getSize().x/2-500, 250));
    m_wonSprite.setScale(sf::Vector2f(2, 2));

    
    pLostTexture = ResourceManager::acquireTexture(ASSETS_PATH + "lost.png");
    m_lostSprite.setTexture(*pLostTexture);
    m_lostSprite.setPosition(sf::Vector2f(m_Engine_ref->m_window->getSize().x / 2-500, 250));
    m_lostSprite.setScale(sf::Vector2f(2, 2));

    wonTimer.Start();
    lostTimer.Start();

    deathSound.setBuffer(*ResourceManager::acquireSound(ASSETS_SOUNDS_PATH+"death.ogg"));
    deathSound.setVolume(50);

    swordHit.setBuffer(*ResourceManager::acquireSound(ASSETS_SOUNDS_PATH+"sword.ogg"));
    swordHit.setVolume(50);

    
    battleMusic.openFromFile(ASSETS_SOUNDS_PATH + "battle.ogg");
    battleMusic.setLoop(true);
    battleMusic.setVolume(20);
    if (m_Engine_ref->m_engine_config.isSound())
    {
        battleMusic.play();
    }
}

void Battle_Scene::cleanupData() 
{
    for (auto it = m_buttonList.begin(); it < m_buttonList.end(); it++)
    {
        delete *it;
    }
    m_buttonList.clear();

    for (auto it = m_potionList.begin(); it < m_potionList.end(); it++)
    {
        delete *it;
    }
    m_potionList.clear();
}
