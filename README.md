# Viagem-Internacional-EDNL

Bloco mermaid gerado do grafo dos caminhos possíveis
```mermaid
graph LR
    CWB["Curitiba"]
    MAD["Madri"]
    LIS["Lisboa"]
    PAR["Paris"]
    ROM["Roma"]
    LON["Londres"]
    TYO["Tóquio"]

    CWB --- MAD
    CWB --- LIS
    CWB --- PAR

    MAD --- ROM
    LIS --- ROM
    PAR --- ROM
    LIS --- LON
    PAR --- LON

    ROM --- TYO
    LON --- TYO
    MAD --- TYO
    PAR --- TYO

    MAD --- LIS
    LIS --- PAR
    ROM --- LON
```

## Todos os voos e seus pesos de viagem, custo, distancia e tempo:
Todos os preços são um valor aproximado, os valores mudam constantemente por causa de data, aerolíneas e etc.

| # | Trecho | Transporte | Custo (R$) | Distância (km) | Tempo (h) |
|---|---|---|---:|---:|---:|
| 1 | Curitiba – Madri | Avião (1 escala) | 3.200 | 8.723 | 14,0 |
| 2 | Curitiba – Lisboa | Avião (direto) | 3.000 | 8.274 | 11,0 |
| 3 | Curitiba – Paris | Avião (1 escala) | 3.500 | 9.744 | 17,0 |
| 4 | Madri – Lisboa | Avião (direto) | 300 | 514 | 1,3 |
| 5 | Madri – Roma | Avião (direto) | 500 | 1.329 | 2,5 |
| 6 | Madri – Tóquio | Avião (direto) | 3.400 | 10.770 | 14,0 |
| 7 | Lisboa – Paris | Avião (direto) | 500 | 1.470 | 2,7 |
| 8 | Lisboa – Londres | Avião (direto) | 450 | 1.565 | 2,8 |
| 9 | Lisboa – Roma | Avião (direto) | 500 | 1.839 | 3,0 |
| 10 | Paris – Londres | Trem (Eurostar) | 450 | 492 | 2,3 |
| 11 | Paris – Roma | Avião (direto) | 600 | 1.101 | 2,1 |
| 12 | Paris – Tóquio | Avião (direto) | 3.500 | 9.710 | 14,0 |
| 13 | Londres – Roma | Avião (direto) | 450 | 1.443 | 2,6 |
| 14 | Londres – Tóquio | Avião (direto) | 3.200 | 9.591 | 14,0 |
| 15 | Roma – Tóquio | Avião (direto) | 3.000 | 9.906 | 12,5 |

**Critérios:**
- **Custo:** passagem econômica só de ida, valor típico pesquisado em novembro de 2026.
- **Distância:** linha reta entre os aeroportos; Paris–Londres usa a distância pelos trilhos do Eurostar.
- **Tempo:** duração total da viagem, incluindo escalas.

## Matrizes de adjacência

Ordem das cidades: Curitiba (CWB), Madri (MAD), Lisboa (LIS), Paris (PAR), Londres (LON), Roma (ROM), Tóquio (TYO).
**∞** = não existe ligação direta. **0** = a própria cidade. As matrizes são simétricas porque o grafo é não-direcionado.

### Custo (R$)

| | CWB | MAD | LIS | PAR | LON | ROM | TYO |
|---|---:|---:|---:|---:|---:|---:|---:|
| **CWB** | 0 | 3.200 | 3.000 | 3.500 | ∞ | ∞ | ∞ |
| **MAD** | 3.200 | 0 | 300 | ∞ | ∞ | 500 | 3.400 |
| **LIS** | 3.000 | 300 | 0 | 500 | 450 | 500 | ∞ |
| **PAR** | 3.500 | ∞ | 500 | 0 | 450 | 600 | 3.500 |
| **LON** | ∞ | ∞ | 450 | 450 | 0 | 450 | 3.200 |
| **ROM** | ∞ | 500 | 500 | 600 | 450 | 0 | 3.000 |
| **TYO** | ∞ | 3.400 | ∞ | 3.500 | 3.200 | 3.000 | 0 |

### Distância (km)

| | CWB | MAD | LIS | PAR | LON | ROM | TYO |
|---|---:|---:|---:|---:|---:|---:|---:|
| **CWB** | 0 | 8.723 | 8.274 | 9.744 | ∞ | ∞ | ∞ |
| **MAD** | 8.723 | 0 | 514 | ∞ | ∞ | 1.329 | 10.770 |
| **LIS** | 8.274 | 514 | 0 | 1.470 | 1.565 | 1.839 | ∞ |
| **PAR** | 9.744 | ∞ | 1.470 | 0 | 492 | 1.101 | 9.710 |
| **LON** | ∞ | ∞ | 1.565 | 492 | 0 | 1.443 | 9.591 |
| **ROM** | ∞ | 1.329 | 1.839 | 1.101 | 1.443 | 0 | 9.906 |
| **TYO** | ∞ | 10.770 | ∞ | 9.710 | 9.591 | 9.906 | 0 |

### Tempo (h)

| | CWB | MAD | LIS | PAR | LON | ROM | TYO |
|---|---:|---:|---:|---:|---:|---:|---:|
| **CWB** | 0 | 14,0 | 11,0 | 17,0 | ∞ | ∞ | ∞ |
| **MAD** | 14,0 | 0 | 1,3 | ∞ | ∞ | 2,5 | 14,0 |
| **LIS** | 11,0 | 1,3 | 0 | 2,7 | 2,8 | 3,0 | ∞ |
| **PAR** | 17,0 | ∞ | 2,7 | 0 | 2,3 | 2,1 | 14,0 |
| **LON** | ∞ | ∞ | 2,8 | 2,3 | 0 | 2,6 | 14,0 |
| **ROM** | ∞ | 2,5 | 3,0 | 2,1 | 2,6 | 0 | 12,5 |
| **TYO** | ∞ | 14,0 | ∞ | 14,0 | 14,0 | 12,5 | 0 |