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

int main() {
    GrafoMatriz grafoCusto(7);
    GrafoMatriz grafoDistancia(7);
    GrafoMatriz grafoTempo(7);

    // Custo (R$)
    grafoCusto.adicionarAresta(CWB, MAD, 3200);
    grafoCusto.adicionarAresta(CWB, LIS, 3000);
    grafoCusto.adicionarAresta(CWB, PAR, 3500);
    grafoCusto.adicionarAresta(MAD, LIS, 300);
    grafoCusto.adicionarAresta(MAD, ROM, 500);
    grafoCusto.adicionarAresta(MAD, TYO, 3400);
    grafoCusto.adicionarAresta(LIS, PAR, 500);
    grafoCusto.adicionarAresta(LIS, LON, 450);
    grafoCusto.adicionarAresta(LIS, ROM, 500);
    grafoCusto.adicionarAresta(PAR, LON, 450);
    grafoCusto.adicionarAresta(PAR, ROM, 600);
    grafoCusto.adicionarAresta(PAR, TYO, 3500);
    grafoCusto.adicionarAresta(LON, ROM, 450);
    grafoCusto.adicionarAresta(LON, TYO, 3200);
    grafoCusto.adicionarAresta(ROM, TYO, 3000);

    // Distancia (km)
    grafoDistancia.adicionarAresta(CWB, MAD, 8723);
    grafoDistancia.adicionarAresta(CWB, LIS, 8274);
    grafoDistancia.adicionarAresta(CWB, PAR, 9744);
    grafoDistancia.adicionarAresta(MAD, LIS, 514);
    grafoDistancia.adicionarAresta(MAD, ROM, 1329);
    grafoDistancia.adicionarAresta(MAD, TYO, 10770);
    grafoDistancia.adicionarAresta(LIS, PAR, 1470);
    grafoDistancia.adicionarAresta(LIS, LON, 1565);
    grafoDistancia.adicionarAresta(LIS, ROM, 1839);
    grafoDistancia.adicionarAresta(PAR, LON, 492);
    grafoDistancia.adicionarAresta(PAR, ROM, 1101);
    grafoDistancia.adicionarAresta(PAR, TYO, 9710);
    grafoDistancia.adicionarAresta(LON, ROM, 1443);
    grafoDistancia.adicionarAresta(LON, TYO, 9591);
    grafoDistancia.adicionarAresta(ROM, TYO, 9906);

    // Tempo (h)
    grafoTempo.adicionarAresta(CWB, MAD, 14.0);
    grafoTempo.adicionarAresta(CWB, LIS, 11.0);
    grafoTempo.adicionarAresta(CWB, PAR, 17.0);
    grafoTempo.adicionarAresta(MAD, LIS, 1.3);
    grafoTempo.adicionarAresta(MAD, ROM, 2.5);
    grafoTempo.adicionarAresta(MAD, TYO, 14.0);
    grafoTempo.adicionarAresta(LIS, PAR, 2.7);
    grafoTempo.adicionarAresta(LIS, LON, 2.8);
    grafoTempo.adicionarAresta(LIS, ROM, 3.0);
    grafoTempo.adicionarAresta(PAR, LON, 2.3);
    grafoTempo.adicionarAresta(PAR, ROM, 2.1);
    grafoTempo.adicionarAresta(PAR, TYO, 14.0);
    grafoTempo.adicionarAresta(LON, ROM, 2.6);
    grafoTempo.adicionarAresta(LON, TYO, 14.0);
    grafoTempo.adicionarAresta(ROM, TYO, 12.5);

    cout << "Matriz de Custo (R$):" << endl;
    grafoCusto.imprimir();

    cout << "\nMatriz de Distancia (km):" << endl;
    grafoDistancia.imprimir();

    cout << "\nMatriz de Tempo (h):" << endl;
    grafoTempo.imprimir();

    return 0;
}
