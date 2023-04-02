#include <iostream>
#include <vector>
using namespace std;

/*cuadrado(i,j){
    if(i == n){
        ifEsMagico(m) soluciones ++
    }
    else{
        if(j+1 < n){
            prox_i = i;
            prox_j = j + 1
        } else {
            prox_i = i + 1;
            prox_j = 0;
        }
        if(m[i][j] == 0){                      //else m[prox_i][prox_j]
            for(int k = 1; k <= n^2; k++){
                if(v[k] == 0){                 //v es un vector hasta n de 0s o 1s que me dicen si ya use el numero en cuestion.
                m[i][j] = k;
                v[k] = 1;
                cuadrado(prox_i, prox_j);
        }
    }
}*/
int n;
vector<int> v(n^2, 0);
vector<vector<int>> m(n, vector<int>(n, 0));

vector<vector<int>> construirCuadrado(int i, int j) {
    if (j + 1 < n) {
        int prox_i = i;
        int prox_j = j + 1;
    } else {
        int prox_i = i + 1;
        int prox_j = 0;

        if (m[i][j] == 0) {
            for (int k = 1; k <= n ^ 2; k++) {
                if (v[k] == 0) {
                    m[i][j] = k;
                    v[k] = 1;
                    construirCuadrado(prox_i, prox_j);
                }
                return m;
            }
        }
    }
}


bool esMagico(vector<vector<int>> res){

}

int main(){
    n = 2;
    vector<vector<int>> rta = construirCuadrado(0, 0);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++){
            cout << rta[i][j] << endl;
        }
    }
    return 0;
}