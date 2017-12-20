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
	int t, n;
 
	cin>>t;
	f(i, t)
	{
		cin>>n;
		cout<<n<<endl;
		f(j, n)
		{
			cout<<n<<endl;
			f(k, n)
				cout<<k+1<<" "<<(k+j)%n+1<<" "<<(k+1+j)%n+1<<endl;
		}
	}
} 