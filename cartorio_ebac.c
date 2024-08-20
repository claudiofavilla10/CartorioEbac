#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no banco de dados (w significa escrever)
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf); //Salva o valor da vari�vel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //formata��o da v�riavel NOME abaixo da vari�vel CPF (a significa alterar)
	fprintf(file,"\nNOME: ");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Inclui a vari�rel Nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a"); //formata��o da v�riavel SOBRENOME abaixo da vari�vel NOME
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Inclui a vari�vel Sobrenome
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a"); //formata��o da v�riavel CARGO abaixo da vari�vel SOBRENOME
	fprintf(file,"\nCARGO: ");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Inclui a vari�vel Cargo
	fprintf(file,cargo);
	fprintf(file,"\n\n"); //inclui mais um espa�o ap�s printar da vari�vel CARGO
	fclose(file);
	printf("\n");
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //l� os dados no arquivo com a v�riavel pesquisada (r significa ler)
	
	if(file == NULL)
	{
		printf("\tArquivo n�o encontrado! Insira um CPF cadastrado.\n\n"); //mensagem de erro ap�s pesquisa de um cpf n�o cadastrado
	}
	
	else
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
	}
	
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\t"); //formata em tab o resultado da consulta
		printf("%s", conteudo);
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); 
	
	FILE *file;
	file = fopen(cpf,"r"); 	
	
	remove(cpf); //define a exclus�o do cadastro indicado
	{
		printf("\tUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
	system("pause");
	
}
	

int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
			printf("       ### Cart�rio da EBAC ###\n\n"); //T�tulo Principal
			printf("   Escolha a op��o desejada no menu:\n\n"); //menu inicial
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("   Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio
	
		system("cls");
	
		
		switch(opcao) //inicio do switch case / inicio da sele��o do menu
		{
			case 1:
			registro(); //chamda das fun��es
			break;
			
			case 2:
			consulta(); //chamada das fun��es
			break;
			
			case 3:
			deletar(); //chamada das fun��es
			break;
			
			case 4:
			printf("\n\tObrigado e at� mais!\n");
			return 0;
			break;
			
			
			default: //erro de sele��o
			printf("\n\tOp��o inv�lida! Escolha umas das op��es dispon�veis no Menu.\n\n");
			system("pause");
			break; 
				
		} //fim do switch case / fim da sele��o
		
	}
}

