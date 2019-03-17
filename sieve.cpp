#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1024;
const int LINE = 10;
int prime[maxn];
bool is_prime[maxn];

int sieve(int n)
{
	int p = 0;
	for(int i=0;i<=n;i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<=n;i++)
	{
		if(is_prime[i])
		{
			prime[p++] = i;
			for(int j=i*i;j<=n;j+=i)
				is_prime[j] = false;
		}
	}
	return p;
}


int main()
{
	int res = sieve(113), i;
	cout << res << endl << "--------------------------------" << endl;
	for(i=0;i<res;i++)
	{
		cout/* << "(" << i << ")" */<< prime[i] <<"\t";
		if((i + 1) % LINE == 0 && i != 0) cout << endl;
	}
	if(i  % LINE != 0) cout << endl;
	//else cout << "*";

	return 0;
}

