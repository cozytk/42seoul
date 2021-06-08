int main ()
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
	return 0;
}
//
// Created by Taekyun Kim on 6/8/21.
//

