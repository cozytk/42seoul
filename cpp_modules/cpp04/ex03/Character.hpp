#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>

# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria *ivt[4];
		std::string name;
		int _idx;
	public:
		Character();
		Character(const std::string _name);
		Character(const Character& copy);
		Character& operator=(const Character& obj);
		virtual ~Character();

		std::string const & getName() const;
		int getIdx() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
