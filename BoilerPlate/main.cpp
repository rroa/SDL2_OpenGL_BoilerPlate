#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// C++ STL
#include <cassert>
#include <iostream>
#include <stdlib.h>

// 
#include "App.hpp"
#include "matrix_4.hpp"

const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char* argv[])
{

	Engine::matrix_4 test = Engine::matrix_4(2, 3, 5, 9, 4, 2, 5, 3, 0, 0, 1, 3, 4, 2, 0, 4);
	Engine::matrix_4 mult = Engine::matrix_4(4, 6, 1, 2, 3, 0, 1, 4, 7, 3, 1, 0, 2, 0, 1, 4);

	test = test * mult;

	std::cout << test;

#if _MSC_VER && _DEBUG
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	assert(_CrtCheckMemory());
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Create Game Object
	//
	Engine::App* app = new Engine::App("Boiler Plate!", WIDTH, HEIGHT);

	// Initialize game
	//
	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}

	// Execute game
	//
	app->Execute();

	// Delete game object
	//
	delete app;

	return 0;
}