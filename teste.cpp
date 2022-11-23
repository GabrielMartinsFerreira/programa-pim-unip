//Sistema de login e senha tcc
#include <stdio.h> // padr�o
#include <stdlib.h> // padr�o
#include <string.h> // Essa biblioteca serve para usar os structs e manipula��o de strings
#include <locale.h>
#define SIZE 200
char nome[SIZE][50];
char email[SIZE][50];
double cpf[SIZE];
int RA [SIZE];
int op;
int SI;

void cadastro();
void pesquisa();
void lista();


typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" � o m�ximo de pessoas com logins e senhas


int main(){
	setlocale(LC_ALL,"Portuguese");


    char login[30]; // respons�vel por armazenar a senha inserida pelo usu�rio
    char senha[30]; // respons�vel por armazenar a senha inserida pelo usu�rio

    strcpy(p[0].login, "Unip"); // Definindo o login "Unip" na struct
    strcpy(p[0].senha, "unip123"); // Definindo a senha "�nip123"  na struct

    printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usu�rio para o vetor login que est� dentro da fun��o main

    printf("\nsenha:");
    scanf("%s", senha); // armazenando os dados inseridos pelo usu�rio para o vetor senha que est� dentro da fun��o main

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ // A fun��o strcmp � respons�vel por comparar string com string
        printf("Usu�rio logado"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da fun��o main, usu�rio ser� logado.
    }else{
        printf("Login e/ou senha incorretos, digite qualquer numero para sair!"); // sen�o, login ou senha incorreta.
        scanf("%d", &SI);
        return 1;// caso erre a senha ira fechar o programa
    }



	do{
		system("cls");//limpa a tela
		printf("\n       ----Bem vindo ao Sistema de Cadastro de cliente & Funcionario----\n");
		printf("\n               -----Selecione a op��o que deseja realizar!-----\n \n1 - Cadastrar\n2 - Listar Todos\n3 - Pesquisar\n4 - Sair\n\nFun��o:");
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
				system("exit");
				break;
				
			default:
				printf("Opcao Invalida");
				break;
		}
	}while(op!=4);
	
}
void lista(){
	int i;
	for(i=0;i<SIZE;i++){
		if(cpf[i]>0){
		printf("\nNome: %s\nEmail: %s\nCPF: %12.0lf\nRA: %d", nome[i], email[i],cpf[i], RA[i]);
		}else{
			break;
		}
	
	}
	getchar();
	getchar();
}
void cadastro(){
	static int linha;
	fflush(stdin);
	do{
		printf("\nDigite o nome: ");
		scanf("%[^\n]", &nome[linha]);
		fflush(stdin);
		printf("\nDigite o email: ");
		scanf("%[^\n]", &email[linha]);
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
}//fim da fun��o de cadastro
void pesquisa(){
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
						printf("\nNome: %s\nEmail: %s\n CPF: %12.0lf\n RA: %d", nome[i], email[i],cpf[i], RA[i]);
					}
				}
				break;
			case 2:
			printf("\nDigite o E-mail");
			scanf("%s", &emailPesquisa);				
			for(i=0;i<SIZE;i++){
					if(strcmp(email[i],emailPesquisa)==0){
						printf("\nNome: %s\nEmail: %s \nCPF: %12.0lf\n RA: %d", nome[i], email[i],cpf[i],RA[i]);
					}
				}
				break;
			default:
				printf("\n Op�ao invalida");
				break;
				
		}
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
		scanf("%d",&op);
	}while(op==1);
}//fim da fun�ao de pesquisa
