#include <bits/stdc++.h>
using namespace std;

#define N 100005

int main() {

	int n, m;
	string t, name;
	vector<string> photos[N];
	bool type[N];
	map<string, int> s;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> t >> m;
		for(int i=0; i<m; i++) {
			cin >> name;
			photos[i].push_back(name);
			s[name]++;
		}
	}

	int cnt = 0;
	for(auto it : s)
		if(it.second > 4)
			cnt++;
	printf("%d\n", cnt);
}