#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, r;
vector<int> v;
vector<vector<int> > dp;

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
    if (dp[i][acum] != -1) { // Si ya hemos calculado el resultado
        return dp[i][acum];
    }

    if (i == n ) { // Si llegamos al final del vector
        // Comprobamos si el acumulador es igual al resto deseado
        bool res = (acum % m) == r;
        dp[i][acum] = res;
        return res;
    }
    long long int multi = (acum * v[i]) % m;
    bool res = busqueda(i + 1, (acum + v[i]) % m) ||
               busqueda(i + 1, multi) ||
               busqueda(i + 1, ((acum - v[i]) + m) % m) || // Agregamos la recursión con la resta
               busqueda(i + 1, power(acum, v[i]));
    dp[i][acum] = res;
    return res;
}

int main() {
    int c;
    cin >> c; // Cantidad de casos
    while (c--) {
        cin >> n >> r >> m; // n = tamaño del vector, r = resto, m = módulo
        v.resize(n); // Redefinimos el vector con tamaño n
        //dp.resize(n, vector<int> m); // Redefinimos la matriz con tamaño n,
        dp = vector<vector<int> >(n + 1, vector<int>(m + 1, -1)); // Inicializamos la matriz
        for (int i = 0; i < n; i++) { // Inicializamos el vector
            int x;
            cin >> x;
            v[i] = x;
        }
        if (busqueda(0, 0)) {
            cout << "Si" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}