
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include <vector>
#include "TreeMap_AVL.h"

std::vector<int> getIntervale(map<int,int> arbol, int k1, int k2){
    std::vector<int> intervale;
    bool k1In = arbol.insert(k1), k2In = arbol.insert(k2);
    
    auto it = arbol.find(k1);
    if (!k1In) intervale.push_back(k1);
    ++it;
    while (k1 != k2 && it->clave != k2){
        intervale.push_back(it->clave);
        ++it;
    }
    if (k1 != k2 && !k2In) intervale.push_back(k2);
    
    return intervale;
}

bool resuelveCaso(){
    int n = 0;
    std::cin >> n;
    
    if (n == 0) return false;
    
    int k1,k2,elem;
    map<int,int> arbol;
    for (int i = 0; i < n; ++i){
        std::cin >> elem;
        arbol.insert(elem);
    }
    std::cin >> k1 >> k2;
    
    
    auto intervale = getIntervale(arbol,k1,k2);
    for (int i = 0; i < intervale.size(); ++i){
        std::cout << intervale[i] << ' ';
    }
    std::cout << '\n';
    
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Rango de claves en un árbol binario de búsqueda/Rango de claves en un árbol binario de búsqueda/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    return 0;
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
}
