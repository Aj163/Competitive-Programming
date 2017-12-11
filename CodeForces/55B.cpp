#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
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

ll operate(int a, int b, char c)
{
	if(c=='+')
		return a+b;
	return a*1ll*b;
}

ll op2(int a[], char s[5][10])
{
	ll ans = 1e18;
	int b[3];

	f(i, 3)
		F(j, i+1, 3, 1)
		{
			b[0] = operate(a[i], a[j], s[1][0]);

			int p = 1;
			f(k, 3)
				if((k!= i) && (k!= j))
					b[p++] = a[k];

			ans = min(ans, operate(b[0], b[1], s[2][0]));
		}

	return ans;
}

ll op1(int a[], char s[5][10])
{
	ll ans = 1e18;
	int b[3];

	f(i, 4)
		F(j, i+1, 4, 1)
		{
			b[0] = operate(a[i], a[j], s[0][0]);

			int p = 1;
			f(k, 4)
				if((k!= i) && (k!= j))
					b[p++] = a[k];

			ans = min(ans, op2(b, s));
		}
	return ans;
}

int main()
{
	int a[5];
	char s[5][10];

	read2(a[0], a[1]);
	read2(a[2], a[3]);

	reads(s[0]);
	reads(s[1]);
	reads(s[2]);
	
	cout<<op1(a, s);
}