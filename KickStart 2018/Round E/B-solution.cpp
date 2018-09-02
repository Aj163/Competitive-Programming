#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define readll(num) scanf("%lld", &num)
#define read3ll(num1, num2, num3) scanf("%lld%lld%lld", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int t, n, m, p;
string a[200], b[200], orig;
int cost[200], ans;
bool flag;

void prt() {
	printf("--");
	for(int i=0; i<p; i++)
		printf("%c", orig[i]);
	printf("--\n");
}

bool valid(string s) {
	for(int i=0; i<m; i++) {
		bool f=1;
		for(int j=0; j<p; j++)
			if(s[j] != b[i][j]) {
				f=0;
				break;
			}

		if(f)
			return 0;
	}

	return 1;
}

int costs(string s) {
	int ret = 0;
	for(int i=0; i<p; i++) {
		if(s[i] == '0')
			ret += n-cost[i];
		else
			ret += cost[i];
	}

	return ret;
}

void dij(string s) {

	multiset<pair<int, string> > q;
	map<string, bool> maps;

	q.insert(mp(costs(s), s));

	while(!q.empty()) {

		pair<int, string> pi = *q.begin();
		q.erase(q.begin());
		string temp = pi.second;
		if(valid(temp)) {
			ans = pi.first;
			break;
		}

		if(maps[temp])
			continue;
		maps[temp] = 1;
		for(int i=0; i<p; i++) {

			temp[i] = 1 - (temp[i] - '0') + '0';
			q.insert(mp(costs(temp), temp));
			temp[i] = 1 - (temp[i] - '0') + '0';
		}
	}
}

int main() {

	

	read(t);
	for(int z=1; z<=t; z++) {

		cin >> n >> m >> p;
		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<m; i++)
			cin >> b[i];
		orig = a[0];

		memset(cost, 0, sizeof(cost));

		for(int j=0; j<p; j++) {
			for(int i=0; i<n; i++)
				cost[j] += (a[i][j] == '0');

			if(cost[j] > n/2)
				orig[j] = '0';
			else
				orig[j] = '1';
		}

		flag = 0;
		ans= 1e9;
		
		dij(orig);
		printf("Case #%d: %d\n", z, ans);
	}
}