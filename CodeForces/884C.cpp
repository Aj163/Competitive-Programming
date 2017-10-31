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
	int n, a[100009], pos=-1, t, t2;
	ll ans = 0;
	vi v;

	read(n);
	f(i, n)
	{
		read(a[i]);
		a[i]--;
	}

	f(i, n)
	{
		if(a[i] != -1)
		{
			v.pb(1);
			pos++;

			t = a[i];
			a[i] = -1;
			while(t!=i)
			{
				t2 = a[t];
				a[t] = -1;
				t = t2;
				v[pos]++;
			}
		}
	}

	f(i, v.size())
		ans += v[i]*1ll*v[i];

	if(v.size() >= 2)
	{
		sort(v.begin(), v.end());
		ans += 2*v[pos]*1ll*v[pos-1];
	}

	cout<<ans;
}