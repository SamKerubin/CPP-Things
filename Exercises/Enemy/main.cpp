#include "enemy.h"
#include <list>

int main()
{
    std::shared_ptr<Enemy> enemy = Enemy::createEnemy("Skeleton", 1, 200);
    enemy->showStats();
    enemy->takeDamage(200);
}