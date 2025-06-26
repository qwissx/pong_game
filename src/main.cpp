#include "Bat.h"
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

        window.clear();
        window.display();
    }
    return 0;
}
