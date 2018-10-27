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

int t, n, q, li, ri, x, tl, tr;
int a[100009], b[100009];
map<int, int> m;

int bin(int k)
{
	int l=0, h=n-1, mid;
	while(l<=h)
	{
		mid = (l+h)/2;
		if(b[mid] == k)
			return mid;
		if(b[mid] > k)
			h = mid -1;
		else
			l = mid +1;
	}
	return mid;
}

void binsearch()
{
	int l=0, h=n-1, mid;
	while(l<=h)
	{
		mid = (l+h)/2;
		if(mid == m[x])
			return;
		if(mid > m[x])
		{
			h = mid -1;
			if(a[mid] < x)
				ri++;
			else
				tr--;
		}
		else
		{
			if(a[mid] > x)
				li++;
			else
				tl--;
			l = mid +1;
		}
	}
}

int main()
{
	read(t);
	while(t--)
	{
		m.clear();
		read2(n, q);
		for(int i=0; i<n; i++)
		{
			read(a[i]);
			m[a[i]] = i;
			b[i] = a[i];
		}
		sort(b, b+n);

		for(int z=0; z<q; z++)
		{
			read(x);
			li = ri = 0;
			int p = bin(x);

			tl = p;
			tr = n-p-1;
			binsearch();

			if(tl < li || tr < ri)
			{
				printf("-1\n");
				continue;
			}

			int ans = min(li, ri);
			li -= ans;
			ri -= ans;
			ans += li;
			ans += ri;

			printf("%d\n", ans);
		}
	}
}