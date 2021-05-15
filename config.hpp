#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>

/*
 * tree 형태 
 * _ 붙은 건 임시용 이름, 이후에 이름 바꿔야 함
 * */

namespace
{

	/*
	 * server {
	 *    new {
	 *      giv a;
	 *    }
	 * }
	 * 일 경우 config["server"]["new"]["giv"]로 사용 가능하게

	class config
	{
	private:
		//map<> new;
	
		// \" 같은 건 어떻게 처리할 건지
		enum _deep
		{
			syntax,
			string
		}

		int _bracket;	
		
	public:
		config();
		config(config const &x);
		~config();

		void read(std::string const &path);
	}
}

#endif
