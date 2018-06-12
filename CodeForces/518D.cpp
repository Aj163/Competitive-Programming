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
	int n, t;
	double p;
	double dp[2009][2009];
	cin>>n>>p>>t;
	
	for(int j=1; j<2009; j++)
		for(int i=1; i<2009; i++)
			dp[i][j] = 0.0;;

	for(int j=1; j<2009; j++)
		for(int i=1; i<2009; i++)
			dp[i][j] = (1-p)*dp[i][j-1]  +  p*dp[i-1][j-1] + p;

	printf("%0.9lf\n", dp[n][t]);
}