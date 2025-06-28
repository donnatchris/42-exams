#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() :
	_targetMap()
{

}

TargetGenerator::~TargetGenerator()
{

}

void TargetGenerator::learnTargetType(ATarget * targetPtr)
{
	if (!targetPtr || _targetMap.find(targetPtr->getType()) != _targetMap.end())
		return ;
	_targetMap[targetPtr->getType()] = targetPtr->clone();
}

void TargetGenerator::forgetTargetType(const std::string & targetType)
{
	if (_targetMap.find(targetType) == _targetMap.end())
		return ;
	delete _targetMap[targetType];
	_targetMap.erase(targetType);
}

ATarget* TargetGenerator::createTarget(const std::string & targetType)
{
	if (_targetMap.find(targetType) == _targetMap.end())
		return (NULL);
	return (_targetMap[targetType]->clone());
	
}
