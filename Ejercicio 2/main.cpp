#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// declaracion de variables globales
int n; int m; int r; int c;
vector<int> v;
map<pair<int, int>, int> dynamic_map;
vector<string> resultados;
// -------------------------------


bool busqueda(int i, int acum){
    if (i == n) {
        return acum % m == r;
    }
    if (dynamic_map.find({i, acum}) != dynamic_map.end()) {
        return dynamic_map[{i, acum}];
    }

    bool resta = busqueda(i + 1, acum - v[i]);
    bool suma = busqueda(i + 1, acum + v[i]);
    bool producto = busqueda(i + 1, acum * v[i]);
    bool potencia = busqueda(i + 1, pow (acum, v[i]));

    return resta || suma || producto || potencia;
}

int main() {
    cin >> c; // cantidad de casos
    resultados.resize(c, "");
    for(int j = 0; j < c; j++){
        cin >> n >> r >> m; // n = tamaño del vector, r = resto, m = modulo
        v.resize(n); // redefinir vector con tamaño n
        for (int i = 0; i < n; i++) { // inicializar vector
            int x; 
            cin >> x;
            v[i] = x;
        }
        if (busqueda(0, 0)){
            resultados.push_back("Si");
        }
        else{
            resultados.push_back("No");
        }
    }
    for(int j = 0; j < c; j++){
        cout << resultados[j] << endl; // imprimir los resultados
    }
    return 0;
}
