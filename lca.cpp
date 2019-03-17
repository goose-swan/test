#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 40001;
const int MAXl = 36;



typedef struct edge{
	int from, to, w;
	// edge(int from, int to, int w)
	// {
	// 	this->from = from;
	// 	this->to = to;
	// 	this->w = w;
	// }
}edge;

vector<edge> edges;
vector<int> G[MAX];

int grand[MAX][MAXl], gw[MAX][MAXl];
int depth[MAX];
int n, m, N;


void addedge(int x, int y, int w)
{
	//edge a(x, y, w), b = {y, x, w};
	edge a = {x, y, w}, b = {y, x, w};
	edges.push_back(a);
	edges.push_back(b);

	G[x].push_back(edges.size()-2);
	G[y].push_back(edges.size()-1);
}

void dfs(int x)
{
	for(int i=1;i<=N;i++)
	{
		grand[x][i] = grand[grand[x][i-1]][i-1];
		gw[x][i] = gw[x][i-1] + gw[grand[x][i-1]][i-1];
	}
	for(int i=0;i<G[x].size();i++)
	{
		edge e = edges[G[x][i]];
		if(e.to != grand[x][0])
		{
			cout << "(" << e.to << ")" << endl;
			depth[e.to] = depth[x] + 1;
			grand[e.to][0] = x;
			gw[e.to][0] = e.w;
			dfs(e.to);
		}
	}
}


void printG()
{
	for(int i=0;i<edges.size();i++)
	{
		cout << edges[i].from << " - " << edges[i].to << " : " << edges[i].w << endl;
	}
	cout << "==================================================================================================================================" << endl;
	cout << "G" << endl;
	cout << "==================================================================================================================================" << endl;
	for(int i=0;i<=n+1;i++)
	{
		if(i == 1) 	cout << ".................................................................................................................................." << endl;
		for(int j=0;j<G[i].size();j++)
		{
			cout << G[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "==================================================================================================================================" << endl;
	cout << "grand" << endl;
	cout << "==================================================================================================================================" << endl;

	for(int i=0;i<=n;i++)
	{
		if(i == 1) 	cout << ".................................................................................................................................." << endl;
		cout << i << ":\t";
		for(int j=0;j<N;j++)
		{
			cout << grand[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "==================================================================================================================================" << endl;
	cout << "gw" << endl;
	cout << "==================================================================================================================================" << endl;

	for(int i=0;i<=n;i++)
	{
		if(i == 1) cout << ".................................................................................................................................." << endl;
		cout << i << ":\t";
		for(int j=0;j<N;j++)
		{
			cout << gw[i][j] << "\t";
		}
		cout << endl;
	}
}


void init()
{
	N = floor(log(n + 0.0) / log(2.0));
	cout << "N = " << N << endl;
	depth[1] = 0;
	memset(grand, 0, sizeof(grand));
	memset(gw, 0, sizeof(gw));
	dfs(1);
}

int lca(int a, int b)
{
	if(depth[a] > depth[b])
	{
		int t = a;
		a = b;
		b = t;
	}

	for(int i=N;i>=0;j--)
	{
		if(gr)
	}
 	return 0;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
	}
	init();
	printG();

	return 0;
}

