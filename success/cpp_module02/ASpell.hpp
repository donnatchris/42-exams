#pragma once
#include <string>
#include <iostream>

class ATarget;

class ASpell
{
	protected:

		std::string _name;
		std::string _effects;

		ASpell();

	public:

		ASpell(const std::string & name, const std::string & effects);
		virtual ~ASpell();

		const std::string & getName() const;
		const std::string & getEffects() const;
		void launch(const ATarget & target) const;
		virtual ASpell * clone() = 0;

};