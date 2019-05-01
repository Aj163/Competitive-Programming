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

int t, n;
int a[20], b[20], ch[3];
double ans, cnt, fans;

void solveb(int i, int s1, int s2, int s3, int c1, int c2, int c3) {

	if(i==3*n) {
		cnt += 1.0;

		int cnts = 0;
		cnts += (s1 < ch[0]);
		cnts += (s2 < ch[1]);
		cnts += (s3 < ch[2]);

		//printf("%d\n", cnts);
		//printf("%d %d %d\n", c1, c2, c3);

		if(cnts > 1)
			ans += 1.0;
	}

	if(c1 < n)
		solveb(i+1, s1+b[i], s2, s3, c1+1, c2, c3);
	if(c2 < n)
		solveb(i+1, s1, s2+b[i], s3, c1, c2+1, c3);
	if(c3 < n)
		solveb(i+1, s1, s2, s3+b[i], c1, c2, c3+1);
}

void solvech(int i, int s1, int s2, int s3, int c1, int c2, int c3) {
	
	if(i==3*n) {
		
		ch[0] = s1;
		ch[1] = s2;
		ch[2] = s3;

		ans = 0.0;
		cnt = 0.0;
		solveb(0, 0, 0, 0, 0, 0, 0);

		fans = max(fans, ans/cnt);
	}

	if(c1 < n)
		solvech(i+1, s1+a[i], s2, s3, c1+1, c2, c3);
	if(c2 < n)
		solvech(i+1, s1, s2+a[i], s3, c1, c2+1, c3);
	if(c3 < n)
		solvech(i+1, s1, s2, s3+a[i], c1, c2, c3+1);
}

int main() {

	read(t);
	for(int z=1; z<=t; z++) {
		read(n);
		for(int i=0; i<3*n; i++)
			read(a[i]);

		for(int i=0; i<3*n; i++)
			read(b[i]);

		fans = 0.0;
		solvech(0, 0, 0, 0, 0, 0, 0);

		printf("Case #%d: %0.9lf\n", z, fans);
	}
}

/*

1
3
1 1 1 1 2 2 3 4 5
1 1 1 2 2 3 3 4 4

3 8 9

*/