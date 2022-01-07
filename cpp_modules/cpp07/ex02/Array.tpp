#ifndef ARRAY_TPP
 #define ARRAY_TPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T   *_arr;
		int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array & arr);
		virtual ~Array();
		Array   &operator=(const Array & arr);
		T		&operator[](int i) const;
		int	size(void) const;
		void	print();
		class OutOfLimitsException : public std::exception
		{
			public:
				OutOfLimitsException() : m_message("Array Exception: Out of limits.") {}
				virtual ~OutOfLimitsException() throw() {return ;}
				virtual const char* what() const throw() {return m_message.c_str();}

			private:
				std::string const	m_message;
		};
};

#endif