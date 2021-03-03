
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

bool resuelveCaso(){
    int N,C,tiempo,caja;
    std::cin >> N >> C;
    
    if (N == 0 && C == 0) return false;
    PriorityQueue<std::pair<int,int>> cajas;
    
    for (int i = 1; i <= N; ++i){
        cajas.push({0,i});
    }
    
    for (int i = 1; i <= C; ++i){
        std::cin >> tiempo;
        cajas.push({cajas.top().first + tiempo,cajas.top().second});
        cajas.pop();
    }
    
    std::cout << cajas.top().second << '\n';
    
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Reina del súper/Reina del súper/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    return 0;
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
}
