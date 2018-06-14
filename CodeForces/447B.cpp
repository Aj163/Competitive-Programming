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
	char s[1009];
	int k, l, m=0, ans=0;
	int val[26];

	reads(s);
	read(k);
	for(int i=0; i<26; i++)
	{
		read(val[i]);
		m = max(m, val[i]);
	}

	l = strlen(s);
	for(int i=0; i<l; i++)
		ans += val[s[i] - 'a'] * (i+1);
	for(int i=0; i<k; i++)
		ans += m * (i+l+1);
	printf("%d\n", ans);
}
