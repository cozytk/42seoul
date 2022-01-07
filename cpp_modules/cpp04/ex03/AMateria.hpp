#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include <iostream>
class AMateria;
#include "ICharacter.hpp"

class AMateria
{
	private:
		std::string _type;
		unsigned int _xp;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& obj);

		std::string const & getType() const;
		unsigned int getXP() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
