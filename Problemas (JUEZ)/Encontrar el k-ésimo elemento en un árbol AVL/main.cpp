
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#include "TreeMap_AVL_Mod.h"

bool resuelveCaso() {
    int N;
    std::cin >> N;
    
    if (N == 0) return false;
    
    int x;
    map<int,int> arbol;
    for (int i = 0; i < N; ++i) {
        std::cin >> x;
        arbol.insert(x);
    }
    
    int M;
    std::cin >> M;
    
    int y;
    for (int i = 0; i < M; ++i) {
        std::cin >> y;
        int sol = arbol.find_pos(y);
        
        if (sol == 0) cout << "??\n";
        else std::cout << sol << '\n';
    }
    
    std::cout << "---\n";
    
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Encontrar el k-ésimo elemento en un árbol AVL/Encontrar el k-ésimo elemento en un árbol AVL/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
