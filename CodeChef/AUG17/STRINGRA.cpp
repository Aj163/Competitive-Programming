#include <bits/stdc++.h>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    int t, n, m, f, used[100001], temp, ans[100001], b, vv, ctr, ppp;
    set<int> v[100001];
    set<pii> p;
 
    cin>>t;
    f(z, t)
    {
        p.clear();
 
        f(i, 100001)
        {
            used[i] = -1;
            ans[i] = -1;
            v[i].clear();
        }
        
        f=1;
        
        cin>>n>>m;
        f(i, m)
        {
            cin>>b>>vv;
            if(p.find(mp(vv, b)) != p.end() || b>=vv || b==n || vv==0)
                f=0;
            
            p.insert(mp(vv, b));
            v[b].insert(vv);
        }
 
        if(f==0)
        {
            cout<<"-1\n";
            continue;
        }
 
        F(j, 1, n+1, 1)
        {
            if((*p.begin()).first != j)
            {
                f=0;
                break;
            }
 
            temp = (*p.begin()).second;
            while(!p.empty() && (*p.begin()).first == j)
            {
                if((*p.begin()).second != temp)
                {
                    f=0;
                    break;
                }
                temp++;
                p.erase(p.begin());
            }
 
            if(p.empty() && j<n)
            {
                f=0;
                break;
            }
 
            if(temp != j || f==0)
            {
                f=0;
                break;
            }  
        }    
 
        if(f==0 || !p.empty())
        {
            cout<<"-1\n";
            continue;
        }
        
        ctr = v[0].size()+1;
        f(i, n)
        {
            if(v[i].size() > ctr || v[i].size() < ctr-1)
            {
                f=0;
                break;
            }
            ppp=0;
            if(v[i].size() == ctr)
                ppp=1;
            ctr = v[i].size();
            while(!v[i].empty())
            {
                //cout<<i<<" "<<v[i][j]<<endl;
                if(ans[*(v[i].begin())] == -1)
                {
                    int pp = 1;
                    while(used[pp]>i)
                        pp++;
                    ans[*(v[i].begin())] = pp;
                    
                    if(ppp==1 && i!=0)
                    {
                        ppp=0;
                        ans[*(v[i].begin())] = ans[i];
                        pp = i;
                    }
                    used[pp] = max(*(v[i].begin()), used[pp]);
                }
                v[i].erase(v[i].begin());
            }
            
        }
        
        if(f==0)
        {
            cout<<"-1\n";
            continue;
        }
        
        F(i, 1, n+1, 1)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}    