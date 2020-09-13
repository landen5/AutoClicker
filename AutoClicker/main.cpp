#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>

//program adds 1 after every click
int i = { 0 };

bool isClicking = false;

void makeWindowOnTop(sf::RenderWindow& window)
{
	HWND hwnd = window.getSystemHandle();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}

void doClick(sf::RenderWindow& window) 
{


	//assign class font to var
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Unable to load font" << "\n";
	}
	//assign class text to var
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(24);

	if (isClicking == true)
	{
		//clear the screen with a black color
		window.clear(sf::Color::Black);


		//click left mouse button ( ******OFF BY DEFAULT******) 
		//mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		//std::cout << "Clicked mouse" << i << "\n";


		i++;
		//sleep for specified milliseconds (1000 ms = 1s)
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
		//convert i to string so the # of clicks can be displayed as text
		text.setString(std::to_string(i));
		//draw to the screen
		window.draw(text);
		//update the screen
		window.display();
	}
		

}
 
int main() 
{
	//create the window
	sf::RenderWindow window(sf::VideoMode(200, 400), "AutoClicker", sf::Style::Close);
	
	//position of window relative to desktop (like offset kinda)
	window.setPosition(sf::Vector2i(10, 10));
	//as long as window is open, loop (run) the program (just remember that this loops through whatever functions are called in it, so I don't need loops inside of loops)
	while (window.isOpen()) 
	{
		//check for all of window's events that were triggered since the last interation of the loop
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Middle)
				{
					std::cout << "Middle mouse button" << "\n";
					isClicking = !isClicking;
				}
			}
		}
		//window.clear(sf::Color::Black);

		//draw everything here
		//window.draw();
		doClick(window);
		makeWindowOnTop(window);

		//end the current frame
		//window.display();
	}
	return 0;
}

