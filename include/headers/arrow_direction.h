#pragma once
#include "sprite_component.h"
#include "transform_component.h"
class ArrowDirection
{
public:
    int dx, dy;
    
    TransformComponent *transform;
    SpriteComponent *sprite;

    ArrowDirection();
    ~ArrowDirection();
    void ResetDirection(int ddx, int ddy);
    void Update();
    void Render();
private:
};

// declare global variable to use in other file
extern ArrowDirection *arrow_direction;