#include "Array.tpp"

template <typename T>
Array<T>::Array(void)
{
	_size = 0;
	_arr = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	T	*ptr = new T();

	_size = (int)n;
	_arr = new T[_size];
	for (int i = 0 ; i < _size ; i++)
		_arr[i] = *ptr;
}

template <typename T>
Array<T>::Array(const Array & src)
{
	_size = src.size();
	_arr = new T[_size];
	for (int i = 0 ; i < _size ; i++)
		_arr[i] = src[i];
}

template <typename T>
Array<T>::~Array(void)
{
	if (_size)
		delete [] _arr;
}

template <typename T>
Array<T>	& Array<T>::operator=(const Array & src)
{
	for (int i = 0 ; (i < _size && i < src.size()) ; i++)
		_arr[i] = src[i];
	return (*this);
}

template <typename T>
T		& Array<T>::operator[](int i) const
{
	if (i < 0 || i >= _size)
		throw std::runtime_error("Out of limits");
	return (_arr[i]);
}

template <typename T>
int		Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
void	Array<T>::print()
{
	for (int i = 0 ; i < _size ; i++)
		std::cout << _arr[i] << std::endl;
	std::cout << "----------" << std::endl;
}