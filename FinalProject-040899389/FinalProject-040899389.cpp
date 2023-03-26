// Soomin Lee 040899389 CST8219 303 Final Project

#include "FinalProject-040899389.h"

int main()
{
	cout << "Opening the window.." << endl;
	sf::RenderWindow window({ 800,600 }, "Simon Game");
	tgui::Gui gui{ window };
	gui.loadWidgetsFromFile("form.txt");
	cout << "Loading the file.." << endl;
	
	while (window.isOpen()) { 
		gui.mainLoop();//////error from here
		cout << "Configuration.." << endl;

		static auto startButton = gui.get<tgui::Button>("StartGameButton");
		static auto greenButton = gui.get<tgui::Button>("GreenButton");
		static auto blueButton = gui.get<tgui::Button>("BlueButton");
		static auto redButton = gui.get<tgui::Button>("RedButton");
		static auto yellowButton = gui.get<tgui::Button>("YellowButton");

		static auto msgTextArea = gui.get<tgui::TextArea>("MessageTextArea");
	
		int click[4] = { GREEN, RED, YELLOW, BLUE }; //array for click by user
	
		cout << msgTextArea << endl;
		startButton->onClick([]() {
			cout << "Starting the new game now" << endl;
			msgTextArea->setText("Starting the new game now\n");
			startGame(); //if click the new game start button, then start new game
			});
		greenButton->onClick([]() {
			msgTextArea->addText("You Clicked Green Button\n");
			});
		blueButton->onClick([]() {
			msgTextArea->addText("You Clicked Blue Button\n");
			});
		redButton->onClick([]() {
			msgTextArea->addText("You Clicked Red Button\n");
			});
		yellowButton->onClick([]() {
			msgTextArea->addText("You Clicked Yellow Button");		
			});
	}
	

	return 0;
}

void startGame() {
	int ran = rand() % 4;
	double seconds = 0.5; //0.5 seconds
	cout << "Random Number Generated. Please Click any buttons" << endl;
	//msgTextArea->addText("Random Number Generated. Please Click any button\n");
}

void endGame() {
	cout << "Game End" << endl;
//	msgTextArea->addText("Game End\n");
}
