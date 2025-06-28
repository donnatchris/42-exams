#pragma once
#include <string>
#include <iostream>
#include "ATarget.hpp"

class ASpell;

class BrickWall: public ATarget
{
	public:
		
		BrickWall();
		virtual ~BrickWall();

		virtual ATarget * clone();

};