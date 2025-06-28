#pragma once
#include <string>
#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
	private:

		std::map<std::string, ATarget*> _targetMap;

	public:

		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget * targetPtr);
		void forgetTargetType(const std::string & targetType);
		ATarget* createTarget(const std::string & targetType);

};