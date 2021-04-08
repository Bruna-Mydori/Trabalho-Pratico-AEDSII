#include <iostream>
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
	string endereco;
	int telefone;
	projeto lista;
};
void cadastro(Vector<cliente> &R, string nome, int cpf, string endereco, int telefone, string nom, int datai, int dataf, float preco, float pago, float receber){
	cliente T;
	T.nome = nome;
	T.cpf = cpf;
	T.endereco = endereco;
	T.telefone = telefone;
	T.lista.nome = nom;
	T.lista.datai = datai;
	T.lista.dataf = dataf;
	T.lista.preco = preco;
	T.lista.pago = pago;
	T.lista.receber = receber;
	R.push_back(T);
}
int main(){
	int x;
	vector<cliente> R;
	string nome, endereco, nom;
	int cpf, datai, dataf, telefone;
	float preco, pago, receber;
	cout << "Menu" << endl;
	cout << "1 - Incluir um cliente na lista\n2 - Associar um projeto a um cliente \n3 - Imprimir a lista de clientes\n4 - Imprimir a lista de projetos\n5 - Imprimir a lista de clientes com seus respectivos projetos\n6 - Informar total de valor a receber\n7 - Informar total de valor já recebido\n8 - Pesquisar um projeto\n9 - Pesquisar um cliente\n10 - Remover um projeto de um cliente\n11 - Remover um cliente\n12 - Listar clientes que ainda devem e quais projetos ainda não foram pagos\n0 - Encerrar o programa\n";
	cin >> x;
	while (x!=0){
		if (x==1){
			cout << "Digite o nome do cliente: ";
			cin >> nome;
			cout << ""
		}
		if (x==2){
			cout << "b" << endl;
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
