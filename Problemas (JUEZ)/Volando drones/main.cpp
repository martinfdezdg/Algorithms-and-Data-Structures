
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

bool resuelveCaso() {
    int N, A, B, horas;
    
    std::cin >> N >> A >> B;
    if (!std::cin) return false;
    
    PriorityQueue<int,std::greater<int>> pilasA, pilasB;
    
    for (int i = 0; i < A; ++i){
        std::cin >> horas;
        pilasA.push(horas);
    }
    for (int i = 0; i < B; ++i){
        std::cin >> horas;
        pilasB.push(horas);
    }
    
    while (!pilasA.empty() && !pilasB.empty()){
        int sol = 0;
        std::vector<int> auxA, auxB;
        for (int i = 0; i < N && !pilasA.empty() && !pilasB.empty(); ++i){
            int pilaA = pilasA.top();
            int pilaB = pilasB.top();
            pilasA.pop();
            pilasB.pop();
            
            if (pilaA == pilaB) sol += pilaA;
            else if (pilaA > pilaB){
                auxA.push_back(pilaA - pilaB);
                sol += pilaB;
            }
            else {
                auxB.push_back(pilaB - pilaA);
                sol += pilaA;
            }
        }
        std::cout << sol << ' ';
        for (int i = 0; i < auxA.size(); ++i) pilasA.push(auxA[i]);
        for (int i = 0; i < auxB.size(); ++i) pilasB.push(auxB[i]);
    }
    
    std::cout << "\n";
    
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Volando drones/Volando drones/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
    return 0;
}
