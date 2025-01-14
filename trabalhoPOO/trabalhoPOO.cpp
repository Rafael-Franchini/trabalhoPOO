/*
author dessa coisa feia:
Rafael F.

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
	void removelink(string sigla);
};
void estacao::removelink(string sigla) {
	for (int i = 0; i < link.size(); i++) {
		if (link[i] == sigla) {
			link.erase(link.begin() + i);
		}
	}
}
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
	vector <estacao> lista;
	int matrizadj[15][15];
public:
	metro();
	void addEst();
	void addEsta(estacao e1);
	void addLink();
	void addLink(string tem1,string tem2);
	void removeEst();
	void imprime(int valor);
	void arestas();
	void removelink();
	//void buscaest(string sigla);
};
metro::metro() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			matrizadj[i][j] = 0;
		}
	}
};
void metro::addLink(string tem1, string tem2) {
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].getSigla() == tem1) {
			for (int j = 0; j < lista.size(); j++) {
				if (lista[j].getSigla() == tem2) {
					if (tem1 != tem2) {
						matrizadj[i][j] = 4;
						matrizadj[j][i] = 4;
						lista[i].setLink(tem2);
						lista[j].setLink(tem1);
					}
					else {
						cout<<"Estacoes iguais"<<endl;
					}
				}
			}
		}
	}
}
void metro::addEsta(estacao e1) {
	lista.push_back(e1);
}
//adicionar estação
void metro::addEst() {
	estacao auxest;
	string temp1,temp2;
	cout <<"Digite o nome da estacao que deseja adicionar" << endl;
	cin >> temp1;
	cout << "Digite a sigla da estacao que deseja adicionar" << endl;
	cin >> temp2;
	for (int i = 0; i < lista.size(); i++) {
		if (temp2 == lista[i].getSigla()) {
			cout << "Estacao ja existente" << endl;
			return;
		}
	}
	auxest.setNome(temp1);
	auxest.setSigla(temp2);
	lista.push_back(auxest);
	cout << "estacao adicionado com sucesso" << endl;
}
//add link
void metro::addLink() {
	int temp;
	string aux,aux2;
	cout << "Digite a estacao que voce deseja adicionar o link: "<<endl;
	cin>> aux;
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].getSigla() == aux) {
			cout << "Digite a sigla da estacao que deseja adicionar" << endl;
			cin >> aux2;
			for (int j = 0; j < lista.size(); j++) {
				if (lista[j].getSigla() == aux2) {
					if (aux != aux2) {
						cout << "digite a distancia em KM entre as estacoes" << endl;
						cin >> temp;
						matrizadj[i][j] = temp;
						matrizadj[j][i] = temp;
						lista[i].setLink(aux2);
						lista[j].setLink(aux);
					}
					else {
						cout << "Estacoes iguais" << endl;
					}
				}
			}
		}
	}
}
//remover estação
void metro::removeEst(){
	string aux;
	cout << "Digite a sigla  estacao que deseja remover :" << endl;
	cin >> aux;
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].getSigla() == aux) {
			for (int j = 0; j < lista.size(); j++) {
				matrizadj[i][j] = 0;
				matrizadj[j][i] = 0;
			}
		}
	}
	for (int k = 0; k < lista.size(); k++) {
		if (lista[k].getSigla() == aux) {
			lista.erase(lista.begin() + k);
		}
	}
	for (int i = 0; i < lista.size(); i++) {
		lista[i].removelink(aux);
	}
	
	cout << "estacao removida com sucesso";
}
//arestas
void metro::arestas() {
	int temp=0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (matrizadj[i][j] > 0 && matrizadj[j][i] > 0) {
				temp+=1;
			}
		}
	}
	cout <<endl << "numero de arestas: " << temp/2 << endl;
}
//imprimir matriz ou lista
void metro::imprime(int valor) {
	switch (valor){
	case 0://matriz && lista
		cout << "lista:" << endl;
		//lista
		for (int i = 0; i < lista.size(); i++) {
			cout<<"estacao: "<< lista[i].getNome() << endl << " sigla: " << lista[i].getSigla() << endl << " Links: " << lista[i].getLink() << endl << endl;
		}
		cout << "matriz:"<<endl;
		//matriz
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				cout<<matrizadj[i][j]<<" ";
			}
			cout << endl;
		}
		cout << endl << "caso nao apareca nada e porque nao ha estacoes adicionadas" << endl;
		break;
	case 1://matriz
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				cout << matrizadj[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << "caso nao apareca nada e porque nao ha estacoes adicionadas" << endl;
		break;
	case 2://lista
		cout << "lista:" << endl;
		for (int i = 0; i < lista.size(); i++) {
			cout << "estacao: " << lista[i].getNome() << endl << " sigla: " << lista[i].getSigla() << endl << " Links: " << lista[i].getLink() << endl << endl;
		}
		cout <<endl <<"caso nao apareca nada e porque nao ha estacoes adicionadas" << endl;
		break;
	default:
		cout << "valor invalido" << endl;
		break;
	}
}
void metro::removelink() {
	string aux, aux2;
	cout<<"digite a sigla da estacao que deseja remover o link"<<endl;
	cin >> aux;
	cout<<"digire a sigla da outra estacao que deseja remover o link"<<endl;
	cin >> aux2;
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].getSigla() == aux) {
			lista[i].removelink(aux2);
		}
	}
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].getSigla() == aux2) {
			lista[i].removelink(aux);
		}
	}
}
//busca por uma estação
/*
void metro::buscaest(string sigla) {
	
	cout<<endl<<"Caso nao tenha aparecido nada e porque nao existe uma estacao com essa sigla"<<endl;
}
*/

