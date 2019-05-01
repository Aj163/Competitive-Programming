#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, m, cnt=0;
string t, name;
set<int> *photos = new set<int>[N];
map<string, int> stringer;
bool type[N];

set<int> *photos_h = new set<int>[N], *photos_v = new set<int>[N];
int h=0, v=0;
vector<int> hind;
vector<pair<int, int> > vind;

int score(int i, int j) {

	int m1=0, m2=0, m3=0;
	for(int p : photos[i]) {
		if(photos[j].find(p) != photos[j].end())
			m2++;
		else
			m1++;
	}
	for(int p : photos[j]) {
		if(photos[i].find(p) == photos[i].end())
			m3++;
	}

	return min(min(m1, m2), m3);
}

int main(int argc, char **argv) {

	if(argc != 3)
		return 0;

	freopen(argv[1], "r", stdin);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> t >> m;
		if(t == "H")
			type[i] = 0;
		else
			type[i] = 1;

		for(int j=0; j<m; j++) {
			cin >> name;
			if(stringer.find(name) != stringer.end())
				photos[i].insert(stringer[name]);
			else {
				photos[i].insert(++cnt);
				stringer[name] = cnt;
			}
		}
	}

	printf("Processed Input\n");
	// ------------------------------------ //

	for(int i=0; i<n; i++) {
		if(type[i] == 0) {
			// H
			hind.push_back(i);
			for(int p : photos[i])
				photos_h[h].insert(p);
			h++;
		}
		else {
			// V
			if(v % 2 == 0)
				vind.push_back(make_pair(i, 0));
			else
				vind[vind.size() -1].second = i;

			for(int p : photos[i])
				photos_v[v].insert(p);
			v++;
		}
	}

	n = 0;
	for(int i=0; i<h; i++) {
		photos[n].clear();
		for(int p : photos_h[i])
			photos[n].insert(p);
		n++;
	}
	for(int i=0; i<v-1; i+=2) {
		photos[n].clear();
		for(int p : photos_v[i])
			photos[n].insert(p);
		for(int p : photos_v[i+1])
			photos[n].insert(p);
		n++;
	}

	printf("Pre processing Done\n");
	// ------------------------------------ //

	vector<pair<pair<int, int>, int> > ind;
	vector<pair<pair<int, int>, int> > ANS;

	for(int i=0; i<hind.size(); i++)
		ind.push_back(make_pair(make_pair(hind[i], -1), i));
	for(int i=0; i<v/2; i++)
		ind.push_back(make_pair(vind[i], hind.size() + i));

	// int global_ans = -1;
	// for(int z=0; z<10; z++) {
	// 	srand(time(0));
	// 	random_shuffle(ind.begin(), ind.end());

	// 	int ans = 0;
	// 	for(int i=0; i<n-1; i++)
	// 		ans += score(ind[i].second, ind[i+1].second);

	// 	if(global_ans < ans) {
	// 		global_ans = ans;
	// 		copy(ind.begin(), ind.end(), ANS.begin());
	// 	}
	// }


	bool done[N];
	memset(done, 0, sizeof(done));

	ANS.push_back(ind[0]);
	done[0] = 1;

	for(int i=1; i<n; i++) {
		cnt = 200;
		int maxval = -1, ch = -1, ptr = rand() % n;
		while(cnt && ptr < n) {
			if(done[ptr]) {
				ptr++;
				continue;
			}

			int temp = score(i-1, ptr);
			if(temp > maxval) {
				maxval = temp;
				ch = ptr;
			}
			ptr++;
			cnt--;
		}

		ANS.push_back(ind[ch]);
		done[ch] = 1;
	}

	n = ANS.size();

	int ans = 0;
	for(int i=0; i<n-1; i++)
		ans += score(ANS[i].second, ANS[i+1].second);
	printf("Score : %d\n", ans);

	// ------------------------------------ //

	ofstream fout(argv[2]);
	fout <<  (int)ind.size() << endl;
	for(auto it : ANS) {
		if(it.first.second == -1)
			fout << it.first.first << endl;
		else
			fout << it.first.first << " " << it.first.second << endl;
	}

	printf("Final answer printed\n");
	// ------------------------------------ //
}