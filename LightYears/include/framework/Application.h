#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

namespace ly
{
	class Application 
	{
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		void RenderInternal();
	public:
		void TickInternal(float deltaTime);
		Application();
		void Run();

		virtual void Render();
		virtual void Tick(float deltaTime);


	};
}



#endif APPLICATION_H