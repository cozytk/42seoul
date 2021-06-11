#include <vector>
#include <Vector.hpp>
#include <iostream>


void print_vec(const std::vector<int> &vec)
{
	std::cout << "first element address is " << &vec.front() << std::endl;
	std::cout << "size is " << vec.size() << std::endl;
	std::cout << "capacity is " << vec.capacity() << std::endl;
	std::cout << "--------element----------\n";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n--------------------------\n";
}

//void ft_print_vec(ft::vector<int> vec)
void print_vec(const ft::vector<int> &vec)
{
	std::cout << "first element address is " << &vec.front() << std::endl;
	std::cout << "size is " << vec.size() << std::endl;
	std::cout << "capacity is " << vec.capacity() << std::endl;
	std::cout << "--------element----------\n";
	for (ft::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
//		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n--------------------------\n";
}

void assign()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;
	ft::vector<int> ft_first;
	ft::vector<int> ft_second;
	ft::vector<int> ft_third;

	first.assign (7,100);             // 7 ints with a value of 100
	ft_first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	ft::vector<int>::iterator ft_it;
	it=first.begin()+1;
	ft_it=ft_first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first
	ft_second.assign (ft_it,ft_first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.
	ft_third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	std::cout << "Size of first: " << int (ft_first.size()) << " ft" << '\n';
	std::cout << "Size of second: " << int (ft_second.size()) << " ft" << '\n';
	std::cout << "Size of third: " << int (ft_third.size()) <<" ft" <<  '\n';
	return ;
}

void begin_end()
{
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
	int i, ft_i;
	for (i=1; i<=5; i++) myvector.push_back(i);
	for (ft_i=1; ft_i<=5; ft_i++) ft_myvector.push_back(ft_i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (ft::vector<int>::iterator it = ft_myvector.begin() ; it != ft_myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	i = 0;
	ft_i = 0;
	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int>::reverse_iterator ft_rit = ft_myvector.rbegin();
	for (; ft_rit!= ft_myvector.rend(); ++ft_rit)
		*ft_rit = ++ft_i;
	std::cout << "ftvector contains:";
	for (ft::vector<int>::iterator it = ft_myvector.begin(); it != ft_myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return ;
}

void capacity_reserve()
{
	std::vector<int>::size_type sz;
	ft::vector<int>::size_type ft_sz;

	std::vector<int> foo;
	ft::vector<int> ft_foo;
	sz = foo.capacity();
	ft_sz = ft_foo.capacity();
	std::cout << "capacity is : " <<  sz << std::endl;
	std::cout << "ft_capacity is : " <<  ft_sz << std::endl;
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "std : capacity changed: " << sz << '\n';
		}
	}
	for (int i=0; i<100; ++i) {
		ft_foo.push_back(i);
		if (ft_sz!=ft_foo.capacity()) {
			ft_sz = ft_foo.capacity();
			std::cout << "ft : capacity changed: " << ft_sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	ft::vector<int> ft_bar;
	ft_sz = ft_bar.capacity();
	ft_bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "std : capacity changed: " << sz << '\n';
		}
	}
	for (int i=0; i<100; ++i) {
		ft_bar.push_back(i);
		if (ft_sz!=ft_bar.capacity()) {
			ft_sz = ft_bar.capacity();
			std::cout << "ft : capacity changed: " << ft_sz << '\n';
		}
	}
	return ;
}

void clear()
{
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	ft::vector<int> ftvector;
	ftvector.push_back (100);
	ftvector.push_back (200);
	ftvector.push_back (300);

	print_vec(myvector);
	print_vec(ftvector);

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	ftvector.clear();
	ftvector.push_back (1101);
	ftvector.push_back (2202);

	print_vec(myvector);
	print_vec(ftvector);
	return ;
}

void constructors()
{
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	ft::vector<int> ft_first;                                // empty vector of ints
	ft::vector<int> ft_second (4,100);                       // four ints with value 100
	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
	ft::vector<int> ft_fourth (ft_third);                       // a copy of third

	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	ft::vector<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );

	print_vec(fifth);
	print_vec(ft_fifth);
	return ;
}

void empty()
{
	std::vector<int> myvector;
	ft::vector<int> ftvector;
	int sum (0);
	int ft_sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);
	for (int i=1;i<=10;i++) ftvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "std_total: " << sum << '\n';
	while (!ftvector.empty())
	{
		ft_sum += ftvector.back();
		ftvector.pop_back();
	}

	std::cout << "ft_total: " << sum << '\n';

	return ;
}

void erase()
{
	std::vector<int> myvector;
	ft::vector<int> ft_vec;

	for (int i = 1; i <= 10; i++) myvector.push_back(i);
	for (int i = 1; i <= 10; i++) ft_vec.push_back(i);


	print_vec(myvector);
	print_vec(ft_vec);

	myvector.erase(myvector.begin(), myvector.begin() + 3);
	ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 3);

	myvector.erase(myvector.begin() + 5);
	ft_vec.erase(ft_vec.begin() + 5);

	print_vec(myvector);
	print_vec(ft_vec);

	return;
}

