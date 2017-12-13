#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       ll sum = 0;
       for(int i = 0; i != n; i++)
       {
           ll temp;
           cin>>temp;
           sum += temp;
           cout<<i<<endl;
       }
       double avg = double(sum)/double(n);
       double rem = avg - floor(avg);
       if(rem == 0.5) cout<<(int)floor(avg);
       else cout<<(int)round(avg);
       if(t) cout<<endl;
   }
   return 0;
}