#include <bits/stdc++.h>
using namespace std;

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
	int t, n, k, chosen, pos;
	ll a[20009], sum, csum, rsum;
	double ans = 0, num, den, coeff;

	read(t);
	for(int z=0; z<t; z++)
	{
		sum = 0;
		csum = 0;
		chosen = 0;

		read2(n, k);
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			sum += a[i];
		}

		sort(a, a+n, greater<int>());

		ans = sum*1.0/n;
		chosen = n;
		pos = n-1;
		csum = sum;

		for(int i=0; i<k; i++)
		{
			while(pos>=0)
			{
				if(a[pos]*1.0/n < ans*1.0/(n*1.0))
				{
					csum -= a[pos];
					pos--;
				}
				else
					break;
			}

			ans = csum*1.0/n + ans*(n-pos-1)/(n*1.0);
		}
		printf("Case #%d: %0.9lf\n", z+1, ans);
	}
}

/*
1
3 1
1 10 1

*/