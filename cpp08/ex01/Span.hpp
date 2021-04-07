#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	private:
		unsigned int        _n;
		std::vector<int>    *_v;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& obj);
		virtual ~Span();
		void                addNumber(int n);
		void				addNumbers(int begin, int end);
		unsigned int        longestSpan();
		unsigned int        shortestSpan();
		int                 getSize() const;
		std::vector<int>	getVect() const;
		class NoSpaceException : public std::exception
		{
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
				virtual const char* what() const throw();
		};
};

#endif
