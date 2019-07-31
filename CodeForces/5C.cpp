#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int main() {

	char str[N];
	vector<int> v;
	int n;
	int close[N];

	cin >> str;
	n = strlen(str);

	stack<int> s;
	int ans = 0, cnt = 0;
	memset(close, -1, sizeof(close));

	for(int i=0; i<n; i++) {
		if(str[i] == '(')
			s.push(i);
		else if(!s.empty()) {
			ans = max(ans, i - s.top() +1);
			close[s.top()] = i;
			close[i] = -2;
			s.pop();
		}
	}

	int covered = -1;
	for(int i=0; i<n; i++) {
		if(close[i] > covered) {
			v.push_back(close[i] - i +1);
			covered = close[i];
		}
		else if(close[i] == -1)
			v.push_back(0);
	}

	for(int num : v) {
		// printf("%d ", num);
		if(num == 0) {
			ans = max(ans, cnt);
			cnt = 0;
		}
		else
			cnt += num;
	}
	// printf("\n");
	ans = max(ans, cnt);

	int req = 0;
	cnt = 0;
	for(int num : v) {
		if(num == 0) {
			if(cnt == ans)
				req++;
			cnt = 0;
		}
		else
			cnt += num;
	}
	if(cnt == ans)
		req++;

	if(ans == 0)
		req = 1;

	printf("%d %d\n", ans, req);
}