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

int t, n, q, v1, v2, c1, c2;
int r1, r2, r3, r4;
ll t1, t2, t3, t4, t5, t6, ans;
vector<ll> v[100009];
ll sum_cyc[100009], sum_edge[100009], sumc[100009];
int size[100009];
pii p[100009];

ll dis(int t1, int t2, int i)
{
    ll sum, t3;

    if(t1==t2)
        sum = 0;
    else
    {
        if(t1==0)
            sum = v[i][t2-1];
        else
            sum = v[i][t2-1] - v[i][t1-1];

        t3 = v[i][size[i]-1] - sum;
        sum = min(sum, t3);
    }

    return sum;
}

int main()
{
    read(t);
    f(z, t)
    {
        read2(n, q);
        f(i, n)
        {
            v[i].clear();
            read(size[i]);
            f(j, size[i])
            {
                read(v1);
                v[i].pb(v1);
            }

            F(j, 1, size[i], 1)
                v[i][j] += v[i][j-1];
        }

        f(i, n)
        {
            read2(v1, c1);
            v1--;
            c1--;
            p[i] = mp(v1, c1);
            read(v1);
            sum_edge[i] = v1;
        }

        //Precomputation
        f(i, n)
        {
            t1 = min(p[i].first, p[(i-1+n)%n].second);
            t2 = max(p[i].first, p[(i-1+n)%n].second);

            sumc[i] = dis(t1, t2, i);
        }

        sum_cyc[0] = sumc[0];
        F(i, 1, n, 1)
        {
            sum_edge[i] += sum_edge[i-1];
            sum_cyc[i] = sum_cyc[i-1] + sumc[i];
            //printf("%lld ", sum_edge[i]);
        }


        f(i, q)
        {
            read2(v1, c1);
            read2(v2, c2);

            v1--;
            c1--;
            v2--;
            c2--;

            if(c2<c1)
            {
                swap(c1, c2);
                swap(v1, v2);
            }


            r1 = p[c1].first;
            t5 = dis(min(v1, r1), max(v1, r1), c1);

            r2 = p[(c2-1+n)%n].second;
            t6 = dis(min(v2, r2), max(v2, r2), c2);

            t4 = sum_cyc[c2-1] - sum_cyc[c1];
            if(c1==0)
                t3 = sum_edge[c2-1];
            else
                t3 = sum_edge[c2-1] - sum_edge[c1-1];

            //printf("\n%lld %lld\n", t3, t4);
            //printf("\n%d_%d-%lld %d_%d-%lld\n", r1, c1, t5, r2, c2, t6);

            ans = t4+t3+t5+t6;
            //printf("\n%lld %lld\n", t3, sum_edge[n-1]);

            r2 = p[c2].first;
            t6 = dis(min(v2, r2), max(v2, r2), c2);


            r1 = p[(c1-1+n)%n].second;
            t5 = dis(min(v1, r1), max(v1, r1), c1);

            t2 = sum_cyc[n-1] - sumc[c1] - sumc[c2] - t4;
            //printf("\n%lld %lld\n", t3, sum_edge[n-1]);
            t1 = sum_edge[n-1] - t3;


            //printf("\n%d_%d-%lld %d_%d-%lld\n", r1, c1, t5, r2, c2, t6);

            ans = min(ans, t1+t2+t5+t6);

            printf("%lld\n", ans);
        }
    }
}  
