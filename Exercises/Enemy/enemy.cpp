#include "enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& name_, const int& level_, const float& health_)
    : name(name_), level(level_), health(health_)
{
    Enemy::alive = true;
}

Enemy::~Enemy()
{
    if (!alive)
    {
        std::cout << "Enemy defeated" << std::endl;
        return;
    }

    std::cout << "Enemy removed" << std::endl;
}

std::shared_ptr<Enemy> Enemy::createEnemy(const std::string& name_, const int& level_, const float& health_)
{
    return std::make_shared<Enemy>(name_, level_, static_cast<float>(health_));
}

void Enemy::showStats() 
{ 
    std::cout << "Name: " << name << std::endl << "Level: " << level << std::endl << "Health: " << health << std::endl; 
}

void Enemy::die()
{ 
    alive = false;

    auto self = shared_from_this();
}

void Enemy::takeDamage(const float& amount_)
{
    health -= amount_;

    if (health <= 0) { die(); }
}