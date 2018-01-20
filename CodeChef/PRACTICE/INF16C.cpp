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

double coeff[260];
double eps = 1e-12;
double ans[260][260];

void calc_coeff(int n)
{
	double low = 0.0, high = 1.0, mid, t1;
	while(low <= high - eps)
	{
		mid = (low+high)/2.0;
		t1 = sqrt(1.0 - mid*mid);

		if((1.0+mid)*(1.0+mid) + t1*t1 > coeff[n-1]*coeff[n-1]*t1*t1)
			high = mid - eps;
		else
			low = mid + eps;
	}

	coeff[n] = sqrt((1+mid)*(1+mid) + t1*t1);
}

void solve(int n, double r)
{
	if(n==1)
	{
		ans[0][0] = r;
		ans[1][0] = -r;
		return;
	}

	double low = 0.0, high = r, mid, t1;
	while(low <= high - eps)
	{
		mid = (low+high)/2.0;
		t1 = sqrt(r*r - mid*mid);

		if((r+mid)*(r+mid) + t1*t1 > coeff[n-1]*coeff[n-1]*t1*t1)
			high = mid - eps;
		else
			low = mid + eps;
	}

	ans[n][n-1] = r;

	f(i, n)
		ans[i][n-1] = -mid;

	solve(n-1, t1);
}

double dis(int i, int j, int n)
{
	double ret = 0;
	f(k, n)
		ret += (ans[i][k] - ans[j][k])*(ans[i][k] - ans[j][k]);

	return sqrt(ret);
}

void checker(int n)
{
	double prec = 1e-6, t1;
	int flag = 1;

	f(i, n+1)
	{
		t1 = 0.0;
		f(j, n)
			t1 += ans[i][j]*ans[i][j];

		if(abs(1.0 - t1) > prec)
			flag = 0;
	}

	double a = dis(0, 1, n);
	printf("%0.6lf\n", a);

	f(i, n)
		F(j, i+1, n+1, 1)
			if(abs(dis(i, j, n) - a) > prec)
				flag = 0, printf("%0.6lf\n", dis(i, j, n));

	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int t, n;

	coeff[1] = 2.0;
	F(i, 2, 260, 1)
		calc_coeff(i);

	read(t);
	f(z, t)
	{
		read(n);
		solve(n, 1.0);

		f(i, n+1)
		{
			f(j, n)
				printf("%0.9lf ", ans[i][j]);
			printf("\n");
		}

		//checker(n);

		printf("\n");
	}
}