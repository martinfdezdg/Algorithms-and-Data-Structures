
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// <bool,h,min,max>
std::pair<bool,std::pair<int,std::pair<int,int>>> esAVL(bintree<int> arbol){
    if (arbol.empty()) return {true,{0,{0,0}}};
    else {
        auto izq = esAVL(arbol.left());
        auto der = esAVL(arbol.right());
        
        int h = std::max(izq.second.first,der.second.first) + 1;
        
        bool r,e,b;
        r = izq.first && der.first;
        e = abs(izq.second.first - der.second.first) <= 1;
        if (arbol.right().empty()) b = izq.second.second.second < arbol.root();
        else b = izq.second.second.second < arbol.root() && arbol.root() < der.second.second.first;
        
        int max,min;
        max = std::max(arbol.root(),der.second.second.second);
        if (arbol.left().empty()) min = arbol.root();
        else min = std::min(arbol.root(),izq.second.second.first);
        
        return {r && e && b,{h,{min,max}}};
    }
}

void resuelveCaso(){
    bintree<int> arbol;
    arbol = leerArbol(-1);
    
    auto AVL = esAVL(arbol);
    
    if (AVL.first) std::cout << "SI\n";
    else std::cout << "NO\n";
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/¿Es un arbol AVL?/¿Es un arbol AVL?/casos.txt");
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
