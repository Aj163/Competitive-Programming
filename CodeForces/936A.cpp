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

int main()
{
	ll k, d, t;
	double ans = 0.0;
	double rem = 1.0;

	cin>>k>>d>>t;
	double step = k*1.0/t + (d*ceil(k*1.0/d) - k)*1.0/(2*t);
	double step2 = 1.0/t;
	double step3 = 1.0/(2*t);

	ans += floor(rem/step)*d*ceil(k*1.0/d);
	rem -= floor(rem/step)*step;

	//cout<<rem<<" "<<endl;

	double inc = min(rem*1.0/step2, 1.0*k);
	ans += inc;

	rem -= inc*step2;
	//cout<<rem<<" "<<step3<<" "<<ans<<endl;
	ans += rem/step3;

	printf("%0.11lf\n", ans);
}