void front_at_back()
{
	std::vector<int> myvector (10);   // 10 zero-initialized ints
	ft::vector<int> ftvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;
	for (unsigned i=0; i<ftvector.size(); i++)
		ftvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (unsigned i=0; i<ftvector.size(); i++)
		std::cout << ' ' << ftvector.at(i);
	std::cout << '\n';
	std::cout << "back - front : " <<  myvector.back() - myvector.front() << std::endl;
	std::cout << "back - front : " <<  ftvector.back() - ftvector.front() << " ft" << std::endl;
	return ;
}

void insert()
{
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;
	ft::vector<int> ftvector (3,100);
	ft::vector<int>::iterator ft;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	ft = ftvector.begin();
	ft = ftvector.insert ( ft , 200 );

	myvector.insert (it,2,300);
	ftvector.insert (ft,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();
	ft = ftvector.begin();

	std::vector<int> anothervector (2,400);
	std::vector<int> ftanothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	ftvector.insert (ft+2,ftanothervector.begin(),ftanothervector.end());
	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	ftvector.insert (ftvector.begin(), myarray, myarray+3);

	print_vec(myvector);
	print_vec(ftvector);

	return ;
}

void operator_equal()
{
	std::vector<int> foo(3, 0);
	std::vector<int> bar(5, 0);
	ft::vector<int> ft_foo(3, 0);
	ft::vector<int> ft_bar(5, 0);

	bar = foo;
	foo = std::vector<int>();
	ft_bar = ft_foo;
	ft_foo = ft::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	std::cout << "Size of foo: " << int(ft_foo.size()) << '\n';
	std::cout << "Size of bar: " << int(ft_bar.size()) << '\n';
	return ;
}

void operator_index()
{
	std::vector<int> myvector (10);   // 10 zero-initialized elements
	std::vector<int> ftvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();
	ft::vector<int>::size_type ft_sz = ftvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;
	for (unsigned i=0; i<ft_sz; i++) ftvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<ft_sz/2; i++)
	{
		int temp;
		temp = ftvector[ft_sz-1-i];
		ftvector[ft_sz-1-i]=ftvector[i];
		ftvector[i]=temp;
	}
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (unsigned i=0; i<ft_sz; i++)
		std::cout << ' ' << ftvector[i];
	std::cout << '\n';
	return ;
}

void push_pop()
{
	std::vector<int> myvector;
	ft::vector<int> ftvector;
	int sum (0);
	int ft_sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	ftvector.push_back (100);
	ftvector.push_back (200);
	ftvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum << '\n';
	while (!ftvector.empty())
	{
		ft_sum+=ftvector.back();
		ftvector.pop_back();
	}
	std::cout << "The elements of ftvector add up to " << sum << '\n';

	return ;
}

/*
 * reserve 를 사용하면 vector front 주소값이 변경됨.
 */
void reserve()
{
	std::vector<int> vec(10, 16);

	std::cout << &vec.front() << std::endl;
	vec.reserve(1);
	std::cout << &vec.front() << std::endl;
	vec.reserve(100);
	std::cout << &vec.front() << std::endl;
	return ;
}

void size()
{
	std::vector<int> myints;
	ft::vector<int> ftints;
	std::cout << "0. size: " << myints.size() << '\n';
	std::cout << "0. size: " << ftints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) ftints.push_back(i);
	std::cout << "1. size: " << ftints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	ftints.insert (ftints.end(),10,100);
	std::cout << "2. size: " << ftints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	ftints.pop_back();
	std::cout << "3. size: " << ftints.size() << '\n';

	std::cout << "4. max_size : " << myints.max_size() << '\n';
	std::cout << "4. max_size : " << ftints.max_size() << '\n';

	myints.resize(5);
	myints.resize(8,100);
	myints.resize(12);
	ftints.resize(5);
	ftints.resize(8,100);
	ftints.resize(12);

	std::cout << "myvector contains:";
	for (unsigned int i=0;i<myints.size();i++)
		std::cout << ' ' << myints[i];
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (unsigned int i=0;i<ftints.size();i++)
		std::cout << ' ' << ftints[i];
	std::cout << '\n';

	return ;
}

void swap()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200
	ft::vector<int> ftfoo (3,100);   // three ints with a value of 100
	ft::vector<int> ftbar (5,200);   // five ints with a value of 200

	print_vec(foo);
	print_vec(bar);
	foo.swap(bar);
	print_vec(foo);
	print_vec(bar);

	print_vec(ftfoo);
	print_vec(ftbar);
	ftfoo.swap(ftbar);
	print_vec(ftfoo);
	print_vec(ftbar);
	return ;
}//
// Created by Taekyun Kim on 6/8/21.
//

int main()
{
	assign();
	begin_end();
	capacity_reserve();
	clear();
	constructors();
	empty();
	erase();
	front_at_back();
	insert();
	operator_equal();
	operator_index();
	push_pop();
	reserve();
	size();
	swap();
	return (0);
}