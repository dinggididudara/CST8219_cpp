// Soomin Lee 040899389 CST8219 303 Final Project

#include "FinalProject-040899389.h"


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



	// main loop
	//while (window.isOpen()) {
	sf::Clock clock;
	sf::Event event;

	// //handle window close event
	//while (window.pollEvent(event)) {
	//	if (event.type == sf::Event::Closed)
	//		window.close();				
	//}

	startButton->onClick([&]() {
		startButton->setEnabled(false);
	cout << "Starting the new game now" << endl;
	msgTextArea->setText("Starting the new game now\n");

	greenButton->getRenderer()->setBackgroundColor(WHITE);
	blueButton->getRenderer()->setBackgroundColor(WHITE);
	redButton->getRenderer()->setBackgroundColor(WHITE);
	yellowButton->getRenderer()->setBackgroundColor(WHITE);

	static vector<int> ran_vec = { 0 };
	static vector<int> clicked_vec = { 0 };
	int ran_num=0;
	for (int i = 0; i < 4; i++) {
		 ran_num = (rand() % 4) + 1;
		cout << ran_num << endl;
		ran_vec.push_back(ran_num);
	} //for end


	cout << "Random Number Generated. Please Click any buttons" << endl;
	msgTextArea->setText("Random Number Generated.\n");

	//turn on and off the button
	cout << "turn on the light now" << endl;
	while (!gameOver) {

		for (int i = 0; i < 4; i++) {
			switch (ran_vec[i]) {
			case 1: //green
				isGreenOn = true;
				break;
			case 2: //blue
				isBlueOn = true;
				break;
			case 3: //red
				isRedOn = true;
				break;
			case 4: //yellow
				isYellowOn = true;
				break;
			} //for end

			// update button colors
			if (isGreenOn) {
				blueButton->getRenderer()->setBackgroundColor(WHITE);
				redButton->getRenderer()->setBackgroundColor(WHITE);
				yellowButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				greenButton->getRenderer()->setBackgroundColor(GREEN);
				isGreenOn = false;
			}
			else if (isBlueOn) {
				greenButton->getRenderer()->setBackgroundColor(WHITE);
				redButton->getRenderer()->setBackgroundColor(WHITE);
				yellowButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				blueButton->getRenderer()->setBackgroundColor(BLUE);
				isBlueOn = false;

			}
			else if (isRedOn) {
				greenButton->getRenderer()->setBackgroundColor(WHITE);
				blueButton->getRenderer()->setBackgroundColor(WHITE);
				yellowButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				redButton->getRenderer()->setBackgroundColor(BLUE);
				isRedOn = false;
			}
			else if (isYellowOn) {
				greenButton->getRenderer()->setBackgroundColor(WHITE);
				redButton->getRenderer()->setBackgroundColor(WHITE);
				blueButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				yellowButton->getRenderer()->setBackgroundColor(BLUE);
				isYellowOn = false;
			} //else if end

		} //for end
		
		
		//detecting user's click event
		greenButton->onClick([]() {
			msgTextArea->setText("You Clicked Green Button\n");
			clicked_vec.push_back(1);
			});
		blueButton->onClick([]() {
			msgTextArea->setText("You Clicked Blue Button\n");
		clicked_vec.push_back(2);
			});
		redButton->onClick([]() {
			msgTextArea->setText("You Clicked Red Button\n");
		clicked_vec.push_back(3);
			});
		yellowButton->onClick([]() {
			msgTextArea->setText("You Clicked Yellow Button");
		clicked_vec.push_back(4);
			});
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) { //if clicked mouse left
					if (!gameOver) //if not game over yet
					{
						for (int i = 0; i < 4; i++) {
							if (greenButton)
							{
								clicked_vec.push_back(1);
							}
							else if (blueButton)
							{
								clicked_vec.push_back(1);
							}
							else if (redButton)
							{
								clicked_vec.push_back(3);
							}
							else if (yellowButton)
							{
								clicked_vec.push_back(4);
							}
							else if (clicked_vec.size() == 4) { //if vector is full
								//disable buttons
								greenButton->setEnabled(false);
								blueButton->setEnabled(false);
								redButton->setEnabled(false);
								yellowButton->setEnabled(false);

								if (ran_vec == clicked_vec) {
									gameOver = true;
								}
								else {
									msgTextArea->setText("Wrong!\n");
									clicked_vec = { 0 }; //reset the clicked vector
								}
							}

						}
				
					} //if end
				} //if end


			} //if end
			
		} //while(event) end

		// check if the sequence is right
		

	} //while(!gameover) end


		}); //startButton onclick end
	


	//} //while(isopen) end

	gui.draw();
	window.display();
	gui.mainLoop();
	return 0;
}

void startGame() {


}

void endGame() {
	cout << "Game End" << endl;
	//	setText("Game End\n");
}
