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

int bin(ll a[], int pos, ll k, int h)
{
	int l = pos+1;
	int mid, ans = h;
	while(h>=l)
	{
		mid = (l+h)/2;
		if(a[mid] - a[pos] > k)
		{
			ans = mid;
			h = mid-1;
		}
		else
			l = mid+1;
	}

	return ans;
}

int main()
{
	ll a[200009];
	ll prefix[200009];
	ll n, q, k, pos = 1, curr;

	readll(n);
	readll(q);
	for(int i=1; i<=n; i++)
		readll(a[i]);
	
	prefix[0] = 0;
	for(int i=1; i<=n; i++)
		prefix[i] = prefix[i-1] + a[i];
	prefix[n+1] = 1e16;

	curr = a[1];
	for(int z=0; z<q; z++)
	{
		readll(k);
		if(k>=curr)
		{
			k -= curr;
			int oldpos = pos;
			pos = bin(prefix, pos, k, n+1);
			k -= prefix[pos-1]-prefix[oldpos];
			curr = a[pos] - k;
		}
		else
			curr -= k;

		if(pos == n+1)
		{
			pos = 1;
			curr = a[1];
		}
		printf("%d\n", (int)(n-pos+1));
	}
}