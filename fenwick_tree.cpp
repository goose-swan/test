#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 64;

int a[MAX];
int n;

int lowbit(const int t)
{
	return t & (-t);
}

void insert(int t, int d)
{
	while(t <= n)
	{
		a[t] += d;
		t += lowbit(t);
	}
}

int getSum(int t)
{
	int sum = 0;
	while(t > 0)
	{
		sum += a[t];
		t -= lowbit(t);
	}
	return sum;
}

void p(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main()
{
	memset(a, 0, sizeof(a));
	n = 5;
	int d;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &d);
		insert(i+1, d);
		p(n);
		cout << "----------------------------------------" << endl;
	}



	return 0;
}