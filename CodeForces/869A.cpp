#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(numa, num2) scanf("%d%d", &numa, &num2);
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

int main()
{
	int n, a[2009], b[2009], ctr=0;

	read(n);
	f(i, n)
		read(a[i]);
	f(i, n)
		read(b[i]);

	sort(a, a+n);
	sort(b, b+n);

	f(i, n)
	{
		f(j, n)
		{
			if(binary_search(a, a+n, a[i]^b[j]) || binary_search(b, b+n, a[i]^b[j]))
				ctr++;
		}
	}

	if(ctr%2)
		printf("Koyomi");
	else
		printf("Karen");
}