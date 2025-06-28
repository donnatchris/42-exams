#pragma once
#include <string>
#include <iostream>
#include "ASpell.hpp"

class ATarget;

class Fwoosh: public ASpell
{
	public:

		Fwoosh();
		virtual ~Fwoosh();
		virtual ASpell * clone();
};