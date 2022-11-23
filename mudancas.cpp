//Sistema de login e senha tcc
#include <stdio.h> // padrão
#include <stdlib.h> // padrão
#include <string.h> // Essa biblioteca serve para usar os structs e manipulação de strings
#include <locale.h> //Biblioteca para adicionar idioma em portugues no sistema
#define SIZE 200 //Constante para definir a palavra SIZE valor fixo a 200
char nome[SIZE][50];//declarações das variaveis no escopo global
char email[SIZE][50];//declarações das variaveis no escopo global
char info[SIZE][50];//declarações das variaveis no escopo global
double cpf[SIZE];//declarações das variaveis no escopo global
int RA [SIZE];//declarações das variaveis no escopo global
int op;//declarações das variaveis no escopo global
int SI;//declarações das variaveis no escopo global

void cadastro();
void pesquisa();
void lista();
void manual();


typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" é o máximo de pessoas com logins e senhas


int main(){
	setlocale(LC_ALL,"Portuguese");

//inicio do sistema de login
    char login[30]; // responsável por armazenar a senha inserida pelo usuário
    char senha[30]; // responsável por armazenar a senha inserida pelo usuário

    strcpy(p[0].login, "Unip"); // Definindo o login "Unip" na struct
    strcpy(p[0].senha, "unip123"); // Definindo a senha "únip123"  na struct

    printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main

    printf("\nsenha:");
    scanf("%s", senha); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ // A função strcmp é responsável por comparar string com string
        printf("Usuário logado"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.
    }else{
        printf("Login e/ou senha incorretos, digite qualquer numero para sair!"); // senão, login ou senha incorreta.
        scanf("%d", &SI);
        return 1;// caso erre a senha ira fechar o programa
    }//final do sistema de login


//inicio do menu do sistema
	do{
		system("cls");//limpa a tela
		printf("\n       ----Bem vindo ao Sistema de Cadastro de cliente & Funcionario----\n");
		printf("\n               -----Selecione a opção que deseja realizar!-----\n \n1 - Cadastrar\n2 - Listar Todos\n3 - Pesquisar\n4 - Manual\n5 - Sair\n\nFunção: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastro();
				break;
			case 2:
				lista();
				break;
			case 3:
				pesquisa();
				break;
			case 4:
				manual();
				break;
			case 5:
				system("exit");
				break;
				
			default:
				printf("Opcao Invalida");
				break;
		}
	}while(op!=5);
	
}//fim do menu do sistema
void manual(){//inicio do manual de instrução do sistema
	static int linha;
	int esc;
	do{
	printf("\nSeja bem vindo ao manual do sistema!\n");
	printf("\nNeste manual irá mostrar algumas dicas para cadastro de clientes e funcionários e regras importantes!\n");
	printf("\nManual do sistema:\n\n1º Não digitar letras nos comandos de opção, apenas números!\n\n2º Nos setores de cadastro CPF e RA, colocar apenas números!\n\n3º Nomes e E-mail permitidos apenas 49 caracteres\n\n4º Qualquer tipo de erro relatar ao administrador do sistema!\n\n5º Clientes e funcionarios são cadastrado no mesmo sistema. Código Ra padrão para cadastrar cliente é 221133 - pode ser alterado!\n\n6º Na função informação, anexar dados importantes informando se é funcionario,cliente,qual o cargo etc! ");
	printf("\n\nDigite qualquer número para retornar ao menu principal: ");
	scanf("%d", &esc);

}while(op==1);
}//fim do manual de instrução do sistema
void lista(){//inicio da função lista, responsavel por mostrar todos os usuarios cadastrados
	int i;
	for(i=0;i<SIZE;i++){
		if(cpf[i]>0){
		printf("\nNome: %s\nEmail: %s\nCPF: %12.0lf\nRA: %d\nInformação: %s\n", nome[i], email[i],cpf[i], RA[i], info[i]);
		}else{
			break;
		}
	
	}
	getchar();
	getchar();
}//fim da função lista
void cadastro(){//Inicio da função cadastro, responsavel por armazenar temporariamente os dados colocados nesta função
	static int linha;
	fflush(stdin);
	do{
		printf("\nDigite o nome: ");
		scanf("%[^\n]", &nome[linha]);
		fflush(stdin);
		printf("\nDigite o email: ");
		scanf("%[^\n]", &email[linha]);
		fflush(stdin);
		printf("\nDigite a informação sobre cliente/funcionário cadastrado: ");
		scanf("%[^\n]", &info[linha]);
		fflush(stdin);
		printf("\nDigite o cpf: ");
		scanf("%lf", &cpf[linha]);
		fflush(stdin);
		printf("\nDigite o RA: ");
		scanf("%d", &RA[linha]);
		fflush(stdin);
		printf("\nDigite 1 para continuar ou outro valor para sair: ");
		scanf("%d", &op);
		fflush(stdin);
		linha++;
	}while(op==1);
}//fim da função de cadastro
void pesquisa(){//inicio da função pesquisa, responsavel por pesquisar via RA ou Email todos os dados anexados nessas opções
	int RAPesquisa;
	char emailPesquisa[50];
	int i;
	do{
		printf("\nDigite 1 para pesquisar RA ou 2 para pesquisar o email: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\nDigite o RA: ");
				scanf("%d", &RAPesquisa);
				for(i=0;i<SIZE;i++){
					if(RA[i]==RAPesquisa){
						printf("\nNome: %s\nEmail: %s\n CPF: %12.0lf\n RA: %d\nInformação: %s\n", nome[i], email[i],cpf[i], RA[i], info[i]);
					}
				}
				break;
			case 2:
			printf("\nDigite o E-mail: ");
			scanf("%s", &emailPesquisa);				
			for(i=0;i<SIZE;i++){
					if(strcmp(email[i],emailPesquisa)==0){
						printf("\nNome: %s\nEmail: %s\nCPF: %12.0lf\nRA: %d\nInformação: %s\n", nome[i], email[i],cpf[i], RA[i], info[i]);
					}
				}
				break;
			default:
				printf("\n Opçao invalida");
				break;
				
		}
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
		scanf("%d",&op);
	}while(op==1);
}//fim da funçao de pesquisa
