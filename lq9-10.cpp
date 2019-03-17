#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	double sum = 0, sum_save, avg = 0;
	scanf("%d%lf", &n, &sum);
	avg = sum / n;
	sum_save = sum;
	double * a = new double[n];
	double * note = new double[n];
	for(int i=0;i<n;i++)
		scanf("%lf", &a[i]);
	sort(a, a+n);
	// for(int i=0;i<n;i++)
	// 	printf("%.5lf\t", a[i]);
	// cout << endl << "-----------------" << endl;

	for(int i=0;i<n;i++)
	{
		if(a[i] < avg)
		{
			note[i] = a[i];
			sum -= a[i];
			avg = sum / (n- i -1);
		}
		else
		{
			note[i] = avg;
			sum -= a[i];
		}
		cout << "sum : " << sum << endl;
		cout << "avg : " << avg << endl;
	}
	//---------------------
	cout << "-----------------" << endl;
	for(int i=0;i<n;i++)
		printf("%.5lf\t", note[i]);
	cout << endl << "-----------------" << endl;
	double re = 0;
	for(int i=0;i<n;i++)
	{
		re += pow(note[i] - sum_save / n, 2);
	}
	cout << sqrt(re / n) << endl;

	return 0;
}
