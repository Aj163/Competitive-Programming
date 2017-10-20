#include <bits/stdc++.h>
//#include <unordered_map>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num)
#define read2(numa, num2) scanf("%d%d", &numa, &num2)
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define ll long long
 
using namespace std;

int sumd(int a)
{
	if(a==0)
		return 0;
	return a%10 + sumd(a/10);
}

int main()
{
	int n;
	read(n);

	vi v;
	F(i, max(1, n-200), n, 1)
	{
		if(sumd(i) + i == n)
			v.pb(i);
	}

	printf("%d\n", (int)v.size());
	f(i, v.size())
	printf("%d ", v[i]);
}