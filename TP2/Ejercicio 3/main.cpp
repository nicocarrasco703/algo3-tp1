// Modems
#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int>> plano;
int n, r, w, u, v;
vector<tuple <double, int, int, int> > E;
int componentes;
double Pu, Pv; 

vector<tu

int main() {
    int casos;
    int test;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        test ++;
        Pu = 0;
        Pv = 0;
        cin >> n >> r >> w >> u >> v;
        componentes = n;
        plano.clear();
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            plano.push_back({x, y});
        }
        E = init_grafo(plano);
        kruskal();
    }


//printTripla(E);
//cout<<componentes<<endl;

//printTripla(crear_grafo(loc));
return 0;
} 