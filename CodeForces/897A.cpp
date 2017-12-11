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
	int n, m, l, r;
	char s[109], c1[5], c2[5];

	read2(n, m);
	reads(s);
	f(i, m)
	{
		read2(l, r);
		reads(c1);
		reads(c2);

		F(i, l-1, r, 1)
			if(s[i] == c1[0])
				s[i] = c2[0];
	}

	printf("%s\n", s);
}