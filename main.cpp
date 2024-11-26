#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Menu.hpp"

using namespace std;
using namespace sf;

int main(){
    float side = 2;
    float diameter = 2;
    int dpi = 500;
    Menu new_menu(side, diameter, dpi);

    return 0;
}