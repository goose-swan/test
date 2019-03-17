#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;



int max_muliply(int * array, int len, int num)
{
	int ret = 0, k = 1;
	if(num == 0)
	{
		for(int i =len-1;i>=0;i--)
		{
			ret += array[i] * k;
			k *= 10;
		}
		//cout << ret << "." << endl;
		return ret;
	}
	int * maxt = new int[len];
	memset(maxt, 0, sizeof(maxt) * len);
	for(int i=0;i<len-num;i++)
	{
		k=1;
		for(int j=i;j>=0;j--)
		{
			maxt[i] += array[j] * k;
			k *= 10;
		}
		int rec = 1;
		//if(len-i-1 > 0)
			 rec = max_muliply(array+i+1, len-i-1, num-1);
		ret = max(ret, maxt[i] * rec);
		cout << "maxt[" << i << "] = " << maxt[i]
		<< " * "<< rec << " = " << maxt[i] * rec << endl;
	}

	return ret;
}

int main()
{

	int a[] = {7, 5, 9, 9, 2, 4};
	cout << max_muliply(a, 6, 2) << endl;
	cout << "-----------------------" << endl;
	int b[] = {9, 9, 2};
	cout << max_muliply(b, 3, 1) << endl;


	return 0;
}

