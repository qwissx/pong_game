#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class Bat {
    private:
        Vector2f m_Position;
        RectangleShape m_Shape;
        float m_Speed = 1000.0f;
        bool m_MovingRight = false;
        bool m_MovingLeft = true;
    public:
        Bat(float startX, float startY);
        FloatRect getPosition();
        RectangleShape getShape();
        void moveLeft();
        void moveRight();
        void stopLeft();
        void stopRight();
        void update(Time dt);
};
