#include<iostream>
#include<math.h>
using namespace std;
int main(){

int t,n,q,l,r,m;
cin>>t;
for(int i=0;i<t;++i)
{int arr[100000];
 cin>>n>>q;
 for(int j=0;j<n;++j){
  cin>>arr[j];


 }
 for(int k=0;k<q;++k)  {
 cin>>l>>r;
m=0;
  for(int p=l-1;p<r-1;++p)
  {
      if(p==l-1)
       m=arr[p]^arr[p+1];
     else
       m=m^arr[p+1];

  }
cout<<m<<endl;
 }

}
return 0;
}