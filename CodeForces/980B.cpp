#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int main()
{
	int n, k;
	char s[4][200];

	read2(n, k);

	
	if(k%2 == 0)
	{
		printf("YES\n");
		for(int i=0; i<4; i++)
		{
			if(i==0 || i==3)
			{
				for(int j=0; j<n; j++)
					printf(".");
				printf("\n");
			}
			else
			{
				printf(".");
				for(int j=0; j<k/2; j++)
					printf("#");
				for(int j=0; j<n-2-k/2; j++)
					printf(".");
				printf(".\n");
			}
		}
	}
	else
	{
		printf("YES\n");
		for(int i=0; i<n; i++)
			printf(".");
		printf("\n");

		//Row 2
		if(k>=n-2)
		{
			k-=n-2;
			printf(".");
			for(int i=0; i<n-2; i++)
				printf("#");
			printf(".\n");
		}
		else
		{
			for(int i=0; i<(n-k)/2; i++)
				printf(".");
			for(int i=0; i<k; i++)
				printf("#");
			for(int i=0; i<(n-k)/2; i++)
				printf(".");
			printf("\n");
			k=0;
		}

		//Row 3
		if(k==0)
		{
			for(int i=0; i<n; i++)
				printf(".");
			printf("\n");
		}
		else
		{
			printf(".");
			for(int i=0; i<k/2; i++)
				printf("#");
			for(int i=0; i<n-2-k; i++)
				printf(".");
			for(int i=0; i<k/2; i++)
				printf("#");

			printf(".\n");
		}

		for(int i=0; i<n; i++)
			printf(".");
		printf("\n");
	}
}