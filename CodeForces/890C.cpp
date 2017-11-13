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
	int n, a[200009], ans=0, t;
	int done[200009];

	memset(done, 0, sizeof(done));
	read(n);

	F(i, 1, n+1, 1)
		read(a[i]);

	F_(i, n, 0, 1)
	{
		t = i;
		if(done[i] == 0)
			ans++;
		
		while(done[t]==0 && t!=0)
		{
			done[t]=1;
			t = a[t];
		}
	}

	printf("%d\n", ans);
}