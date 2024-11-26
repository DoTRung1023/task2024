#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std; 
using namespace sf; 

enum ButtonStates { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE }; 

class Button{
    private:
        //the shape of button, font of text and the content of the button 
        RectangleShape shape;
        Font* font; 
        Text text; 
        Color idleColor; //Idle state (When user does not click or hover it)
        Color hoverColor; //Hover state (When user Hover)
        Color activeColor; //Active State (When user click on it)
        ButtonStates buttonState;
    public:
        Button(float x, float y, float width, float height, string text, Font* font, Color idleColor, Color hoverColor, Color activeColor);
        void render(RenderTarget* target);  //Draw the target into window
        void update(Vector2f mousePos); //Change the state of buttons if user click, hover or take no action if user does nnot click on it 
        ButtonStates getButtonStates(); //Return the state of the button 
};

#endif