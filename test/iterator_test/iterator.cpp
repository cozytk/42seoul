
class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
	int* p;
public:
	MyIterator(int* x) :p(x) {}
	MyIterator(const MyIterator& mit) : p(mit.p) {}
	MyIterator& operator++() {++p;return *this;}
	MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
	bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
	bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
	int& operator*() {return *p;}
};
class ftIterator : public ft::iterator<ft::input_iterator_tag, int>
{
	int* p;
public:
	ftIterator(int* x) :p(x) {}
	ftIterator(const ftIterator& mit) : p(mit.p) {}
	ftIterator& operator++() {++p;return *this;}
	ftIterator operator++(int) {ftIterator tmp(*this); operator++(); return tmp;}
	bool operator==(const ftIterator& rhs) const {return p==rhs.p;}
	bool operator!=(const ftIterator& rhs) const {return p!=rhs.p;}
	int& operator*() {return *p;}
};
int main () {
	int numbers[]={10,20,30,40,50};
	MyIterator from(numbers);
	MyIterator until(numbers+5);
	ftIterator ftfrom(numbers);
	ftIterator ftuntil(numbers+5);
	for (MyIterator it=from; it!=until; it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	for (ftIterator it=ftfrom; it!=ftuntil; it++)
		std::cout << *it << ' ';
	std::cout << '\n';

	return 0;
}