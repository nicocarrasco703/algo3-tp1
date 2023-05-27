#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Modificar el código de solución según tus necesidades
void solveProblem(int N, int R, int W, int U, int V, vector<tuple<int, int>>& office_positions) {
    // Implementar aquí el código de solución al problema
    // ...
    // ...
}

int main() {
    const string inputDirectory = "./inputs/";  // Directorio de los archivos de entrada
    const string outputFilename = "results.csv";  // Nombre del archivo CSV de salida

    // Abrir el archivo CSV de salida
    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "No se pudo abrir el archivo CSV de salida: " << outputFilename << endl;
        return 1;
    }

    // Escribir encabezado en el archivo CSV
    outputFile << "Tamaño del input, Tiempo (ms)" << endl;

    for (int power = 16; power <= 26; ++power) {
        int n = 1 << power;
        string inputFilename = inputDirectory + "input_" + to_string(n);

        ifstream inputFile(inputFilename);
        if (!inputFile) {
            cerr << "No se pudo abrir el archivo de entrada: " << inputFilename << endl;
            return 1;
        }

        int c;
        inputFile >> c;  // Leer el número de casos de prueba

        // Procesar cada caso de prueba
        for (int i = 0; i < c; ++i) {
            int N, R, W, U, V;
            inputFile >> N >> R >> W >> U >> V;

            vector<tuple<int, int>> office_positions(N);
            for (int j = 0; j < N; ++j) {
                int x, y;
                inputFile >> x >> y;
                office_positions[j] = make_tuple(x, y);
            }

            // Medir el tiempo de ejecución del código de solución
            auto start = high_resolution_clock::now();
            solveProblem(N, R, W, U, V, office_positions);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);

            // Guardar los resultados en el archivo CSV
            outputFile << n << ", " << duration.count() << endl;
        }

        inputFile.close();
    }

    outputFile.close();

    cout << "Proceso completado. Los resultados se han guardado en el archivo: " << outputFilename << endl;

    return 0;
}
