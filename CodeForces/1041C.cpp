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

int main() {

	ll n, m, d;
	pair<ll, int> p[200009];

	read3ll(n, m, d);
	for(int i=0; i<n; i++) {
		readll(p[i].first);
		p[i].second = i;
	}

	sort(p, p+n);
	queue<pair<pair<ll, int>, int> > q;

	int cur=0;
	int ans[200009];
	for(int i=0; i<n; i++) {
		if(!q.empty()) {
			pair<pair<ll, int>, int> t = q.front();
			if(t.first.first < p[i].first - d) {
				q.pop();
				q.push(mp(p[i], t.second));
				ans[p[i].second] = t.second;
			}
			else {
				cur++;
				q.push(mp(p[i], cur));
				ans[p[i].second] = cur;
			}
		}
		else {
			cur++;
			q.push(mp(p[i], cur));
			ans[p[i].second] = cur;
		}
	}

	printf("%d\n", cur);
	for(int i=0; i<n; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

/*

4 5 3
1 2 3 5


*/