//---------------------------------------------------------
/**
//    @file		isoTriangle.cpp
//    @brief	Implementation file for class isoTriangle
//    @author	Nicolò Busi S5209833
*/
//---------------------------------------------------------


#include "isoTriangle.h"


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



//////////////////////////////////////////////////////////////////////////////
// fpi
// memory debug, place after includes

#ifdef DBGMEM_CRT
#undef new
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif // DBGMEM_CRT


/************************** GLOBAL FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Print operator
ostream& operator << (ostream& o, isoTriangle& X)
{

	return o;
}

///////////////////////////////////////////////////////////////////////////
istream& operator >> (istream& i, isoTriangle& X)
{

	return i;
}

/************************** MEMBER FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Default Constructor

/// @brief default constructor 
isoTriangle::isoTriangle()
{
	cout << "isoTriangle - Constructor - Default" << endl;
	Init();

}

///////////////////////////////////////////////////////////////////////////
// Constructor

/// @brief constructor which also check if the value entered is >= 0
/// @param dH diagH of the isoTriangle
/// @param dV diagV of the isoTriangle
isoTriangle::isoTriangle(float b, float h) {

	base = 0;
	height = 0;

	cout << "isoTriangle - Constructor" << endl;

	if (b <= 0)
		ErrorMessage("WARNING: isoTriangle - constructor : base should be > 0");
	else
		base = b;

	if (h <= 0)
		ErrorMessage("WARNING: isoTriangle - constructor : height should be > 0");
	else
		height = h;

}


///////////////////////////////////////////////////////////////////////////
// Copy Constructor

/// @brief copy constructor 
/// @param reference to the object that should be copied 
isoTriangle::isoTriangle(isoTriangle& X)
{
	cout << "isoTriangle - Copy Constructor" << endl;
	Init(X);
}

///////////////////////////////////////////////////////////////////////////
// Destructor

/// @brief destructor 
isoTriangle::~isoTriangle()
{
	cout << "isoTriangle - Destructor" << endl;
	Reset();
}

///////////////////////////////////////////////////////////////////////////
// Init default initializer

/// @brief init default initializer of the object
void isoTriangle::Init()
{
	base = 0;
	height = 0;
}

///////////////////////////////////////////////////////////////////////////
// Init copy initializer

/// @brief init copy initializer of the object
/// @param reference to the object that should be copied 
void isoTriangle::Init(isoTriangle& X)
{
	Reset();
	base = X.base;
	height = X.height;
}

///////////////////////////////////////////////////////////////////////////
// Object eraser

/// @brief object's eraser
void isoTriangle::Reset()
{
	base = 0;
	height = 0;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of assignment operator

/// @brief overload of operator = 
/// @param reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
isoTriangle& isoTriangle::operator =(isoTriangle& X)
{
	Reset();
	Init(X);
	return *this;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of comparison operator

/// @brief overload of operator == 
/// @param reference to the object on the right side of the operator 
/// @return true if the two objects have the same diagH and the same diagV
bool isoTriangle::operator ==(isoTriangle& X)
{
	if (X.base == base && X.height == height)
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////
// Error messaging routine

/// @brief warning routine
/// @param warning string printed on the screen

void isoTriangle::ErrorMessage(const char* string)
{
	printf("%s\n", string);
}

///////////////////////////////////////////////////////////////////////////
// Debug routine

/// @brief It shows the programm status
void isoTriangle::Dump()
{
	cout << "base = " << base << endl;
	cout << "height = " << height << endl;
	cout << "side = " << Side(base, height) << endl;
}

/************************** ACCESS FUNCTIONS ******************/

/// @brief set the side of the object
/// @param dH diagH
/// @param dV diagV
/// @return side
double isoTriangle::Side(float b, float h) {

	return sqrt(pow(b / 2, 2) + pow(h, 2));

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set diagH and diagV of the object
/// @param dH diagH 
/// @param dV diagV
void isoTriangle::SetDim(float b, float h) {

	SetBase(b);
	SetHeight(h);

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set diagH of the object
/// @param dV diagH
void isoTriangle::SetBase(float b) {

	if (b < 0) {
		ErrorMessage("isoTriangle - SetBase: base should be > 0");
		return;
	}

	base = b;

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set diagV of the object
/// @param dV diagV
void isoTriangle::SetHeight(float h) {

	if (h < 0) {
		ErrorMessage("isoTriangle - SetHeight: height should be > 0");
		return;
	}

	height = h;
}
///////////////////////////////////////////////////////////////////////////
// 


/// @brief get diagH and diagVof the object
/// @param dH diagH
/// @param dV diagV
void isoTriangle::GetDim(float& b, float& h) {

	b = base;
	h = height;

	return;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get diagH of the object
/// @return diagH 
float isoTriangle::GetBase() {
	return base;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get diagV of the object
/// @return diagV 
float isoTriangle::GetHeight() {
	return height;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the side of the object
/// @return side 
float isoTriangle::GetSide() {
	return Side(base, height);
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the area of the object
/// @return area of the isoTriangle
float isoTriangle::GetArea() {
	return Area();
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the perimeter of the object
/// @return perimeter of the isoTriangle
float isoTriangle::GetPerimeter() {
	return Perimeter();
}
///////////////////////////////////////////////////////////////////////////
// 

float isoTriangle::Area() {
	return (base * height) / 2;
}
float isoTriangle::Perimeter() {
	return Side(base, height) * 2 + base;
}

void isoTriangle::Draw() {
	cout << "This is a isoTriangle with this features:" << endl << "1) base = " << base << endl << "2) height = " << height << endl
		<< "3) side = " << Side(base, height) << endl << "4) perimeter = " << Perimeter() << endl << "5) area = " << Area() << endl << endl << endl;
}