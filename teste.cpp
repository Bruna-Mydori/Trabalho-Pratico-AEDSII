#include <iostream>
#include <vector>
using namespace std;

struct projeto{
	string nome;
	int datai;
	int dataf;
	float preco;
	float pago;
	float receber;
};

struct cliente{
	string nome;
	int cpf;
	char endereco[500];
	int telefone;
	projeto lista;
};
struct cel{
    struct cliente conteudo;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;
typedef no *arvore;
void inserir (arvore &r, int c, string nome, int tel, char end){
    if(r==NULL){
		r = new no;
		r->conteudo.cpf = c;
		r->conteudo.nome = nome;
		r->conteudo.telefone = tel;
		r->conteudo.endereco = end;
		r->esq = NULL;
		r->dir = NULL;
    }
   else {
		if(c < r->conteudo.cpf){
			inserir(r->esq, c, nome, tel, end);
		}
		else{
			inserir(r->dir,c, nome, tel, end);
		}
    }
}
no *busca(arvore r, int k){
	if(r==NULL || r->conteudo.cpf == k)
		return r;
	if(r->conteudo.cpf > k)
		return busca(r->esq, k);
	else
		return busca(r->dir, k);
}
int main(){
	arvore r; r = NULL;
	int x;
	string nome;
	char end[500];
	int c, tel;
	float preco, pago, receber;
	cout << "Menu" << endl;
	cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor já recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda não foram pagos\n0 - Encerrar o programa\n";
	cin >> x;
	while (x!=0){
		if (x==1){
			cout << "Digite o nome do cliente: ";
			cin >> nome;
			cout << "Digite o CPF(apenas números): ";
			cin >> c;
			cout << "Digite o telefone(apenas números): ";
			cin >> tel;
			cout << "Digite o endereço: ";
			cin >> end;
			inserir(r, c, nome, tel, end);
		}
		if (x==2){
			cout << "Digite o CPF: ";
			cin >> c;
			arvore a = busca(r, c);
			if (a==NULL){
				cout << "Nao encontrado!" << endl;
				system("pause");
			}
			else {
				cout << "Nome: " << a->conteudo.nome << endl;
				cout << "CPF: " << a->conteudo.cpf << endl;
				cout << "Telefone: " << a->conteudo.telefone << endl;
				cout << "Endereco: " << a->conteudo.endereco << endl;
			}
			system("pause");
		}
		if (x==3){
			cout << "c" << endl;
		}
		if (x==4){
			cout << "d" << endl;
		}
		if (x==5){
			cout << "e" << endl;
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
