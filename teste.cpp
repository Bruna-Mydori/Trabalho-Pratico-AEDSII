#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct cliente{
	string nome;
	int cpf;
	string endereco;
	int telefone;
	struct cliente *esq;
    struct cliente *dir;
};
struct projeto{
	string nome;
	string datai;
	string dataf;
	float preco;
	float pago;
	cliente lista;
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
void cadastro(vector<projeto> &R, string nome, string datai, string dataf, float preco, float pago){
	projeto T;
	T.nome = nome;
	T.datai = datai;
	T.dataf = dataf;
	T.preco = preco;
	T.pago = pago;
	R.push_back(T);
}

no *busca(arvore r, string k){
	if(r==NULL || r->nome == k)
		return r;
	if(r->nome > k)
		return busca(r->esq, k);
	else
		return busca(r->dir, k);
}

void exclui(vector <projeto> &R, string re){
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
}
/*void ordena(vector<projeto>&R){
    int menor;
    vector<string> q;
    for(int a=0; a<R.size(); a++){
    	string coisa = R[a].nome;
    	q.push_back(coisa);
	}
    for(int i=0; i<q.size(); i++){
        menor = i;
        for(int j = i+1; j<q.size(); j++){
            if(q[j]<q[menor])
                menor = j;
        }
        swap(q[i], q[menor]);
    }
}*/

int main(){
	arvore r; r = NULL;
	vector<projeto> R;
	vector<projeto> V;
	projeto T;
	string nome, end, datai, dataf, n, re, cliente;
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
			busca(r, n);
			if(nome==n){
				cout << "Digite o nome do projeto(use _ em vez de espaço): ";
				cin >> nome;
				cout << "Digite a data inicial do projeto: ";
				cin >> datai;
				cout << "Digite a data final do projeto: ";
				cin >> dataf;
				cout << "Digite o preço total do projeto: ";
				cin >> preco;
				cout << "Digite o valor recebido do projeto: ";
				cin >> pago;
				cadastro(R, nome, datai, dataf, preco, pago);
			}
			else{
				cout << "Cliente nao encontrado.";
				system("pause");
			}
		}
		if (x==3){
			erd(r);
			system("pause");
		}
		if (x==4){
			/*int particao(vector<projeto> &R, int inicio, int fim){
				int pivo = R[fim];
			 	int i = inicio;
			 	int j = fim-1;
			 	while( i <= j ){
			 		while( R[i] < pivo )
			 			i++;
			 		while( j >= inicio && R[j] >= pivo )
			 			j--;
			 		if( i < j )
			 		swap(R[i], V[j]);
 					}
 				swap(R[fim], V[i]);
 				return i;
				}
			void quickSort(vector<projeto> &R, int inicio, int fim) {
				if (inicio < fim){
					int corte = particao(R, inicio, fim);
					quickSort(R, inicio, corte - 1);
					quickSort(R, corte + 1, fim);
				}
			}*/
			cout << "|Nome dos projetos|" << endl;
			//ordena(R);
			system("pause");
		}
		if (x==5){
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
			cout << "Digite o nome do projeto(use _ em vez de espaço): ";
			cin >> re;
			exclui(R, re);	
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
