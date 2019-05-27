#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int t, r, c, K;
int a[N][N], h[N][N], hist[N];

int getMaxArea(int hist[], int n) 
{ 
 
    stack<int> s; 
  
    int max_area = 0; // Initalize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
    int i = 0;

    while (i < n) 
    { 
        
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++);      
        else
        { 
            tp = s.top();  
            s.pop();  
  
            area_with_top = hist[tp] * (s.empty() ? i :  i - s.top() - 1); 
            
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
}


int main() {

	cin >> t;
	for(int z=1; z<=t; z++) {
		
		cin >> r >> c >> K;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				scanf("%d", &a[i][j]);

		int ans = 1;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) {
				int mx = a[i][j], mn = a[i][j];
				h[i][j] = 1;
				for(int k=j+1; k<c; k++) {
					mx = max(mx, a[i][k]);
					mn = min(mn, a[i][k]);
					// printf(">> %d %d\n", mn, mx);
					if(mx - mn > K)
						break;

					h[i][j]++;
				}

				// printf("%d %d : %d\n", i, j, h[i][j]);
			}

		for(int j=0; j<c; j++) {
			for(int i=0; i<r; i++)
				hist[i] = h[i][j];

			ans = max(ans, getMaxArea(hist, r));
		}

		printf("Case #%d: %d\n", z, ans);
	}
}