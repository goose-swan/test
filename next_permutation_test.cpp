#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	const int n = 5;
	int a[n] = {1, 2, 3, 4, 5};
	auto p = [&a, n](){
		for(int i=0;i<n;i++)
			cout << a[i] << "  ";
		cout << endl;
	};
	p();
	while(next_permutation(a, a+5))
	{
		p();
	}



	return 0;
}



