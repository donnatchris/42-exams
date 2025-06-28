#include "SpellBook.hpp"

SpellBook::SpellBook() :
	_spellMap()
{

}

SpellBook::~SpellBook()
{

}


void SpellBook::learnSpell(ASpell * spellPtr)
{
	if (!spellPtr || _spellMap.find(spellPtr->getName()) != _spellMap.end())
		return ;
	_spellMap[spellPtr->getName()] = spellPtr->clone();
}

void SpellBook::forgetSpell(const std::string & spellName)
{
	if (_spellMap.find(spellName) == _spellMap.end())
		return ;
	delete _spellMap[spellName];
	_spellMap.erase(spellName);
}

ASpell * SpellBook::createSpell(const std::string & spellName)
{
	if (_spellMap.find(spellName) == _spellMap.end())
		return (NULL);
	return (_spellMap[spellName]->clone());
}
