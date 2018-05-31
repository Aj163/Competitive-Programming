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

int main()
{
	int n, cnt=6;
	map<string, string> m;
	read(n);
	string s;

	m["purple"] = "Power\n";
	m["green"] = "Time\n";
	m["blue"] = "Space\n";
	m["orange"] = "Soul\n";
	m["red"] = "Reality\n";
	m["yellow"] = "Mind\n";

	for(int i=0; i<n; i++)
	{
		cin>>s;
		m[s] = "";
		cnt--;
	}

	printf("%d\n", cnt);
	for(auto it : m)
		cout<<it.second;
}