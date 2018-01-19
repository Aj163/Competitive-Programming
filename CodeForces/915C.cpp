#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define INF ((int)2e9)
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long    

ll a, b, ans = 0;
ll v[30];

bool solve(ll num, int p)
{
    if(num == 1)
    {
        if(ans + v[0] <=b)
        {
            ans += v[0];
            return 1;
        }
        return 0;
    }


    F_(i, p, -1, 1)
    {
    	if(i!=p && v[i] == v[i+1])
    		continue;
        if(v[i]*num + ans > b)
            continue;
        else
        {
            ll q = v[i];
            F(j, i, p, 1)
                v[j] = v[j+1];



            ans += q*num;
            bool z = solve(num/10, p-1);
            if(z)
                return 1;
            else
            {
                ans -= q*num;
                v[p] = q;
                sort(v, v+p+1);
            }
        }
    }

    return 0;
}

int main()
{
    ll t1;
    int pos = 0;
    cin>>a>>b;
    t1 = a;

    while(t1)
    {
        v[pos++] = (t1%10);
        t1/=10;
    }

    sort(v, v+pos);
    solve((ll)pow(10, pos-1), pos-1);

    ll z = (ll)pow(10, pos-1);
    while(z)
    {
        cout<<ans/z;
        ans%=z;
        z/=10;
    }
    printf("\n");
}