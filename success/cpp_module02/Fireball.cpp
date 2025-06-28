#include "Fireball.hpp"
#include "ASpell.hpp"

Fireball::Fireball() :
	ASpell("Fireball", "burnt to a crisp")
{

}

Fireball::~Fireball()
{

}

ASpell * Fireball::clone()
{
	return (new Fireball(*this));
}
