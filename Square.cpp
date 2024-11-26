#include <iostream>
#include <fstream>
#include "Square.hpp"

using namespace sf;
using namespace std;

Square::Square(float side, float diameter, int dpi){
    displaySquare.create(VideoMode(300, 300), "Display Square");
    // Convert 2mm to pixels
    float sizePx = mmToPixels(side, dpi);

    // Create a square
    RectangleShape square(sf::Vector2f(sizePx, sizePx));
    square.setFillColor(sf::Color::White);

    // Center the square
    square.setPosition(
        (displaySquare.getSize().x / 2) - (sizePx / 2), // X position
        (displaySquare.getSize().y / 2) - (sizePx / 2)  // Y position
    );

    // Main loop
    while(displaySquare.isOpen()){
        sf::Event event;
        while (displaySquare.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                displaySquare.close();
            else if(event.type == Event::Resized){
                // get new size of new window
                int width = displaySquare.getSize().x;
                int height = displaySquare.getSize().y;
                // set current active view for rendering
                displaySquare.setView(View(FloatRect(0, 0, width, height)));
                // Center the square
                square.setPosition(
                    (width / 2) - (sizePx / 2), // X position
                    (height / 2) - (sizePx / 2)  // Y position
                );
            }
            else if(event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::M){
                    displaySquare.close();
                    Menu new_menu(side, diameter, dpi);
                }
            }
        }

        // Clear screen
        displaySquare.clear(sf::Color::Black);

        // Draw shapes
        displaySquare.draw(square);

        // Display on screen
        displaySquare.display();
    }
}

float Square::mmToPixels(float side, int dpi){
    return side * (dpi / 25.4);
}