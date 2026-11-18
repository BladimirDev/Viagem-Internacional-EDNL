#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
using namespace std;

const double INF = 1e9;
const int N = 7;

const int CWB = 0; // Curitiba
const int MAD = 1; // Madri
const int LIS = 2; // Lisboa
const int PAR = 3; // Paris
const int LON = 4; // Londres
const int ROM = 5; // Roma
const int TYO = 6; // Toquio

string nomes[N] = {"Curitiba", "Madri", "Lisboa", "Paris", "Londres", "Roma", "Toquio"};

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

    void imprimir() {
        cout << setw(10) << " ";
        for (int j = 0; j < numVertices; j++) 
        {
            cout << setw(10) << nomes[j];
        }
        cout << endl;

        for (int i = 0; i < numVertices; i++) {
            cout << setw(10) << nomes[i];
            for (int j = 0; j < numVertices; j++) 
            {
                if (matriz[i][j] == INF) {
                    cout << setw(10) << "-";
                } else {
                    cout << setw(10) << matriz[i][j];
                }
            }
            cout << endl;
        }
    }

    void removerAresta(int origem, int destino)
    {
        if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices && origem != destino)
        {
            matriz[origem][destino] = INF;
            matriz[destino][origem] = INF;
        }
    }

    bool existeAresta(int origem, int destino)
    {
        return origem != destino && matriz[origem][destino] != INF;
    }

    double obterPeso(int origem, int destino)
    {
        return matriz[origem][destino];
    }

    bool ehConexo() {
        vector<bool> visitado(numVertices, false);
        queue<int> fila;

        visitado[0] = true;
        fila.push(0);
        int contador = 1;

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();

            for (int v = 0; v < numVertices; v++) 
            {
                if (existeAresta(atual, v) && !visitado[v]) 
                {
                    visitado[v] = true;
                    fila.push(v);
                    contador++;
                }
            }
        }
        return contador == numVertices;
    }

    vector<int> dijkstra(int origem, int destino) {
        vector<double> dist(numVertices, INF);
        vector<int> anterior(numVertices, -1);
        vector<bool> visitado(numVertices, false);

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        dist[origem] = 0;
        pq.push({0, origem});

        while (!pq.empty()) 
        {
            int u = pq.top().second;
            pq.pop();

            if (visitado[u]) continue;
            visitado[u] = true;

            for (int v = 0; v < numVertices; v++) 
            {
                if (existeAresta(u, v) && !visitado[v]) 
                {
                    double novaDist = dist[u] + matriz[u][v];
                    if (novaDist < dist[v]) {
                        dist[v] = novaDist;
                        anterior[v] = u;
                        pq.push({novaDist, v});
                    }
                }
            }
        }

        vector<int> caminho;
        if (dist[destino] == INF) {
            return caminho;
        }
        for (int v = destino; v != -1; v = anterior[v]) {
            caminho.insert(caminho.begin(), v);
        }
        return caminho;
    }

    double somarCaminho(vector<int> caminho) {
        double total = 0;
        for (int i = 0; i + 1 < (int)caminho.size(); i++) {
            total += matriz[caminho[i]][caminho[i + 1]];
        }
        return total;
    }

    double prim(string unidade) {
        vector<double> dist(numVertices, INF);
        vector<int> pai(numVertices, -1);
        vector<bool> visitado(numVertices, false);

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});
        double total = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visitado[u]) continue;
            visitado[u] = true;
            total += dist[u];

            if (pai[u] != -1) {
                cout << "  " << nomes[pai[u]] << " - " << nomes[u] << " (" << matriz[pai[u]][u] << " " << unidade << ")" << endl;
            }

            for (int v = 0; v < numVertices; v++) {
                if (existeAresta(u, v) && !visitado[v] && matriz[u][v] < dist[v]) {
                    dist[v] = matriz[u][v];
                    pai[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        return total;
    }
};

GrafoMatriz grafoCusto(N);
GrafoMatriz grafoDistancia(N);
GrafoMatriz grafoTempo(N);

void carregarDados() 
{
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
}

void imprimirMatrizes() 
{
    cout << "\nMatriz de Custo (R$):" << endl;
    grafoCusto.imprimir();

    cout << "\nMatriz de Distancia (km):" << endl;
    grafoDistancia.imprimir();

    cout << "\nMatriz de Tempo (h):" << endl;
    grafoTempo.imprimir();
}

void mostrarRota(string titulo, vector<int> caminho) 
{
    cout << "\n" << titulo << endl;
    if (caminho.empty()) {
        cout << "  Nao existe caminho." << endl;
        return;
    }
    cout << "  Rota: ";
    for (int i = 0; i < (int)caminho.size(); i++) {
        cout << nomes[caminho[i]];
        if (i + 1 < (int)caminho.size()) cout << " -> ";
    }
    cout << endl;
    cout << "  Custo total:     R$ " << grafoCusto.somarCaminho(caminho) << endl;
    cout << "  Distancia total: " << grafoDistancia.somarCaminho(caminho) << " km" << endl;
    cout << "  Tempo total:     " << grafoTempo.somarCaminho(caminho) << " h" << endl;
}

void caminhosMinimos(int origem, int destino) 
{
    cout << "\nCaminhos Minimos (Dijkstra): " << nomes[origem] << " -> " << nomes[destino] << endl;
    mostrarRota("[Menor Custo]", grafoCusto.dijkstra(origem, destino));
    mostrarRota("[Menor Distancia]", grafoDistancia.dijkstra(origem, destino));
    mostrarRota("[Menor Tempo]", grafoTempo.dijkstra(origem, destino));
}

void arvoreGeradoraMinima(int criterio) 
{
    double total;
    if (criterio == 1) {
        cout << "\nArvore Geradora Minima (Prim) - Custo:" << endl;
        total = grafoCusto.prim("R$");
        cout << "  Custo total da AGM: R$ " << total << endl;
    } else if (criterio == 2) {
        cout << "\nArvore Geradora Minima (Prim) - Distancia:" << endl;
        total = grafoDistancia.prim("km");
        cout << "  Distancia total da AGM: " << total << " km" << endl;
    } else {
        cout << "\nArvore Geradora Minima (Prim) - Tempo:" << endl;
        total = grafoTempo.prim("h");
        cout << "  Tempo total da AGM: " << total << " h" << endl;
    }
}

void verificarConexo() 
{
    cout << "\nConexidade:" << endl;
    if (grafoCusto.ehConexo()) {
        cout << "  O grafo e conexo: todas as cidades sao alcancaveis." << endl;
    } else {
        cout << "  O grafo NAO e conexo!" << endl;
    }
}

void listarCidades() 
{
    for (int i = 0; i < N; i++) {
        cout << "  " << i << " - " << nomes[i] << endl;
    }
}

void alterarPeso() 
{
    int a, b, criterio;
    double valor;
    cout << "\nCidades:" << endl;
    listarCidades();
    cout << "Origem: ";
    cin >> a;
    cout << "Destino: ";
    cin >> b;
    if (a < 0 || a >= N || b < 0 || b >= N || a == b) {
        cout << "Cidades invalidas." << endl;
        return;
    }
    cout << "Criterio (1 = custo, 2 = distancia, 3 = tempo): ";
    cin >> criterio;
    cout << "Novo valor (-1 para remover a ligacao): ";
    cin >> valor;

    if (criterio < 1 || criterio > 3) {
        cout << "Criterio invalido." << endl;
        return;
    }

    if (valor < 0) {
        grafoCusto.removerAresta(a, b);
        grafoDistancia.removerAresta(a, b);
        grafoTempo.removerAresta(a, b);
        cout << "Ligacao " << nomes[a] << " - " << nomes[b] << " removida." << endl;
    } else {
        if (criterio == 1) grafoCusto.adicionarAresta(a, b, valor);
        if (criterio == 2) grafoDistancia.adicionarAresta(a, b, valor);
        if (criterio == 3) grafoTempo.adicionarAresta(a, b, valor);
        cout << "Peso atualizado." << endl;
    }
}

int main() 
{
    carregarDados();

    imprimirMatrizes();
    verificarConexo();
    caminhosMinimos(CWB, TYO);
    arvoreGeradoraMinima(1);

    int opcao = -1;
    while (opcao != 0) 
    {
        cout << "\nMenu:" << endl;
        cout << "1 - Mostrar matrizes" << endl;
        cout << "2 - Caminhos minimos (Curitiba -> Toquio)" << endl;
        cout << "3 - Caminhos minimos (escolher origem e destino)" << endl;
        cout << "4 - Arvore Geradora Minima (Prim)" << endl;
        cout << "5 - Alterar ou remover peso de uma aresta" << endl;
        cout << "6 - Verificar se o grafo e conexo" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                imprimirMatrizes();
                break;
            case 2:
                caminhosMinimos(CWB, TYO);
                break;
            case 3: {
                int o, d;
                listarCidades();
                cout << "Origem: ";
                cin >> o;
                cout << "Destino: ";
                cin >> d;
                if (o >= 0 && o < N && d >= 0 && d < N) {
                    caminhosMinimos(o, d);
                } else {
                    cout << "Cidades invalidas." << endl;
                }
                break;
            }
            case 4: {
                int c;
                cout << "Criterio (1 = custo, 2 = distancia, 3 = tempo): ";
                cin >> c;
                arvoreGeradoraMinima(c);
                break;
            }
            case 5:
                alterarPeso();
                break;
            case 6:
                verificarConexo();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    }
    return 0;
}
