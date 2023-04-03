#include <iostream>
#include <vector>
using namespace std;

int n;
int k;
int numeroMagico;
vector<int> v;
vector<vector<int>> m;
int cont = 0;

bool filaSuperaNumero(int fila , int sum){
    bool res;
    int suma = 0;
    for(int j = 0; j < n; j++){
        suma = suma + m[fila][j];
    }
    res = suma > numeroMagico;
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
    int row_sum, col_sum, diag_sum1, diag_sum2;
    for (int i = 0; i < n; i++) {
        row_sum = col_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += m[i][j];
            col_sum += m[j][i];
            if (filaSuperaNumero(i, numeroMagico) || columnaSuperaNumero(i, numeroMagico)) {
                return false; // poda si la suma excede la suma mágica
            }
        }
        if (row_sum != numeroMagico || col_sum != numeroMagico) {
            return false;
        }
    }
    diag_sum1 = diag_sum2 = 0;
    for (int i = 0; i < n; i++) {
        diag_sum1 += m[i][i];
        diag_sum2 += m[i][n-i-1];
    }
    if (diag_sum1 != numeroMagico || diag_sum2 != numeroMagico) {
        return false;
    }
    return true;
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
        if (m[i][j] == 0) {
            for (int x = 1;x <= n*n; x++) {
                if (v[x - 1] == 0) {                        //v es un vector de 0 a n^2 que me dice si el elemento x esta usado o no en la matriz
                    m[i][j] = x;
                    v[x - 1] = 1;
                    //if(!filaSuperaNumero(i , numeroMagico) && !columnaSuperaNumero(j, numeroMagico)){
                        //construirCuadrado(prox_i, prox_j);
                    //}
                    if(construirCuadrado(prox_i, prox_j)){
                        return true;
                    }
                    v[x - 1] = 0;
                    construirCuadrado(i, j);
                }
            }
        } else construirCuadrado(prox_i, prox_j);
    }
}


int main(){
    cin >> n;
    cin >> k;
    numeroMagico = ((n * n * n +n)/2);
    m = vector(n, vector<int>(n, 0));
    v = vector(n*n, 0);
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