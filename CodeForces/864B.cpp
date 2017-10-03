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
	char s[209];
	set<char> m;
	int n, ans=0;

	read(n);
	reads(s);
	f(i, n)
	{
		if(s[i]>='A'&&s[i]<='Z')
			m.clear();
		else
		{
			m.insert(s[i]);
			ans = max(ans, (int)m.size());
		}
	}
	printf("%d", ans);
}