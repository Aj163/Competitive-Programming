#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
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
	int n, a;
	char s[400009];
	set<pii> s1, s2;
	set<pii>::iterator it;
	pii p;

	read(n);
	for(int i=0; i<n; i++)
	{
		read(a);
		s1.insert(mp(a, i+1));
	}

	reads(s);
	for(int i=0; i<2*n; i++)
	{
		if(s[i]=='0')
		{
			p = *s1.begin();
			s1.erase(s1.begin());
			s2.insert(p);
			printf("%d ", p.second);
		}
		else
		{
			it = s2.end();
			it--;
			p = *it;
			s2.erase(it);
			printf("%d ", p.second);
		}
	}
	printf("\n");
}