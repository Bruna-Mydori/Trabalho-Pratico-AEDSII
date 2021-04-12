#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////
//
// PROGRAMA EXEMPLO DESENVOLVIDO NAS AULAS DE 16/06 e 20/06/2008
//
//   Este programa gerencia um cadastro de funcionarios
//   implementado em forma de ÁRVORE BINÁRIA DE BUSCA,
//   com as seguintes funções:
//
//     1 - Incluir um novo funcionario
//     2 - Listar todos os funcionarios
//     3 - Reajustar o salário de um funcionário
//     4 - Excluir um funcionario
//
////////////////////////////////////////////////////////////////////

typedef struct
{
  int matricula;
  char nome[51];
  float salario;
} Funcionario;

typedef struct arvore
{
  Funcionario raiz;
  struct arvore *pEsq;
  struct arvore *pDir;
} Arvore;

///////////////////////////////////////////////////
//  Incluir novo funcionario
///////////////////////////////////////////////////

int incluir(Arvore **ppArvore, Funcionario *pNovoFunc)
{
  Arvore *pNovaArvore;
  
  // 1. Tratar o caso de arvore vazia
  
  if (!(*ppArvore))
  {
    pNovaArvore = malloc(sizeof(Arvore)); // alocar um novo no
    if (!pNovaArvore) return(1);          // erro de alocacao de memoria
    pNovaArvore->raiz = *pNovoFunc;
    pNovaArvore->pEsq = NULL;
    pNovaArvore->pDir = NULL;
    *ppArvore = pNovaArvore;
    return(0);
  }

  // 2. Se a nova matricula for menor que a matricula armazenada na raiz,
  //      incluir a nova matricula na subarvore esquerda

  if ( pNovoFunc->matricula < (*ppArvore)->raiz.matricula )
    return incluir(&((*ppArvore)->pEsq),pNovoFunc);

  // 3. Se a nova matricula for maior que a matricula armazenada na raiz,
  //      incluir a nova matricula na subarvore direita

  if ( pNovoFunc->matricula > (*ppArvore)->raiz.matricula )
    return incluir(&((*ppArvore)->pDir),pNovoFunc);

  // 4. Se a matricula ja existir, retornar erro 2
  
  return(2);
}

///////////////////////////////////////////////////
//  Listar funcionarios
///////////////////////////////////////////////////

void listarFuncionarios(Arvore *pArvore)
{
    if (!pArvore) return;
    listarFuncionarios(pArvore->pEsq);
    printf("%9d  %-10s  %7.2f  %p  %p  %p\n",
           pArvore->raiz.matricula,
           pArvore->raiz.nome,
           pArvore->raiz.salario,
           pArvore,
           pArvore->pEsq,
           pArvore->pDir);
    listarFuncionarios(pArvore->pDir);
}

///////////////////////////////////////////////////
//  Reajustar salario de um funcionario
///////////////////////////////////////////////////

int reajustar(Arvore *pArvore, int matricula, float reajuste)
{

  // 1. Se a arvore estiver vazia, retornar erro 1

  if (!pArvore) return(1);   // elemento nao encontrado

  // 2. Se a matricula do funcionario for menor que a matricula armazenada na raiz,
  //      procurar matricula na subarvore esquerda

  if ( matricula < pArvore->raiz.matricula )
    return reajustar(pArvore->pEsq,matricula,reajuste);

  // 3. Se a matricula do funcionario for maior que a matricula armazenada na raiz,
  //      procurar matricula na subarvore direita

  if ( matricula > pArvore->raiz.matricula )
    return reajustar(pArvore->pDir,matricula,reajuste);

  // 4. Funcionario encontrado: reajustar salario

  pArvore->raiz.salario *= 1 + reajuste/100;
  
  return(0);
  
}


///////////////////////////////////////////////////
//  Excluir funcionario
///////////////////////////////////////////////////


