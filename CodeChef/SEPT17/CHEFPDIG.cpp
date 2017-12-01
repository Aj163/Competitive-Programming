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
	int t, count[10], l, a, b;
	char s[100009];
 
	read(t);
	f(z, t)
	{
		memset(count, 0, sizeof(count));
		scanf("%s", s);
 
		l = strlen(s);
		f(i, l)
			count[s[i]-'0']++;
 
		F(i, 'A', 'Z'+1, 1)
		{
			a = i/10;
			b = i%10;
 
			count[a]--;
			count[b]--;
 
			if(count[a]>=0 && count[b]>=0)
				printf("%c", i);
 
			count[a]++;
			count[b]++;
		}
		printf("\n");
	}
} 