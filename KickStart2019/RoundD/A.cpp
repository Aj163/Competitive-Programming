#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {

    int t, n, q, p, v;
    int a[N];

    cin >> t;
    for(int z=1; z<=t; z++) {
    	scanf("%d%d", &n, &q);
    	set<int> s;

    	for(int i=0; i<n; i++) {
    		scanf("%d", &a[i]);
    		if(__builtin_popcount(a[i]) % 2 == 1)
    			s.insert(i);
    	}

    	printf("Case #%d: ", z);
    	while(q--) {
    		scanf("%d%d", &p, &v);
    		if(s.find(p) != s.end())
    			s.erase(s.find(p));
    		if(__builtin_popcount(v) % 2 == 1)
    			s.insert(p);

    		if(s.size() % 2 == 0)
    			printf("%d ", n);
    		else {
    			int first = *(s.begin());
    			auto it = s.end();
    			it--;
    			int end = *it;
    			printf("%d ", max(n-first-1, end));
    		}
    	}

    	printf("\n");

    }
}