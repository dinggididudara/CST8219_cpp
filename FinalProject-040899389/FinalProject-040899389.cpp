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

	static auto msgTextArea = gui.get<tgui::TextArea>("MessageTextArea");

	static bool gameOver = false;
	static bool gameStart = false;

	//for sound
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	sf::SoundBuffer buffer3;
	sf::SoundBuffer buffer4;
	sf::SoundBuffer buffer5;
	sf::SoundBuffer buffer6;
	sf::Sound sound;

	int counter = 0;
	int click = 0; //how many times clicked

	static vector<int> ran_vec = { 0 };
	static vector<int> clicked_vec = { 0 };

	clicked_vec.clear();
	ran_vec.clear();

	////generate random number and save to vector
	//int ran_num = 0;
	//clicked_vec.clear();
	//srand(std::time(0));
	//for (int i = 0; i < 4; i++) {
	//	ran_num = (rand() % 4) + 1;
	//	ran_vec.push_back(ran_num);
	//	cout << ran_vec[i] << endl;
	//} //for end

	//cout << "Random Number Generated. Please Click any buttons" << endl;
	//msgTextArea->setText("Random Number Generated.\n");

	//cout << "Starting the new game now" << endl;
	//msgTextArea->setText("Starting the new game now\n");

	// start the main loop
	while (window.isOpen()) {
		sf::Clock clock;
		
		if (gameStart) {
			if (counter == 4) {
				counter = 0;
			} // turn on light
			else if (ran_vec[counter] == 1) { //green
				blueButton->getRenderer()->setBackgroundColor(WHITE);
				redButton->getRenderer()->setBackgroundColor(WHITE);
				yellowButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(1000)); //pause for 0.5 seconds
				greenButton->getRenderer()->setBackgroundColor(GREEN);

				counter++;
			}
			else if (ran_vec[counter] == 2) { //red
				greenButton->getRenderer()->setBackgroundColor(WHITE);
				blueButton->getRenderer()->setBackgroundColor(WHITE);
				yellowButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				redButton->getRenderer()->setBackgroundColor(RED);

				counter++;
			}
			else if (ran_vec[counter] == 3) { //yellow
				greenButton->getRenderer()->setBackgroundColor(WHITE);
				redButton->getRenderer()->setBackgroundColor(WHITE);
				blueButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				yellowButton->getRenderer()->setBackgroundColor(YELLOW);

				counter++;
			}
			else if (ran_vec[counter] == 4) { //blue
				greenButton->getRenderer()->setBackgroundColor(WHITE);
				redButton->getRenderer()->setBackgroundColor(WHITE);
				yellowButton->getRenderer()->setBackgroundColor(WHITE);
				sf::sleep(sf::milliseconds(2000)); //pause for 0.5 seconds
				blueButton->getRenderer()->setBackgroundColor(BLUE);
				counter++;
			} //if else end

		}

		if (click == 4)
		{
			cout << "Click counter: " << click << endl;
			click = 0;
			cout << "Let's check your sequence..." << endl;
			//disable buttons
			greenButton->setEnabled(false);
			blueButton->setEnabled(false);
			redButton->setEnabled(false);
			yellowButton->setEnabled(false);
			// check if the sequence is right
			if (ran_vec == clicked_vec) { // if true
				
				buffer6.loadFromFile(music[5]);
				sound.setBuffer(buffer6);
				sound.play();
				sf::sleep(sf::milliseconds(2000));
				sound.stop();

				cout << "Congrats" << endl;
				msgTextArea->setText("Congrats");
		
				counter = 0;
				gameStart = false;
				
				/*exit(EXIT_SUCCESS);*/
			}
			else {
					msgTextArea->setText("beep");
					buffer5.loadFromFile(music[4]);
					sound.setBuffer(buffer5);
					sound.play();
					sf::sleep(sf::milliseconds(1000));
					sound.stop();
					click = 0;
					clicked_vec.clear();
				char a;
				cout << "Wrong! do you want to start over?(y for yes / q for quit)" << endl;
				cin >> a;
				if (a == 'q') {
					
					exit(EXIT_FAILURE);
				}
				else if(a=='y')
				{
					clicked_vec.clear();
					click = 0;
					break;
				} //if else end

			} //if else end

		}  //if end (click)

		sf::Event event;
		//handle window close event
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} // Check for mouse button press event
			else if (event.type == sf::Event::MouseButtonPressed) {
				// Check if mouse position is inside the bounds of the button	
				auto widget = gui.getWidgetBelowMouseCursor(sf::Mouse::getPosition(window));
				cout << "Clicked widget: " << widget->getWidgetName() << endl;
				if (widget == startButton) { //if click start button
					startButton->setEnabled(false);
					gameStart = true;

					//generate random number and save to vector
					int ran_num = 0;

					srand(std::time(0));
					for (int i = 0; i < 4; i++) {
						ran_num = (rand() % 4) + 1;
						ran_vec.push_back(ran_num);
						cout << ran_vec[i] << endl;
					} //for end

					cout << "Random Number Generated. Please Click any buttons" << endl;
					msgTextArea->setText("Random Number Generated.\n");

					cout << "Starting the new game now" << endl;
					msgTextArea->setText("Starting the new game now\n");

					break;
				}
				else if (widget == greenButton) {
					click++;
					buffer1.loadFromFile(music[0]);
					sound.setBuffer(buffer1);
					sound.play();
					sf::sleep(sf::milliseconds(1000));
					sound.stop();

					msgTextArea->setText("You Clicked Green Button\n");
					clicked_vec.push_back(1);
					break;
				}
				else if (widget == redButton) {
					click++;
					buffer2.loadFromFile(music[1]);
					sound.setBuffer(buffer2);
					sound.play();
					sf::sleep(sf::milliseconds(1000));
					sound.stop();

					msgTextArea->setText("You Clicked Red Button\n");
					clicked_vec.push_back(2);
					break;
				}
				else if (widget == yellowButton) {
					click++;
					buffer3.loadFromFile(music[2]);
					sound.setBuffer(buffer3);
					sound.play();
					sf::sleep(sf::milliseconds(1000));
					sound.stop();

					msgTextArea->setText("You Clicked Yellow Button\n");
					clicked_vec.push_back(3);
					break;
				}
				else if (widget == blueButton) {
					click++;
					buffer4.loadFromFile(music[3]);
					sound.setBuffer(buffer4);
					sound.play();
					sf::sleep(sf::milliseconds(1000));
					sound.stop();

					msgTextArea->setText("You Clicked Blue Button\n");
					clicked_vec.push_back(4);
					break;
				}
				
			}  //if end (MouseButtonPressed)
			break;
		} //while end (event)

	//display
		window.clear(WHITE);
		gui.draw();
		window.display();

	} //while end (window.isOpen)

	return 0;
}
