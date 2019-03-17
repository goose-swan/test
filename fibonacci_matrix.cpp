#include <iostream>


using namespace std;

const int N = 2;
const int mod = 10000;
typedef long long LL;
typedef struct{
	LL m[2][2];
}matrix;

matrix e = {1, 0, 0, 1,};

matrix matrix_mutiply(matrix m, matrix n)
{
	matrix c;;
	for(int i=0;i<N;i++)
		for(int k=0;k<N;k++)
			c.m[i][k] = 0;

	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				c.m[i][j] = c.m[i][j] + m.m[i][k] * n.m[k][j];
	return c;
}


matrix matrix_pow(matrix m, LL x)
{
	matrix ans = e;

	while(x)
	{
		if(x & 1)
			ans = matrix_mutiply(ans, m);
		m = matrix_mutiply(m, m);
		x >>= 1;

	}
	return ans;
}


int main()
{
	LL n;
	matrix m = {1, 1, 1, 0};
	cin >> n;
	matrix a = matrix_pow(m, n);
	cout << a.m[1][0] % mod << endl;

	return 0;
}

