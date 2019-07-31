#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
int n;
int tree[4*N];
int a[N];
 
void update1(int v, int l, int r, int p, int x) {
 
	if(r < p || l > p)
		return;
 
	if(l == r) {
		// printf(">> %d\n", l);
		a[l] = x;
		tree[v] = -1;
		return;
	}
 
	tree[v*2] = max(tree[v], tree[v*2]);
	tree[v*2 +1] = max(tree[v], tree[v*2 +1]);
	tree[v] = -1;
 
	int mid = (l+r) / 2;
	update1(v*2, l, mid, p, x);
	update1(v*2 +1, mid +1, r, p, x);
}
 
void pushall(int v, int l, int r) {
 
	if(l == r) {
		a[l] = max(a[l], tree[v]);
		return;
	}
 
	tree[v*2] = max(tree[v], tree[v*2]);
	tree[v*2 +1] = max(tree[v], tree[v*2 +1]);
 
	int mid = (l+r) / 2;
	pushall(v*2, l, mid);
	pushall(v*2 +1, mid +1, r);
}
 
int main() {
 
	int q, p, x, type;
	memset(tree, -1, sizeof(tree));
 
	cin >> n;	
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
 
	cin >> q;
	while(q--) {
		scanf("%d", &type);
		if(type == 1) {
			scanf("%d%d", &p, &x);
			update1(1, 0, n-1, p-1, x);
		}
		else {
			scanf("%d", &x);
			tree[1] = max(tree[1], x);
		}
	}
 
	pushall(1, 0, n-1);
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}