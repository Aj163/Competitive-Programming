#include <bits/stdc++.h>

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
    int t, x, y, ca, cb, ab, l, ga, gb, cta, ctb, gga, ggb;
    char s[100009];
    int a[100009], b[100009];

    read(t);
    f(z, t)
    {
        reads(s);
        read2(x, y);
        l = strlen(s);

        ca=0;
        cb=0;

        f(i, l)
        {
            if(s[i]=='a')
                ca++;
            else
                cb++;
        }

        ga = ceil(ca*1.0/x);
        gb = ceil(cb*1.0/y);
        cta=0;
        ctb=0;

        if(ga>cb)
        {
            f(i, l)
            {
                if(cta==x && cb)
                {
                    printf("b");
                    cta=0;
                    cb--;
                }
                else
                {
                    if(cta>=x)
                    {
                        printf("*");
                        cta=0;
                    }

                    printf("a");
                    ca--;
                    cta++;
                }
            }
        }
        else if(gb>ca)
        {
            f(i, l)
            {
                if(ctb==y && ca)
                {
                    printf("a");
                    ctb=0;
                    ca--;
                }
                else
                {
                    if(ctb>=y)
                    {
                        printf("*");
                        ctb=0;
                    }

                    printf("b");
                    cb--;
                    ctb++;
                }
            }
        }

        else if(ga>gb)
        {
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));

            gga = ga;
            ggb = ga;

            f(i, ga)
            {
                a[i] = ceil(ca*1.0/gga);
                ca -= (a[i]);
                gga--;
            }

            f(i, ga)
            {
                b[i] = ceil(cb*1.0/ggb);
                cb -= (b[i]);
                ggb--;
            }

            f(i, ga)
            {
                f(j, a[i])
                    printf("a");
                f(j, b[i])
                    printf("b");
            }
        }
        else
        {
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));

            gga = gb;
            ggb = gb;

            f(i, gb)
            {
                a[i] = ceil(ca*1.0/gga);
                ca -= (a[i]);
                gga--;
            }

            f(i, gb)
            {
                b[i] = ceil(cb*1.0/ggb);
                cb -= (b[i]);
                ggb--;
            }

            f(i, gb)
            {
                f(j, b[i])
                    printf("b");
                f(j, a[i])
                    printf("a");
            }
        }

        printf("\n");
    }
}
