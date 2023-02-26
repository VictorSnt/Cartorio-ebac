#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int menu()
{
		//estilização em volta do titulo
	printf("==========================================================\n=");
	
	//Titulo do Programa
	printf("================> Cartório da EBAC <=====================\n");
	
	printf("==========================================================\n\n\n");

	
	//Menu de opções
	printf("\tBem vindo! Você pode escolher uma dessas opçoes:\n\n\n");
	printf("  1 - Registrar um nome\n\n");
	printf("  2 - Consultar um nome\n\n");
	printf("  3 - Deletar um nome\n\n");
	printf("  4 - Sair\n\n\n\n\n");
}


int created_by() // função que mostra os creditos na tela 
	{
		//estilização em volta dos creditos
		printf("-----------------------------------------------------------\n");
		
		//creditos
		printf("-  Created by: Victor Santos                              -\n");
		
		
		printf("-----------------------------------------------------------\n");
	}


int cadastrar() //função reponsavel por cadatrar
{
	//Definição do idioma do programa 
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

int consultar() //função reponsavel por consultar cadastros
{
	//Definição do idioma do programa 
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
	char content[200]; // variavel que vai receber todo o conteudo
	char cpf[11]; // armazenara a chave primaria (cpf)
	//------------------------------------------------------------
	
	printf("\nDigite o cpf que quer consultar utilizando apenas numeros: ");
	scanf("%s",&cpf); // recebendo input do usuario na variavel cpf
	
	FILE *file;
	file = fopen(cpf,"r");// abrindo arquivo com "r" Leitura
	
	if (!file) // verificando se o arquivo é nulo
	{
		printf("\n\nNão há nenhum registro com esse cpf no sistema");
	}
	
	while (fgets(content, 200, file) != NULL) // loop enquanto arquivo tiver conteudo
	{
		printf("\n\nInformações encontradas: %s",content); // exibindo conteudo na tela 
		
	}
	fclose(file); // fecha arquivo

}

int deletar() //função reponsavel por deletar
{
	char cpf[11]; // armazenara a chave primaria (cpf)
	
	printf("\nDigite o cpf que quer deletar utilizando apenas numeros: ");
	scanf("%s", cpf); // colocando input do usuario na variavel de cpf
	
	FILE *file;
	file = fopen(cpf,"r"); // abrindo arquivo 

	if(!file) // verificando se o arquivo é nulo
	{
		printf("\n\nNão há nenhum registro com esse cpf no sistema");
	}

	fclose(file); // fecha arquivo
	
	remove(cpf); // apaga arquuivo
	
	printf("\n\nDeletado com sucesso\n");
	
}






int main() 
{
	//Definição do idioma do programa 
	setlocale(LC_ALL, "Portuguese");
	
	// OPção de retornar ao menu
	int voltar_ao_menu = 1;
	
	//variavel que vai guardar a opção digitada
	int option = 0;
	
	int menu_loop() // Pergunta o usuario ao usuario se deseja retornar ao menu.
	{
		int loop_value = 0;
		while (loop_value != 1 && loop_value != 2)
		{
			printf("\n\nDeseja retornar ao menu inicial?\nDigite 1 - para sim\nDigite 2 - para não\n:");
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
			
		//Ler opção do usuario
		printf("Escolha uma da opções acima de 1 a 4: ");
		scanf("%d", &option);
	
		
		//validação da opção escolhida pelo usuario
		while (option > 4 || option < 1)
		{
			printf("Você deve escolher uma das opções do menu numeradas de 1 a 4: ");	
			scanf("%d", &option);
		}
		
		//limpar informações da tela
		system("cls");
		
		
		switch(option)
		
		{
		
		//Opção de consultar nome 
			case 1:
				cadastrar();
				menu_loop();
			 	
			break;
			
		//Opção de Registrar nome 
			case 2:
				consultar();
				menu_loop();
			break;
			
		//Opção de deletar nome 
			case 3:
				deletar();
				menu_loop();
			break;
			
		//Opção de Sair
		    case 4:
		
				voltar_ao_menu = 2;	
			break;
	    
	}
}   
	printf("\n\nAté a proxima\n\n\n");
	created_by();
}
	
