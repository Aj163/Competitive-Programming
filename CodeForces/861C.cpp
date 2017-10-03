#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

bool isv(char c)
{
	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'u':
		case 'o':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	char s[3000], t;
	int flag=1, l, c;

	reads(s);
	l = strlen(s);
	f(i, l)
	{
		if(isv(s[i]))
		{
			flag=1;
			printf("%c", s[i]);
		}
		else if(flag==1)
		{
			flag=2;
			c=1;
			t=s[i];
			printf("%c", s[i]);
		}
		else if(flag==2 && s[i]==t)
		{
			c++;
			printf("%c", s[i]);
		}
		else if(flag==2)
		{
			c++;
			flag=3;
			if(c==2)
				printf("%c", s[i]);
			else
			{
				flag=2;
			c=1;
			t=s[i];
				printf(" %c", s[i]);
			}
		}
		else
		{
			flag=2;
			c=1;
			t=s[i];
			printf(" %c", s[i]);
		}
	}
}