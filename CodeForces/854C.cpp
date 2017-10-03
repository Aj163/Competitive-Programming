#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);

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
	int n, k, ans[300009], c[300009], p;
	ll cost = 0;
	set< pii > s;
	set< pii >::iterator it;
	pii pp;

	read2(n, k);
	f(i, n)
		read(c[i]);

	f(i, k)
		s.insert(mp(c[i], i));

	p = k;
	
	f(i, n)
	{

		if(p<n)
		{
			s.insert(mp(c[p], p));
			p++;
		}

		//printf("LOL %d  - i=%d\n", s.size(), i);

		it = s.end();
		it--;

		pp = *it;
		s.erase(it);
		cost += (((k+i) - pp.second)*1ll*pp.first);
		ans[pp.second] = k+i+1;
	}

	cout<<cost<<endl;
	f(i, n)
		printf("%d ", ans[i]);
}