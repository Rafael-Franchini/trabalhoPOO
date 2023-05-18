//Rafael Alexandre Lima Franchini  109179
//Danilo Henrique Muller 105918
//Otávio Augusto Delatorre Fadini 108999


#include <iostream>
#include <string>
#include <vector>


using namespace std;

class estacao{
private:
	string nome;
	string sigla;
public:
	estacao();	
	void setNome(string nome);
	void setSigla(string sigla);
	string getNome();
	string getSigla();
};
estacao::estacao() {
	nome = "";
	sigla = "";
}
void estacao::setNome(string nome) {
	this->nome = nome;
}
void estacao::setSigla(string sigla) {
	this->sigla = sigla;
}
string estacao::getNome() {
	return nome;
}
string estacao::getSigla() {
	return sigla;
} 
class linha {
private:

public:
};

int main(){
	int op;
	do{
		cout << "0 –Parar execucao " << endl
			<< "1 – criar o grafo  " << endl
			<< "2 – adicionar estação  " << endl
			<< "3 – remover estação " << endl
			<< "4 – busca por uma estação " << endl
			<< "5 – encontrar um caminho determinado entre uma estação e outra retornando o tempo do caminho encontrado, bem como as estações intermediárias " << endl
			<< "6 – encontrar o menor caminho entre uma estação e outra retornando o tempo encontrado e asestações intermediárias " << endl
			<< "7 – encontrar o mínimo de arestas que constroem o mesmo sistema metroviário " << endl
			<< "8 – imprimir o sistema metroviário criado(o usuário escolhe se quer a lista ou a matriz)" << endl
			<< "Digite o numero da opcao desejada:" << endl;
		cin>>op;
		switch (op){
			case 0:
				cout << "pulando fora" << endl;
				break;

			case 1:
				cout<<"Voce escolheu criar o grafo (tanto em matriz de adjacências quanto em lista de adjacências)"<<endl; 
				break;
			
			case 2:
				cout<<"Voce escolheu adicionar estação (paralelamente na lista e na matriz de adjacências)"<<endl; 
				break;

			case 3:
				cout<<" Voce escolheu remover estação(paralelamente na lista e na matriz de adjacências)"<<endl;
				break;
			case 4:
				cout << " Voce escolheu busca por uma estação(largura e profundidade imprimindo na tela os nós do grafo visitados)" << endl;
				break;
			case 5:
				cout << " Voce escolheu encontrar um caminho determinado entre uma estação e outra retornando o tempo do caminho encontrado, bem como as estações intermediárias" << endl;
				break;
			case 6:
				cout << " Voce escolheu encontrar o menor caminho entre uma estação e outra retornando o tempo encontrado e asestações intermediárias" << endl;
				break;
			case 7:
				cout << "Voce escolheu  encontrar o mínimo de arestas que constroem o mesmo sistema metroviário" << endl;
				break;
			case 8:
				cout << "Voce escolheu  imprimir o sistema metroviário criado(o usuário escolhe se quer a lista ou a matriz)" << endl;
				break;
			default:
				cout<<"Opção invalida tente novamente"<<endl;
				break;
		}
	}while(op !=0);
	return 0;
}


