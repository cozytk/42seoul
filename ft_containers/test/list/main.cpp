#include <List.hpp>
#include <ft_containers.hpp>
#include <Vector.hpp>
#include <vector>
#include <list>
#include <iostream>

template <class T>
void print_list(std::list<T> list)
{
	for (typename std::list<T>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
}
template <class T>
void print_list(ft::list<T> list)
{
	for (typename ft::list<T>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << "ft \n";
}


void assign()
{
	std::list<int> first;
	std::list<int> second;
	ft::list<int> ft_first;
	ft::list<int> ft_second;

	first.assign (7,100);                      // 7 ints with value 100
	ft_first.assign (7,100);                      // 7 ints with value 100

	second.assign (first.begin(),first.end()); // a copy of first
	ft_second.assign (first.begin(),first.end()); // a copy of first

	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array
	ft_first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of first: " << int (first.size()) << " ft\n";
	std::cout << "Size of second: " << int (second.size()) << " ft\n";
	return ;
}

void begin_end()
{
	int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);
	ft::list<int> ftlist (myints,myints+5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it != ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "-> ft";
	std::cout << '\n';

	for (int i=1; i<=5; ++i) mylist.push_back(i);
	for (int i=1; i<=5; ++i) ftlist.push_back(i);

	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';
	std::cout << "ftlist backwards:";
	for (ft::list<int>::reverse_iterator rit=ftlist.rbegin(); rit!=ftlist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << "-> ft";
	std::cout << '\n';

	return ;
}

void clear()
{
	std::list<int> mylist;
	std::list<int>::iterator it;
	ft::list<int> ftlist;
	ft::list<int>::iterator ft;

	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	ftlist.push_back (100);
	ftlist.push_back (200);
	ftlist.push_back (300);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft=ftlist.begin(); ft!=ftlist.end(); ++ft)
		std::cout << ' ' << *ft;
	std::cout << " ft\n";

	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);
	ftlist.clear();
	ftlist.push_back (1101);
	ftlist.push_back (2202);

	print_list(mylist);
	print_list(ftlist);

	return;
}

void constructor()
{
	// constructors used in the same order as described above:
	std::list<int> first;                                // empty list of ints
	std::list<int> second (4,100);                       // four ints with value 100
	std::list<int> third (second.begin(),second.end());  // iterating through second
	std::list<int> fourth (third);                       // a copy of third
	ft::list<int> ft_first;                                // empty list of ints
	ft::list<int> ft_second (4,100);                       // four ints with value 100
	ft::list<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
	ft::list<int> ft_fourth (ft_third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	ft::list<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are: ";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of fifth are: ";
	for (ft::list<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << "-> ft";

	return ;
}

void empty()
{
	std::list<int> mylist;
	ft::list<int> ftlist;
	int sum(0);

	for (int i = 1; i <= 10; ++i) mylist.push_back(i);
	for (int i = 1; i <= 10; ++i) ftlist.push_back(i);

	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}
	std::cout << "total: " << sum << '\n';
	sum = 0;
	while (!ftlist.empty())
	{
		sum += ftlist.front();
		ftlist.pop_front();
	}
	std::cout << "total: " << sum << "-> ft\n";
	return ;
}

void erase()
{
	std::list<int> mylist;
	ft::list<int> ftlist;

	// set some values:
	for (int i = 1; i < 10; ++i) mylist.push_back(i * 10);
	for (int i = 1; i < 10; ++i) ftlist.push_back(i * 10);

	std::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator it2 = mylist.end();
	ft::list<int>::iterator ft = ftlist.begin();
	ft::list<int>::iterator ft2 = ftlist.end();
	print_list(mylist);
	print_list(ftlist);
	it = mylist.erase(it);
	ft = ftlist.erase(ft);
	print_list(mylist);
	print_list(ftlist);
	++it;
	--it2;
	++ft;
	--ft2;
	mylist.erase(it, it2);
	ftlist.erase(ft, ft2);
	if (mylist.empty())
		std::cout << "empty\n";
	else
		print_list(mylist);
	if (ftlist.empty())
		std::cout << "empty ft\n";
	else
		print_list(ftlist);

}//
// Created by Taekyun Kim on 6/10/21.
//
void front_back()
{
	std::list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	// now front equals 77, and back 22

	mylist.front() -= mylist.back();

	std::cout << "mylist.front() is now " << mylist.front() << '\n';

	return ;
}

void insert()
{
	std::list<int> mylist;
	std::list<int>::iterator it;
	ft::list<int> ftlist;
	ft::list<int>::iterator ft;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5
	for (int i=1; i<=5; ++i) ftlist.push_back(i); // 1 2 3 4 5
	it = mylist.begin();
	++it;       // it points now to number 2           ^
	ft = ftlist.begin();
	++ft;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5
	ftlist.insert (ft,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
	ftlist.insert (ft,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^
	--ft;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	ft::vector<int> ftvector (2,30);
	ftlist.insert (ft,ftvector.begin(),ftvector.end());
	// 1 10 20 30 30 20 2 3 4 5
	//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft=ftlist.begin(); ft!=ftlist.end(); ++ft)
		std::cout << ' ' << *ft;
	std::cout << '\n';

	return ;
}
// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void merge()
{
	std::list<double> first, second;
	ft::list<double> ft_first, ft_second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);
	ft_first.push_back (3.1);
	ft_first.push_back (2.2);
	ft_first.push_back (2.9);
	ft_second.push_back (3.7);
	ft_second.push_back (7.1);
	ft_second.push_back (1.4);

	std::cout << "first contains:\n";
	print_list(first);
	print_list(ft_first);
	std::cout << "second contains:\n";
	print_list(second);
	print_list(ft_second);
	first.sort();
	second.sort();
	ft_first.sort();
	ft_second.sort();
	std::cout << "after sort\n";
	print_list(first);
	print_list(ft_first);
	print_list(second);
	print_list(ft_second);

	std::cout << "after merge\n";
	first.merge(second);
	ft_first.merge(ft_second);
	print_list(first);
	print_list(ft_first);
	if (second.empty())
		std::cout << "second is empty\n";
	else
		print_list(second);
	if (ft_second.empty())
		std::cout << "second is empty ft\n";
	else
		print_list(ft_second);

	std::cout << "push_back 2.1 on second\n";

	second.push_back (2.1);
	ft_second.push_back (2.1);

	std::cout << "after merge with function(mycomparison)\n";

	first.merge(second,mycomparison);
	first.merge(second,mycomparison);
	ft_first.merge(ft_second,mycomparison);
	ft_first.merge(ft_second,mycomparison);

	std::cout << "first contains:\n";
	print_list(first);
	print_list(ft_first);

	return ;
}

void operator_equal()
{
	std::list<int> first(3);      // list of 3 zero-initialized ints
	std::list<int> second(5);     // list of 5 zero-initialized ints
	ft::list<int> ft_first(3);      // list of 3 zero-initialized ints
	ft::list<int> ft_second(5);     // list of 5 zero-initialized ints

	second = first;
	first = std::list<int>();
	ft_second = ft_first;
	ft_first = ft::list<int>();

	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of first: " << int(ft_first.size()) << "-> ft\n";
	std::cout << "Size of second: " << int(ft_second.size()) << "-> ft\n";
	return ;
}

void push_pop_front_back()
{
	std::list<int> mylist (2,100);         // two ints with a value of 100
	ft::list<int> ftlist (2,100);         // two ints with a value of 100
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.push_front (300);
	ftlist.push_front (300);
	std::cout << "push_front 300\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.pop_front();
	ftlist.pop_front();
	std::cout << "pop_front\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.push_back (400);
	ftlist.push_back (400);
	std::cout << "push_back 400\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.pop_back();
	ftlist.pop_back();
	std::cout << "pop_back\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return ;
}
bool single_digit (const int& value) { return (value<10); }


// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};
void remove()
{
	int myints[]= {1,52,17,89,7,20,14,91,44};
	std::list<int> mylist (myints,myints+8);
	ft::list<int> ftlist (myints,myints+8);

	mylist.remove(89);
	ftlist.remove(89);

	std::cout << "mylist contains:\n";
	print_list(mylist);
	print_list(ftlist);
	mylist.remove_if(single_digit);
	ftlist.remove_if(single_digit);
	std::cout << "remove if single_digit\n";
	print_list(mylist);
	print_list(ftlist);
	mylist.remove_if(is_odd());
	ftlist.remove_if(is_odd());
	std::cout << "remove if is_odd\n";
	print_list(mylist);
	print_list(ftlist);

	return ;
}


void resize()
{
	std::list<int> mylist;
	ft::list<int> ftlist;

	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);
	for (int i=1; i<10; ++i) ftlist.push_back(i);

	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);
	ftlist.resize(5);
	ftlist.resize(8,100);
	ftlist.resize(12);

	print_list(mylist);
	print_list(ftlist);

	return ;
}
void reverse()
{
	std::list<int> mylist;
	ft::list<int> ftlist;

	for (int i=1; i<10; ++i) mylist.push_back(i);
	for (int i=1; i<10; ++i) ftlist.push_back(i);

	std::cout << "Init\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.reverse();
	ftlist.reverse();

	std::cout << "mylist contains:\n";
	print_list(mylist);
	print_list(ftlist);

	return ;
}
void size()
{
	std::list<int> myints;
	ft::list<int> ftints;
	std::cout << "0. size: " << myints.size() << '\n';
	std::cout << "0. size: " << ftints.size() << "-> ft \n";

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) ftints.push_back(i);
	std::cout << "1. size: " << ftints.size() <<  "-> ft \n";

	myints.insert (myints.begin(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	ftints.insert (ftints.begin(),10,100);
	std::cout << "2. size: " << ftints.size() <<  "-> ft \n";

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	ftints.pop_back();
	std::cout << "3. size: " << ftints.size() <<  "-> ft \n";

	std::cout << "4. max_size: " << myints.max_size() << std::endl;
	std::cout << "4. max_size: " << ftints.max_size() << "-> ft" << std::endl;

	return ;
}
#include <string>
#include <cctype>

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void sort()
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	ft::list<std::string> ftlist;
	ft::list<std::string>::iterator ft;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");
	ftlist.push_back ("one");
	ftlist.push_back ("two");
	ftlist.push_back ("Three");

	std::cout << "Init\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.sort();
	ftlist.sort();

	std::cout << "sort()\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.sort(compare_nocase);
	ftlist.sort(compare_nocase);

	std::cout << "sort(compare_nocase)\n";
	print_list(mylist);
	print_list(ftlist);
}


void splice()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	ft::list<int> ftlist1, ftlist2;
	ft::list<int>::iterator ft;

	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30
	for (int i=1; i<=4; ++i)
		ftlist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		ftlist2.push_back(i*10);   // mylist2: 10 20 30
	print_list(mylist1);
	print_list(ftlist1);
	print_list(mylist2);
	print_list(ftlist2);

	it = mylist1.begin();
	++it;                         // points to 2
	ft = ftlist1.begin();
	++ft;                         // points to 2

	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
	ftlist1.splice (ft, ftlist2); // mylist1: 1 10 20 30 2 3 4

	std::cout<<"list1 splice second it to list2\n";
	print_list(mylist1);
	print_list(ftlist1);
	print_list(mylist2);
	print_list(ftlist2);
	// mylist2 (empty)
	// "it" still points to 2 (the 5th element)

	mylist2.splice (mylist2.begin(),mylist1, it);
	ftlist2.splice (ftlist2.begin(),ftlist1, ft);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2
	// "it" is now invalid.
	it = mylist1.begin();
	++it;
	++it;
	++it;
	ft = ftlist1.begin();
	++ft;
	++ft;
	++ft;

	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	ftlist1.splice ( ftlist1.begin(), ftlist1, ft, ftlist1.end());
	// mylist1: 30 3 4 1 10 20

	std::cout << "mylist1 contains\n";
	print_list(mylist1);
	print_list(ftlist1);
	std::cout << "mylist2 contains\n";
	print_list(mylist2);
	print_list(ftlist2);

	return ;
}

