#include "ListaEncadeada.cpp"

int main(){
    //Cria uma lista encadeda
    ListaEncadeada lista1;

    //Adiciona elementos
    lista1.adicionar(10);
    lista1.adicionar(20);
    lista1.adicionar(30);
    lista1.adicionar(40);
    
    //Exibe a lista
    lista1.mostrar();

    //Remove um elemento
    lista1.remover(20);
    cout << "\nApós remover o 20: " << endl;
    lista1.mostrar();

    //Demonstração de ponteiros e memória
    lista1.ponteiroAritmetico();

    //Demonstração de smart pointers
    lista1.ponteiroInteligente();

    return 0;
}