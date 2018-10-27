#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, t, l, r, p, x;
    vector<long long> a(100009);
    bool used[100009];
    long long ans;

    scanf("%d%d", &n, &q);
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);

    for(int i=0; i<q; i++)
    {
        scanf("%d", &t);
        if(t==1)
        {
            scanf("%d%d", &p, &x);
            a[p-1] = x;
        }
        else
        {
            scanf("%d%d", &l, &r);
            ans = 0;
            if(r-l+1 >= 3)
            {
                t = r-l+1;
                
                memset(used, 0, sizeof(used));
                for(; t>=3; t--)
                {
                    //Find max
                    long long m1=-1, m2=-1, m3=-1;
                    for(int i=l-1; i<r; i++)
                    {
                        if(a[i] > m3 && used[i] == 0)
                        {
                            if(a[i] > m2)
                            {
                                if(a[i] > m1)
                                {
                                    m3 = m2;
                                    m2 = m1;
                                    m1 = a[i];
                                    p = i;
                                }
                                else
                                {
                                    m3 = m2;
                                    m2 = a[i];
                                }
                            }
                            else
                                m3 =  a[i];
                        }
                    }

                    used[p] = 1;
                    if(m1 < m2+m3)
                    {
                        ans = m2+m3+m1;
                        break;
                    }


                }
            }

            printf("%lld\n", ans);
        }
    }
}