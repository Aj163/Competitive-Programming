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
	set<int> s1, s2, s;

	read(n);
	for(int i=0; i<n; i++)
	{
		read(a);
		if(i%2==0)
		{
			for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
				s2.insert((*it)|a);
			for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
				s.insert(*it);
			s2.insert(a);
			s1.clear();
		}
		else
		{
			for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
				s1.insert((*it)|a);
			for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
				s.insert(*it);
			s1.insert(a);
			s2.clear();
		}
	}

	for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
		s.insert(*it);
	for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
		s.insert(*it);
	printf("%d\n", (int)s.size());
}