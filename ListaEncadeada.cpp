#include <iostream>
#include <memory> //Ponteiros inteligentes
#include "Construtor.h"

using namespace std;

class ListaEncadeada{
    private:
    No * inicio;
    No * fim;

    //Construtor
    public:
    ListaEncadeada(){
        inicio = nullptr;
        fim = nullptr;
    }

    ~ListaEncadeada(){
        No * atual = inicio;
        while (atual != nullptr){
            No * proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }

    //Adicionar elemento
    void adicionar (const int & valor){
        No * novo = new No(valor);//Alocação dinâmica

        if(inicio == nullptr){
            inicio = fim = novo;
        } else {
            fim -> proximo = novo;
            fim = novo;
        }
    }

    //Remover elemento
    bool remover(int valor){
        No * atual = inicio;
        No * anterior = nullptr;

        while (atual != nullptr && atual->data != valor){
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == nullptr){
            return false;
        }

        if(anterior == nullptr){
            inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        if (atual == fim){
            fim = anterior;
        }

        delete atual;
        return true;        
    }

    //Exibe a lista (usando ponteiros)
    void mostrar() const {
        const No* atual = inicio; //Ponteiro constante
        cout << "Lista: [";
        while (atual != nullptr){
            cout << atual->data;
            if (atual->proximo != nullptr){
                cout << ", ";
            }
            atual = atual -> proximo;
        }
        cout << "]" << endl;
    }

    //Demonstração de arimética de ponteiros
    void ponteiroAritmetico(){
        if(inicio == nullptr){
            cout << "Lista vazia - Não é possível mostrar o primeiro elemento." << endl;
            return;
        }

        cout << "\nDemonstração de artimética de ponteiros: " << endl;

        //Mostra endereços de memória
        cout << "Endereço de memória do primeiro elemento: " << &inicio << endl;
        cout << "Conteúdo armazenado no endereço de memória do primeiro elemento: " << inicio->data << endl;

        //Acessando o segundo elemento caso exista
        if(inicio->proximo != nullptr){
            cout << "Endereço de memória do segundo elemento: " << inicio->proximo << endl;
            cout << "Conteúdo armazenado no endereço de memória do segundo elemento: " << inicio->proximo->data << endl;
            cout << "Diferença entre endereços em bytes: " 
            << reinterpret_cast<char*>(inicio->proximo) - reinterpret_cast<char*>(inicio)
            << endl;
        }
    }

    //Função que demonstra o uso de smart pointers (unique_ptr)
    void ponteiroInteligente(){
        cout << "\nDemonstração de smart pointers: " << endl;

        //Cria um unique_ptr que gerencia a memória automaticamente
        unique_ptr<No> ponteiroInteligente(new No(99));

        cout << "No criado com smart pointer, valor: " << ponteiroInteligente->data << endl;
        cout << "Endereço gerenciado pelo smart pointer: " << ponteiroInteligente.get() << endl;

        //O smart pointer será automaticamente deletado quando sair do escopo
    }

};