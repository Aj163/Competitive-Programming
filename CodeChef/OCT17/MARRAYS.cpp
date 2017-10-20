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

int t, n;
int size[1000009];
vi v[1000009];
ll p[1000009][2][2];
ll dp[1000009][2][2];

ll solve(int i, int t1, int t2)
{
    if(i==n-1)
        return p[i][t1][t2];

    if(dp[i][t1][t2] != -1)
        return dp[i][t1][t2];

    ll ans1 = 0, ans2=0;
    if(t2==0)
    {
        ans1 = solve(i+1, 1, 0);
        ans2 = solve(i+1, 1, 1);
    }
    else
    {
        ans1 = solve(i+1, 0, 0);
        ans2 = solve(i+1, 0, 1);
    }

    ans1 = max(ans1, ans2);
    ans1 += p[i][t1][t2];

    return dp[i][t1][t2] = ans1;
}

int main()
{
    int t1;
    ll ans;

    read(t);
    f(z, t)
    {
        read(n);
        memset(dp, -1, sizeof(dp));
        f(i, n)
        {
            v[i].clear();
            read(size[i]);

            f(j, size[i])
            {
                read(t1);
                v[i].pb(t1);
            }

            //11
            p[i][1][1] = v[i][0]*1ll*i + v[i][size[i]-1]*1ll*(i+1);
            f(j, size[i]-1)
                p[i][1][1] = max(p[i][1][1], v[i][j]*1ll*(i+1) + v[i][j+1]*1ll*i);

            //10
            p[i][1][0] = v[i][0]*1ll*i - v[i][size[i]-1]*1ll*(i+1);
            f(j, size[i]-1)
                p[i][1][0] = max(p[i][1][0], -v[i][j]*1ll*(i+1) + v[i][j+1]*1ll*i);

            //01
            p[i][0][1] = -v[i][0]*1ll*i + v[i][size[i]-1]*1ll*(i+1);
            f(j, size[i]-1)
                p[i][0][1] = max(p[i][0][1], v[i][j]*1ll*(i+1) - v[i][j+1]*1ll*i);

            //00
            p[i][0][0] = -v[i][0]*1ll*i - v[i][size[i]-1]*1ll*(i+1);
            f(j, size[i]-1)
                p[i][0][0] = max(p[i][0][0], -v[i][j]*1ll*(i+1) - v[i][j+1]*1ll*i);

            if(i==n-1)
            {
                p[i][1][0] = p[i][1][1] = v[i][0]*1ll*i;
                F(j, 1, size[i], 1)
                    p[i][1][0] = p[i][1][1] = max(p[i][1][0], v[i][j]*1ll*i);

                p[i][0][0] = p[i][0][1] = -v[i][0]*1ll*i;
                F(j, 1, size[i], 1)
                    p[i][0][0] = p[i][0][1] = max(p[i][0][0], -v[i][j]*1ll*i);
            }
        }

        ans = 0;
        f(i, 2)
            f(j, 2)
                ans = max(ans, solve(0, i, j));

        printf("%lld\n", ans);
    }
} 
