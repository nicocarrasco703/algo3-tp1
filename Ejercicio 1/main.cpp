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
int sumaParcialFila;
vector<int> fil;
vector<int> col;
int sumaFila;
int sumaColumna;
int sumaDiagonal1;
int sumaDiagonal2;




bool esMagico() {
    for (int i = 0; i < n; i++) {
        sumaFila = 0;
        sumaColumna = 0;
        for (int j = 0; j < n; j++) {
            sumaFila += m[i][j];
            sumaColumna += m[j][i];
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


bool construirCuadrado(int i, int j, vector<int> sumFil, vector<int> sumCol){
    if(i == n){
        if(esMagico()){
            cont++;
            if(cont == k) return true;
        }
    } else {
        if(m[i][j] == 0){
            for(int x = 0; x < n*n; x++){
                if(usados[x+1] == 0){
                    m[i][j] = x + 1;
                    usados[x + 1] = 1;
                    sumFil[i] += x + 1;
                    sumCol[j] += x + 1;
                    if(j + 1 < n){
                        if(sumFil[i] < numeroMagico && !(sumCol[j] > numeroMagico) && construirCuadrado(i, j + 1, sumFil, sumCol))
                            return true;
                        else{
                            m[i][j] = 0;
                            sumFil[i] -= x + 1;
                            sumCol[j] -= x + 1;
                            usados[x + 1] = 0;

                        }
                    } else {
                        if(sumFil[i] == numeroMagico && !(sumCol[j] > numeroMagico) && construirCuadrado(i + 1, 0, sumFil, sumCol))
                            return true;
                        else{
                            m[i][j] = 0;
                            sumFil[i] -= x + 1;
                            sumCol[j] -= x + 1;
                            usados[x + 1] = 0;
                        }
                    }
                }
            }
        }
    } return false;
}


int main(){
    cin >> n;
    cin >> k;
    numeroMagico = ((pow(n,3)+ n)/2);
    m = vector(n, vector<int>(n, 0));
    usados = vector(n*n, 0);
    fil = vector(n, 0);
    col = vector(n, 0);

    if (construirCuadrado(0, 0, fil, col)) {
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
