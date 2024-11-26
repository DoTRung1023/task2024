#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"

using namespace std; 
using namespace sf; 

class Square
{
private:
    RenderWindow displaySquare;
public:
    Square(float side, float diameter, int dpi);
    float mmToPixels(float side, int dpi);
};


#endif