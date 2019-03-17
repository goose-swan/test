#include <iostream>
#include <stdio.h>

#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
	int a[3] = {0}, b[3] = {0}, ab=0, c[3] = {0}, d[3] = {0}, cd=0, e[3] = {0}, f[3] = {0};
	char ch;
	freopen("data9-6.txt", "r", stdin);
	int n;
	fscanf(stdin, "%d", &n);
	while(n--)
	{
		ab = 0, cd = 0;
		for(int i=0;i<3;i++)
			a[i] = b[i] = c[i] = d[i] = e[i] = f[i] = 0;
		//------------------------------
		fscanf(stdin, "%d:%d:%d", &a[0], &a[1], &a[2]);
		fscanf(stdin, "%d:%d:%d", &b[0], &b[1], &b[2]);
		ch = getchar();
		if(ch == ' ')
		{
			fscanf(stdin, "(+%d)", &ab);
			ch = getchar();
		}
		fscanf(stdin, "%d:%d:%d", &c[0], &c[1], &c[2]);
		fscanf(stdin, "%d:%d:%d", &d[0], &d[1], &d[2]);
		ch = getchar();
		if(ch == ' ')
		{
			fscanf(stdin, "(+%d)", &cd);
			ch = getchar();
		}
		//-----------------------------
		if(ab == 1)
			b[0] += 24;
		else if(ab == 2)
			b[0] += 48;
		if(cd == 1)
			d[0] += 24;
		else if(cd == 2)
			d[0] += 48;
		if((e[2] = e[2] + b[2] - a[2]) < 0) {e[2] += 60; e[1] += -1;}
		if((e[1] = e[1] + b[1] - a[1]) < 0) {e[1] += 60; e[0] += -1;}
		e[0] = e[0] + b[0] - a[0];

		if((f[2] = f[2] + d[2] - c[2]) < 0) {f[2] += 60; f[1] += -1;}
		if((f[1] = f[1] + d[1] - c[1]) < 0) {f[1] += 60; f[0] += -1;}
		f[0] = f[0] + d[0] - c[0];

		printf("%02d:%02d:%02d\n", e[0], e[1], e[2]);
		printf("%02d:%02d:%02d\n\n", f[0], f[1], f[2]);

		// printf("%02d:%02d:%02d\n", a[0], a[1], a[2]);
		// printf("%02d:%02d:%02d\n", b[0], b[1], b[2]);
		// printf("%02d:%02d:%02d\n", c[0], c[1], c[2]);
		// printf("%02d:%02d:%02d\n", d[0], d[1], d[2]);

	}




	return 0;
}
