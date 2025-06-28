#pragma once
#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:

		std::map<std::string, ASpell*> _spellMap;

	public:

		SpellBook();
		~SpellBook();

		void learnSpell(ASpell * spellPtr);
		void forgetSpell(const std::string & spellName);
		ASpell * createSpell(const std::string & spellName);

};