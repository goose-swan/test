#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 64;
const int INF = 1 << 30;
int n, m;

typedef struct node{
	int v, w;
	node(int v, int w){this->v = v;this->w = w;}
	bool operator<(const node & n) const
	{
		return this->w > n.w;
	}
}node;

vector<node> G[maxn];
int dis[maxn];
bool vis[maxn];
bool inq[maxn];
int cnt[maxn];


void init()
{
	for(int i=0;i<n;i++)
	{
		G[i].clear();
		dis[i] = INF;
		vis[i] = false;
		inq[i] = false;
		cnt[i] = 0;
	}
}


void dijkstra(int s)
{
	priority_queue<node> Q;
	Q.push(node(s, 0));
	dis[s] = 0;
	//vis[s] = true;
	while(!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		int v = now.v;
		if(vis[v]) continue;
		vis[v] = true;
		for(int i=0;i<G[v].size();i++)
		{
			int v2 = G[v][i].v;
			int len = G[v][i].w;
			if(!vis[v2] && dis[v2] > dis[v] + len)
			{
				dis[v2] = dis[v] + len;
				Q.push(node(v2, dis[v2]));
			}
		}
	}
}


void spfa(int s)
{
	queue<int> Q;
	Q.push(s);
	dis[s] = 0;
	inq[s] = true;
	cnt[s]++;

	while(!Q.empty())
	{
		int v1 = Q.front();
		cout << "v1 = " << v1 << endl;
		Q.pop();
		inq[v1] = false;

		for(int i=0;i<G[v1].size();i++)
		{
			int v2 = G[v1][i].v;
			int len = G[v1][i].w;
			cout << v2 << " - " << len << endl;
			if(dis[v2] > dis[v1] + len)
			{
				dis[v2] = dis[v1] + len;
				if(inq[v2] == false)
				{
					Q.push(v2);
					inq[v2] = true;
					cnt[v2]++;
				}
			}
		}
	}
}



int main()
{
	int a, b, w;
	cin >> n >> m;
	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		G[a-1].push_back(node(b-1, w));
		G[b-1].push_back(node(a-1, w));
	}
	cout << "------------------------------" << endl;
	for(int i=0;i<n;i++)
	{
		cout << i << " : ";
		for(int j=0;j<G[i].size();j++)
			cout << G[i][j].v << "(" << G[i][j].w << ")" << "\t";
		cout << endl;
	}
	cout << "------------------------------" << endl;

	//dijkstra(0);
	spfa(0);
	for(int i=0;i<n;i++)
		cout << dis[i] << "\t";
	cout << endl;
	cout << "------------------------------" << endl;
	cout << dis[n-1] << endl;


	return 0;
}

