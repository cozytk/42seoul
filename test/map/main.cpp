#include <iostream>
#include <map>
#include <Map.hpp>

//template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
template<class Key, class T>
//void print_map(std::map<Key, T, Compare, Alloc> map)
void print_map(std::map<Key, T> map)
{
	if (map.empty())
	{
		std::cout << "It's empty map\n";
		return ;
	}
//	for (typename std::map<Key, T, Compare, Alloc>::iterator it = map.begin(); it != map.end(); ++it)
	for (typename std::map<Key, T>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "Key : " << it->first << ", Value : " << it->second << std::endl;
}

//template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
template<class Key, class T>
//void print_map(ft::map<Key, T, Compare, Alloc> map)
void print_map(ft::map<Key, T> map)
{
	if (map.empty())
	{
		std::cout << "It's empty map\n";
		return ;
	} /*	for (typename ft::map<Key, T, Compare, Alloc>::iterator it = map.begin(); it != map.end(); ++it)*/ for (typename ft::map<Key, T>::iterator it = map.begin(); it != map.end(); ++it)std::cout << "Key : " << it->first << ", Value : " << it->second << " ft" << std::endl;

}


void begin_end_r()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	print_map(mymap);
	print_map(ftmap);

	std::cout << "after allocate \n";

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	ftmap['b'] = 100;
	ftmap['a'] = 200;
	ftmap['c'] = 300;

	// show content:
	print_map(mymap);
	print_map(ftmap);
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
	ft::map<char,int>::reverse_iterator rft;
	for (rft=ftmap.rbegin(); rft!=ftmap.rend(); ++rft)
		std::cout << rft->first << " => " << rft->second << '\n';
	return ;
}


void clear()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;
	ftmap['x']=100;
	ftmap['y']=200;
	ftmap['z']=300;

	std::cout << "mymap contains:\n";
	print_map(mymap);
	print_map(ftmap);

	mymap.clear();
	ftmap.clear();
	mymap['a']=1101;
	mymap['b']=2202;
	ftmap['a']=1101;
	ftmap['b']=2202;

	std::cout << "clear() and reallocate\n";

	std::cout << "mymap contains:\n";
	print_map(mymap);
	print_map(ftmap);

	return ;
}


void constructor()
{
	std::map<char,int> first;
	ft::map<char,int> ft_first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	ft_first['a']=10;
	ft_first['b']=30;
	ft_first['c']=50;
	ft_first['d']=70;
	std::cout << "default constuctor, and allocate : first generate\n";
	print_map(first);
	print_map(ft_first);
	std::map<char,int> second (first.begin(),first.end());
	ft::map<char,int> ft_second (ft_first.begin(),ft_first.end());
	std::cout << "Iterator constructor : second generate\n";
	print_map(second);
	print_map(ft_second);
	std::map<char,int> third (second);
	ft::map<char,int> ft_third (ft_second);
	std::cout << "Copy constructor : third generate\n";
	print_map(third);
	print_map(ft_third);
	/* test with different print_map
	std::map<char,int,classcomp> fourth;                 // class as Compare
	ft::map<char,int,classcomp> ft_fourth;                 // class as Compare
	std::cout << "Class as compare constructor : fourth generate\n";
	print_map(fourth);
	print_map(ft_fourth);
	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	bool(*ft_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> ft_fifth (ft_pt); // function pointer as Compare
	print_map(fifth);
	print_map(ft_fifth);
	 */
	return ;
}


void empty()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	ftmap['a']=10;
	ftmap['b']=20;
	ftmap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
	while (!ftmap.empty())
	{
		std::cout << ftmap.begin()->first << " => " << ftmap.begin()->second << '\n';
		ftmap.erase(ftmap.begin());
	}

	return ;
}

void equal_range()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	ftmap['a']=10;
	ftmap['b']=20;
	ftmap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret;
	ft_ret = ftmap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << " ft\n";
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << " ft\n";

	return ;
}


void erase()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	ft::map<char,int> ftmap;
	ft::map<char,int>::iterator ft;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;
	ftmap['a']=10;
	ftmap['b']=20;
	ftmap['c']=30;
	ftmap['d']=40;
	ftmap['e']=50;
	ftmap['f']=60;
	print_map(mymap);
	print_map(ftmap);
	std::cout << "erase by iterator\n";
	it=mymap.find('b');
	ft=ftmap.find('b');
	mymap.erase (it);                   // erasing by iterator
	ftmap.erase (ft);                   // erasing by iterator
	print_map(mymap);
	print_map(ftmap);
	std::cout << "erase by key\n";
	mymap.erase ('c');                  // erasing by key
	ftmap.erase ('c');                  // erasing by key
	print_map(mymap);
	print_map(ftmap);
	it=mymap.find ('e');
	ft=ftmap.find ('e');
	std::cout << "erase by range\n";
	mymap.erase ( it, mymap.end() );    // erasing by range
	ftmap.erase ( ft, ftmap.end() );    // erasing by range
	print_map(mymap);
	print_map(ftmap);
	// show content:
	return ;
}

void find()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	ft::map<char,int> ftmap;
	ft::map<char,int>::iterator ft;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;
	ftmap['a']=50;
	ftmap['b']=100;
	ftmap['c']=150;
	ftmap['d']=200;

	print_map(mymap);
	print_map(ftmap);

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);
	ft = ftmap.find('b');
	if (ft != ftmap.end())
		ftmap.erase (ft);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	std::cout << "elements in ftmap:" << '\n';
	std::cout << "a => " << ftmap.find('a')->second << '\n';
	std::cout << "c => " << ftmap.find('c')->second << '\n';
	std::cout << "d => " << ftmap.find('d')->second << '\n';

	return ;
}


