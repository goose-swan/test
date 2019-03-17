#include <iostream>

using namespace std;

int main()
{

	int n;
	cin >> n;
	int * array = new int[n], *c = new int[n], *d = new int[n],
	 *ans = new int [n], res = 0;
	for(int i=0;i<n;i++)
	{
		cin >> array[i];
		cout << array[i] << "\t";
	}
	cout << endl;
	for(int i=0;i<n;i++)
	{
		c[i] = 0;
		for(int j=0;j<i;j++)
		{
			if(array[i] > array[j])
				c[i]++;
		}
	}

	for(int i=n-1;i>=0;i--)
	{
		d[i] = 0;
		for(int j=n-1;j>i;j--)
		{
			if(array[i] < array[j])
				d[i]++;
		}
	}
//--------------------------------------------------------

	for(int i=0;i<n;i++)
	{
		cout << c[i] << "\t" << n - i - 1 - d[i] << "\t" << d[i]  << "\t" << i - c[i] << "\t";
		ans[i] = c[i] * d[i] + (i - c[i]) * (n - i - 1 - d[i]);
		cout << ans[i] << endl;
		res += ans[i];
	}
	cout << endl << res << endl;

	return 0;
}

