/*
	mergering and finding set
	X-Plosives, LA 3644

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
const int MAX = 512;

int pa[MAX];

int find(int a)
{
	while(a != pa[a])
	{
		a = pa[a];
	}
	return a;
}

int main()
{
	//memset(pa, 0, sizeof(pa));
	for(int i=0;i<MAX;i++)
		pa[i] = i;
	//-------------------------------------------------------
	int a, b, res = 0;

	while(scanf("%d%d", &a, &b) == 2)
	{
		if(find(a) != find(b))
		{
			//cout << a << "(" << find(a) << ")" << "\t"
			//<< b << "(" << find(b) << ")" << endl;

			if(a > b) pa[a] = b;
			else pa[b] = a;

			//-----
			for(int i=1;i<=6;i++)
				cout << i << "(" << find(i) << ")" << "\t";
			cout << endl;
		}
		else
		{
			//cout << a << "    " << b << endl;
			res++;
		}
	}

	cout << res << endl;

	return 0;
}



