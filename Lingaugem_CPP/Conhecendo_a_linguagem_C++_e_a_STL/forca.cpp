#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

// Definição de variáveis globais
const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

//Funções utilizadas no código 
bool letra_existe(char chute){

	// for na forma do C++ normal
	//for(int i = 0; i < PALAVRA_SECRETA.size(); i++){
	//	if(chute == PALAVRA_SECRETA[i]){
	//		return true;
	//	}
	//}

	// for na forma do c++11
	for(char letra : PALAVRA_SECRETA){
		if(chute == letra){
			return true;
		}
	}
	return false; 
}

bool nao_acertou(){
	for(char letra : PALAVRA_SECRETA){
		if(!chutou[letra]){
			return true;
		}
	}
	return false;
}

bool nao_enforcou(){
	return chutes_errados.size() < 5;
}

int main () {

	cout << PALAVRA_SECRETA << endl;
	
//	bool nao_acertou = true;
//	bool nao_enforcou = true;
	cout << "***************************\n";
	cout << "****** Jogo da forca ******\n";
	cout << "***************************\n";
	while(nao_acertou() && nao_enforcou()){

		cout << "Chutes errados: ";
		for (char letra : chutes_errados){
			cout << letra << ' ';
		}
		cout << endl; 

		for(char letra : PALAVRA_SECRETA){
			if(chutou[letra]){
				cout << letra << " ";
			}else{
				cout << "_";
			}
		}
		cout << endl;
		


		char chute;
		cin >> chute;

		if(letra_existe(chute)){
			cout << "Você acertou! Seu chute está na palavra." << endl;
			chutou[chute] = true;
		}else{
			cout << "Você errou! Tente novamente" << endl;
			chutes_errados.push_back(chute);
		}
	
	}
	cout << "\n\n";
	if(!nao_enforcou()){
		cout << "Você enforcou! Tente novamente";
	}else{
		cout << "Parabéns!!! Você acertou a palavra secreta!";
	}

}
