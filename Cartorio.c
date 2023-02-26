#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int menu()
{
		//estiliza��o em volta do titulo
	printf("==========================================================\n=");
	
	//Titulo do Programa
	printf("================> Cart�rio da EBAC <=====================\n");
	
	printf("==========================================================\n\n\n");

	
	//Menu de op��es
	printf("\tBem vindo! Voc� pode escolher uma dessas op�oes:\n\n\n");
	printf("  1 - Registrar um nome\n\n");
	printf("  2 - Consultar um nome\n\n");
	printf("  3 - Deletar um nome\n\n");
	printf("  4 - Sair\n\n\n\n\n");
}


int created_by() // fun��o que mostra os creditos na tela 
	{
		//estiliza��o em volta dos creditos
		printf("-----------------------------------------------------------\n");
		
		//creditos
		printf("-  Created by: Victor Santos                              -\n");
		
		
		printf("-----------------------------------------------------------\n");
	}


int cadastrar() //fun��o reponsavel por cadatrar
{
	//Defini��o do idioma do programa 
	setlocale(LC_ALL, "Portuguese");
	
	// variaveis
	char file_name[11];
	char cpf[11];
	char name[15];
	char last_name[15];
	char position[25];
	//---------------------------------	
	printf("Digite seu cpf utilizando apenas numeros: ");
	scanf("%s", &cpf); // Armazena cpf do usuario na variavel	
	
	printf("\nDigite seu primeiro nome: "); 
	scanf("%s", &name);	// copiando o input do usuario e armazenando na variavel name

	printf("\nDigite seu sobrenome: ");
	scanf("%s", &last_name);	 // copiando o input do usuario e armazenando na variavel last_name
	
	printf("\nDigite seu cargo: ");
	scanf("%s", &position);  // copiando o input do usuario e armazenando na variavel position
	
	strcpy(file_name,cpf); // copiando o cpf para a variavel "file_name"
	
	FILE *file;
	file = fopen(file_name, "w"); // cria e abre arquivo "w" escrever no arquivo
	
	fprintf(file, "%s,%s,%s,%s",cpf,name,last_name,position);// escrevendo no arquivo
	fclose(file); // fechando arquivo
	
	printf("\nRegistrado com sucesso!\n\n");
	
}

int consultar() //fun��o reponsavel por consultar cadastros
{
	//Defini��o do idioma do programa 
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
	char content[200]; // variavel que vai receber todo o conteudo
	char cpf[11]; // armazenara a chave primaria (cpf)
	//------------------------------------------------------------
	
	printf("\nDigite o cpf que quer consultar utilizando apenas numeros: ");
	scanf("%s",&cpf); // recebendo input do usuario na variavel cpf
	
	FILE *file;
	file = fopen(cpf,"r");// abrindo arquivo com "r" Leitura
	
	if (!file) // verificando se o arquivo � nulo
	{
		printf("\n\nN�o h� nenhum registro com esse cpf no sistema");
	}
	
	while (fgets(content, 200, file) != NULL) // loop enquanto arquivo tiver conteudo
	{
		printf("\n\nInforma��es encontradas: %s",content); // exibindo conteudo na tela 
		
	}
	fclose(file); // fecha arquivo

}

int deletar() //fun��o reponsavel por deletar
{
	char cpf[11]; // armazenara a chave primaria (cpf)
	
	printf("\nDigite o cpf que quer deletar utilizando apenas numeros: ");
	scanf("%s", cpf); // colocando input do usuario na variavel de cpf
	
	FILE *file;
	file = fopen(cpf,"r"); // abrindo arquivo 

	if(!file) // verificando se o arquivo � nulo
	{
		printf("\n\nN�o h� nenhum registro com esse cpf no sistema");
	}

	fclose(file); // fecha arquivo
	
	remove(cpf); // apaga arquuivo
	
	printf("\n\nDeletado com sucesso\n");
	
}






int main() 
{
	//Defini��o do idioma do programa 
	setlocale(LC_ALL, "Portuguese");
	
	// OP��o de retornar ao menu
	int voltar_ao_menu = 1;
	
	//variavel que vai guardar a op��o digitada
	int option = 0;
	
	int menu_loop() // Pergunta o usuario ao usuario se deseja retornar ao menu.
	{
		int loop_value = 0;
		while (loop_value != 1 && loop_value != 2)
		{
			printf("\n\nDeseja retornar ao menu inicial?\nDigite 1 - para sim\nDigite 2 - para n�o\n:");
			scanf("%d", &loop_value);
			system("cls");	
		}	
		voltar_ao_menu = loop_value;
	}
	
	//loop do menu
	while (voltar_ao_menu == 1)
	
	{
		
		char password[20] = "1234";
		char user_password[20] = "a";
		printf("Digite sua senha para acessar o cartorio EBAC: ");
		scanf("%s",user_password);
		if ( strcmp(password, user_password))
		{
			printf("senha incorreta");
			return 1;
		}
		menu();
		
		created_by();
			
		//Ler op��o do usuario
		printf("Escolha uma da op��es acima de 1 a 4: ");
		scanf("%d", &option);
	
		
		//valida��o da op��o escolhida pelo usuario
		while (option > 4 || option < 1)
		{
			printf("Voc� deve escolher uma das op��es do menu numeradas de 1 a 4: ");	
			scanf("%d", &option);
		}
		
		//limpar informa��es da tela
		system("cls");
		
		
		switch(option)
		
		{
		
		//Op��o de consultar nome 
			case 1:
				cadastrar();
				menu_loop();
			 	
			break;
			
		//Op��o de Registrar nome 
			case 2:
				consultar();
				menu_loop();
			break;
			
		//Op��o de deletar nome 
			case 3:
				deletar();
				menu_loop();
			break;
			
		//Op��o de Sair
		    case 4:
		
				voltar_ao_menu = 2;	
			break;
	    
	}
}   
	printf("\n\nAt� a proxima\n\n\n");
	created_by();
}
	
