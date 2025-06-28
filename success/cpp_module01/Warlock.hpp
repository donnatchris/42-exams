#pragma once
#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class Warlock
{
	private:

		std::string _name;
		std::string _title;
		std::map<std::string, ASpell*> _spellMap;

		Warlock();

	public:

		Warlock(const std::string & name, const std::string & title);
		~Warlock();

		const std::string & getName() const;
		const std::string & getTitle() const;
		void setTitle(const std::string & title);
		void introduce() const;

		void learnSpell(ASpell * spellPtr);
		void forgetSpell(const std::string & spellName);
		void launchSpell(const std::string & spellName, const ATarget & target);
};