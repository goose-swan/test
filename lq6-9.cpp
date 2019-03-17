#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAX = 40001;
const int MAXl = 36;
int n, m, mod = 1e9 + 7;

typedef struct Matrix{
	LL m[6][6];
}Matrix;

Matrix matrix_mutiply(Matrix m, Matrix n)
{
	Matrix res;
	memset(&res.m, 0, sizeof(res.m));
	for(int k=0;k<6;k++)
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				res.m[i][j] = res.m[i][j] % mod + m.m[i][k] * n.m[k][j] % mod ;

	return res;
}

Matrix matrix_pow(Matrix m, LL x)
{
	Matrix res;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			if(i == j)
				res.m[i][j] = 1l;
			else
				res.m[i][j] = 0l;
	while(x)
	{
		if(x & 1)
			res = matrix_mutiply(res, m);
		m = matrix_mutiply(m, m);
		x >>= 1;
	}
	// for(int i=0;i<6;i++)
	// {
	// 	for(int j=0;j<6;j++)
	// 	{
	// 		cout <<res.m[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	// cout << "------------------------------------" << endl;
	return res;
}

int main()
{
	Matrix e;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			e.m[i][j] = 1;
	cin >> n >> m;
	int a, b;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		e.m[a-1][b-1] = 0l;
		e.m[b-1][a-1] = 0l;
	}

	LL dp[n][6];
	for(int i=0;i<6;i++)
		dp[0][i] = 1;


	for(int i=1;i<n;i++)
	{
		for(int j=0;j<6;j++)
			dp[i][j] =
	}

	Matrix res = matrix_pow(e, n-1);
	LL ans = 0;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			ans += res.m[i][j];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout << res.m[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;

	cout << ans * pow(4, n) << endl;

	//------------------------------------------------


	return 0;
}

