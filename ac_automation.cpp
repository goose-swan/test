#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 26;
const int N = 8;
typedef struct trie{
	int cnt;
	trie * next[maxn];
	trie * fail;
	trie()
	{
		fail = NULL;
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
}trie;

trie * root;

void insert(char * word)
{
	trie * r = root;
	while(*word)
	{
		int x = *word - 'a';
		if(r->next[x] == NULL)
			r->next[x] = new trie();
		r = r->next[x];
		r->cnt++;
		word++;
	}
}

int search(char * word)
{
	trie * r = root;
	while(*word)
	{
		int x = *word - 'a';
		if(r->next[x] == NULL)
		{
			cout << ".";
			return 0;
		}
		r = r->next[x];
		word++;
	}
	return r->cnt;
}


void remove(char * word, int t)
{
	return;
}



int main()
{
	root = new trie();
	char * str[N] = {
		"hello",
		"him",
		"he",
		"hers",
		"his",
		"she",
		"shell",
		"s",
	};
	for(int i=0;i<N;i++)
	{
		cout << str[i] << endl;
		insert(str[i]);
	}
	cout << "--------------------------" << endl;
	for(int i=0;i<N;i++)
	{
		cout << search(str[i]) << endl;
	}


	return 0;
}

