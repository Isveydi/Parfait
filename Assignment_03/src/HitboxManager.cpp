#include "HitboxManager.h"
#include <cstring>

/**
 * @author Mar Werner Hernandez
 */

AttackHitbox* HitboxManager::enemyAtHitboxes[MAX_HITBOXES] = {};
ColliderHitbox* HitboxManager::enemyCoHitboxes[MAX_HITBOXES] = {};
u32 HitboxManager::numEnemyAtHitboxes = 0;
u32 HitboxManager::numEnemyCoHitboxes = 0; 
Player* HitboxManager::player = nullptr;

void HitboxManager::RegisterPlayer(Player* player)
{
	HitboxManager::player = player;
}

void HitboxManager::RegisterAttackHitbox(AttackHitbox* const at) {
    enemyAtHitboxes[numEnemyAtHitboxes++] = at;
}

void HitboxManager::RegisterColliderHitbox(ColliderHitbox* const co) {
    enemyCoHitboxes[numEnemyCoHitboxes++] = co;
}

void HitboxManager::Update(void) {
    for(u32 i = 0; i < numEnemyAtHitboxes; i++) {
        /*
        if(enemyAtHitboxes[i]->isActive && enemyAtHitboxes[i]->getGlobalBounds().intersects(PlayerManager::GetPlayer().GetCoHitbox()->getGlobalBounds()))
            PlayerManager::GetPlayer().OnHit();
        */
    }

    
    // Check if player is attacking and whether their attack hitbox overlaps with the registered enemy collider hitboxes
    if(player->getAttackHitbox().isActive) {
        for(u32 i = 0; i < numEnemyCoHitboxes; i++) {
            if(enemyCoHitboxes[i]->getGlobalBounds().intersects(player->getAttackHitbox().getGlobalBounds())) {
		        enemyCoHitboxes[i]->RunHitFunction(&player->getAttackHitbox());
            }
        }
    }

    /*
    if(MapManager::GetCollision().getBounds().intersects(PlayerManager::GetPlayer().GetCoHitbox()->getGlobalBounds())) {
        // Set player to be above ground
    }
    */

    /*
    for(u32 i = 0; i < numEnemyCoHitboxes; i++) {
        if(enemyCoHitboxes[i]->getGlobalBounds().intersects(MapManager::GetCollision().getBounds()) {
            // Set enemy to be above ground
        }
    }
    */

    numEnemyAtHitboxes = numEnemyCoHitboxes = 0;
}
