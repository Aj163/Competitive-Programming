#include <bits/stc++.h>
using namespace std;

const int N = 305;

int main() {

	int t, n;
	char s[N];

	cin >> t;
	for(int z=1; z<=t; z++) {
		scanf("%s", s);
		n = strlen(s);

		if(n == 1) {
			if(s[0] == '0' || s[0] == '1')
				printf("Case #%d: 0\n", z);
			else
				printf("Case #%d: 1\n", z);

			continue;
		}

		stack<char> st;
	}
}