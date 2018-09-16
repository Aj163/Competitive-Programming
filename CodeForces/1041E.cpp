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

	int n, b, flag=1;
	int a[1009], cnt[1009];
	memset(cnt, 0, sizeof(cnt));
	pii ans[1009];

	read(n);
	for(int i=0; i<n-1; i++) {
		read(a[i]);
		cnt[a[i]]++;
		read(b);
		
		if(b != n)
			flag = 0;
	}

	if(flag == 0) {
		printf("NO\n");
		return 0;
	}

	set<int> s;
	int cur=0;
	int temp[1009];

	for(int i=1; i<n; i++) {
		if(cnt[i] == 0)
			s.insert(i);
		else {
			if(cnt[i] -1 > s.size()) {
				printf("NO\n");
				return 0;
			}

			for(int j=0; j<cnt[i] -1; j++) {
				temp[j] = *s.begin();
				s.erase(s.begin());
			}

			if(cnt[i] == 1) {
				ans[cur++] = mp(n, i);
			}
			else {
				ans[cur++] = mp(n, temp[0]);
				ans[cur++] = mp(temp[cnt[i] -2], i);
				for(int j=0; j<cnt[i] -2; j++)
					ans[cur++] = mp(temp[j], temp[j+1]);
			}
		}
	}

	printf("YES\n");
	for(int i=0; i<n-1; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
}