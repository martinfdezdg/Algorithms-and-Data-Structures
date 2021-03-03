
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// <b,h>
std::pair<bool,int> estaEquilibrado(bintree<char> arbol){
    if (arbol.empty()) return {true,0};
    else {
        auto eqIzq = estaEquilibrado(arbol.left());
        auto eqDer = estaEquilibrado(arbol.right());
        return {eqIzq.first && eqDer.first && abs(eqIzq.second - eqDer.second) <= 1, std::max(eqIzq.second,eqDer.second) + 1};
    }
}

void resuelveCaso(){
    bintree<char> arbol;
    arbol = leerArbol('.');
    
    auto equilibrado = estaEquilibrado(arbol);
    if (equilibrado.first) std::cout << "SI\n";
    else std::cout << "NO\n";
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/¿Está el arbol equilibrado?/¿Está el arbol equilibrado?/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
}
