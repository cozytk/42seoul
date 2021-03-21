#include "Brain.hpp"

const std::string Brain::identify() const
{
	std::stringstream addr;

	addr << this;
	return (addr.str());
}
