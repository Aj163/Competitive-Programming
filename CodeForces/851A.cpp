#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long

using namespace std;

int main()
{
	int n, k, t;
	read3(n, k, t);
	if(t<=k)
		printf("%d", t);
	else if(t>n)
		printf("%d", k-(t-n));
	else
		printf("%d", k);
}