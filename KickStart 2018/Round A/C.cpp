#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
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

bool comp(int a[], int b[])
{
	for(int i=0; i<26; i++)
		if(a[i] != b[i])
			return 0;

	return 1;
}

int main()
{
	int t, l, n, a, b, c, d, cnt;
	int s[1000009];
	int t1, t2, t3;
	char str[10], s1, s2, s3;
	vector<string> strings;
	string temp;

	read(t);
	for(int z=1; z<=t; z++)
	{
		read(l);
		strings.clear();
		for(int i=0; i<l; i++)
		{
			cin>>temp;
			strings.pb(temp);
		}

		cin>>str;
		s1 = str[0];
		cin>>str;
		s2 = str[0];

		read(n);
		read2(a, b);
		read2(c, d);


		t1 = s1;
		t2 = s2;
		s[0] = s1 - 'a';
		s[1] = s2 - 'a';

		for(int i=2; i<n; i++)
		{
			t3 = (t1*1ll*b + t2*1ll*a + c)%d;
			s[i] = t3%26;

			t1 = t2;
			t2 = t3;

		}

		cnt = 0;
		for(int k=0; k<l; k++)
		{
			int beta[26] = {0};
			int len = strings[k].length();
			int st = strings[k][0] - 'a';
			int en = strings[k][len - 1] - 'a';
			for(int i=1; i<len-1; i++)
				beta[strings[k][i] - 'a']++;

			int alpha[26] = {0};
			for(int i=1; i<len-1; i++)
				alpha[s[i]]++;

			for(int i=0; i<=n-len; i++)
			{
				if(s[i] != st || s[i+len-1] != en)
				{
					alpha[s[i+1]]--;
					alpha[s[i+len-1]]++;
					continue;
				}


				if(comp(alpha, beta))
				{
					cnt++;
					break;
				}
				

				alpha[s[i+1]]--;
				alpha[s[i+len-1]]++;

				
			}
		}

		printf("Case #%d: %d\n", z, cnt);
	}
}