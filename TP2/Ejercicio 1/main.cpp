#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<pair<int,int>> aristas;
vector<int> vertices;
int n; int m;
double prob;

// void calcularProbabilidad(){

// }

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){ // Inicializo las aristas
        int v1; int v2;
        cin >> v1 >> v2;
        aristas.push_back(make_pair(v1,v2));
    }
    for(int i = 1; i <= n; i++){ // Inicializo los vertices
        vertices.push_back(i);
    }
    //cout << setprecision(5) << prob << '\n';
    return 0;
}