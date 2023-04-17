#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// declaracion de variables globales ((a % b) +b )%b
int n; int m; unsigned long int r; int c;
vector<int> v;
vector<string> resultados;
// -------------------------------

unsigned long int power(int x, unsigned int y){
     unsigned long int temp;
     if( y == 0)
       return 1;
     if(y ==1)
        return x % m;
     temp = power(x, y/2);
     if (y%2 == 0)
       return (temp*temp) % m;
     else
       return (x*temp*temp) % m;
  }


bool busqueda(int i, unsigned long int acum, map<pair<int, int>, bool> &dynamic_map){
    pair<int, int> clave = make_pair(i, acum); // creo la clave de antemano para no tener que hacerlo en cada llamada recursiva

    if (dynamic_map.find(clave) != dynamic_map.end()) { // si ya esta definido el valor de la clave, lo devuelvo
        return dynamic_map[clave];
    }

    if (i == n) { // si llegue al final del vector guardo el valor en el diccionario y devuelvo el resultado
        bool res = (acum % m) == r;
        dynamic_map.emplace(clave, res);
        return res;
    }

    unsigned long int restoNeg = (((acum - v[i] )% m) + m) % m;
    
    // hacemos la recursion y guardamos en el diccionario si alguna de ellas da true
    dynamic_map.emplace(clave, busqueda(i + 1, restoNeg, dynamic_map) ||
     busqueda(i + 1, acum + v[i], dynamic_map) ||
      busqueda(i + 1, (acum * v[i]) % m, dynamic_map) || 
      busqueda(i + 1, power(acum, v[i]), dynamic_map));

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