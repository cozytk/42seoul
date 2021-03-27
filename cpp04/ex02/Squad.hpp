#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <string>
# include <iostream>

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	private:
		int n;
		ISpaceMarine** units;
	public:
		Squad();
		Squad(const Squad& copy);
		Squad& operator=(const Squad& obj);
		virtual ~Squad();

		int getCount() const;
		ISpaceMarine* getUnit(int _n) const;
		int push(ISpaceMarine* _unit);
};

#endif
