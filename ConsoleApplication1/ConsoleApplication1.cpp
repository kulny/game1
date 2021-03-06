#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>


using namespace std;

// using large number types for cases where the game goes plays for a while; int could eventually be too small

long resource = 50;
bool outOfRes;
double resIncrsRt = 1; // increase rate
double resIncrsMod = 1; // increase rate modifier
long currentPrice = 5;
int prodThreshhold = 0; // this variable is used to keep track of when to add resources, once per second. Necessary because asynchronicity is hard See production()
string warningStrings;
bool factoryBought;


int tick;
bool cd = false;

// TODO: build randomly oriented array of 'units' to buy or upgrade?
// TODO: add additional actions like the upgrade such as sabotage? only after implementing opponent production

// TODO: production doesn't start until after first buy, for factory thing?

int ResTest(int n) {
	if (resource - n < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CallResError(int errNum) {
	switch (errNum)
	{
	case 1: warningStrings = "You cannot purchase that. Not enough resources."; // not enough resources error
		break;

	}
}

void Render() { // writes to screen
	system("cls");
	cout << "Resource: " << resource << "                         " << "Current Upgrade Cost: " << currentPrice << endl;
	cout << endl;
	cout << "Press Y to upgrade! Be careful not to lose all your resources!" << endl << endl;
	cout << warningStrings;
	cout << endl << tick % 30;
}
void Production() { // resource production
	if (factoryBought == true)
	{
		if (prodThreshhold == 30)
		{
			resource = resource + resIncrsRt * resIncrsMod;
			prodThreshhold = 0;
		}
		prodThreshhold += 1;
	}


}

void IncrsPrice() { // formula for increase in price
	currentPrice += (currentPrice / 2) + (pow(resIncrsRt, 1.1) / 3);
}
void IncrsResRt() { // formula for increase rate
	resIncrsRt += resIncrsRt * resIncrsMod;
	resIncrsMod += .1;
}

void Upgrade() { // logic upon buying
	resource = resource - currentPrice;
	IncrsPrice();
	IncrsResRt();


}

void Update() { // activates every frame 
	Production();
	if (resource < 0)
	{
		outOfRes = true;
	}

	tick++;
	if (tick / 15 > 1)
	{
		cd = false;
	}

	// TODO: add opponent logic with competing resources?
}
// TODO: figure out enums so I can have FactoryBoughtTrue as a viable input

void Input() {
	if (GetAsyncKeyState('Y') != 0 & cd == false) {
		if (ResTest(currentPrice) == 0)
		{
			Upgrade();
		}
		else
		{
			CallResError(1);
		}
		cd = true;
	}
	if (GetAsyncKeyState('B') != 0) {
		//increase production code here
	}
	{

	}

}

int main()
{
	outOfRes = false;

	while (!outOfRes) // TODO set while loop true, when outofres is set true call an EndGame() method
	{


		Render();
		Update();
		Input();

		Sleep(16); // sleep for 1000/60 ms for cheap 60fps refresh; not dynamic for lag
		
		// TODO: key press to build factory, factory flags production start, render building bar in Render() using tick count? or something
	}

	return 0;
}

