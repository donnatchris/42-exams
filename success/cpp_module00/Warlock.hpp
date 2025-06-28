#pragma once

#include <string>
#include <iostream>
#include <map>

class Warlock
{
	private:
	
		std::string _name;
		std::string _title;

		Warlock();

	public:

		Warlock(const std::string & name, const std::string & title);
		~Warlock();

		const std::string & getName() const;
		const std::string & getTitle() const;
		void setTitle(const std::string & title);
		void introduce() const;

};