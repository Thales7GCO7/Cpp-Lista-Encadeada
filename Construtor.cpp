//Estrutura de nó para a lista encadeada
struct No {
    int data;
    No * proximo; //Ponteiro para o próximo nó

    //Construtor
    No(int valor){
        data = 0;
        proximo = nullptr;
    }
};