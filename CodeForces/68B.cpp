#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
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

int n, k;
double a[10000];

bool possible(double val)
{
	double req = 0.0, excess = 0.0;
	f(i, n)
	{
		if(a[i]*1.0 > val)
			excess += a[i]*1.0 - val;
		else
			req += val - a[i]*1.0;
	}

	if(excess*k/100 >= req)
		return 1;
	return 0;
}

double ans()
{
	double low = 0.0, high = 1000.0, mid;
	double ret = 0.0, eps = 1e-9;

	while(low < high - eps)
	{
		mid = (low+high)/2;
		if(possible(mid))
		{
			ret = mid;
			low = mid + eps;
		}
		else
			high = mid - eps;
	}

	return ret;
}

int main()
{
	read2(n, k);
	f(i, n)
		cin>>a[i];

	k = 100-k;
	printf("%0.9lf\n", ans());
}