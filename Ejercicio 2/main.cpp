#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, r;
vector<int> v;
unordered_map<int, bool> dp; // Tabla de programación dinámica

int power(int x, int y) {
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

bool busqueda(int i, int acum) {
    int key = i * 10000 + acum; // Crear una clave única basada en 'i' y 'acum'

    // Si el valor ya se encuentra en la tabla de programación dinámica, lo devolvemos
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

    if (i == n) { // Si llegamos al final del vector
        // Comprobamos si el acumulador es igual al resto deseado
        bool res = (acum % m) == r;
        dp[key] = res; // Guardamos el resultado en la tabla de programación dinámica
        return res;
    }

    long long int multi = (acum * v[i]) % m;
    // Hacemos las llamadas recursivas y actualizamos el valor de la tabla de programación dinámica
    bool res = busqueda(i + 1, (acum + v[i]) % m) ||
               busqueda(i + 1, multi) ||
               busqueda(i + 1, ((acum - v[i]) + m) % m) || // Agregamos la recursión con la resta
               busqueda(i + 1, power(acum, v[i]));
    dp[key] = res; // Guardamos el resultado en la tabla de programación dinámica
    return res;
}

int main() {
    int c;
    cin >> c; // Cantidad de casos
    while (c--) {
        cin >> n >> r >> m; // n = tamaño del vector, r = resto, m = módulo
        v.resize(n); // Redefinimos el vector con tamaño n
        for (int i = 0; i < n; i++) { // Inicializamos el vector
            int x;
            cin >> x;
            v[i] = x;
        }
        dp.clear(); // Limpiamos la tabla de programación dinámica
        if (busqueda(0, 0)) {
            cout << "Si" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}