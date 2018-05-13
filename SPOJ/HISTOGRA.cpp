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
	ll n, a[100009];
	ll ans;
	stack<ll> s;
	ll fans[100009], bans[100009];
 
	while(1)
	{
		while(!s.empty())
			s.pop();
 
		readll(n);
		if(n==0)
			break;
		for(ll i=0; i<n; i++)
			readll(a[i]);
 
		for(ll i=0; i<n; i++)
		{
			while(!s.empty() && a[s.top()] > a[i])
			{
				fans[s.top()] = (i-s.top())*1ll*a[s.top()];
				s.pop();
			}
			s.push(i);
		}
 
		while(!s.empty())
		{
			fans[s.top()] = (n-s.top())*1ll*a[s.top()];
			s.pop();
		}
 
 
		for(ll i=n-1; i>=0; i--)
		{
			while(!s.empty() && a[s.top()] > a[i])
			{
				bans[s.top()] = (s.top()-i)*1ll*a[s.top()];
				s.pop();
			}
			s.push(i);
		}
 
		while(!s.empty())
		{
			bans[s.top()] = (s.top()+1)*1ll*a[s.top()];
			s.pop();
		}
 
		ans = -1;
		for(int i=0; i<n; i++)
			ans = max(ans, bans[i]+fans[i]-a[i]);
 
		printf("%lld\n", ans);
	}
} 