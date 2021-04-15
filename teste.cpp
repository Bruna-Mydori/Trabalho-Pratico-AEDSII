#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct projeto{
	string nomep;
	string datai;
	string dataf;
	float preco;
	float pago;
	string nomec;
};
struct cliente{
	string nome;
	int cpf;
	string endereco;
	int telefone;
	struct cliente *esq;
    struct cliente *dir;
    vector<projeto> R;
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
void cadastro(arvore &r, string nome, string datai, string dataf, float preco, float pago, string nomec){
	projeto T;
	T.nomep = nome;
	T.datai = datai;
	T.dataf = dataf;
	T.preco = preco;
	T.pago = pago;
	T.nomec = nomec;
	r->R.push_back(T);
}
no *buscaproj(arvore r, string k){
	for (int i=0; i < r->R.size();i++){
		if(r==NULL || r->R[i].nomep == k)
			return r;
		if(r->R[i].nomep > k)
			return buscaproj(r->esq, k);
		else
			return buscaproj(r->dir, k);
	}
}
no *busca(arvore r, string k){
	if(r==NULL || r->nome == k)
		return r;
	if(r->nome > k)
		return busca(r->esq, k);
	else
		return busca(r->dir, k);
}
void selecao(arvore r){
	int menor;
	for (int i=0; i < r->R.size();i++){
		menor = i;
		for (int j=i+1;j<r->R.size();j++){
			if (r->R[j].nomep < r->R[menor].nomep)
				menor = j;
		}
		swap(r->R[i], r->R[menor]);
	}
}
void proj(arvore r){
    if(r!=NULL){
        proj(r->esq);
        for(int n=0; n<r->R.size(); n++){
        	selecao(r);
			cout << "- " << r->R[n].nomep << endl;
		}
        proj(r->dir);
    }
}
void cp(arvore r){
    if(r!=NULL){
        cp(r->esq);
        cout << "Cliente: " << r->nome << endl;
        cout << "Lista de projeto(s):" << endl;
        for(int i=0; i<r->R.size(); i++){
        	if(r->R[i].nomec==r->nome){
        		selecao(r);
				cout << "- " << r->R[i].nomep << endl;
			}
		}
        cp(r->dir);
    }
}

void debito(arvore r, string nproj){
	if(r!=NULL){
		debito(r->esq, nproj);
		for(int n=0; n<r->R.size(); n++){
			if(r->R[n].nomep==nproj){
				float receber;
				receber = r->R[n].preco - r->R[n].pago;
				cout << "Valor a receber: " << receber << endl;
			}
		}
		debito(r->dir, nproj);
	}
}

/*void exclui(vector <projeto> &R, string re){
  for (int q=0; q< R.size();q++){
          if (R[q].nome==re){
              R.erase(R.begin()+q);
        }
    }
}
/*removeraiz (arvore r) {  
    no *p, *q;
    if (r->esq == NULL) {
       q = r->dir;
       free (r);
       return q;
    }
    p = r; q = r->esq;
    while (q->dir != NULL) {
       p = q; q = q->dir;
    }
    // q é nó anterior a r na ordem e-r-d
    // p é pai de q
    if (p != r) {
       p->dir = q->esq;
       q->esq = r->esq;
    }
    q->dir = r->dir;
    free (r);
    return q;
}*/

int main(){
	arvore r; r = NULL;
	projeto T;
	string nome, nom, end, datai, dataf, n, re, cliente, nproj;
	int x, c, tel;
	float preco, pago;
	cout << "|Menu|" << endl;
	cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor ja recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda nao foram pagos\n0 - Encerrar o programa\n";
	cin >> x;
	while (x!=0){
		if (x==1){
			cout << "Digite o nome do cliente(use _ em vez de espaço): ";
			cin >> nome;
			cout << "Digite o CPF(apenas numeros): ";
			cin >> c;
			cout << "Digite o telefone(apenas numeros): ";
			cin >> tel;
			cout << "Digite o endereco(use _ em vez de espaço): ";
			cin >> end;
			inserir(r, c, nome, tel, end);
		}
		if (x==2){
			cout << "Digite o nome do cliente(use _ em vez de espaço): ";
			cin >> n;
			arvore a = busca(r, n);
			if(a==NULL){
				cout << "Cliente nao encontrado." << endl;
				system("pause");
			}
			else{
				cout << "Digite o nome do projeto(use _ em vez de espaço): ";
				cin >> nom;
				cout << "Digite a data inicial do projeto: ";
				cin >> datai;
				cout << "Digite a data final do projeto: ";
				cin >> dataf;
				cout << "Digite o preço total do projeto: ";
				cin >> preco;
				cout << "Digite o valor recebido do projeto: ";
				cin >> pago;
				cadastro(a, nom, datai, dataf, preco, pago, n);
			}
		}
		if (x==3){
			erd(r);
			system("pause");
		}
		if (x==4){
			cout << "|Nome dos projetos|" << endl;
			proj(r);
			system("pause");
		}
		if (x==5){
			cp(r);
			system("pause");
		}
		if (x==6){
			cout << "Digite o nome do projeto: ";
			cin >> nproj;
			arvore p = buscaproj(r, nproj);
			if(p==NULL){
				cout << "Projeto nao encontrado." << endl;
			}
			else{
				debito(r, nproj);
				system("pause");
			}
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
			cout << "Digite o nome do projeto(use _ em vez de espaço): ";
			cin >> re;
			//exclui(R, re);	
		}
		if (x==11){
			cout << "Digite o nome do cliente(use _ em vez de espaço): ";
			cin >> cliente;
			
		}
		if (x==12){
			cout << "l" << endl;
		}
		system("cls");
		cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor ja recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda nao foram pagos\n0 - Encerrar o programa\n";
		cin >> x;
	}
	cout << "Programa encerrado" << endl;
}
/*cout << "Digite um nome: ";
			cin >> nome;
			if(nome==a.nome){
				cout << "Nome projeto: " << a.lista.nome << endl;
				cout << "Data inicial: " << a.lista.datai << endl;
				cout << "Data final: " << a.lista.dataf << endl;
				cout << "Valor: " << a.lista.preco << endl;
				cout << "Pago: " << a.lista.pago << endl;
				system("pause");
			}*/
