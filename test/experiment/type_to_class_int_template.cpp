#include <iostream>

template <class T>
class MyClass {
public:
	typedef T value_type;
private:
	value_type _value;
public:
	MyClass(){}
	MyClass(value_type value) : _value(value) {}
	value_type getValue() { return _value; }
};

int main()
{
	MyClass<float> A(100.232332);

	std::cout << A.getValue() << std::endl;
}
