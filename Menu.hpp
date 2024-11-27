#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

using namespace sf; 
using namespace std; 

class Menu{
    private:
        RenderWindow menuWindow; //Object for the intro window
        Font font; //Object for the Font of text
        float side = 0;
        float diameter = 0;
        int dpi = 0;
    public:
        Menu(float side, float diameter, float dpi); //Constructor for the Intro. 
        Menu();
        void closeWindow();  //Getter for introWindow. 
}; 

#endif