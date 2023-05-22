#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll n, m;
vector<vector<int>> grafo, grafo_rev;
vector<bool> visitados;
vector<int> pila, component;
set<int> res;
vector<bool> tiene_entrada, condensado_tiene_entrada;
vector<bool> tiradas;
vector<int> vertices_raiz;



void dfs1(int v) {
    visitados[v] = true;
    for(auto u : grafo[v]){
        if (!visitados[u]){
            dfs1(u);
        }
    }
    pila.push_back(v);
}

void dfs2(int v){
    visitados[v] = true;
    component.push_back(v);
    for(auto u : grafo_rev[v]){
        if (!visitados[u]){
            dfs2(u);
        }
    }
}

void condensar(){
    vector<int> raices(n + 1, 0);
    vector<vector<int>> grafo_condensado(n + 1);    

    for(auto v : pila){
        if (!visitados[v]) {
            dfs2(v);

            //condensar grafo
            int raiz = component.front();
            for (auto u : component){
                raices[u] = raiz;
            }
            vertices_raiz.push_back(raiz);

            component.clear();
        }
    }
    // armar grafo condensado
    for (int v = 1; v <= n; v++)
        for (int u : grafo[v]) {
            int raiz_v = raices[v];
            int raiz_u = raices[u];
            if (raiz_v != raiz_u){
                grafo_condensado[raiz_v].push_back(raiz_u);
                condensado_tiene_entrada[raiz_u] = true;
            }
        }
}

void kosaraju() {
   visitados = vector<bool>(n + 1, false);
   for (int i = 1; i <= n; i++){
        if (!visitados[i] && !tiradas[i])
            dfs1(i);
    }

    visitados.assign(n+1, false);
    reverse(pila.begin(), pila.end());

    condensar();
}


void tirar(int u){
    tiradas[u] = true;
    for(int v : grafo[u]){
        if(!tiradas[v]){
            tirar(v);
        }
    }
}


int main() {
    cin >> n >> m;
    int a, b;
    grafo.assign(n + 1, vector<int>());
    grafo_rev.assign(n + 1, vector<int>());

    tiene_entrada.assign(n + 1, false);
    condensado_tiene_entrada.assign(n + 1, false);
    
    tiradas.assign(n + 1, false);

    // inicializar grafo
    while(m--) {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo_rev[b].push_back(a);
    }



    kosaraju();

    for(int u : vertices_raiz){
        if(!condensado_tiene_entrada[u]){
            res.insert(u);
            tirar(u);
        }
    }

    cout << res.size()<< endl;
    for(int i : res){
        cout << i << " ";
    }
    
    return 0;
}