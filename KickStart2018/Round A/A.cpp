#include <bits/stdc++.h>
using namespace std;

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
	int t;
	ll n, ans1, ans2, ans;

	read(t);
	for(int j=1; j<=t; j++)
	{
		cin>>n;
		vi v;
		ll temp = n;
		
		//1
		for(int i=18; i>=0; i--)
			if(((temp/((ll)pow(10, i))) %10) %2 == 1)
			{
				temp = (temp/((ll)pow(10, i)))*((ll)pow(10, i)) -1;
				i=19;
			}

		ans1 = n - temp;
		
		
		//2
		temp = n;
		for(int i=18; i>=0; i--)
			if(((temp/((ll)pow(10, i))) %10) %2 == 1)
			{
				temp = (temp/((ll)pow(10, i)) +1)*((ll)pow(10, i));
				i=19;
			}

		ans2 = temp - n;
		ans = min(ans1, ans2);
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
}