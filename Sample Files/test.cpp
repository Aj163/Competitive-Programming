#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <utility>
#include <queue>
#include <cassert>
#include <set>
#include <fstream>

#define N 100009

using namespace std;

set< pair<int,int> > lol;
vector<int> final;

int main(){
	int i,j,t1,t2,t3,t4,k,siz;
	long long int n,buf1,buf2,buf3;
	scanf("%lld %d",&n,&k);
	for(i=0;i<60;i++){
		buf1=1ll<<i;
		if(buf1&n){
			lol.insert(make_pair(i,1));
		}
	}
	t1=(int)lol.size();
	if(t1>k){
		printf("No\n");
		return 0;
	}
	siz=t1;
	while(1){
		if(siz==k){
			break;
		}
		auto it=lol.end();
		it--;
		if(it->second==0){
			lol.erase(it);
			continue ;
		}
		if(it==lol.begin()){
			t1=it->first;
			t2=it->second;
			lol.erase(lol.find(make_pair(t1,t2)));
			lol.insert(make_pair(t1-1,2));
			t2--;
			lol.insert(make_pair(t1,t2));
		}
		else{
			auto it2=it;
			it2--;
			t1=it->first;
			t2=it->second;
			t3=it2->first;
			t4=it2->second;
			lol.erase(lol.find(make_pair(t1,t2)));
			if(t3+1==t1){
				lol.erase(lol.find(make_pair(t3,t4)));
				t4+=2;
				lol.insert(make_pair(t3,t4));
			}
			else{
				lol.insert(make_pair(t1-1,2));
			}
			t2--;
			lol.insert(make_pair(t1,t2));
		}
		siz++;
	}
	printf("Yes\n");
	for(auto it : lol){
		t1=it.first;
		t2=it.second;
		for(i=0;i<t2;i++){
			final.push_back(t1);
		}
	}
	reverse(final.begin(),final.end());
	for(auto it : final){
		printf("%d ",it);
	}
	printf("\n");
    return 0;
}