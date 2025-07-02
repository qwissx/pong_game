#include "Bat.h"
#include "Ball.h"

#include <sstream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;


int main() {
    RenderWindow window(VideoMode({1920u, 1080u}), "PONG");
    window.setFramerateLimit(144);

    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    Ball ball(1920 / 2, 0);
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
        if (Keyboard::isKeyPressed(Keyboard::Key::Left)) bat.moveLeft();
        else bat.stopLeft();
        if (Keyboard::isKeyPressed(Keyboard::Key::Right)) bat.moveRight();
        else bat.stopRight();

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

        //if (ball.getPosition().top < 0) {
        //    ball.reboundBatOrTop();
        //    score++;
        //}

        //if (ball.getPosition().left < 0 ||
        //    ball.getPosition().left + ball.getPosition().width > window.getSize().x) {
        //    ball.reboundSides();
        //}

        //if (ball.getPosition().findIntersection(bat.getPosition())) ball.reboundBatOrTop();

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}
