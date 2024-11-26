#include <iostream>
#include <fstream> 
#include "Menu.hpp"
#include "Button.hpp"
#include "Circle.hpp"
#include "Square.hpp"

using namespace sf; 
using namespace std; 

Menu::Menu(float side, float diameter, int dpi): side(side), diameter(diameter), dpi(dpi){
    menuWindow.create(VideoMode(400, 550), "DISPLAY SHAPE"); 
    font.loadFromFile("Times New Normal Regular.ttf");

    //Create the title of the game:
    RectangleShape rectangle(Vector2f(400.0f, 100.0f)); // Width x Height
    rectangle.setFillColor(Color::Black); // Set rectangle color
    // Center it at the top
    rectangle.setPosition((menuWindow.getSize().x / 2) - (rectangle.getSize().x / 2), 60.0f); 

    //Create Text object for the title:
    Text title;
    title.setFont(font);
    title.setString("Display shape"); // Set the title text
    title.setCharacterSize(50); // Set text size
    title.setFillColor(Color::White); // Set text color
    title.setOutlineThickness(1.3);

    // Center the text in the rectangle
    FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.width / 2, textRect.height / 2); // Set origin to center of text
    title.setPosition(rectangle.getPosition().x + rectangle.getSize().x / 2, 
                      rectangle.getPosition().y + rectangle.getSize().y / 2); // Center the text in the rectangle

    //Make the introImage in the middle of the screen: 
    sf::Vector2u windowSize = menuWindow.getSize();
    
    //Define 2 buttons in the intro menu: 
    Button circleButton(windowSize.x/2 - 100, windowSize.y/2, 200.0, 50.0, "Circle", &font, Color::White, sf::Color(146,146,146,100), sf::Color(146,146,146,170));
    Button squareButton(windowSize.x/2 - 100, windowSize.y/2 + 80, 200.0, 50.0, "Square", &font, Color::White, sf::Color(146,146,146,100), sf::Color(146,146,146,170)); 

    // Main loop
    while (menuWindow.isOpen()) {
        Vector2f mousePos = menuWindow.mapPixelToCoords(sf::Mouse::getPosition(menuWindow));
        // Update the button state based on mouse position
        circleButton.update(mousePos);
        squareButton.update(mousePos);
        //When user click on a button or quit the game intro Menu
        Event event;
        while (menuWindow.pollEvent(event)) {
            if (event.type == Event::Closed){
                menuWindow.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                if(squareButton.getButtonStates() == BTN_ACTIVE){
                    menuWindow.close();
                    Square squareWindow(side, diameter, dpi);
                }
                else if(circleButton.getButtonStates() == BTN_ACTIVE){   
                    menuWindow.close();
                    Circle circleWindow(side, diameter, dpi);
                }
            }
            // Clear the window
            menuWindow.clear(sf::Color::Black);

            //Draw the button
            circleButton.render(&menuWindow);
            squareButton.render(&menuWindow);             

            //Draw the rectangle and the title
            menuWindow.draw(rectangle);
            menuWindow.draw(title);

            // Display the contents of the window
            menuWindow.display();        
        }
    }

}

void Menu::closeWindow(){
    menuWindow.close(); 
}

