
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

// <orden,id,p>
void envios(PriorityQueue<std::pair<long int,std::pair<long int,long int>>> ucm, long int M){
    long int orden,id,p;
    for (int i = 0; i < M; ++i){
        orden = ucm.top().first;
        id = ucm.top().second.first;
        p = ucm.top().second.second;
        ucm.pop();
        
        std::cout << id << '\n';
        
        ucm.push({orden + p,{id,p}});
    }
}

bool resuelveCaso(){
    long int N,id,p,M;
    std::cin >> N;
    
    if (N == 0) return false;
    PriorityQueue<std::pair<long int,std::pair<long int,long int>>> ucm;
    
    for (int i = 0; i < N; ++i){
        std::cin >> id >> p;
        ucm.push({p,{id,p}});
    }
    
    std::cin >> M;
    envios(ucm,M);
    std::cout << "---\n";
    
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Unidad Curiosa de Monitorización/Unidad Curiosa de Monitorización/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    return 0;
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
}
