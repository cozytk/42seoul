#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy {
	private:
		int hp;
		std::string type;
	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(const Enemy& copy);
		virtual ~Enemy();
		Enemy& operator=(const Enemy& obj);
		std::string const getType() const;
		int getHP() const;
		virtual void takeDamage(int damage);
};

#endif
