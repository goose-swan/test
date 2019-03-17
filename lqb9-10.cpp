#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1<<30;

int main()
{
	int N, K;
	cin >> N >> K;

	int array[N+1];
	for(int i=0;i<N;i++)
		cin >> array[i+1];
	int dp[K+1][N+1];
	memset(dp, -INF, sizeof(dp));
	for(int i=0;i<=N;i++) dp[0][i] = array[i];
	for(int i=0;i<=K;i++) dp[i][0] = 1;//INF;

	//--------------------------------

	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[i][j] = max(dp[i-1][j-1] * array[j], dp[i][j-1]);
		}
	}

	//--------------
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
