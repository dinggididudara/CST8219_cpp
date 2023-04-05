// Soomin Lee 040899389 CST8219 303 Final Project

#include "FinalProject-040899389.h"
#include <vector>

int main()
{
	cout << "Opening the window.." << endl;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Simon Game");
	tgui::Gui gui(window);
	gui.loadWidgetsFromFile("form.txt");
	cout << "Loading the file.." << endl;

	cout << "Configuration.." << endl;

	static sf::Color GREEN = sf::Color(191, 255, 126);
	static sf::Color RED = sf::Color(255, 166, 153);
	static sf::Color YELLOW = sf::Color(255, 246, 174);
	static sf::Color BLUE = sf::Color(176, 180, 255);
	static sf::Color WHITE = sf::Color::White;


	static auto startButton = gui.get<tgui::Button>("NewGameButton");
	static auto greenButton = gui.get<tgui::Button>("GreenButton");
	static auto blueButton = gui.get<tgui::Button>("BlueButton");
	static auto redButton = gui.get<tgui::Button>("RedButton");
	static auto yellowButton = gui.get<tgui::Button>("YellowButton");

	greenButton->getRenderer()->setBackgroundColor(GREEN);
	blueButton->getRenderer()->setBackgroundColor(BLUE);
	redButton->getRenderer()->setBackgroundColor(RED);
	yellowButton->getRenderer()->setBackgroundColor(YELLOW);

	static bool isGreenOn = false;
	static bool isBlueOn = false;
	static bool isRedOn = false;
	static bool isYellowOn = false;

	static auto msgTextArea = gui.get<tgui::TextArea>("MessageTextArea");

	static bool gameOver = false;


	static vector<int> ran_vec = { 0 };
	static vector<int> clicked_vec = { 0 };
	clicked_vec.clear();

	// main loop
	
	


	greenButton->onClick([&]() {
		msgTextArea->setText("You Clicked Green Button\n");
	clicked_vec.push_back(1);

		});
	redButton->onClick([&]() {
		msgTextArea->setText("You Clicked Blue Button\n");
	clicked_vec.push_back(2);

		});
	yellowButton->onClick([&]() {
		msgTextArea->setText("You Clicked Red Button\n");
	clicked_vec.push_back(3);

		});
	blueButton->onClick([&]() {
		msgTextArea->setText("You Clicked Yellow Button");
	clicked_vec.push_back(4);

		});

	startButton->onClick([&]() {
		startButton->setEnabled(false);
	cout << "Starting the new game now" << endl;
	msgTextArea->setText("Starting the new game now\n");

	greenButton->getRenderer()->setBackgroundColor(WHITE);
	blueButton->getRenderer()->setBackgroundColor(WHITE);
	redButton->getRenderer()->setBackgroundColor(WHITE);
	yellowButton->getRenderer()->setBackgroundColor(WHITE);

	int ran_num = 0;
	ran_vec.clear();
	clicked_vec.clear();
	srand(std::time(0));
	for (int i = 0; i < 4; i++) {
		ran_num = (rand() % 4) + 1;

		ran_vec.push_back(ran_num);
		cout << ran_vec[i] << endl;
	} //for end


	cout << "Random Number Generated. Please Click any buttons" << endl;
	msgTextArea->setText("Random Number Generated.\n");

	


	if (clicked_vec.size() == 4)
	{
		//if vector is full
		//disable buttons
		greenButton->setEnabled(false);
		blueButton->setEnabled(false);
		redButton->setEnabled(false);
		yellowButton->setEnabled(false);
		// check if the sequence is right
		if (ran_vec == clicked_vec) {
			gameOver = true;
			msgTextArea->setText("Game Over! Bye");
			exit(EXIT_SUCCESS);
		}
		else {
			msgTextArea->setText("Wrong!\n");
			clicked_vec.clear(); //reset the clicked vector

		}
	}
		}); //startButton onclick end

	while (window.isOpen()) {
		sf::Clock clock;
		sf::Event event;

		//handle window close event
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			gui.handleEvent(event);
		}

		// Check for mouse button press event
		if (event.type == sf::Event::MouseButtonPressed) {
			// Check if mouse position is inside the bounds of the button
			if () {
				// Execute button's callback function
				
			}
		}






		window.clear();
		gui.draw();
		window.display();
	}
	
	return 0;
}

