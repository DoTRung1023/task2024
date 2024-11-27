#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Menu.hpp"
#include <cmath>

using namespace std;
using namespace sf;

int main(){
    float side = 2;
    float diameter = 2;
    int width = 2560;
    int length = 1600;
    float inch = 13.3;
    float dpi = sqrt(pow(width, 2) + pow(length, 2))/inch;
    Menu new_menu(side, diameter, dpi);

    return 0;
}