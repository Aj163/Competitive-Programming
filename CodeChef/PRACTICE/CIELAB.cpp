#include <bits/stdc++.h>
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
#define M 1000000007
#define PII pair<int, int>
#define VI vector<int>
#define VIT vector<int>::iterator
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b;
	cin>>a>>b;
	a=a-b;
	if(a%10==9)
		cout<<a-1;
	else cout<<a+1;
}