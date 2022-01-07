/*
 * reserve 를 사용하면 vector front 주소값이 변경됨.
 */
int main()
{
	std::vector<int> vec(10, 16);

	std::cout << &vec.front() << std::endl;
	vec.reserve(1);
	std::cout << &vec.front() << std::endl;
	vec.reserve(100);
	std::cout << &vec.front() << std::endl;
}
