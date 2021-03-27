#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include <iostream>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int num;
		AMateria *sources[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& obj);
		virtual ~MateriaSource();

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

		int getNum() const;
		AMateria *getSource(int i) const;
};

#endif
