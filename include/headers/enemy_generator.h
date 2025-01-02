#pragma once
#include "enemy_skeleton.h"

#include <vector>
class EnemyGenerator 
{
public:
    EnemyGenerator();
    ~EnemyGenerator();
    void AddNewSkeleton(int x, int y);
    
    void Update();
    void Render();
    std::vector<EnemySkeleton*> skeleton_container;
    

private:
    const int MAX_ENEMY = 15;
    int generator_interval;
    const char *texture;

};
extern EnemyGenerator *enemy_generator;