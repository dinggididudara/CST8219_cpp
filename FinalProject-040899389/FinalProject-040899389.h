// Soomin Lee 040899389 CST8219 303 Final Project

#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/Components.hpp>
//#include "include/Graphics/Color.hpp"

#include <stdlib.h>
#include <iostream>

//#define GREEN sf::Color(191,255,126)
//#define RED sf::Color(255,166,153)
//#define sf::Color(255,246,174)
//#define BLUE sf::Color(176,180,255)

using namespace std;

sf::Color col[]{ sf::Color(191,255,126), //green
				 sf::Color(255,166,153), //red
				 sf::Color(255,246,174), //yellow
				 sf::Color(176,180,255) //blue
};


string music[]{"canary.wav", "ball.wav", "orchestral.ogg", "doodle_pop.ogg"};

void startGame();
void endGame();
//void setText(string a);


