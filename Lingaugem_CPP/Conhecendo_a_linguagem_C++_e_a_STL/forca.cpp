#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

// Definição de variáveis globais
string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

//Funções utilizadas no código 
bool letra_existe(char chute){

	// for na forma do C++ normal
	//for(int i = 0; i < palavra_secreta.size(); i++){
	//	if(chute == palavra_secreta[i]){
	//		return true;
	//	}
	//}

	// for na forma do c++11
	for(char letra : palavra_secreta){
		if(chute == letra){
			return true;
		}
	}
	return false; 
}

bool nao_acertou(){
	for(char letra : palavra_secreta){
		if(!chutou[letra]){
			return true;
		}
	}
	return false;
}

bool nao_enforcou(){
	return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
	cout << "***************************\n";
	cout << "****** Jogo da forca ******\n";
	cout << "***************************\n";
}

vector<string> le_arquivo(){
	ifstream arquivo;
	arquivo.open("palavras.txt");

	if(arquivo.is_open()){
	
		int quantidade_de_palavras;
		arquivo >> quantidade_de_palavras;
	
		string palavra; 
		vector<string> lista_de_palavras;
		for(int i = 0; i < quantidade_de_palavras ; i++){
			arquivo >> palavra;
			lista_de_palavras.push_back(palavra);
		}
	
		// é uma boa prática sempre fechar o arquivo
		arquivo.close();
		return lista_de_palavras;
	}
	else{
		cout << "Não foi possível acessar o banco de palavras";
		exit(0);
	}
}

void sorteia_palavra(){
	vector<string> palavras = le_arquivo();

	srand(time(NULL));
	int indice_sorteado = rand() % palavras.size();
	palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista){
	
	ofstream arquivo;
	arquivo.open("palavras.txt");
	if(arquivo.is_open()){
		arquivo << nova_lista.size() << endl;
		for(string palavra : nova_lista){
			arquivo << palavra << endl;
		}

		arquivo.close();
	}
	else{ 
		cout << "Não foi possível acessar o banco de palavras";
		exit(0);	
	}
}

void adiciona_palavra(){
	cout << "Digite a nova palavra, usando apenas letras maiúscula." << endl;
	string nova_palavra;
	cin >> nova_palavra;

	vector<string> lista_de_palavras = le_arquivo();
	lista_de_palavras.push_back(nova_palavra);

	salva_arquivo(lista_de_palavras);
}



int main () {

	imprime_cabecalho();

	sorteia_palavra();
//	cout << palavra_secreta << endl;
	
//	bool nao_acertou = true;
//	bool nao_enforcou = true;
	
	while(nao_acertou() && nao_enforcou()){

		cout << "Chutes errados: ";
		for (char letra : chutes_errados){
			cout << letra << ' ';
		}
		cout << endl; 

		for(char letra : palavra_secreta){
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
	cout << "A palavra secreta é: " << palavra_secreta; 

	if(!nao_enforcou()){
		cout << "Você enforcou! Tente novamente";
	}else{
		cout << "Parabéns!!! Você acertou a palavra secreta!\n";

		cout << "Você deseja adicionar uma nova palavra ao banco? (S/N)\n";
		char resposta;
		cin >> resposta;
		if (resposta == 'S'){
			adiciona_palavra();
		}
	}

}
