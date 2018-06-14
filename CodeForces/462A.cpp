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
	int n, ans=1;
	char a[109][109];

	read(n);
	for(int i=0; i<n; i++)
			reads(a[i]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			int cnt=0;
			if(i>0 && a[i-1][j] == 'o')
				cnt++;
			if(j>0 && a[i][j-1] == 'o')
				cnt++;
			if(i<n-1 && a[i+1][j] == 'o')
				cnt++;
			if(j<n-1 && a[i][j+1] == 'o')
				cnt++;
			if(cnt%2)
				ans = 0;
		}

	if(ans)
		printf("YES\n");
	else
		printf("NO\n");
}