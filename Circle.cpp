#include <iostream>
#include <fstream>
#include "Circle.hpp"

using namespace sf;
using namespace std;

Circle::Circle(float side, float diameter, int dpi){
    displayCircle.create(VideoMode(300, 300), "Display Circle");
    // Convert 2mm to pixels
    float sizePx = mmToPixels(diameter, dpi);

    // Create a circle
    sf::CircleShape circle(sizePx / 2);
    circle.setFillColor(sf::Color::White);

    // Center the circle
    circle.setPosition(
        (displayCircle.getSize().x / 2) - (sizePx / 2), // X position
        (displayCircle.getSize().y / 2) - (sizePx / 2)  // Y position
    );

    // Main loop
    while(displayCircle.isOpen()){
        sf::Event event;
        while (displayCircle.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                displayCircle.close();
            else if(event.type == Event::Resized){
                // get new size of new window
                int width = displayCircle.getSize().x;
                int height = displayCircle.getSize().y;
                // set current active view for rendering
                displayCircle.setView(View(FloatRect(0, 0, width, height)));
                // Center the circle
                circle.setPosition(
                    (width / 2) - (sizePx / 2), // X position
                    (height / 2) - (sizePx / 2)  // Y position
                );
            }
            else if(event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::M){
                    displayCircle.close();
                    Menu new_menu(side, diameter, dpi);
                }
            }
        }

        // Clear screen
        displayCircle.clear(sf::Color::Black);

        // Draw shapes
        displayCircle.draw(circle);

        // Display on screen
        displayCircle.display();
    }
}

float Circle::mmToPixels(float diameter, int dpi){
    return diameter * (dpi / 25.4);
}