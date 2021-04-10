#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct projeto{
	string nome;
	string datai;
	string dataf;
	float preco;
	float pago;
};

struct cliente{
	string nome;
	int cpf;
	string endereco;
	int telefone;
	projeto lista;
	struct cliente *esq;
    struct cliente *dir;
};

typedef struct cliente no;
typedef no *arvore;
void inserir (arvore &r, int c, string nome, int tel, string end){
    if(r==NULL){
		r = new no;
		r->cpf = c;
		r->nome = nome;
		r->telefone = tel;
		r->endereco = end;
		r->esq = NULL;
		r->dir = NULL;
    }
   else {
		if(nome < r->nome){
			inserir(r->esq, c, nome, tel, end);
		}
		else{
			inserir(r->dir,c, nome, tel, end);
		}
    }
}
void erd(arvore r){
    if(r!=NULL){
        erd(r->esq);
        cout << "- " << r->nome << endl;
        erd(r->dir);
    }
}

void red(cliente a){
    if(cliente a!=NULL){
        erd(a->esq);
        cout << "- " << a.lista.nome << endl;
        erd(a->dir);
    }
}

/*no *busca(arvore r, int k){
	if(r==NULL || r->conteudo.nome == k)
		return r;
	if(r->conteudo.nome > k)
		return busca(r->esq, k);
	else
		return busca(r->dir, k);
}*/
int main(){
	arvore r; r = NULL;
	cliente a;
	string nome, end;
	int x, c, tel;
	cout << "Menu" << endl;
	cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor já recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda não foram pagos\n0 - Encerrar o programa\n";
	cin >> x;
	while (x!=0){
		if (x==1){
			cout << "Digite o nome do cliente(use _ em vez de espaço): ";
			cin >> nome;
			cout << "Digite o CPF(apenas números): ";
			cin >> c;
			cout << "Digite o telefone(apenas números): ";
			cin >> tel;
			cout << "Digite o endereço(use _ em vez de espaço): ";
			cin >> end;
			inserir(r, c, nome, tel, end);
		}
		if (x==2){
			cout << "Digite o nome do projeto(use _ em vez de espaço): ";
			cin >> a.lista.nome;
			cout << "Digite a data inicial do projeto: ";
			cin >> a.lista.datai;
			cout << "Digite a data fianl do projeto: ";
			cin >> a.lista.dataf;
			cout << "Digite o preço total do projeto: ";
			cin >> a.lista.preco;
			cout << "Digite o valor recebido do projeto: ";
			cin >> a.lista.pago;
			cout << "Digite o nome do cliente(use _ em vez de espaço): ";
			cin >> a.nome;
		}
		if (x==3){
			erd(r);
			system("pause");
		}
		if (x==4){
			red(cliente a);
			system("pause");
		}
		if (x==5){
			cout << "Digite um nome: ";
			cin >> nome;
			if(nome==a.nome){
				cout << "Nome projeto: " << a.lista.nome << endl;
				cout << "Data inicial: " << a.lista.datai << endl;
				cout << "Data final: " << a.lista.dataf << endl;
				cout << "Valor: " << a.lista.preco << endl;
				cout << "Pago: " << a.lista.pago << endl;
				system("pause");
			}
		}
		if (x==6){
			cout << "f" << endl;
		}
		if (x==7){
			cout << "g" << endl;
		}
		if (x==8){
			cout << "h" << endl;
		}
		if (x==9){
			cout << "i" << endl;
		}
		if (x==10){
			cout << "j" << endl;
		}
		if (x==11){
			cout << "k" << endl;
		}
		if (x==12){
			cout << "l" << endl;
		}
		system("cls");
		cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor já recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda não foram pagos\n0 - Encerrar o programa\n";
		cin >> x;
	}
	cout << "Programa encerrado" << endl;
}
