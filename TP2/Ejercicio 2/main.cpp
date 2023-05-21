#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> grafo, grafo_rev;
vector<bool> visitados;
vector<int> pila, component;
vector<vector<int>> grafo_condensado;

void dfs1(int v) {
    visitados[v] = true;
    for(auto u : grafo[v]){
        if (!visitados[u]){
            dfs1(u);
        }
    }
    pila.push_back(v);
}

void dfs2(int v) {
    visitados[v] = true;
    component.push_back(v);
    for(auto u : grafo_rev[v]){
        if (!visitados[u]){
            dfs2(u);
        }
    }
}

void condensar(){
    vector<int> raices(n+1, 0);
    vector<int> vertices_raiz;
    vector<vector<int>> grafo_condensado(n+1);

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
    for (int v = 0; v < n; v++)
        for (auto u : grafo[v]) {
            int raiz_v = raices[v];
            int raiz_u = raices[u];
            if (raiz_v != raiz_u){
                grafo_condensado[raiz_v].push_back(raiz_u);
            }
        }
}

void kosaraju() {
    visitados.assign(n + 1, false);
   for (int i = 1; i <= n; i++){
        if (!visitados[i])
            dfs1(i);
    }

    visitados.assign(n+1, false);
    reverse(pila.begin(), pila.end());

    condensar();
}

int main() {
    cin >> n >> m;
    int a, b;
    grafo.assign(n + 1, vector<int>());
    grafo_rev.assign(n + 1, vector<int>());
    // inicializar grafo
    while(m--) {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo_rev[b].push_back(a);
    }
    
    kosaraju();
    
    return 0;
}