int excluir(Arvore **ppArvore, int matriculaExcluir)
{
  Arvore *pVerticeExcluir, *pSucessor, **ppSucessor;

  // 1. Se a arvore estiver vazia, retornar erro 1

  if (!(*ppArvore)) return(1);   // elemento nao encontrado

  // 2. Se a matricula a ser excluida for menor que a matricula armazenada na raiz,
  //      excluir matricula na subarvore esquerda

  if ( matriculaExcluir < (*ppArvore)->raiz.matricula )
    return excluir(&((*ppArvore)->pEsq),matriculaExcluir);

  // 3. Se a matricula a ser excluida for maior que a matricula armazenada na raiz,
  //      excluir matricula na subarvore direita

  if ( matriculaExcluir > (*ppArvore)->raiz.matricula )
    return excluir(&((*ppArvore)->pDir),matriculaExcluir);

  // 4. Aqui o vertice a ser excluido foi encontrado (eh a raiz da arvore)

  pVerticeExcluir = *ppArvore;
  
  // 5. Se o vertice a ser excluido nao tiver filho esquerdo,
  //      o vertice-pai passa a apontar o filho direito do vertice a ser excluido

  if (!((*ppArvore)->pEsq))
  {
     *ppArvore = (*ppArvore)->pDir;
  }

  // 6. Se o vertice a ser excluido tiver filho esquerdo mas nao tiver filho direito,
  //      o vertice-pai passa a apontar o filho esquerdo do vertice a ser excluido

  else if ((!(*ppArvore)->pDir))
  {
     *ppArvore = (*ppArvore)->pEsq;
  }

  // 7. Se o vertice a ser excluido tiver 2 filhos
  //
  //    7.1. localizar o sucessor do vertice a ser excluido
  //         (sucessor = descendente mais a esquerda do filho direito)
  //
  //    7.2. pai do sucessor passa a apontar filho direito do sucessor
  //
  //    7.3. sucessor passa a ocupar o lugar do vertice a ser excluido (raiz da arvore)

  else
  {
     // 7.1. localizar o sucessor do vertice a ser excluido
     //      (sucessor = descendente mais a esquerda do filho direito)

     ppSucessor = &(pVerticeExcluir->pDir);
     while ((*ppSucessor)->pEsq) ppSucessor = &((*ppSucessor)->pEsq);
     pSucessor = *ppSucessor;
     
     // 7.2. pai do sucessor passa a apontar filho direito do sucessor
     
     *ppSucessor = pSucessor->pDir;

     // 7.3. sucessor passa a ocupar o lugar do vertice a ser excluido (raiz da arvore)
     
     *ppArvore = pSucessor;
     pSucessor->pEsq = pVerticeExcluir->pEsq;
     pSucessor->pDir = pVerticeExcluir->pDir;

  }
      
  // 8. Desalocar memoria ocupada pela antiga posicao do sucessor
  
  free(pVerticeExcluir);

  // 9. Retornar codigo de exclusao bem sucedida

  return(0);
  
}




///////////////////////////////////////////////////
//  PROGRAMA PRINCIPAL
///////////////////////////////////////////////////

int main()
{
  char opcao[200];
  int op, codRetorno, matricula;
  float reajuste;
  Funcionario novoFuncionario;
  Arvore *pCadastro = NULL;

  do
  {
    system("cls");
    printf("1 - Incluir um novo funcionario\n");
    printf("2 - Listar todos os funcionarios\n");
    printf("3 - Reajustar o salário de um funcionario\n");
    printf("4 - Excluir um funcionario\n");
    printf("5 - Sair do programa\n");
    printf("\nOpcao: ");
    scanf("%s",opcao);
    op = atoi(opcao);

    // 1 - Incluir um novo funcionario
    
    if (op==1)
    {
       printf("\n\n\n");
       printf("Nome: ");      scanf("%s",novoFuncionario.nome);
       printf("Matricula: "); scanf("%d",&(novoFuncionario.matricula));
       printf("Salario: ");   scanf("%f",&(novoFuncionario.salario));
       codRetorno = incluir(&pCadastro,&novoFuncionario);
       if (codRetorno==0) printf("\nInclusao bem sucedida\n\n");
       if (codRetorno==1) printf("\nERRO: memoria insuficiente\n\n");
       if (codRetorno==2) printf("\nERRO: matricula duplicada\n\n");
    }

    // 2 - Listar todos os funcionarios

    if (op==2)
    {
       printf("\n\n                                Endereco  Endereco  Endereco");
       printf(  "\nMatricula  Nome        Salario  Proprio   Esquerdo  Direito\n\n");
       listarFuncionarios(pCadastro);
       printf("\n\n");
    }
       
    // 3 - Reajustar o salario de um funcionario

    if (op==3)
    {
       printf("\n\n\n");
       printf("Matricula do Funcionario: "); scanf("%d",&matricula);
       printf("Percentual de Reajuste:   "); scanf("%f",&reajuste);
       codRetorno = reajustar(pCadastro,matricula,reajuste);
       if (codRetorno==0) printf("\nAtualizacao bem sucedida\n\n");
       if (codRetorno==1) printf("\nERRO: matricula nao encontrada\n\n");
    }

    // 4 - Excluir um funcionario

    if (op==4)
    {
       printf("\n\n\n");
       printf("Matricula: "); scanf("%d",&matricula);
       codRetorno = excluir(&pCadastro,matricula);
       if (codRetorno==0) printf("\nExclusao bem sucedida\n\n");
       if (codRetorno==1) printf("\nERRO: matricula nao encontrada\n\n");
    }


    if (op != 5) system("pause");

  } while (op != 5);
}
  
