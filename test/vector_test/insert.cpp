int main ()
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

	return 0;
}