#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da advinhação! *" << endl;
    cout << "*************************************" << endl;
    cout << endl;
    
	srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    //cout << "O número secreto é " << NUMERO_SECRETO<< endl;

    int chute = 0;
    bool acertou;
	bool nao_acertou = true;
    bool maior;
	bool fim_de_jogo = false;
	int tentativas = 0;

	int escolha;
	int tentativas_maximas = 0;

	double pontuacao = 1000.0;

	cout.precision(2);
	cout << fixed; 

	cout << endl << "Qual o nível de dificuldade desejada? (1) Fácil, (2) Médio ou (3) difícil?" << endl;
	cin >> escolha; 
	cout << endl;
		
	if( escolha == 1){
		tentativas_maximas = 15;	
	}else if(escolha == 2){
		tentativas_maximas = 10;
	}else if(escolha == 3){
		tentativas_maximas = 5;
	}else{
		cerr << "Valor inserido não válido   "; 
		return 0;	
	}

    while(!fim_de_jogo){
        
		tentativas++;
        cout << "Qual o seu chute? ";
        cin >> chute; 
		cout << endl << "Tentaiva" << tentativas << endl;
        cout << endl << "O valor do seu chute é " << chute << endl;

        maior = chute > NUMERO_SECRETO;
        nao_acertou = chute != NUMERO_SECRETO;

		pontuacao = pontuacao - abs(chute-NUMERO_SECRETO)/2.0;
        if (maior){
            cout << "O seu chute é maior que o número secreto" << endl;
        }else {
            cout << "O seu chute é menor que o número secreto" << endl;
        }
		fim_de_jogo = !nao_acertou || tentativas == tentativas_maximas;	
    }

	if(nao_acertou){
		cout << "Você perdeu, tente novamente" << endl;
	}else {
    	cout << " Você acertou o número secreto em " << tentativas << " tentativas" << endl;
		cout << "Sua pontuação foi " << pontuacao << endl;
	}
	cout << "Fim de Jogo";
}
