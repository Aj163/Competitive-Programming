#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {

	long long t, k, n;
	long long a[N], c[N];

	cin >> t;
	for(int z=1; z<=t; z++) {
		scanf("%lld%lld", &k, &n);
		for(int i=0; i<n; i++)
			scanf("%lld", &a[i]);
		for(int i=0; i<n; i++)
			scanf("%lld", &c[i]);

		vector<pair<long long, long long> > stalls;
		for(long long i=0; i<n; i++)
			stalls.push_back(make_pair(a[i], c[i]));
		sort(stalls.begin(), stalls.end());

		long long left = k/2;
		long long right = k - left;

		multiset<long long> lefts;
		long long left_sum = 0;
		for(int i=0; i<left; i++) {
			lefts.insert(stalls[left].first - stalls[i].first + stalls[i].second);
			left_sum += stalls[left].first - stalls[i].first + stalls[i].second;
		}

		long long ans[N];
		memset(ans, 0, sizeof(ans));

		ans[left] += stalls[left].second + left_sum;
		long long inc = 0, prev_inc = 0;

		for(int select = left +1; select < n - right; select++) {
			ans[select] += stalls[select].second;
			inc += stalls[select].first - stalls[select -1].first;
			
			lefts.insert(stalls[select -1].second - prev_inc);
			left_sum += stalls[select -1].second - prev_inc;
			auto it = lefts.end();
			it--;
			left_sum -= *it;
			lefts.erase(it);

			// prlong longf("-- %lld %lld\n", left_sum, inc);

			ans[select] += left_sum + inc * 1ll * left;
			// prlong longf(">> %lld\n", ans[select]);

			prev_inc += stalls[select].first - stalls[select -1].first;
		}


		// Right
		multiset<long long> rights;
		long long right_pos = n-right-1;
		long long right_sum = 0;
		for(int i=n-1; i>right_pos; i--) {
			rights.insert(stalls[i].first - stalls[right_pos].first + stalls[i].second);
			right_sum += stalls[i].first - stalls[right_pos].first + stalls[i].second;
		}


		ans[right_pos] += right_sum;
		inc = 0;
		prev_inc = 0;

		for(long long select = right_pos -1; select >= left; select--) {
			inc += stalls[select +1].first - stalls[select].first;
			
			rights.insert(stalls[select +1].second - prev_inc);
			right_sum += stalls[select +1].second - prev_inc;
			auto it = rights.end();
			it--;
			right_sum -= *it;
			rights.erase(it);

			// prlong longf("--- %lld %lld\n", right_sum, inc);
			ans[select] += right_sum + inc * 1ll * right;
			// prlong longf(">>> %lld\n", right_sum + inc * 1ll * right);

			prev_inc += stalls[select +1].first - stalls[select].first;
		}

		long long answer = 1e18;
		for(int i=left; i<=right_pos; i++)
			answer = min(answer, ans[i]);

		printf("Case #%d: %lld\n", z, answer);
	}
}

/*
1
1 5
150 300 301 400 700
8 35 26 5 2

1
6 7
22 21 20 23 26 25 24
10 10 10 10 10 10 10


*/