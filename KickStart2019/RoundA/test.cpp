#include <bits/stdc++.h>
using namespace std;

int main() {

	int r=50, c=50;
	printf("1\n%d %d\n", r, c);
	srand(time(0));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			int n = rand()%200;
			if(n)
				printf("0");
			else
				printf("1");
		}
		printf("\n");
	}

}