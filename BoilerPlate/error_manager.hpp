#pragma once
#include <iostream>
struct error_manager
{
public:
	error_manager();
	~error_manager();

	int show_errors(std::string, std::string, std::string, std::string);
};

