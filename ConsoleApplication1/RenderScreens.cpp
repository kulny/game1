#include "stdafx.h"
#include "RenderScreens.h"
#include <Windows.h>
#include <iostream>



RenderScreens::RenderScreens()
{
}


RenderScreens::~RenderScreens()
{
}

void RenderScreens::RenderBase()
{
	system("cls");
	std::cout << "Resource: ";// << GetResource1()
	// TODO: define production class and make Getters for resource var
	std::cout << std::endl;
	std::cout << std::endl; //<< GetCurrentTick % 30;
	//TODO: define GetCurrentTick in update class
}
