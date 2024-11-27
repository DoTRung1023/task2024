#ifndef CIRCLE_HPP
#define CIRCLE_HPP

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

class Circle
{
private:
    RenderWindow displayCircle;
public:
    Circle(float side, float diameter, float dpi);
    float mmToPixels(float diameter, float dpi);
    Color generateRandomColor();
};
#endif