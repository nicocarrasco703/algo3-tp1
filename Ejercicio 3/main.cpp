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


void sortDeActividades(vector<tuple<int, int, int>>& p){
    vector<vector<tuple<int, int, int>>> s((2*n) + 1);
    for(int i = 0; i < (2*n) + 1; i++){
        s[get<1>(p[i])].push_back(p[i]);
    }
    int k = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] > 0)
            for(int j = 0; j < s[i].size(); j++){
                p[k] = s[i][j];
                k++;
            }
        }
}



vector<tuple<int, int, int>> subconj(){
    vector<tuple<int, int, int>> res;
    vector<tuple<int, int, int>> r;
    r = paresAStructs();
    sortDeActividades(r);
    res.push_back(r[0]);
    for(int i = 1; i < n; i ++){
        if(get<0>(r[i]) >= get<1>(res.back())) // Usar res.back() en lugar de res[i - 1]
            res.push_back(r[i]);
        else continue;
    }
    return res;
}


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
