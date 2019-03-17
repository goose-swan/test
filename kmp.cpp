#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int * get_next(char * str)
{
	int n = strlen(str);
	int * next = new int[n];
	next[0] = -1;
	int j=0, k=-1;
	while(j < n)
	{
		if(k == -1 || str[j] == str[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	for(int i=0;i<n;i++)
		cout << next[i] << " ";
	cout << endl;
	return next;
}

int kmp(char * s, char * t)
{
	int * next = get_next(t);
	int i = 0, j = 0;
	while(i < strlen(s))
	{
		if(j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];

		if(j == strlen(t))
			return i - j;
	}
	return -1;
}


int bf(char * s, char * t)
{
	int i = 0, j = 0, n = strlen(s), m = strlen(t);
	while(i < n)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
		}
		if(j == m)
			return i-j+1;
	}
	return 0;
}


int main()
{
	char str[] = "hello_world";
	char tem[] = "ell";

	cout << kmp(str, tem) << endl;
	cout << bf(str, tem) << endl;


	return 0;
}



