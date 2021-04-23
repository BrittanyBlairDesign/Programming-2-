/*

SPECIFICATION A:
NAME: Reference Counted Data
PURPOSE: A class that wraps a value and counts the number of pointers accessing the data.
DETAILS:
- Implement this as a class.
- Store a value of some data type (we'll refer to it as T).
- Functions:
	- ctor(T value)
		- value: the value to store and protect
		- SIDE EFFECT: initialize the reference count to zero.
	- T* GetPointer()
		- SIDE EFFECT: Increment the reference count.
		- RETURN: a pointer to the data.
	- void ReleasePointer()
		- SIDE EFFECT: Decrement the reference count.
	- unsigned int GetReferenceCount()
		- RETURN: The current reference count value.


TASK 1:
- In RefCountedData.h, write a macro to make it possible to generate an implementation of Specification A for some specific data type T.
- There should be only one parameter: the data type used to replace T.
- The generated class must have a unique identifier that incorporates the identifier passed in.
EXAMPLE: GENERATE_REF_COUNTED(int) generates RefCounted_int which stores an int as the ref-counted data.
THIS TASK IS DONE WHEN: I can generate classes to store and ref-count any data types I choose, such as int, bool, or Foo.


TASK 2:
- In RefCountedData.h, write a class template to make it possible to generate an implementation of Specification A for some specific data type T.
- Do not use 'T' as the template parameter name; use a more meaningful identifier.
EXAMPLE: RefCounted<int> stores an int as the ref-counted data.
THIS TASK IS DONE WHEN: I can generate classes to store and ref-count any data types I choose, such as int, bool or Foo.


TASK 3:
- In Game.h, implement the functions Game::Save and Game::Load.
- The Save function should write actor states to a file, and the Load function should restore those actor states from the file.
- Program the 's' key to call the Save function.
- Program the 'l' key to call the Load function.
THIS TASK IS DONE WHEN: When I start the game, save, quit, and load the game, the actors will be restored to when I saved.


SPECIFICATION B:
NAME: Actor Behavior
PURPOSE: To implement injectable behavior into the Actor class.
DETAILS:
- Inherit from the Actor class (Game.h) and add the functionality in this specification.
- We will use the word 'behavior' to describe a function with this signature: void(Actor*, Game*)
- Functions:
	- ctor(size_t x, size_t y, Direction direction, Actor::Color color, behavior)
		- x: the horizontal position of the actor
		- y: the vertical position of the actor
		- direction: the direction of the actor
		- color: the color of the actor
		- behavior: a function that will execute once per frame for this actor
	- void Update(Game* pGame)
		- pGame: a pointer to the Game instance that is currently running.
		- SIDE EFFECT: This executes the behavior, passing in this actor and pGame.

TASK 4:
- In Game.h, implement specification B as a subclass of Actor.
- Modify the Game class as needed to also do the following.
- In one actor of the game, inject this behavior: the actor moves in a random direction each frame.
- In the other actor of the game, inject this behavior: the actor turns around in place.
- Test both actor behaviors!
THIS TASK IS DONE WHEN: I can play the game and both actors work as described.

*/