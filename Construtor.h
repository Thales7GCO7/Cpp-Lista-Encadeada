#ifndef CONSTRUTOR_H
#define CONSTRUTOR_H

struct No {
    int data;
    No* proximo;

    No(int valor){
        data = valor;
        proximo = nullptr;
    }
};

#endif