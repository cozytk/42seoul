#ifndef CPP_HUMAN_HPP
#define CPP_HUMAN_HPP

#include "Brain.hpp"

class Human
{
private:
	const Brain			brain;
public:
	const std::string	identify() const;
	const Brain&		getBrain() const;
};


#endif //CPP_HUMAN_HPP
