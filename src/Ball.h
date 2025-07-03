#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_Speed = 1000.0f;
    float m_DirectionX;
    float m_DirectionY;
public:
    Ball(float startX, float startY);
    Vector2f getPosition();
    FloatRect getBounds();
    RectangleShape getShape();
    float getXVelocity();
    void reboundSides();
    void reboundBatOrTop();
    void reboundBottom();
    void update(Time dt);
};
