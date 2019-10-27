#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int main() {

	int n;
	char s[N];
	map<char, int> m;

	cin >> n;
	scanf("%s", s);

	for(int i=0; i<n; i++)
		m[s[i]]++;

	int ones = (n - 4 * m['z']) / 3;
	while(ones--) 
		printf("1 ");
	while(m['z']--)
		printf("0 ");
	printf("\n");
}