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
	string codigo;
};

struct cliente{
	string nome;
	string cpf;
	string endereco;
	string telefone;
	struct cliente *esq;
    struct cliente *dir;
    vector<projeto> R;
};

typedef struct cliente no;
typedef no *arvore;
void inserir (arvore &r, string c, string nome, string tel, string end){
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
void cadastro(arvore &r, string nome, string datai, string dataf, float preco, float pago, string nomec, string cod){
	projeto T;
	T.nomep = nome;
	T.datai = datai;
	T.dataf = dataf;
	T.preco = preco;
	T.pago = pago;
	T.nomec = nomec;
	T.codigo = cod;
	r->R.push_back(T);
}
no *buscaproj(arvore r, string k){
	for (int i=0; i < r->R.size();i++){
		if(r==NULL || r->R[i].codigo == k)
			return r;
		if(r->R[i].codigo > k)
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

no *buscac(arvore r, string k){
	if(r==NULL || r->cpf == k)
		return r;
	if(r->cpf > k)
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
			if(r->R[n].codigo == nproj){
				float receber;
				receber = r->R[n].preco - r->R[n].pago;
				cout << "Valor a receber: " << receber << endl;
			}
		}
		debito(r->dir, nproj);
	}
}

void recebido(arvore r, string nproj){
	if(r!=NULL){
		recebido(r->esq, nproj);
		for(int n=0; n<r->R.size(); n++){
			if(r->R[n].codigo == nproj){
				float recebido;
				recebido = r->R[n].pago;
				cout << "Valor recebido: " << recebido << endl;
			}
		}
		recebido(r->dir, nproj);
	}
}

void doze(arvore r){
	if(r!=NULL){
		doze(r->esq);
		for(int n=0; n<r->R.size(); n++){
			if(r->R[n].preco != r->R[n].pago){
				cout << "Cliente: " << r->nome << endl;
				cout << "|Projeto nao pagos|" << endl;
				for(int z=0; z<r->R.size(); z++){
					if(r->R[z].nomec == r->nome){
						cout << "- " << r->R[z].nomep << endl;
					}
				}
			}
		}
		doze(r->dir);
	}
}


void imprimicp(arvore r, string nproj){
	if (r!=NULL){
		imprimicp(r->esq, nproj);
		for(int i=0; i<r->R.size(); i++){
			if(r->R[i].codigo == nproj){
				cout << "|Dados do Projeto|" << endl;
				cout << "Nome: " << r->R[i].nomep << endl;
				cout << "Codigo: " << r->R[i].codigo << endl;
				cout << "Data Inicial: " << r->R[i].datai << endl;
				cout << "Data Final: " << r->R[i].dataf << endl;
				cout << "Valor Total: " << r->R[i].preco << endl;
				cout << "Valor Pago: " << r->R[i].pago << endl;
				debito(r, nproj);
				cout << "|Dados do Cliente|" << endl;
				cout << "Nome: " << r->nome << endl;
				cout << "CPF: " << r->cpf << endl;
				cout << "Telefone: " << r->telefone << endl;
				cout << "Endereco: " << r->endereco << endl;
			}
		}
		imprimicp(r->dir, nproj);
	}
}

void imprimicl(arvore r, string c){
	if (r!=NULL){
		imprimicl(r->esq, c);
		if(r->cpf == c){
			cout << "|Dados do Cliente|" << endl;
			cout << "Nome: " << r->nome << endl;
			cout << "CPF: " << r->cpf << endl;
			cout << "Telefone: " << r->telefone << endl;
			cout << "Endereco: " << r->endereco << endl;
			for(int i=0; i<r->R.size(); i++){
				if(r->R[i].nomec == r->nome){
					cout << "|Dados do Projeto|" << endl;
					cout << "Nome: " << r->R[i].nomep << endl;
					cout << "Codigo: " << r->R[i].codigo << endl;
					cout << "Data Inicial: " << r->R[i].datai << endl;
					cout << "Data Final: " << r->R[i].dataf << endl;
					cout << "Valor Total: " << r->R[i].preco << endl;
					cout << "Valor Pago: " << r->R[i].pago << endl;
					debito(r, r->R[i].codigo);					
				}
			}
		}
		imprimicl(r->dir, c);
	}
}

void exclui(arvore r, string ex){
	if (r!=NULL){
		exclui(r->esq, ex);
		for (int q=0; q < r->R.size(); q++){
	        if (r->R[q].codigo==ex){	
	            r->R.erase(r->R.begin()+q);
        	}
        }
        exclui(r->dir, ex);
        for (int q=0; q < r->R.size(); q++){
	        if (r->R[q].codigo==ex){	
	            r->R.erase(r->R.begin()+q);
	        }
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
    // q � n� anterior a r na ordem e-r-d
    // p � pai de q
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
	string nome, nom, end, datai, dataf, n, re, cliente, nproj, c, tel, cod;
	string ex;
	int x;
	float preco, pago;
	cout << "|Menu|" << endl;
	cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor ja recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda nao foram pagos\n0 - Encerrar o programa\n";
	cin >> x;
	while (x!=0){
		if (x==1){
			cout << "Digite o nome do cliente(use _ em vez de espa�o): ";
			cin >> nome;
			cout << "Digite o CPF(apenas numeros): ";
			cin >> c;
			cout << "Digite o telefone(apenas numeros): ";
			cin >> tel;
			cout << "Digite o endereco(use _ em vez de espa�o): ";
			cin >> end;
			inserir(r, c, nome, tel, end);
		}
		if (x==2){
			cout << "Digite o nome do cliente(use _ em vez de espa�o): ";
			cin >> n;
			arvore a = busca(r, n);
			if(a==NULL){
				cout << "Cliente nao encontrado." << endl;
				system("pause");
			}
			else{
				cout << "Digite o nome do projeto(use _ em vez de espaco): ";
				cin >> nom;
				cout << "Digite um codigo unico para o projeto: ";
				cin >> cod;
				cout << "Digite a data inicial do projeto: ";
				cin >> datai;
				cout << "Digite a data final do projeto: ";
				cin >> dataf;
				cout << "Digite o pre�o total do projeto: ";
				cin >> preco;
				cout << "Digite o valor recebido do projeto: ";
				cin >> pago;
				cadastro(a, nom, datai, dataf, preco, pago, n, cod);
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
			cout << "Digite o codigo do projeto: ";
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
			cout << "Digite o codigo do projeto: ";
			cin >> nproj;
			arvore bi = buscaproj(r, nproj);
			if(bi==NULL){
				cout << "Projeto nao encontrado. " << endl;
			}
			else{
				recebido(r, nproj);
				system("pause");
			}
		}
		if (x==8){
			cout << "Digite o codigo do projeto: " << endl;
			cin >> nproj;
			arvore td = buscaproj(r, nproj);
			if(td==NULL){
				cout << "Projeto nao encontrado. " << endl;
			}
			else{
				imprimicp(r, nproj);
				system("pause");
			}
		}	
		if (x==9){
			cout << "Digite o CPF do cliente desejado: " << endl;
			cin >> c;
			arvore cl = buscac(r, c);
			if(cl==NULL){
				cout << "Cliente nao encontrado. " << endl;
			}
			else{
				imprimicl(r, c);
				system("pause");
			}
		}
		if (x==10){
			cout << "Digite o codigo do projeto que deseja excluir: ";
			cin >> ex;
			arvore te = buscaproj(r, ex);
			if(te==NULL){
				cout << "Projeto nao encontrado. " << endl;
			}
			else{
				exclui(r, ex);
				cout << "Projeto Excluido. " << endl;
				system("pause");
			}
		}
		if (x==11){
			cout << "Digite o nome do cliente(use _ em vez de espa�o): ";
			cin >> c;
		}
		if (x==12){
			doze(r);
			system("pause");
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
