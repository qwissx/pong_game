#include "Ball.h"
#include "Dependencies.h"

Ball::Ball(float startX, float startY) : m_Position(startX, startY) {
    m_Shape.setSize(sf::Vector2f(10, 10));
    m_Shape.setPosition(m_Position);
    m_DirectionY = generatePosInteger() * 0.1f;
    m_DirectionX = generateInteger() * 0.1f;
}

Vector2f Ball::getPosition() {
    return m_Shape.getPosition();
}

FloatRect Ball::getBounds() {
    return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
    return m_Shape;
}

float Ball::getXVelocity() {
    return m_DirectionX;
}

void Ball::reboundSides() {
    m_DirectionX -= m_DirectionX * 2;
}

void Ball::reboundBatOrTop() {
    m_DirectionY -= m_DirectionY * 2;
}

void Ball::reboundBottom() {
    m_Position.y = 30;
    m_Position.x = 1980 / 2;
    m_DirectionY = generatePosInteger() * 0.1f;
    m_DirectionX = generateInteger() * 0.1f;
}

void Ball::update(Time dt) {
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Shape.setPosition(m_Position);
}
