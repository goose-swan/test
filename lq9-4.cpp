#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
LL MAX = 10000;

LL func1(LL num)
{
	int temp3 = 0, temp5 = 0, temp7 = 0, res = 0;
	LL nums[MAX];
	// if(nums == NULL)
	// {
	// 	cout << "error" << endl;
	// 	return 0;
	// }
	// else
	// {
	// 	cout << "nums : " << sizeof(nums) << endl;
	// }
	nums[0] = 1;
	while(1)
	{
		LL t = min(min(nums[temp3] * 3, nums[temp5] * 5), nums[temp7] * 7);
		nums[++res] = t;
		//cout << t << endl;
		while(nums[temp3] * 3 <= t) temp3++;
		while(nums[temp5] * 5 <= t) temp5++;
		while(nums[temp7] * 7 <= t) temp7++;
		if(t == num)
			return res;
		else if(t > num)
			return -1;
	}
	return -1;
}


int main()
{
	LL num = 59084709587505;
	cout << "-----------------" << endl;
	LL res = func1(num);
	cout << res << endl;


	return 0;
}

