// Soomin Lee 040899389 CST8219 303 Final Project

#include "FinalProject-040899389.h"

int main()
{
	sf::RenderWindow window({ 800,600 }, "TGUI window with sfml");
	tgui::Gui gui{ window };
	gui.loadWidgetsFromFile("form.txt");
	gui.mainLoop();

	auto startButton = gui.get<tgui::Button>("StartGameButton");
	auto greenButton = gui.get<tgui::Button>("GreenButton");
	auto blueButton = gui.get<tgui::Button>("BlueButton");
	auto redButton = gui.get<tgui::Button>("RedButton");
	auto yellowButton = gui.get<tgui::Button>("YellowButton");

	auto msgTextArea = gui.get<tgui::TextArea>("MessageTextArea");

	startButton->onClick([]() {
		startGame(); //if click the new game start button, then start new game
		
		});
	greenButton->onClick([]() {cout << "You Clicked start button"; });
	blueButton->onClick([]() {cout << "You Clicked start button"; });
	redButton->onClick([]() {cout << "You Clicked start button"; });
	yellowButton->onClick([]() {cout << "You Clicked Yellow button"; });


	return 0;
}

void startGame() {


}
