#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <set>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack> 

#define gc getchar_unlocked
#define N 2009

using namespace std;

char s1[N];
int mar[30],cnt[30];
set< pair<int,char> > lol;
vector< pair<int,char> > final;

int main(){
	int i,j,t1,t2,t3,t4,n,k,tots=0,diff=0;
	char tempes;
	scanf("%d %d",&n,&k);
	scanf("%s",s1);
	if(k>n){
		printf("WRONGANSWER\n");
		return 0;
	}
	for(i=0;i<26;i++){
		mar[i]=cnt[i]=0;
	}
	for(i=0;i<n;i++){
		cnt[s1[i]-'a']++;
	}
	for(i=0;i<26;i++){
		if(cnt[i]){
			lol.insert(make_pair(cnt[i],'a'+i));
			diff++;
		}
	}
	tots=k;
	auto it=lol.begin();
	t1=it->first;
	tempes=it->second;
	if(k<t1 && diff==26){
		printf("WRONGANSWER\n");
		return 0;
	}
	if(k<t1){
		for(i=0;i<k;i++){
			printf("%c",tempes);
		}
		for(i=0;i<26;i++){
			if(!cnt[i]){
				tempes='a'+i;
				break;
			}
		}
		for(i=0;i<n-k;i++){
			printf("%c",tempes);
		}
		printf("\n");
		return 0;
	}
	while(tots>0 && !lol.empty()){
		auto it=lol.begin();
		if(it->first<tots){
			final.push_back(make_pair(it->first,it->second));
			tots-=it->first;
			lol.erase(it);
		}
		else{
			final.push_back(make_pair(tots,it->second));
			break;
		}
	}
	for(auto it : final){
		t1=it.first;
		for(j=0;j<n;j++){
			if(s1[j]==it.second){
				t1--;
				mar[j]=1;
			}
			if(t1==0){
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		if(mar[i]==1){
			printf("%c",s1[i]);
		}
	}
	for(i=0;i<n-k;i++){
		printf("%c",tempes);
	}
	printf("\n");
	return 0;
}