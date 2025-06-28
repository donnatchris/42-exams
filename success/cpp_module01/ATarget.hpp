#pragma once
#include <string>
#include <iostream>

class ASpell;

class ATarget
{
	protected:

		std::string _type;

		ATarget();

	public:

		ATarget(const std::string & type);
		virtual ~ATarget();

		const std::string & getType() const;
		void getHitBySpell(const ASpell & spell) const;
		virtual ATarget * clone() = 0;

};