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

	Engine::matrix_4 test = Engine::matrix_4(2,3,5,9,4,2,5,3,0,0,1,3,4,2,0,4);
	Engine::matrix_4 inverse = test.get_invert();
	std::cout << inverse;

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