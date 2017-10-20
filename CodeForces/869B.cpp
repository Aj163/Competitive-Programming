#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(numa, num2) scanf("%d%d", &numa, &num2);
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

int main()
{
    ll a, b;
    ll c, d;
    int ans, flag=0;

    cin>>a>>b;

    c = min(a, b);
    d = max(a, b);

    if(d-c>10)
        flag=1;

    if(flag==1)
        printf("0");
    else
    {
        ans=1;

        for(ll i = c+1; i< d+1; i++)
            ans=(ans*(i%10))%10;

        printf("%d", ans);
    }
}