void insert()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );
	ftmap.insert ( ft::pair<char,int>('a',100) );
	ftmap.insert ( ft::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}
	ft::pair<ft::map<char,int>::iterator,bool> ft_ret;
	ft_ret = ftmap.insert ( ft::pair<char,int>('z',500) );
	if (ft_ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ft_ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
	ft::map<char,int>::iterator ft = ftmap.begin();
	ftmap.insert (ft, ft::pair<char,int>('b',300));  // max efficiency inserting
	ftmap.insert (ft, ft::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));
	ft::map<char,int> ftanothermap;
	ftanothermap.insert(ftmap.begin(),ftmap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "ftmap contains:\n";
	for (ft=ftmap.begin(); ft!=ftmap.end(); ++ft)
		std::cout << ft->first << " => " << ft->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "anothermap contains:\n";
	for (ft=ftanothermap.begin(); ft!=ftanothermap.end(); ++ft)
		std::cout << ft->first << " => " << ft->second << '\n';

	return ;
}

void key_comp()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();
	ft::map<char,int>::key_compare ftcomp = ftmap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	ftmap['a']=100;
	ftmap['b']=200;
	ftmap['c']=300;

	std::cout << "mymap contains:\n";
	char highest = mymap.rbegin()->first;     // key value of last element
	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';
	std::cout << "ftmap contains:\n";
	char fthighest = ftmap.rbegin()->first;     // key value of last element
	ft::map<char,int>::iterator ft = ftmap.begin();
	do {
		std::cout << ft->first << " => " << ft->second << '\n';
	} while ( ftcomp((*ft++).first, fthighest) );
	std::cout << '\n';

	return ;
}

void operator_equal()
{
	std::map<char,int> first;
	std::map<char,int> second;
	ft::map<char,int> ft_first;
	ft::map<char,int> ft_second;

	first['x']=8;
	first['y']=16;
	first['z']=32;
	ft_first['x']=8;
	ft_first['y']=16;
	ft_first['z']=32;

	second=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty
	ft_second=ft_first;                // second now contains 3 ints
	ft_first=ft::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
	std::cout << "Size of first: " << ft_first.size() << " ft\n";
	std::cout << "Size of second: " << ft_second.size() << " ft\n";
	return ;
}

void operator_index()
{
	std::map<char,std::string> mymap;
	ft::map<char,std::string> ftmap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];
	ftmap['a']="an element";
	ftmap['b']="another element";
	ftmap['c']=ftmap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';
	std::cout << "ftmap['a'] is " << ftmap['a'] << '\n';
	std::cout << "ftmap['b'] is " << ftmap['b'] << '\n';
	std::cout << "ftmap['c'] is " << ftmap['c'] << '\n';
	std::cout << "ftmap['d'] is " << ftmap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	std::cout << "ftmap now contains " << ftmap.size() << " elements.\n";

	return ;
}


void size()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;
	ftmap['a']=101;
	ftmap['b']=202;
	ftmap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	std::cout << "ftmap.size() is " << ftmap.size() << '\n';
	std::cout << "mymap.size() is " << mymap.max_size() << '\n';
	std::cout << "ftmap.size() is " << ftmap.max_size() << '\n';

	return ;
}


void swap()
{
	std::map<char,int> foo,bar;
	ft::map<char,int> ft_foo,ft_bar;

	foo['x']=100;
	foo['y']=200;
	ft_foo['x']=100;
	ft_foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	ft_bar['a']=11;
	ft_bar['b']=22;
	ft_bar['c']=33;
	std::cout << "foo contains:\n";
	print_map(foo);
	print_map(ft_foo);
	std::cout << "bar contains:\n";
	print_map(bar);
	print_map(ft_bar);

	foo.swap(bar);
	ft_foo.swap(ft_bar);

	std::cout << "swap foo , boo\n";

	std::cout << "foo contains:\n";
	print_map(foo);
	print_map(ft_foo);
	std::cout << "bar contains:\n";
	print_map(bar);
	print_map(ft_bar);

	return ;
}



void upper_lower_boud()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;
	ft::map<char,int> ftmap;
	ft::map<char,int>::iterator ftlow,ftup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	ftmap['a']=20;
	ftmap['b']=40;
	ftmap['c']=60;
	ftmap['d']=80;
	ftmap['e']=100;

	print_map(mymap);
	print_map(ftmap);

	std::cout << "itlow points to b" << std::endl;
	std::cout << "itup points to e" << std::endl;
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	ftlow=ftmap.lower_bound ('b');  // itlow points to b
	ftup=ftmap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "erase b to e" << std::endl;
	mymap.erase(itlow,itup);        // erases [itlow,itup)
	ftmap.erase(ftlow,ftup);        // erases [itlow,itup)

	// print content:
	print_map(mymap);
	print_map(ftmap);

	return ;
}

void value_comp()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	ftmap['x']=1001;
	ftmap['y']=2002;
	ftmap['z']=3003;

	print_map(mymap);
	print_map(ftmap);

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element
	std::map<char,int>::iterator it = mymap.begin();
	ft::pair<char,int> ft_highest = *ftmap.rbegin();          // last element
	ft::map<char,int>::iterator ft = ftmap.begin();

	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	do {
		std::cout << ft->first << " => " << ft->second << " ft\n";
	} while ( ftmap.value_comp()(*ft++, ft_highest) );
	return ;
}

int main()
{
	begin_end_r();
	clear();
	constructor();
	empty();
	equal_range();
	erase();
	find();
	insert();
	key_comp();
	operator_equal();
	operator_index();
	size();
	swap();
	upper_lower_boud();
	value_comp();
	return (0);
}
