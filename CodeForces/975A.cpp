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

int main()
{
	int n;
	set<string> m;
	set<char> dis;
	string str;

	read(n);
	for(int i=0; i<n; i++)
	{
		dis.clear();
		cin>>str;
		for(int j=0; j<str.length(); j++)
			dis.insert(str[j]);

		str = "";
		for(set<char>::iterator it = dis.begin(); it!=dis.end(); it++)
			str += *it;

		str += "";
		m.insert(str);
	}

	printf("%d\n", (int)m.size());
}