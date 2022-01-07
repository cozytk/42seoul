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

int main ()
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