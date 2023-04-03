#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int k;
int numeroMagico;
vector<int> usados;
vector<vector<int>> m;
int cont = 0;

bool filaSuperaNumero(int fila , int sum){
    bool res;
    int sumaFila = 0;
    for(int j = 0; j < n; j++){
        sumaFila = sumaFila + m[fila][j];
    }
    res = sumaFila > numeroMagico;
    return res;
}

bool columnaSuperaNumero(int col, int sum){
    bool res;
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma = suma + m[i][col];
    }
    res = suma > numeroMagico;
    return res;
}

bool esMagico() {
    int sumaFila;
    int sumaColumna;
    int sumaDiagonal1;
    int sumaDiagonal2;
    for (int i = 0; i < n; i++) {
        sumaFila = sumaColumna = 0;
        for (int j = 0; j < n; j++) {
            sumaFila += m[i][j];
            sumaColumna += m[j][i];
            if (filaSuperaNumero(i, numeroMagico) || columnaSuperaNumero(i, numeroMagico)) {
                return false; // poda si la suma excede la suma mágica
            }
        }
        if (sumaFila != numeroMagico || sumaColumna != numeroMagico) return false;
    }
    sumaDiagonal1 = sumaDiagonal2 = 0;
    for (int i = 0; i < n; i++) {
        sumaDiagonal1 += m[i][i];
        sumaDiagonal2 += m[i][n-i-1];
    }
    if (sumaDiagonal1 != numeroMagico || sumaDiagonal2 != numeroMagico) {
        return false;
    }
    return true;
}

int sumaDeFila(int i, int j){
    int sumx = 0;
    for(int i = 0; i < n; i++){
        sumx = sumx + m[i][j];
    }
}

bool construirCuadrado(int i, int j){
    int prox_i;
    int prox_j;
    if(i == n){
        if(esMagico()) {
            cont++;
            if(cont == k){
                return true;
            }
        }
    }
    else {
        if(j + 1 < n){
            prox_i = i;
            prox_j = j + 1;
        }
        else {
            prox_i = i + 1;
            prox_j = 0;
        }
        if(m[i][j] == 0) {
            for (int x = 0; x < n * n; x++) {
                if (usados[x + 1] == 0) {
                    m[i][j] = x + 1;
                    usados[x + 1] = 1;
                    if (!filaSuperaNumero(i, numeroMagico) && !columnaSuperaNumero(j, numeroMagico) &&
                        construirCuadrado(prox_i, prox_j))
                        return true;
                    usados[x + 1] = 0;
                }
                m[i][j] = 0;
            }
        }
    }
    return false;
}


int main(){
    cin >> n;
    cin >> k;
    numeroMagico = ((pow(n,3)+ n)/2);
    m = vector(n, vector<int>(n, 0));
    usados = vector(n*n, 0);
    if (construirCuadrado(0, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}