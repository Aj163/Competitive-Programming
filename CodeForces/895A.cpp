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
	int n, a[360], t1, t2, t3, ans = 1e9;

	read(n);
	f(i, n)
		read(a[i]);

	if(n==1)
	{
		printf("360\n");
		return 0;
	}

	f(i, n)
	{
		t1=0;
		F(j, i, n, 1)
		{
			t1+=a[j];
			t2 = 360-t1;
			ans = min(ans, abs(t1-t2));
		}	
	}

	printf("%d\n", ans);
}