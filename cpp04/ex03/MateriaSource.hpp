#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include <iostream>

class MateriaSource
{
	private:
		/* declare member variable */
	public:
		MateriaSource();
		MateriaSource(const std::string& /* parameter */, ...);
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& obj);
		virtual ~MateriaSource();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const MateriaSource& materiaSource);

#endif
