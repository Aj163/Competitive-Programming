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
 
int main()
{
	int t, n, a[5];
	char s[50];
	read(t);
 
	f(z, t)
	{
		read(n);
 
		f(i, 5)
			a[i]=0;
 
		f(i, n)
		{
			reads(s);
			if(!strcmp(s, "cakewalk"))
				a[0]=1;
			else if(!strcmp(s, "simple"))
				a[1]=1;
			else if(!strcmp(s, "easy"))
				a[2]=1;
			else if(!strcmp(s, "easy-medium") || !strcmp(s, "medium"))
				a[3]=1;
			else if(!strcmp(s, "medium-hard") || !strcmp(s, "hard"))
				a[4]=1;
		}
 
		int flag=0;
		f(i, 5)
			flag+=a[i];
 
		if(flag==5)
			printf("Yes\n");
		else
			printf("No\n");
	}
} 