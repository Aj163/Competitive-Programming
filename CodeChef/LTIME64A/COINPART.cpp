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

void findMin(pii arr[], int n) 
{ 
    // Calculate sum of all elements 
    int sum = 0;  
    for (int i = 0; i < n; i++) 
        sum += arr[i].first; 
  
    // Create an array to store results of subproblems 
    bool dp[n+1][sum+1];
    bool chosen[n+1][sum+1]; 
    
    memset(chosen, 0, sizeof(chosen));
    memset(dp, 0, sizeof(dp));
  
    // Initialize first column as true. 0 sum is possible  
    // with all elements. 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // Initialize top row, except dp[0][0], as false. With 
    // 0 elements, no other sum except 0 is possible 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    // Fill the partition table in bottom up manner 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) 
        { 
            // If i'th element is excluded 
            if(dp[i-1][j]) {
            	dp[i][j] = 1;
            	//chosen[i-1][j] = 1;
            	continue;
            }
  
            // If i'th element is included 
            if (arr[i-1].first <= j && dp[i-1][j-arr[i-1].first]) {
            	chosen[i-1][j] = 1;
                dp[i][j] = 1; 
                continue;
            }
        } 
    } 
   
    // Initialize difference of two sums.  
    int diff = INT_MIN; 
      
    // Find the largest j such that dp[n][j] 
    // is true where j loops from sum/2 t0 0 
    for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = max(diff, j); 
            break; 
        } 
    }
	
	int res[n+3];
    for(int i=0; i<n; i++) {
    	
    	memset(res, 0, sizeof(res));
    	int d = diff, ind=n-1;
    	while(d > 0) {
    		while(ind>=0 && chosen[ind][d] == 0)
    			ind--;

    		res[ind] = 1;
    		d -= arr[ind].first;
    		ind--;
    	}
	}
    
	int p=0, q=0, cnt=n+1, s1=0, s2=0;
	res[n] = 2;
	res[n+1] = 1;
	res[n+2] = 0;

	// for(int i=0; i<n+3; i++)
	// 	printf("%d ", res[i]);
	// printf("\n");

	while(res[p] == 0)
		p++;
	while(res[q] == 1)
		q++;

	while(cnt--) {
		if(s1 <= s2) {
			printf("%d ", arr[p].second+1);
			s1 += arr[p].first;
			p++;
			while(res[p] == 0)
				p++;
		}
		else {
			printf("%d ", arr[q].second+1);
			s2 += arr[q].first;
			q++;
			while(res[q] == 1)
				q++;
		}
	}

	printf("\n");
} 

int main() {

	int t, n;
	pii a[509];

	read(t);
	while(t--) {
		read(n);
		for(int i=0; i<n; i++) {
			read(a[i].first);
			a[i].second = i;
		}

		sort(a, a+n);
		findMin(a, n-1);
	}
}

/*

4
6
1 2 3 4 5 6
4
3 5 9 20
4
2 2 2 2
6
1 2 3 4 5 6


*/