//#pragma once

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <SFML/Graphics.hpp>
#include "MapManager.h"
#include "EnemyManager.h"
#include "Player.h"
#include "Literals.h"

/**
 * @author Isveydi Moreno
 * 
 */

class EnemyManager;

class LevelManager {
    static u32 currentLevel;

    static std::vector<std::unique_ptr<EnemyManager>>& GetEnemyManagers(void);

    public:
    LevelManager();
    static void Update(Player& player);

    static void setupEnemies();

    static void draw(sf::RenderWindow& window);
    

};

#endif