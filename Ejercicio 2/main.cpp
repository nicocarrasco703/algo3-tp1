#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int n; int m; int r;
vector<int> v;
map<pair<int, int>, int> dynamic_map;

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
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    return 0;
}
