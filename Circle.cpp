#include <iostream>
#include <fstream>
#include "Circle.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>

using namespace sf;
using namespace std;

Circle::Circle(float side, float diameter, float dpi){
    displayCircle.create(VideoMode(300, 300), "Display Circle");
    // Convert 2mm to pixels
    float sizePx = mmToPixels(diameter, dpi);

    // Create a circle
    float radius = sizePx/2;

    // Create a circle
    vector<CircleShape> circle;
    for(int i = 0; i<radius; i++){
        sf::CircleShape new_circle(radius-i);
        new_circle.setFillColor(generateRandomColor());
        // Center the circle
        new_circle.setPosition(
            (displayCircle.getSize().x / 2) - (radius-i), // X position
            (displayCircle.getSize().y / 2) - (radius-i)  // Y position
        );
        circle.push_back(new_circle);
    }

    // Show diameter
    std::ostringstream stream1;
    stream1.precision(2); // Set precision to 2 decimal places
    stream1 << std::fixed << diameter;
    Font font;
    font.loadFromFile("Times New Normal Regular.ttf");
    Text text1;
    text1.setFont(font);                   // Set the font
    string message1 = "Diameter: " + stream1.str() + "mm";
    text1.setString(message1);       // Set the text1 string
    text1.setCharacterSize(17);            // Set the font size (in pixels)
    text1.setFillColor(sf::Color::Black);  // Set the text1 color
    text1.setPosition(10, 10);           // Set the position of the text1
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
                for(int i = 0; i<circle.size(); i++){
                    circle[i].setPosition(
                        (width / 2) - (radius-i), // X position
                        (height / 2) - (radius-i)  // Y position
                    );                
                }
            }
            else if(event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::M){
                    displayCircle.close();
                    Menu new_menu(side, diameter, dpi);
                }
            }
        }

        // Clear screen
        displayCircle.clear(sf::Color::White);
        // Draw shapes
        for(int i = 0; i<circle.size(); i++){
            displayCircle.draw(circle[i]);  
        }
        displayCircle.draw(text1);
        displayCircle.draw(text2);
        // Display on screen
        displayCircle.display();
    }
}

float Circle::mmToPixels(float diameter, float dpi){
    return diameter * (dpi / 25.4);
}

sf::Color Circle::generateRandomColor() {
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