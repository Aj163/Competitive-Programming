#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long

using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	int n, m, t, a, b, block, ctr, pos;
	int arr[100009], count[100009], jump[100009];

	scanf("%d%d", &n, &m);
	f(i, n)
		scanf("%d", arr+i);

	block = sqrt(n);
	F_(i, n-1, -1, 1)
	{
		if(arr[i]+i>=n)
		{
			jump[i]=i;
			count[i]=0;
		}
		else if(arr[i]+i >= (i/block +1)*block)
		{
			jump[i] = arr[i] + i;
			count[i] =  1;
		}
		else
		{
			jump[i] = jump[arr[i] + i];
			count[i] = count[arr[i] + i] +1;
		}
	}

	/*cout<<endl;
	f(i, n)
		cout<<arr[i]<<" ";
	cout<<endl;
	f(i, n)
		cout<<count[i]<<" ";
	cout<<endl;
	f(i, n)
		cout<<jump[i]<<" ";
	cout<<endl;*/

	f(i, m)
	{
		scanf("%d", &t);
		if(t==1)
		{
			scanf("%d", &pos);
			pos--;
			ctr=0;

			while(arr[pos]+pos<n)
			{
				ctr+=count[pos];
				pos = jump[pos];
			}

			printf("%d %d\n", pos+1, ctr+1);
		}
		else
		{
			scanf("%d%d", &a, &b);
			a--;
			arr[a] = b;

			F_(i, a, ((a/block)*block -1), 1)
			{
				if(arr[i]+i>=n)
				{
					jump[i]=i;
					count[i]=0;
				}
				else if(arr[i]+i >= (i/block +1)*block)
				{
					jump[i] = arr[i] + i;
					count[i] =  1;
				}
				else
				{
					jump[i] = jump[arr[i] + i];
					count[i] = count[arr[i] + i] +1;
				}
			}

			/*cout<<endl;
			f(i, n)
				cout<<arr[i]<<" ";
			cout<<endl;
			f(i, n)
				cout<<count[i]<<" ";
			cout<<endl;
			f(i, n)
				cout<<jump[i]<<" ";
			cout<<endl;*/
		}
	}
}