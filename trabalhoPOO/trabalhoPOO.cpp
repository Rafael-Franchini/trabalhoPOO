//Rafael Alexandre Lima Franchini  109179
//Danilo Henrique Muller 105918
//Otávio Augusto Delatorre Fadini 108999
#include <iostream>

using namespace std;

int main(){

	int op;
	do{
		cin>>op;
		switch (op){
			case 1:
				cout<<"Voce escolheu a opção 1"<<endl; 
				break;
			
			case 2:
				cout<<"Voce escolheu a opção 2"<<endl; 
				break;

			case 3:
				cout<<"pulando fora"<<endl;
				break;

			default:
				cout<<"Opção invalida tente novamente"<<endl;
				break;
		}
	}while(op !=3);
	return 0;
}


