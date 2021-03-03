
// MARTIN FERNANDEZ DE DIEGO

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

struct hotel{
    int inicio,fin;
};

bool ordenar(hotel const& h1, hotel const& h2) {
    return h1.fin < h2.fin || (h1.fin == h2.fin && h1.inicio < h2.inicio);
}

int tuneles(std::vector<hotel> hoteles){
    int tuneles = 0, inicio = 0, fin = 0;
    
    int i = 0;
    while (i < hoteles.size()){
        inicio = hoteles[i].inicio;
        fin = hoteles[i].fin;
        ++i;
        while ( i < hoteles.size() && hoteles[i].inicio < fin){
            if (inicio < hoteles[i].inicio) inicio = hoteles[i].inicio;
            if (fin > hoteles[i].fin) fin = hoteles[i].fin;
            ++i;
        }
        tuneles++;
    }
    
    return tuneles;
}

bool resuelveCaso() {
    int N;
    std::cin >> N;
    
    if (N == 0) return false;
   
    std::vector<hotel> hoteles(N);
    for (int i = 0; i < N; ++i) std::cin >> hoteles[i].inicio >> hoteles[i].fin;
    std::sort(hoteles.begin(),hoteles.end(),ordenar);
    
    std::cout << tuneles(hoteles) << '\n';
    
    return true;
}

int main() {
    #ifndef DOMJUDGE
        std::ifstream in("/Users/martin/Library/Mobile Documents/com~apple~CloudDocs/Cursos/2019:2020/MARP/Problemas JUEZ/¡En primera línea de playa!/¡En primera línea de playa!/casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    
    while (resuelveCaso());
    
    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
    #endif
}