void swap()
{
	std::list<int> first (3,100);   // three ints with a value of 100
	std::list<int> second (5,200);  // five ints with a value of 200
	ft::list<int> ft_first (3,100);   // three ints with a value of 100
	ft::list<int> ft_second (5,200);  // five ints with a value of 200

	print_list(first);
	print_list(second);
	print_list(ft_first);
	print_list(ft_second);

	first.swap(second);
	ft_first.swap(ft_second);

	std::cout << "first contains:";
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "first contains:";
	for (ft::list<int>::iterator it=ft_first.begin(); it!=ft_first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " ft \n";

	std::cout << "second contains:";
	for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second contains:";
	for (ft::list<int>::iterator it=ft_second.begin(); it!=ft_second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " ft \n";

	return ;
}
#include <cmath>

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

void unique()
{
	double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
	                      12.77, 73.35, 72.25, 15.3, 72.25};
	std::list<double> mylist(mydoubles, mydoubles + 10);
	ft::list<double> ftlist(mydoubles, mydoubles + 10);

	std::cout << "list generates:\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	ftlist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35
	std::cout << "list sorted:\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	ftlist.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35
	std::cout << "unique():\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
	ftlist.unique(same_integral_part);  //  2.72,  3.14, 12.15
	// 15.3,  72.25, 73.0

	std::cout << "unique(same_int):\n";
	print_list(mylist);
	print_list(ftlist);
	mylist.unique(is_near());           //  2.72, 12.15, 72.25
	ftlist.unique(is_near());           //  2.72, 12.15, 72.25

	std::cout << "unique(is_near):\n";
	print_list(mylist);
	print_list(ftlist);
	std::cout << "list contains:\n";
	print_list(mylist);
	print_list(ftlist);

	return ;
}

int main()
{
	begin_end();
	clear();
	constructor();
	empty();
	erase();
	front_back();
	insert();
	merge();
	operator_equal();
	push_pop_front_back();
	remove();
	resize();
	reverse();
	size();
	sort();
	splice();
	swap();
	unique();
}