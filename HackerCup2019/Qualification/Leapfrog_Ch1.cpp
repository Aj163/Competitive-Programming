#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int main() {

    int t, n;
    char s[N];

    cin >> t;
    for(int z=1; z<=t; z++) {
        scanf("%s", s);
        n = strlen(s);

        int b = 0, dot = 0;
        for(int i=1; i<n; i++) {
            if(s[i] == 'B')
                b++;
            else
                dot++;
        }

        if(dot > b || dot == 0)
            printf("Case #%d: N\n", z);
        else
            printf("Case #%d: Y\n", z);
    }
}