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
map<int, vector<int> > inv;

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
            for(int p : photos[i]) {
                photos_h[h].insert(p);
            }
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
        for(int p : photos_h[i]) {
            photos[n].insert(p);
            inv[p].push_back(n);
        }
        n++;
    }
    for(int i=0; i<v-1; i+=2) {
        photos[n].clear();
        for(int p : photos_v[i]) {
            photos[n].insert(p);
            inv[p].push_back(n);
        }
        for(int p : photos_v[i+1]) {
            photos[n].insert(p);
            inv[p].push_back(n);
        }
        n++;
    }

    printf("Pre processing Done\n");
    // ------------------------------------ //

    vector<pair<pair<int, int>, int> > ind;
    vector<pair<pair<int, int>, int> > ANS(n);

    for(int i=0; i<hind.size(); i++)
        ind.push_back(make_pair(make_pair(hind[i], -1), i));
    for(int i=0; i<v/2; i++)
        ind.push_back(make_pair(vind[i], hind.size() + i));

    bool done[N];
    memset(done, 0, sizeof(done));
    ANS[0] = ind[0];
    done[0] = 1;
    int ptr = 0, ptr2=0;

    while(ptr2 < n) {
        // printf("%d %d\n", ptr, ptr2);
        bool flag = 0;
        for(int p : photos[ANS[ptr].second]) {
            if(flag)
                break;
            if(inv[p].size() > 9000) {
                for(int index : inv[p])
                    if(done[index] == 0) {
                        // printf("@ %d\n", index);
                        ANS[ptr +1] = ind[index];
                        // printf("#\n");
                        ptr++;
                        flag = 1;
                        done[index] = 1;
                        break;
                    }
            }
        }
        if(flag == 0) {
            // printf("##\n");
            while(done[ptr2])
                ptr2++;
            if(ptr2 >= n)
                break;
            ANS[ptr +1] = ind[ptr2];
            done[ptr2] = 1;
            ptr2++;
            ptr++;
        }
    }

    n = ANS.size();

    int ans = 0;
    for(int i=0; i<n-1; i++)
        ans += score(ANS[i].second, ANS[i+1].second);
    printf("Score : %d\n", ans);

    // ------------------------------------ //

    ofstream fout(argv[2]);
    fout <<  (int)ANS.size() << endl;
    for(auto it : ANS) {
        if(it.first.second == -1)
            fout << it.first.first << endl;
        else
            fout << it.first.first << " " << it.first.second << endl;
    }

    printf("Final answer printed\n");
    // ------------------------------------ //
}