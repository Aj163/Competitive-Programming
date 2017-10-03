#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(numa, num2) scanf("%d%d", &numa, &num2);
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

int main()
{
	int n, c1=0, c2=0, a, b, d, flag=0;
	int c[109];
	set<int> s;
	set<int>::iterator it;
	memset(c, 0, sizeof(c));
	read(n);
	f(i, n)
	{
		read(a);
		c[a]++;
		s.insert(a);
	}


	if(s.size() !=2)
	{
		printf("NO");
		return 0;
	}

	it = s.begin();
	b = *it;
	it++;
	d = *it;
	if(c[b]==c[d] && c[b]==n/2)
		printf("YES\n%d %d", b, d);
	else
		printf("NO");

}