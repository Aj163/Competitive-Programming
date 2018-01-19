#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define INF ((int)2e9)
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int n1, n2, x, ans;
char str_left[70000][20], str_right[70000][20], s[40];
int m[2009][2009], mini[2009], inv[70000];
bool exists[2009];
vi avals;
set<int> adis;
pair< pii, int > p[70000];

int getinv(char a[], char b[], int l)
{
	int ret = 0;
	for(int i=0; i<l; i++)
		if(a[i] != b[i])
			ret++;

	return ret;
}

void get_left_strings()
{
	f(i, (1<<(n1-1)))
	{
		str_left[i][0] = '1';
		F(j, 1, n1, 1)
		{
			if(i & (1<<(n1-j-1)))
				str_left[i][j] = '1';
			else
				str_left[i][j] = '0';
		}

		str_left[i][n1] = '\0';
	}
}

void get_right_strings()
{
	f(i, (1<<(n2-1)))
	{
		int in = 0;
		f(j, n2-1)
		{
			if(i & (1<<(n2-j-2)))
				str_right[i][j] = '1';
			else
				str_right[i][j] = '0';

			if(str_right[i][j] != s[j+n1])
				in++;
		}

		inv[i] = in;
		str_right[i][n2-1] = '0';
		str_right[i][n2] = '\0';

		//printf("%s -> %d\n", str_right[i], inv[i]);
	}
}

int calc(char s[], int l, int a, int b)
{
	for(int i=0; i<l; i++)
	{
		if(s[i]=='0')
			a += b;
		else
			b += 1+a;
	}

	return a;
}

void get_ab_values()
{
	f(i, (1<<(n1-1)))
	{
		int a=0, b=0;
		for(int j=0; j<n1; j++)
		{
			if(str_left[i][j]=='0')
				a += b;
			else
				b += 1+a;
		}

		m[a][b] = min(m[a][b], getinv(str_left[i], s, n1));
		exists[a] = 1;
		mini[a] = min(mini[a], m[a][b]);
		adis.insert(a);
	}
}

void get_xyz_values()
{
	f(i, (1<<(n2-1)))
	{
		int a = calc(str_right[i], n2, 2, 0);
		int b = calc(str_right[i], n2, 1, 0);
		int c = calc(str_right[i], n2, 0, 1);

		p[i].first.first = a - b;
		p[i].second = b - p[i].first.first;
		p[i].first.second = c - p[i].second;

		//printf("%s %d %d %d\n", str_right[i], p[i].first.first, p[i].first.second, p[i].second);
	}
}

void getans()
{
	set<int>::iterator it;
	for(it = adis.begin(); it!=adis.end(); it++)
		avals.pb(*it);

	int t1;
	f(z, avals.size())
	{
		int i = avals[z];
		if(exists[i] == 0)
			continue;

		f(j, (1<<(n2-1)))
		{
			if(p[j].first.second == 0)
			{
				if(i*p[j].first.first + p[j].second == x)
					ans = min(ans, mini[i] + inv[j]);
			}
			else if((x - p[j].second - i*p[j].first.first)%p[j].first.second == 0)
			{
				t1 = (x - p[j].second - i*p[j].first.first)/p[j].first.second;
				if(m[i][t1] < 1e8 && t1>=0 && t1<=2000)
				{
					//printf("%d %d %s ** %d %d\n", i, t1, str_right[j], m[i][t1], inv[j]);
					ans = min(ans, m[i][t1] + inv[j]);
				}
			}
		}
	}
}

int main()
{
	int l, t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", s);
		l = strlen(s);
		scanf("%d", &x);

		n2 = l/2;
		n1 = l-n2;

		get_left_strings();
		get_right_strings();
		
		memset(exists, 0, sizeof(exists));
		avals.clear();
		adis.clear();
		f(i, 2009)
		{
			mini[i] = 1e8;
			f(j, 2009)
				m[i][j] = 1e8;
		}

		get_ab_values();
		get_xyz_values();

		ans = 1e8;
		getans();

		if(ans >= 1e8)
			printf("NO\n");
		else
			printf("YES\n%d\n", ans);
	}
}