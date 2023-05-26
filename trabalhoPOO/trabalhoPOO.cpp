//Rafael Alexandre Lima Franchini  109179
//Danilo Henrique Muller 105918
//Otávio Augusto Delatorre Fadini 108999


#include <iostream>
#include <string>
#include <vector>


using namespace std;
//classe estação  objeto da matriz e da lista
class estacao{
private:
	string nome;
	string sigla;
	vector <string>link;
public:
	estacao();	
	estacao(string nome, string sigla);
	void setNome(string nome);
	void setSigla(string sigla);
	void setLink(string link);
	string getNome();
	string getSigla();
	string getLink();
};
estacao::estacao(string nome, string sigla) {
	this->nome = nome;
	this->sigla = sigla;
}
estacao::estacao() {
	nome = " ";
	sigla = " ";
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
void estacao::setLink(string link) {
	this->link.push_back(link);
}
//retorna as coneccoes de cada estação
string estacao::getLink() {
	string aux = "";
	for (int i = 0; i < link.size(); i++) {
		aux += link[i] + " ";
	}
	return aux;
}
class metro {
private:
	estacao matriz[26][26];
public:
	metro();
	void addEst();
	void removeEst();
	void imprime(int valor);
	void buscaest(string sigla);
};
metro::metro() {
	estacao est;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = est;
		}
	}
};
//adicionar estação
void metro::addEst() {
	estacao auxest;
	string temp;
	int aux,aux2,aux3;
	cout << "Digite o nome da estação que deseja adicionar" << endl;
	cin >> temp;
	auxest.setNome(temp);
	cout << "Digite a sigla da estação que deseja adicionar" << endl;
	cin >> temp;
	auxest.setSigla(temp);
	cout<<"quantas conecoes esta estação tem?"<<endl;
	cin >>aux;
	for (int j = 0; j< aux; j++) {
		cout<<"Digite a sigla da estação que deseja adicionar"<<endl;
		cin >> temp;
		auxest.setLink(temp);
	}
	cout << "Digite as coordenadas (x y) da estação que deseja adicionar :" << endl;
	cin >> aux2>>aux3;
	if (aux2!=aux3) {
		for (int i = 0; i < 10; i++) {
			if (matriz[aux2][aux3].getNome() == " " && matriz[aux3][aux2].getNome() == " ") {
				matriz[aux2][aux3] = auxest;
				matriz[aux3][aux2] = auxest;
				cout << "Objeto adicionado com sucesso";
			}
			else {
				cout << "Ja existe uma estação nessa coordenada" << endl;
			}
		}
	}
	else {
		cout << "uma estação nao pode ter conexao com ela mesma" << endl;
	}
}
//remover estação
void metro::removeEst() {
	estacao est;
	int aux2,aux3;
	cout << "Digite as coordenadas (x y) da estação que deseja adicionar :" << endl;
	cin >> aux2 >> aux3;
	for (int i = 0; i < 10; i++) {
		matriz[aux2][aux3] = est;
		matriz[aux3][aux2] = est;
	}
	cout << "Objeto removido com sucesso";
}
//imprimir matriz ou lista
void metro::imprime(int valor) {
	switch (valor){
	case 0://matriz && lista
		cout << "lista:" << endl;
		//lista
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (matriz[i][j].getNome() != " ") {
					cout << "estacao " << i << j << " sigla :" << matriz[i][j].getSigla() << " Possui Links com estacoes : " << endl;
					for (int k = 0; k < matriz[i][j].getLink().size(); k++) {
						cout << matriz[i][j].getLink()[k] << " " ;
					}
					cout << endl;
				}
			}
		}
		cout << "matriz:"<<endl;
		//matriz
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (matriz[i][j].getNome()!=" ") {
					cout << matriz[i][j].getSigla()<<" ";
				}
				else {
					cout << 0;
				}
			}
			cout << endl;
		}
		cout << endl << "caso nao apareca nada e porque nao ha estacoes adicionadas" << endl;
		break;
	case 1://matriz
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (matriz[i][j].getNome() != " ") {
					cout << matriz[i][j].getSigla() << " ";
				}
				else {
					cout << 0;
				}
			}
			cout << endl;
		}
		cout << endl << "caso nao apareca nada e porque nao ha estacoes adicionadas" << endl;
		break;
	case 2://lista
		cout << "lista:" << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (matriz[i][j].getNome() != " ") {
					cout << "estacao " << i << j <<" sigla :" << matriz[i][j].getSigla() << " Possui Links com estacoes : " << endl;
					for (int k = 0; k < matriz[i][j].getLink().size(); k++) {
						cout << matriz[i][j].getLink()[k] << " " ;
					}
					cout << endl;
				}
			}
		}
		cout <<endl <<"caso nao apareca nada e porque nao ha estacoes adicionadas" << endl;
		break;
	default:
		cout << "valor invalido" << endl;
		break;
	}
}
//busca por uma estação
void metro::buscaest(string sigla) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j].getSigla() == sigla) {
				cout << "esta estacao esta na coordenada " << i << j <<" OU "<<j<<i << "ja que e uma matriz de adjacencia" <<endl 
					<< "NOME = " << matriz[i][j].getNome() << endl 
					<< "SIGLA = " << matriz[i][j].getSigla() <<endl
					<<"tem coneccoes com :";
				for (int k = 0; k < matriz[i][j].getLink().size(); k++) {
					cout << matriz[i][j].getLink()[k] << ",";
				}
			}
		}
	}
	cout<<endl<<"Caso nao tenha aparecido nada e porque nao existe uma estacao com essa sigla"<<endl;
}
int main(){
	
	metro o1;
	int op,op2;
	string temp;
	do{
		cout << "0  Parar execucao " << endl
			<< "1 criar o grafo  " << endl
			<< "2  adicionar estação  " << endl
			<< "3  remover estação " << endl
			<< "4  busca por uma estação " << endl
			<< "5  encontrar um caminho determinado entre uma estação e outra retornando o tempo do caminho encontrado, bem como as estações intermediárias " << endl
			<< "6 encontrar o menor caminho entre uma estação e outra retornando o tempo encontrado e asestações intermediárias " << endl
			<< "7  encontrar o mínimo de arestas que constroem o mesmo sistema metroviário " << endl
			<< "8  imprimir o sistema metroviário criado(o usuário escolhe se quer a lista ou a matriz)" << endl
			<< "Digite o numero da opcao desejada:" << endl;
		cin>>op;
		switch (op){
			case 0:
				cout << "pulando fora" << endl;
				break;

			case 1:
				cout<<"Voce escolheu criar o grafo (lista e matriz)"<<endl; 
				o1.imprime(0);
				break;
			case 2:
				cout<<"Voce escolheu adicionar estação"<<endl; 
				o1.addEst();
				break;
			case 3:
				cout<<" Voce escolheu remover estação"<<endl;
				o1.removeEst();
				break;
			case 4:
				cout << " Voce escolheu busca por uma estação" << endl;
				cout << "digite a sigla da estacao que deseja buscar : " << endl;
				cin>>temp;
				o1.buscaest(temp);
				break;
			case 5:
				cout << " Voce escolheu encontrar um caminho determinado entre uma estação e outra " << endl;
				cout << "funcao nao foi criada";
				break;
			case 6:
				cout << " Voce escolheu encontrar o menor caminho entre uma estação e outra retornando o tempo encontrado e asestações intermediárias" << endl;
				cout << "funcao nao foi criada";
				break;
			case 7:
				cout << "Voce escolheu  encontrar o mínimo de arestas que constroem o mesmo sistema metroviário" << endl;
				cout << "funcao nao foi criada";
				break;
			case 8:
				cout << "Voce escolheu  imprimir o sistema metroviário criado" << endl;
				cout << "0  imprimir matriz e lista " << endl
					<< "1  imprimir matriz " << endl
					<< "2  imprimir lista " << endl;
				cin >> op2;
				o1.imprime(op2);
				break;
			default:
				cout<<"Opção invalida tente novamente"<<endl;
				break;
		}
	}while(op !=0);
	return 0;
}


