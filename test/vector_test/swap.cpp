int main ()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200
//	ft::vector<int> foo (3,100);   // three ints with a value of 100
//	ft::vector<int> bar (5,200);   // five ints with a value of 200
//
	std_print_vec(foo);
	std_print_vec(bar);
	foo.swap(bar);
	std_print_vec(foo);
	std_print_vec(bar);

//	ft_print_vec(foo);
//	ft_print_vec(bar);
//	foo.swap(bar);
//	ft_print_vec(foo);
//	ft_print_vec(bar);
	return 0;
}//
// Created by Taekyun Kim on 6/8/21.
//

