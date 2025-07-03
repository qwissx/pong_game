#include "Bat.h"
#include "Ball.h"

#include <sstream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

const unsigned windowWidth = 1920;
const unsigned windowHeight = 1080;

int main() {
    RenderWindow window(VideoMode({windowWidth, windowHeight}), "PONG");
    window.setFramerateLimit(144);

    int score = 0;
    int lives = 3;

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 20);
    Font font;

    if (!font.openFromFile("static/fonts/DS-DIGIT.TTF")) {
        std::cerr << "error to open";
        return -1;
    }
    Text hud(font, "HUB", 75);
    hud.setFillColor(Color::White);

    Clock clock;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) window.close();

        if (Keyboard::isKeyPressed(Keyboard::Key::Left) &&
            bat.getPosition().x > 0) { 
            bat.moveLeft();
        } else bat.stopLeft();

        if (Keyboard::isKeyPressed(Keyboard::Key::Right) &&
            bat.getPosition().x < windowWidth - 50) {
            bat.moveRight();
        } else bat.stopRight();

        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        std::stringstream ss;
        ss << "Score:" << score << "    Lives:" << lives;
        hud.setString(ss.str());

        if (ball.getPosition().y > bat.getPosition().y) {
            ball.reboundBottom();
            lives--;

            if (lives < 1) {
                score = 0;
                lives = 3;
            }
        }

        if (ball.getPosition().y < 0) {
            ball.reboundBatOrTop();
            score++;
        }

        if (ball.getPosition().x < 0 || ball.getPosition().x > windowWidth - 10) {
            ball.reboundSides();
        }

        if (ball.getBounds().findIntersection(bat.getBounds())) ball.reboundBatOrTop();

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}
