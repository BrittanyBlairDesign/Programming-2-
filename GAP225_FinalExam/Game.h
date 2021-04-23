#pragma once

#include <array>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include <Windows.h>

template<typename ComponentType>
struct Vector2
{
	ComponentType m_x;
	ComponentType m_y;
};

enum class Direction : unsigned char
{
	kNorth,
	kSouth,
	kEast,
	kWest,
	kCount
};

class Actor
{
public:
	using Color = WORD;

private:
	Vector2<size_t> m_position;
	Direction m_direction;
	Color m_color;

public:
	Actor(size_t x, size_t y, Direction direction, Color color)
		: m_position{x, y}
		, m_direction{ direction }
		, m_color{color}
	{}

	Vector2<size_t>& GetPosition() { return m_position; }

	void SetDirection(Direction direction) { m_direction = direction; }

	Color& GetColor() { return m_color; }

	char GetAppearance()
	{
		switch (m_direction)
		{
		case Direction::kNorth: return '^';
		case Direction::kSouth: return 'v';
		case Direction::kEast: return '>';
		case Direction::kWest: return '<';
		}
	}
};

///////////////////////////////
/// TO DO : Add Actor subclass
///////////////////////////////

// Behavior Interface.
class ActorBehavior : public Actor
{
public:
	// Behavior constructor, takes in all the same parameters as an actor.
	ActorBehavior(size_t x, size_t y, Direction direction, Actor::Color color)
		: Actor(x, y, direction, color)
	{}

	// Executes the behavior, passing in this actor and pGame
	virtual void Update(Game* pGame) = 0;
};

// Move behavior handles an actor that moves in a random direction every turn.
class MoveBehavior : public ActorBehavior
{
public:
	MoveBehavior(size_t x, size_t y, Direction direction, Actor::Color color)
		: ActorBehavior(x, y, direction, color)
	{}

	//void Update(Game* pGame) override
	//{
	//
	//}

};

class Game
{
	using ConsoleHandle = HANDLE;
	using Color = WORD;

private:
	static constexpr unsigned kActorCount = 2;

	size_t m_width;
	size_t m_height;
	std::vector<Actor> m_actors;
	ConsoleHandle m_handle;
	Color m_defaultColor;
	bool m_quit;

public:
	Game(size_t w, size_t h)
		: m_width{w}
		, m_height{h}
		, m_actors{}
		, m_handle{GetStdHandle(STD_OUTPUT_HANDLE)}
		, m_defaultColor{0x07}
		, m_quit{ false }
	{
		srand((unsigned)time(nullptr));
		RandomizeActors();
	}

	size_t GetWidth() const { return m_width; }
	size_t GetHeight() const { return m_height; }

	void RandomizeActors()
	{
		while (m_actors.size() < kActorCount)
		{
			size_t randX = rand() % m_width;
			size_t randY = rand() % m_height;
			Direction randDirection = (Direction)(rand() % (int)Direction::kCount);
			Color randColor = rand() % 0xff;
			m_actors.emplace_back(randX, randY, randDirection, randColor);
		}
	}

	void RunGameLoop()
	{
		while (!m_quit)
		{
			system("cls");
			Draw();
			Update();
		}
	}

	void LoadActors()
	{
		// TODO

		// Open the file.
		std::ifstream SaveFile{ "save.dat", std::ios::out };

		if (SaveFile.is_open())
		{
			// Saving Actor information to a file.
			for (size_t i = 0; i < m_actors.size(); ++i)
			{
				// Constructor Variables
				int x, y; 
				char arrow;
				Direction direction;
				Color color;

				// Set variables based on the file
				SaveFile >>x >> y >> arrow >> color;

				// Determine Direction.
				switch (arrow)
				{
				case '^': direction = Direction::kNorth; break;
				case 'v': direction = Direction::kSouth; break;
				case '>': direction = Direction::kEast; break;
				case '<': direction = Direction::kWest; break;
				}
				Actor newActor(x, y, direction, color);

				m_actors[i] = newActor;
			}
		}
		else
		{
			std::cout << "save.txt cannot be opened.";
		}

		//Close the file.
		SaveFile.close();
	}

	void SaveActors()
	{
		// Open the file.
		std::ofstream SaveFile{ "save.dat", std::ios::out };

		if (SaveFile.is_open())
		{
			// Saving Actor information to a file.
			for (size_t i = 0; i < m_actors.size(); ++i)
			{
				// Save X and Y.
				Vector2 position = m_actors[i].GetPosition();
				SaveFile << position.m_x << " ";
				SaveFile << position.m_y << " ";
				
				// Save appearance.
				SaveFile << m_actors[i].GetAppearance();

				// Save the Color.
				SaveFile << m_actors[i].GetColor() << " ";

				// newline for the next actor.
				SaveFile << std::endl;
			}
		}
		else
		{
			std::cout << "save.txt cannot be opened.";
		}

		//Close the file.
		SaveFile.close();
	}

private:
	void Draw()
	{
		for (size_t y = 0; y < m_height; ++y)
		{
			for (size_t x = 0; x < m_width; ++x)
			{
				bool actorIsHere = false;
				for (Actor& actor : m_actors)
				{
					if (x == actor.GetPosition().m_x && y == actor.GetPosition().m_y)
					{
						actorIsHere = true;
						SetConsoleTextAttribute(m_handle, actor.GetColor());
						std::cout << actor.GetAppearance();
						SetConsoleTextAttribute(m_handle, m_defaultColor);
						break;
					}
				}
				
				if (!actorIsHere)
				{
					std::cout << '.';
				}
				
			}
			std::cout << std::endl;
		}
	}

	void Update()
	{
		switch (_getch())
		{
		case 'q': m_quit = true; break;
		case 's': SaveActors(); break;
		case 'l': LoadActors(); break;
		}
	}
};