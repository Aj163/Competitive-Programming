#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

int main() {

	char s[N];
	int n;

	scanf("%s", s);
	n = strlen(s);

	char c = s[0];
	printf("Mike\n");
	for(int i=1; i<n; i++) {
		if(s[i] > c)
			printf("Ann\n");
		else
			printf("Mike\n");
		c = min(c, s[i]);
	}
}