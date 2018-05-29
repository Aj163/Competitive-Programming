#include  <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	for (int k = 0; k < n; ++k)
	{
		long long  l,r;
		cin  >>  l >> r;

		int max=-1;
		int tmp;
		int ans;

		while((l | (l+1)) <= r)
		{
			l |= (l+1);
		}



		cout << l <<  endl;
	}
		
	return 0;
}