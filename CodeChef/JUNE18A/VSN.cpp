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
	ll px, py, pz;
	ll qx, qy, qz;
	ll dx, dy, dz;
	ll cx, cy, cz;
	ll r, t;

	double ans, l, h, mid, eps = 1e-9, t1, t2, t3, t4, t5;
	double sx, sy, sz, pcx, pcy, pcz, psx, psy, psz;

	cin>>t;
	while(t--)
	{
		cin>>px>>py>>pz;
		cin>>qx>>qy>>qz;
		cin>>dx>>dy>>dz;
		cin>>cx>>cy>>cz;
		cin>>r;

		l = 0.0;
		h = 1e15;
		while(l < h-eps)
		{
			mid = (l+h)/2;

			sx = qx + dx*mid;
			sy = qy + dy*mid;
			sz = qz + dz*mid;

			pcx = px - cx;
			pcy = py - cy;
			pcz = pz - cz;

			psx = px - sx;
			psy = py - sy;
			psz = pz - sz;

			t1 = (pcy*psz - psy*pcz)*(pcy*psz - psy*pcz);
			t2 = (pcx*psz - psx*pcz)*(pcx*psz - psx*pcz);
			t3 = (pcx*psy - psx*pcy)*(pcx*psy - psx*pcy);
			t4 = sqrt(t1+t2+t3);
			t5 = sqrt(psx*psx + psy*psy + psz*psz);

			if(r*1.0 > t4/t5)
				l = mid+eps;
			else
			{
				ans = mid;
				h = mid-eps;
			}
		}

		printf("%0.9lf\n", ans);
	}
}