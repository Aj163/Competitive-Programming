#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int a, b, g;
    vector<int> ans, nums = {4, 8, 15, 16, 23, 42};
    map<int, int> bits, inv_nums;
 
    for(int i=0; i<6; i++)
        for(int j=i+1; j<6; j++)
            bits[nums[i] * nums[j]] = ((1<<i) | (1<<j));
 
    for(int i=0; i<6; i++)
        inv_nums[1<<i] = nums[i];
 
    printf("? 1 2\n");
    cin >> a;
    printf("? 1 3\n");
    cin >> b;
 
    a = bits[a];
    b = bits[b];
    g = a & b;
    ans.push_back(inv_nums[g]);
    ans.push_back(inv_nums[a-g]);
    ans.push_back(inv_nums[b-g]);
 
    printf("? 4 5\n");
    cin >> a;
    printf("? 4 6\n");
    cin >> b;
 
    a = bits[a];
    b = bits[b];
    g = a & b;
    ans.push_back(inv_nums[g]);
    ans.push_back(inv_nums[a-g]);
    ans.push_back(inv_nums[b-g]);
 
    printf("! ");
    for(int it : ans)
        printf("%d ", it);
    printf("\n");
}