#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 6;
 
int main() {
 
	int n;
	long long a[N], ans = 1;
	clock_t start = clock();
 
	cin >> n;
	for(int i=0; i<n; i++)
		scanf("%lld", &a[i]);
 
	srand(time(0));
	random_shuffle(a, a+n);
	do {
		long long x = a[rand() % n];
		map<long long, int> g;
		for(int i=0; i<n; i++)
			g[__gcd(a[i], x)]++;
 
		for(auto it1 = g.begin(); it1 != g.end(); it1++) {
			int cnt = 0;
			for(auto it2 = it1; it2 != g.end(); it2++)
				if(it2->first % it1->first == 0)
					cnt += it2->second;
 
			if(cnt*2 >= n)
				ans = max(ans, it1->first);
		}
	}while((clock() - start)*1.0/CLOCKS_PER_SEC < 3.7);
 
	printf("%lld\n", ans);
}