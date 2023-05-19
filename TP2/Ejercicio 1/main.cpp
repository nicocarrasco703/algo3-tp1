//king graffs defense

#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;
typedef long long ll;

vector<vector<int>> grafo;      // Lista de adyacencia.
ll n; ll m;
ll prob;
vector<int> desc;            //momento en el que descubri cada nodo (si es -1 no lo descubri)
vector<int> low;             //minimo nivel al que puedo llegar a traves de backedges
int tiempo = 0;
vector<bool> visitados;
map<pair<int,int>, bool> puentes;



void guardarPuentes(int u, int p){     //quiero guardar en un vector todas las aristas puente para luego eliminarlas
    visitados[u] = true;
    tiempo++;
    desc[u] = tiempo;
    low[u] = tiempo;
    for(int i = 0; i < grafo[u].size(); i++){
        int v = grafo[u][i];
        if(v == p) continue;
        if(!visitados[v]){
            guardarPuentes(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > desc[u])
            puentes[{u,v}] = true;
            puentes[{v,u}] = true;
        }
        else low[u] = min(low[u],desc[v]);
    }
}


bool esPuente(int u, int v){
    return puentes[{u,v}] || puentes[{v,u}];
}



void eliminarPuentes(){
    for(int u = 0; u <  grafo.size(); u++){
        for(int v : grafo[u]){
            if(esPuente(u,v)){
                grafo[u].erase(grafo[u].begin() + v);
                grafo[v].erase(grafo[v].begin() + u);
            }
        }
    }
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){ // Inicializo las lista de adyacencia
        int u,v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    //cout << setprecision(5) << prob << '\n';
    return 0;
}