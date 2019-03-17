#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b)
{
	int temp;
	while(b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}


int main()
{
	int a = 0, b = 1;
	for(int i=0;i<20;i++)
	{
		b *= 2;
		a += b;
	}
	cout << a << " " << b << endl;
	int c = gcd(a, b);
	cout << c << endl;
	cout << a * 1.0 / c << " " << b * 1.0 / c << endl;

}

