#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// declaracion de variables globales
int n; int m; int r;
vector<int> v;
map<pair<int, int>, int> dynamic_map;
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
    cin >> n >> r >> m; // n = tamaño del vector, r = resto, m = modulo
    for (int i = 0; i < n; i++) { // inicializar vector
        int x; cin >> x;
        v.push_back(x);
    }
    bool res = busqueda(0, 0);
    if (res){
        cout << "Si" << endl;
     }
    else{
        cout << "No" << endl;
    }
    return 0;
}
