#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(ll i=0; i<num; i++)
#define F(i, lower, upper, step) for(ll i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(ll i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
#define read2(numa, num2) scanf("%d%d", &numa, &num2)
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<ll, ll>
#define vi vector<ll>
#define ll long long

using namespace std;
#define m (1<<21)

int t, n, q, block, l, r, x;
int t1, t2, t3, t4, t5, t6;
int a[1000009];
int nxt[1000009], jump[1000009], ctr[1000009];
char c;
stack<int> s;
int tree[m];
set<int> updates;
set<int>::iterator it;

void build()
{
    f(i, n)
        tree[m/2+i] = a[i];
    F(i, m/2+n, m, 1)
        tree[i] = 0;

    F_(i, m/2-1, 0, 1)
        tree[i] = max(tree[i*2], tree[i*2 +1]);
}

int query(int node, int a, int b, int i, int j, int val)
{
    int r1, r2;
    if(j<a || b<i || a>b || i>j)
        return -1;

    if(a==b)
    {
        if(tree[a] >= val)
            return a-m/2;
        return -1;
    }

    if(tree[node*2] >= val)
    {
        r1 = query(node*2, a, (a+b)/2, i, j, val);
        if(r1 != -1)
            return r1;

        if(tree[node*2 +1] >= val)
        {
            r2 = query(node*2 +1, (a+b)/2 +1, b, i, j, val);
            return r2;
        }
    }
    else if(tree[node*2 +1] >= val)
    {
        r2 = query(node*2 +1, (a+b)/2 +1, b, i, j, val);
        return r2;
    }

    return -1;
}

bool chk_block(int a, int b)
{
    if(a/block == b/block)
        return 1;
    return 0;
}

void update(int node, int a, int b, int i, int j, int val)
{
    if(j<a || b<i || a>b || i>j)
        return;

    if(a==b)
    {
        tree[node] += 1ll*val;
        return;
    }

    update(node*2, a, (a+b)/2, i, j, val);
    update(node*2 +1, (a+b)/2 +1, b, i, j, val);
    tree[node] = max(tree[node*2], tree[node*2 +1]);
}

void re_init()
{
    int t1;

    while(!s.empty())
        s.pop();
    f(i, n)
    {
        nxt[i] = i;
        jump[i] = i;
        ctr[i] = 0;
        while(!s.empty() && a[s.top()]<a[i])
        {
            t1 = s.top();
            s.pop();
            nxt[t1] = i;
        }
        s.push(i);
    }

    F_(i, n-2, -1, 1)
    {
        if(nxt[i] == i)
            continue;
        if(chk_block(i, nxt[i]))
        {
            ctr[i] = ctr[nxt[i]] +1;
            jump[i] = jump[nxt[i]];
        }
    }
}

int main()
{
    char str[100];
    scanf("%d", &t);
    f(z, t)
    {
        updates.clear();
        memset(tree, -1, sizeof(tree));

        scanf("%d%d", &n, &q);
        f(i, n)
            scanf("%d", &a[i]);

        //Precomputation
        block = 5000;//sqrt(n);
        re_init();
        build();


        f(i, q)
        {
            reads(str);
            c = str[0];

            if(c=='?')
            {
                scanf("%d%d%d", &x, &l, &r);
                x--;
                //Query
                //Get least position such that a[pos] >= l
                t1 =  query(1, m/2, m-1, x+m/2, n-1+m/2, l);
                t2 = 0;

                if(t1 == -1)
                {
                    printf("0\n");
                    continue;
                }

                while(1)
                {
                    t5 = nxt[t1];
                    if(jump[t1] != t1 && a[jump[t1]] <=r)
                    {
                        t2 += ctr[t1];
                        t1 = jump[t1];
                    }
                    else if(t5==t1 && a[t1]<r)
                    {
                        it = updates.upper_bound(t1);
                        while(it!=updates.end())
                        {
                            if(a[*it] > a[t1])
                            {
                                t5 = *it;
                                break;
                            }
                            it++;
                        }
                        if(t5==t1)
                            break;
                        t2++;
                        t1=t5;
                    }
                    else if(t5!=t1 && a[t1]<r)
                    {
                        it = updates.upper_bound(t1);
                        while(it!=updates.end() && *it<t5)
                        {
                            if(a[*it] > a[t1])
                            {
                                t5 = *it;
                                break;
                            }
                            it++;
                        }

                        t2++;
                        t1 = t5;
                    }
                    else
                        break;
                }

                //prllf("-%d-", t1);
                t2++;
                printf("%d\n", t2);
            }
            else
            {
                //Update
                scanf("%d%d", &x, &l);
                x--;
                a[x] += 1ll*l;
                update(1, m/2, m-1, x+m/2, x+m/2, l);

                updates.insert(x);
                if(updates.size()>=block)
                {
                    //Re-initialize
                    re_init();
                    updates.clear();
                    continue;
                }

                //Forward update
                t4 = query(1, m/2, m-1, m/2+x+1, m/2+n-1, a[x]+1);
                if(t4 == -1)
                {
                    nxt[x] = x;
                    jump[x] = x;
                    ctr[x] = 0;
                }
                else
                {
                    nxt[x] = t4;
                    if(chk_block(t4, x))
                    {
                        jump[x] = jump[t4];
                        ctr[x] = ctr[t4] +1;
                    }
                    else
                    {
                        jump[x] = x;
                        ctr[x] = 0;
                    }
                }

                //Backward update
                t4 = (x/block)*block;
                F_(j, x-1, t4-1, 1)
                {
                    if((nxt[j] == j || nxt[j]>x) && (a[x] > a[j]))
                    {
                        nxt[j] = x;
                        ctr[j] = ctr[x] +1;
                        jump[j] = jump[x];
                    }
                    else if(nxt[j] == j || nxt[j]>x);
                    else
                    {
                        jump[j] = jump[nxt[j]];
                        ctr[j] = ctr[nxt[j]] +1;
                    }
                }
            }
        }
    }
}
