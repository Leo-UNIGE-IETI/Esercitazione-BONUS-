//---------------------------------------------------------
/**
//    @file		isoTriangle.h
//    @brief	Header file for CLASS isoTriangle
//    @author	Nicol� Busi	S5209833
*/
//---------------------------------------------------------

#ifndef isoTriangle__DEF
#define isoTriangle__DEF

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "polygon.h"
using namespace std;
/**
@class isoTriangle
@brief isoTriangle is a poligonal figure with equal sides and perpendicolar diagonals

*/
class isoTriangle :public Polygon
{
	///////////////////////////// PRIVATE   Segment
private:
	float base;
	float height;

	double Side(float b, float h);

	///////////////////////////// PROTECTED Segment
protected:

	///////////////////////////// PUBLIC    Segment
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{

	/// Default constructor
	isoTriangle();
	/// Constructor
	isoTriangle(float b, float h);
	/// Copy constructor
	isoTriangle(isoTriangle& X);
	/// Destructor
	virtual ~isoTriangle();
	//@}

	/// @name OPERATORS
	/// @{

	/// Assignment overloading
	isoTriangle& operator = (isoTriangle& X);
	/// Comparison overloading
	bool	 operator ==(isoTriangle& X);
	/// Print operator
	friend ostream& operator << (ostream& o, isoTriangle& X);
	/// Input operator
	friend istream& operator >> (istream& i, isoTriangle& X);
	//@}

	/// @name BASIC HANDLING
	/// @{

	/// Default initialization
	void Init();
	/// Copy initialization
	void Init(isoTriangle& X);
	/// Object erasure
	void Reset();
	/// Outputs internal errors
	void ErrorMessage(const char* string);
	//@}

	// ACCESS FUNCTIONS
	void SetDim(float b, float h);
	void SetBase(float b);
	void SetHeight(float h);

	void GetDim(float& b, float& h);
	float GetBase();
	float GetHeight();
	float GetSide();
	float GetArea();
	float GetPerimeter();

	virtual float Area();
	virtual float Perimeter();

	virtual void Draw();

	/// @name DEBUG and SERIALIZATION
	/// @{

	/// Object printout for diagnostic
	void Dump();
	//@}
};

#endif
