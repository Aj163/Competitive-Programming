#define base complex<double>
#define PI acos(-1.0)

void FFT(vector<base> &a, bool inverseFFT) {

	int n=a.size(), i, j;

	for(i=1,j=0; i<n; i++) {
		int bit=n>>1;
		for(; j>=bit; bit>>=1)
			j=j-bit;
		j=j+bit;
		if(i<j)
			swap(a[i],a[j]);
	}

	for(int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (inverseFFT?-1:1);
		base wlen(cos(ang), sin(ang));
		for(i=0; i<n; i+=len) {
			base w(1);
			for(int j=0; j<len/2; j++) {
				base u=a[i+j],v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w = w*wlen;
			}
		}
	}

	if(inverseFFT) {
		for(i=0; i<n; i++)
			a[i]/=n;
	}
}

vector<long long> res;

void FFT_multiply(const vector<long long> &a, const vector<long long> &b) {

	vector<base> fa(a.begin(), a.end());
	vector<base> fb(b.begin(), b.end());
	int i, n=1;

	while(n < max(a.size(),b.size()))
		n<<=1;
	n<<=1;

	fa.resize(n);
	fb.resize(n);
	FFT(fa, false);
	FFT(fb, false);

	for(i=0;i<n;++i)
		fa[i] = fa[i]*fb[i];
	
	FFT(fa, true);
	res.resize(n);
	for(i=0; i<n; i++)
		res[i] = (long long)(fa[i].real()+0.5);
}