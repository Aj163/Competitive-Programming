#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int main()
{
	char s[500];
	int l, ctr = 0, flag=0;

	reads(s);
	l = strlen(s);
	F_(i, l-1, -1, 1)
	{
		if(ctr>=6 && s[i] == '1')
			flag = 1;
		if(s[i] == '0')
			ctr++;
	}

	if(flag)
		printf("yes\n");
	else
		printf("no\n");
}