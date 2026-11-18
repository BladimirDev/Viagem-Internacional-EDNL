#include <iostream>
#include <vector>
#include <string>
using namespace std;

const double INF = 1e9;

const int CWB = 0; // Curitiba
const int MAD = 1; // Madri
const int LIS = 2; // Lisboa
const int PAR = 3; // Paris
const int LON = 4; // Londres
const int ROM = 5; // Roma
const int TYO = 6; // Toquio

string nomes[7] = {"Curitiba", "Madri", "Lisboa", "Paris", "Londres", "Roma", "Toquio"};

class GrafoMatriz {
private:
    int numVertices;
    vector<vector<double>> matriz;

public:
    GrafoMatriz(int vertices) : numVertices(vertices) 
    {
        matriz.resize(vertices, vector<double>(vertices, INF));
        for (int i = 0; i < numVertices; i++) 
        {
            matriz[i][i] = 0;
        }
    }

    void adicionarAresta(int origem, int destino, double peso) 
    {
        if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) 
        {
            matriz[origem][destino] = peso;
            matriz[destino][origem] = peso;
        }
    }

    void imprimir() 
    {
        cout << "\t";
        for (int j = 0; j < numVertices; j++) 
        {
            cout << nomes[j] << "\t";
        }
        cout << endl;

        for (int i = 0; i < numVertices; i++) 
        {
            cout << nomes[i] << "\t";
            for (int j = 0; j < numVertices; j++) 
            {
                if (matriz[i][j] == INF) {
                    cout << "-" << "\t";
                } else {
                    cout << matriz[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
};