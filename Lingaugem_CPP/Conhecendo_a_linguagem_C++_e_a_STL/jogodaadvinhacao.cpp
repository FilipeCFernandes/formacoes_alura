#include<iostream>

using namespace std;

int main(){
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da advinhação! *" << endl;
    cout << "*************************************" << endl;
    cout << endl;
    
    const int NUMERO_SECRETO = 42;

    cout << "O número secreto é " << NUMERO_SECRETO<< endl;

    int chute = 0;
    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    while(!acertou){
        
        cout << "Qual o seu chute? ";
        cin >> chute; 
        cout << endl << "O valor do seu chute é " << chute << endl;

        maior = chute > NUMERO_SECRETO;
        acertou = chute == NUMERO_SECRETO;

        if (maior){
            cout << "O seu chute é maior que o número secreto" << endl;
        }else {
            cout << "O seu chute é menor que o número secreto" << endl;
        }
    }

    cout << " Você acertou o número secreto! ";
}