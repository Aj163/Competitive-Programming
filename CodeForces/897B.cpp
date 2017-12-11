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
	int k, p, pos = 10, ans2=0;
	ll ans = 0;

	read2(k, p);

	pos=1;
	while(k && pos<10)
	{
		//cout<<pos*10 + pos<<endl;
		ans = (ans + pos*10 + pos)%p;
		pos++;
		ans2++;
		k--;
	}

	pos=10;
	while(k && pos<100)
	{
		//cout<<pos*100 + (pos%10)*10 + pos/10<<endl;
		ans = (ans + pos*100 + (pos%10)*10 + pos/10)%p;
		pos++;
		ans2++;
		k--;
	}

	pos=100;
	while(k && pos<1000)
	{
		//cout<<pos*1ll*1000 + ((pos/1)%10)*1ll*100  + ((pos/10)%10)*1ll*10 + pos/100<<endl;
		ans = (ans + pos*1ll*1000 + ((pos/1)%10)*1ll*100  + ((pos/10)%10)*1ll*10 + pos/100)%p;
		pos++;
		ans2++;
		k--;
	}

	pos=1000;
	while(k && pos<10000)
	{
		//cout<<pos*1ll*10000 + ((pos/1)%10)*1ll*1000 + ((pos/10)%10)*1ll*100  + ((pos/100)%10)*1ll*10 + pos/1000<<endl;
		ans = (ans + pos*1ll*10000 + ((pos/1)%10)*1ll*1000 + ((pos/10)%10)*1ll*100  + ((pos/100)%10)*1ll*10 + pos/1000)%p;
		pos++;
		ans2++;
		k--;
	}

	pos=10000;
	while(k && pos<100000)
	{
		//cout<<pos*1ll*100000 + ((pos/1)%10)*1ll*10000 + ((pos/10)%10)*1ll*1000 + ((pos/100)%10)*1ll*100  + ((pos/1000)%10)*1ll*10 + pos/10000<<endl;
		ans = (ans + pos*1ll*100000 + ((pos/1)%10)*1ll*10000 + ((pos/10)%10)*1ll*1000 + ((pos/100)%10)*1ll*100  + ((pos/1000)%10)*1ll*10 + pos/10000)%p;
		pos++;
		ans2++;
		k--;
	}

	if(k)
		ans = (ans + 100000000001)%p;


	printf("%d\n", (int)ans);
}