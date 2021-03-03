
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

long int calcularCoste(PriorityQueue<long int> sumandos){
    long int coste = 0, suma = 0;
    while (sumandos.size() > 1){
        suma = sumandos.top();
        sumandos.pop();
        suma += sumandos.top();
        sumandos.pop();
        
        if (!sumandos.empty()) sumandos.push(suma);
        coste += suma;
    }
    return coste;
}

bool resuelveCaso(){
    long int N, elem;
    std::cin >> N;
    
    if (N == 0) return false;
    PriorityQueue<long int> sumandos;
    
    for (int i = 0; i < N; ++i){
        std::cin >> elem;
        sumandos.push(elem);
    }
    
    std::cout << calcularCoste(sumandos) << '\n';
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Lo que cuesta sumar/Lo que cuesta sumar/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    return 0;
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
}
