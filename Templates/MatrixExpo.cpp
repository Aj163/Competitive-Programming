#define N 2
#define MOD 1000000007

void multiply(int c[N][N], int a[N][N], int b[N][N]) {

    int temp[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            temp[i][j] = 0;
            for(int k=0; k<N; k++)
                temp[i][j] = (temp[i][j] + a[i][k]*1ll*b[k][j]) % MOD;
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            c[i][j] = temp[i][j];
}

void matrixExpo(int a[N][N], long long n) {

    int res[N][N];
    memset(res, 0, sizeof(res));

    for(int i=0; i<N; i++)
        res[i][i] = 1;

    while(n) {
        if(n%2 == 1)
            multiply(res, res, a);
        multiply(a, a, a);
        n/=2;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            a[i][j] = res[i][j];
}