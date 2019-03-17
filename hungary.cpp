#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int U = 6;
const int V = 7;
const int N = U + V;

vector<int> G[N + 1];

int link[N+1];
bool visited[N+1];

void example()
{
	G[1].push_back(1+6);
	G[1].push_back(2+6);
	G[1].push_back(4+6);
	G[2].push_back(2+6);
	G[2].push_back(5+6);
	G[3].push_back(1+6);
	G[3].push_back(7+6);
	G[4].push_back(3+6);
	G[4].push_back(4+6);
	G[5].push_back(4+6);
	G[5].push_back(6+6);
	G[6].push_back(4+6);

	G[1+6].push_back(1);
	G[2+6].push_back(1);
	G[4+6].push_back(1);
	G[2+6].push_back(2);
	G[5+6].push_back(2);
	G[1+6].push_back(3);
	G[7+6].push_back(3);
	G[3+6].push_back(4);
	G[4+6].push_back(4);
	G[4+6].push_back(5);
	G[6+6].push_back(5);
	G[4+6].push_back(6);
}

bool hungary(int u)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(!visited[v])
		{
			visited[v] = true;
			if(link[v] == 0 || hungary(link[v]))
			{
				link[v] = u;
				//link[u] = v;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int res = 0;
	memset(link, 0, sizeof(link));
	memset(visited, false, sizeof(visited));
	example();
	for(int i=1;i<=U;i++)
	{
		memset(visited, false, sizeof(visited));
		if(hungary(i))
			res++;
	}

	cout << res << endl;
	return 0;
}

