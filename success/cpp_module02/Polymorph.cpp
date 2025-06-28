#include "Polymorph.hpp"
#include "ASpell.hpp"

Polymorph::Polymorph() :
	ASpell("Polymorph", "turned into a critter")
{

}

Polymorph::~Polymorph()
{

}

ASpell * Polymorph::clone()
{
	return (new Polymorph(*this));
}
