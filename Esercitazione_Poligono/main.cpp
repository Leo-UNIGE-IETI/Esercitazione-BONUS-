//---------------------------------------------------------
/**
//    @file		main.cpp
//    @brief	Stressing test for all classes
//    @author	Nicolo' Busi	S5209833 & Leonardo Motta S4952213
*/
//---------------------------------------------------------

#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "polygon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "isoTriangle.h"

int main() {

	/**
	@brief Evocating the costructors/destructors & simulations of graphics interfaces
	*/
	rectangle rectA(8, 16);
	cout << endl;
	rectA.Draw();
	cout << endl << endl;

	rectangle rectB(-2, 0);
	cout << endl;
	rectB.Draw();
	cout << endl << endl;

	rhombus rhomA(8, 16);
	cout << endl;
	rhomA.Draw();
	cout << endl << endl;

	rhombus rhomB(-2, 0);
	cout << endl;
	rhomB.Draw();
	cout << endl << endl;

	isoTriangle isoA(8, 16);
	cout << endl;
	isoA.Draw();
	cout << endl << endl;

	isoTriangle isoB(2, 0);
	cout << endl;
	isoB.Draw();
	cout << endl << endl;

	return 0;
}