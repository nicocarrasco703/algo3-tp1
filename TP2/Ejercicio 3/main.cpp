// Modems
#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int>> localizacion;
int n, r, w, u, v;
//vector<tuple <double, int, int, int> > grafo;
int componentes;
double Pu, Pv; 
const char UTP = 'U';
const char Fibra = 'F';


struct DSU{

    DSU(int n){
        padre = rank = vector<int>(n);
        for(int v = 0; v < n; v++) padre[v] = v;
    }

    int find(int v){
        if(v == padre[v]) return v;
        return padre[v] = find(padre[v]);
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u,v);
        padre[v] = padre[u];
        rank[u] = max(rank[u],rank[v]+1);
    }

    vector<int> padre;
    vector<int> rank;
};


int distancia(int x1, int y1, int x2, int y2){
    return sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
}

vector<tuple<double, int, int, char>> init_grafo(vector<tuple<int, int>> &p){
    double costo;
    char tipo;
    vector<tuple<double, int, int, char>> aristas;
    for(int i = 0; i < p.size(); i++){
        for(int j = i+1; j < p.size(); j++){
            int x1 = get<0>(p[i]);
            int y1 = get<1>(p[i]);
            int x2 = get<0>(p[j]);
            int y2 = get<1>(p[j]);
            int d = distancia(x1, y1, x2, y2);
            if(d <= r){
                costo = u * d;
                tipo = UTP;
            } else {
                costo = v * d;
                tipo = Fibra;
            }
            aristas.push_back({costo, i, j, tipo});
        }
    }
    return aristas;
}


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
        localizacion.clear();

        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            localizacion.push_back({x, y});
        }
        E = init_grafo(localizacion);
        // kruskal();
    }


//printTripla(E);
//cout<<componentes<<endl;

//printTripla(crear_grafo(loc));
return 0;
} 