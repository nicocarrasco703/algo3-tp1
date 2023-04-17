#include <iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;


vector<pair<int,int>> a;
int n;


bool orden(tuple<int, int, int> t, tuple<int, int, int> h){
   return  get<1>(t) < get<1>(h);
}

vector<tuple<int, int, int>> paresAStructs(){
    vector<tuple<int, int, int> > r;
    for(unsigned long int i = 0; i < a.size(); i++){
        tuple<int, int, int> t;
        get<0>(t) = a[i].first;
        get<1>(t) = a[i].second;
        get<2>(t) = i;
        r.push_back(t);
    }
    return r;
}


/*void sortDeActividades(vector<tuple<int, int, int>> p){
    vector<vector<tuple<int, int, int>>> s;
    for(int i = 0; i < n; i ++){
        s[get<1>(p[i])].push_back(p[i]);
    }
    int k = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[i].size(); j++){
            p[k] = s[i][j];
            k++;
        }
    }
}*/


vector<tuple<int, int, int> > subconj(){
    vector<tuple<int, int, int> > res;
    vector<tuple<int, int, int> > r;
    r = paresAStructs();
    //sortDeActividades(r);
    sort(r.begin(), r.end(), orden);
    res.push_back(r[0]);
    for(int i = 1; i < n; i ++){
        if(get<0>(r[i]) >= get<1>(res[res.size() - 1])) res.push_back(r[i]);
        else continue;
    }
    return res;
}

//<0,3><1,4><3,6><6,7><4,10>
//  3    2    5    1    4

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int y; cin >> y;
        pair<int, int> c = make_pair(x, y);
        a.push_back(c);
    }
    vector<tuple<int, int, int> > h = subconj();
    cout << h.size() << "\n";
    for(unsigned long int i = 0; i < h.size(); i++){
        cout << ((get<2>(h[i])) + 1) << " ";
    }
    return 0;
}
