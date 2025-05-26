#ifndef _ENEMY_H_

#define _ENEMY_H_

#include <string>
#include <memory>

class Enemy : public std::enable_shared_from_this<Enemy>
{
public:
    bool alive;

    Enemy(const std::string& name_, const int& level_, const float& health_);
    ~Enemy();

    static std::shared_ptr<Enemy> createEnemy(const std::string& name_, const int& level_, const float& health_);

    void showStats();
    void takeDamage(const float& amount_);
    void die();

private:
    std::string name;
    int level;
    float health;
};

#endif