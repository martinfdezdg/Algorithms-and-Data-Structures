
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

bool resuelveCaso(){
    int n,gravedad;
    char tipo;
    std::string nombre;
    std::cin >> n;
    
    if (n == 0) return false;
    // <gravedad,espera,nombre>
    PriorityQueue<std::pair<std::pair<int,int>,std::string>,std::greater<>> pacientes;
    
    for (int i = 0; i < n; ++i){
        std::cin >> tipo;
        if (tipo == 'I'){
            std::cin >> nombre >> gravedad;
            pacientes.push({{gravedad,n-i},nombre});
        }
        else {
            std::cout << pacientes.top().second << '\n';
            pacientes.pop();
        }
    }

    std::cout << "---\n";
    
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/Ordenando a los pacientes en urgencias/Ordenando a los pacientes en urgencias/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    return 0;
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
}