int main(){
	estacao e1("lapa","LP"), e2("Morumbi","MR"), e3("Luiz","LZ");
	metro o1;
	o1.addEsta(e1);
	o1.addEsta(e2);
	o1.addEsta(e3);
	o1.addLink("LP","MR");
	o1.addLink("MR","LZ");	
	o1.addLink("LZ", "LP");
	int op,op2;
	string temp;
	do{
		cout <<endl<< "0  Parar execucao " << endl
			<< "1 criar o grafo (lista e matriz adjacencia)  " << endl
			<< "2  adicionar estacao  " << endl
			<< "3  remover estacao " << endl
			<< "7  encontrar o minimo de arestas que constroem o mesmo sistema metroviario " << endl
			<< "8  imprimir o sistema metroviario criado(o usuario escolhe se quer a lista ou a matriz adjacencia)" << endl
			<< "9  Adicionar link a uma estacao" << endl
			<< "10 remove link da estacao" << endl
			<< "11 Limpa console" << endl
			<< "Digite o numero da opcao desejada:" << endl;
		cin >> op;
		switch (op){
			case 0:
				cout << "pulando fora" << endl;
				break;
			case 1:
				cout << endl <<"Voce escolheu criar o grafo (lista e matriz adjacencia)"<<endl;
				o1.imprime(0);
				break;			case 2:
				cout << endl <<"Voce escolheu adicionar estacao"<<endl;
				o1.addEst();
				break;
			case 3:
				cout << endl <<" Voce escolheu remover estacao"<<endl;
				o1.removeEst();
				break;
/*			case 4:
				cout << endl << " Voce escolheu busca por uma estacao" << endl;
				cout << endl << "digite a sigla da estacao que deseja buscar : " << endl;
				cin>>temp;
	
				break;*/	
			case 7:
				cout <<endl<< " Voce escolheu encontrar o minimo de arestas que constroem o mesmo sistema metroviario" << endl;
				o1.arestas();
				break;
			case 8:
				cout << endl << "Voce escolheu  imprimir o sistema metroviario criado" << endl;
				cout << "0  imprimir matriz adjacencia e lista " << endl
					<< "1  imprimir matriz adjacencia " << endl
					<< "2  imprimir lista " << endl;
				cin >> op2;
				o1.imprime(op2);
				break;
			case 9:
				cout << endl <<"Voce escolheu adicionar link"<<endl;
				o1.addLink();
				break;
			case 10:
				cout << endl << "Voce escolheu remover link" << endl;
				o1.removelink();
				break;
			case 11:
				system("cls");
				break;
			default:
				cout << endl <<"Opção invalida tente novamente"<<endl;
				break;
		}
	}while(op !=0);
	return 0;
}
