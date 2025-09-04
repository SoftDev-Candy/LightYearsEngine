#include<iostream>
#include "framework/Application.h"

namespace ly
{
	
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
		std::cout << "Ticking at frameRate : " << 1.f / deltaTime << std::endl;
	}

	Application::Application() // constructor
		: mWindow{ sf::VideoMode(500,968) , "Light Years" },
		mTargetFrameRate{ 60.f },
		mTickClock{}
	{
	
	//Donot remove brackets they for the constructur

	}
	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.0f / mTargetFrameRate; 
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
			accumulatedTime += mTickClock.restart().asSeconds();

			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}

		}
	}

	void Application::Render()
	{
		sf::CircleShape rect{ 50 };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);

		mWindow.draw(rect);
	}

	void Application::Tick(float deltaTime)
	{
	}

	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();

		mWindow.display();
	}



}

