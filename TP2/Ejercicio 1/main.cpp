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
vector<pair<int,int>> puentes; //guarda las aristas puente



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
            if(low[v] > desc[u]){
            puentes.push_back({u,v});
            }
        }
        else low[u] = min(low[u],desc[v]);
    }
}


void borrar(int u,int v){
    for(int i = 0; i < grafo[u].size(); i++){
        if(grafo[u][i] == v){
            grafo[u].erase(grafo[u].begin() + i);
            break;
        }
    }
    for(int j = 0; j < grafo[v].size(); j++){
        if(grafo[v][j] == u){
            grafo[v].erase(grafo[v].begin() + j);
            break;
        }
    }
}

void eliminarPuentes(){
    for(int i = 0; i < puentes.size(); i++){
        int u = puentes[i].first;
        int v = puentes[i].second;
        borrar(u,v);
    }
}


int main(){
    cin >> n >> m;
    grafo = vector<vector<int>>(n+1);
    desc = vector<int>(n+1,-1);
    low = vector<int>(n+1,-1);
    visitados = vector<bool>(n+1,false);
    while (m--){ // Inicializo las lista de adyacencia
        int u,v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    guardarPuentes(1,-1);
    eliminarPuentes();
    //cout << setprecision(5) << prob << '\n';
    return 0;
}