#include <iostream>
#include <fstream>
#include "Square.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>

using namespace sf;
using namespace std;

Square::Square(float side, float diameter, float dpi){
    displaySquare.create(VideoMode(300, 300), "Display Square");
    // Convert 2mm to pixels
    float sizePx = mmToPixels(side, dpi);

    // Create a square
    vector<RectangleShape> square;
    for(int i = 0; i<sizePx; i++){
        RectangleShape new_square(sf::Vector2f(sizePx-i, sizePx-i));
        new_square.setFillColor(generateRandomColor());
        // Center the square
        new_square.setPosition(
            (displaySquare.getSize().x / 2) - ((sizePx-i) / 2), // X position
            (displaySquare.getSize().y / 2) - ((sizePx-i) / 2)  // Y position
        );
        square.push_back(new_square);
    }

    // Create a formatted string using ostringstream
    std::ostringstream stream1;
    stream1.precision(2); // Set precision to 2 decimal places
    stream1 << std::fixed << side;
    Font font;
    font.loadFromFile("Times New Normal Regular.ttf");
    Text text1;
    text1.setFont(font);                   // Set the font
    string message1 = "Side: " + stream1.str() + "mm";
    text1.setString(message1);       // Set the text string
    text1.setCharacterSize(17);            // Set the font size (in pixels)
    text1.setFillColor(sf::Color::Black);  // Set the text color
    text1.setPosition(10, 10);           // Set the position of the text
    // Black pixels
    std::ostringstream stream2;
    stream2.precision(2); // Set precision to 2 decimal places
    stream2 << std::fixed << sizePx;
    Text text2;
    text2.setFont(font);                   // Set the font
    string message2 = stream1.str() + "mm " + "= " + stream2.str() + "pixels";
    text2.setString(message2);       // Set the text1 string
    text2.setCharacterSize(17);            // Set the font size (in pixels)
    text2.setFillColor(sf::Color::Black);  // Set the text1 color
    text2.setPosition(10, 28);           // Set the position of the text1
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
                for(int i = 0; i<square.size(); i++){
                    square[i].setPosition(
                        (width / 2) - ((sizePx-i) / 2), // X position
                        (height / 2) - ((sizePx-i) / 2)  // Y position
                    );
                }
            }
            else if(event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::M){
                    displaySquare.close();
                    Menu new_menu(side, diameter, dpi);
                }
            }
        }

        // Clear screen
        displaySquare.clear(sf::Color::White);

        // Draw shapes
        for(int i = 0; i<square.size(); i++){
            displaySquare.draw(square[i]);
        }
        displaySquare.draw(text1);
        displaySquare.draw(text2);

        // Display on screen
        displaySquare.display();
    }
}

float Square::mmToPixels(float side, float dpi){
    return side * (dpi / 25.4);
}

sf::Color Square::generateRandomColor() {
    // Create a random number generator and distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255); // Random number between 0 and 255

    // Generate random values for Red, Green, Blue
    int r = dis(gen);  // Red component
    int g = dis(gen);  // Green component
    int b = dis(gen);  // Blue component

    // Return the generated random color
    return sf::Color(r, g, b);
}