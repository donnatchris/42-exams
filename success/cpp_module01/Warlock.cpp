#include "Warlock.hpp"

Warlock::Warlock(const std::string & name, const std::string & title) :
	_name(name),
	_title(title),
	_spellMap()
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const
{
	return (_name);
}

const std::string & Warlock::getTitle() const
{
	return (_title);
}

void Warlock::setTitle(const std::string & title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell * spellPtr)
{
	if (!spellPtr || _spellMap.find(spellPtr->getName()) != _spellMap.end())
		return ;
	_spellMap[spellPtr->getName()] = spellPtr->clone();
}

void Warlock::forgetSpell(const std::string & spellName)
{
	if (_spellMap.find(spellName) == _spellMap.end())
		return ;
	delete _spellMap[spellName];
	_spellMap.erase(spellName);
}

void Warlock::launchSpell(const std::string & spellName, const ATarget & target)
{
	if (_spellMap.find(spellName) == _spellMap.end())
		return ;
	_spellMap[spellName]->launch(target);
}
