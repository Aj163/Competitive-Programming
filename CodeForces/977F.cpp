#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
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

map<int, int> ans, pos;
int back[200009];

void print_ans(int i)
{
	if(back[i] == i)
	{
		printf("%d ", i+1);
		return;
	}

	print_ans(back[i]);
	printf("%d ", i+1);
}

int main()
{
	int n, a[200009];

	read(n);
	for(int i=0; i<n; i++)
	{
		read(a[i]);
		pos[a[i]] = i;
		back[i] = i;
		ans[a[i]] = 1;
		
		if(ans.find(a[i] -1) != ans.end())
		{
			ans[a[i]] = ans[a[i] -1] +1;
			back[i] = pos[a[i] -1];
		}
	}

	int maxi = -1;
	map<int, int>::iterator p, it;
	for(it = ans.begin(); it!=ans.end(); it++)
		if(maxi < (it->second))
		{
			maxi = it->second;
			p = it;
		}

	printf("%d\n", maxi);
	print_ans(pos[p->first]);
	printf("\n");
}