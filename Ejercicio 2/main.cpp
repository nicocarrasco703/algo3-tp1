#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// declaracion de variables globales
int n; int m; int r; int c;
vector<int> v;
vector<string> resultados;
// -------------------------------


bool busqueda(int i, int acum, map<pair<int, int>, bool> &dynamic_map){
    pair<int, int> clave = make_pair(i, acum);

    if (dynamic_map.find(clave) != dynamic_map.end()) {
        return dynamic_map[clave];
    }

    if (i == n) {
        bool res = (acum % m) == r;
        dynamic_map.emplace(clave, res);
        return res;
    }

    bool resta = busqueda(i + 1, acum - v[i], dynamic_map);
    bool suma = busqueda(i + 1, acum + v[i], dynamic_map);
    bool producto = busqueda(i + 1, acum * v[i], dynamic_map);
    bool potencia = busqueda(i + 1, pow (acum, v[i]), dynamic_map);

    dynamic_map.emplace(clave, resta || suma || producto || potencia);
    return dynamic_map[clave];
}

int main() {
    cin >> c; // cantidad de casos
    for(int j = 0; j < c; j++){
        map<pair<int, int>, bool> dynamic_map;
        cin >> n >> r >> m; // n = tamaño del vector, r = resto, m = modulo
        v.resize(n); // redefinir vector con tamaño n
        for (int i = 0; i < n; i++) { // inicializar vector
            int x;
            cin >> x;
            v[i] = x;
        }
        if (busqueda(1, v[0], dynamic_map)){
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