#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo no banco de dados (w significa escrever)
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf); //Salva o valor da variável cpf
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //formatação da váriavel NOME abaixo da variável CPF (a significa alterar)
	fprintf(file,"\nNOME: ");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Inclui a variárel Nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a"); //formatação da váriavel SOBRENOME abaixo da variável NOME
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Inclui a variável Sobrenome
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a"); //formatação da váriavel CARGO abaixo da variável SOBRENOME
	fprintf(file,"\nCARGO: ");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Inclui a variável Cargo
	fprintf(file,cargo);
	fprintf(file,"\n\n"); //inclui mais um espaço após printar da variável CARGO
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
	file = fopen(cpf,"r"); //lê os dados no arquivo com a váriavel pesquisada (r significa ler)
	
	if(file == NULL)
	{
		printf("\tArquivo não encontrado! Insira um CPF cadastrado.\n\n"); //mensagem de erro após pesquisa de um cpf não cadastrado
	}
	
	else
	{
		printf("Essas são as informações do usuário: \n");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); 
	
	FILE *file;
	file = fopen(cpf,"r"); 	
	
	remove(cpf); //define a exclusão do cadastro indicado
	{
		printf("\tUsuário deletado com sucesso!\n\n");
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
	
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
			printf("       ### Cartório da EBAC ###\n\n"); //Título Principal
			printf("   Escolha a opção desejada no menu:\n\n"); //menu inicial
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("   Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls");
	
		
		switch(opcao) //inicio do switch case / inicio da seleção do menu
		{
			case 1:
			registro(); //chamda das funções
			break;
			
			case 2:
			consulta(); //chamada das funções
			break;
			
			case 3:
			deletar(); //chamada das funções
			break;
			
			case 4:
			printf("\n\tObrigado e até mais!\n");
			return 0;
			break;
			
			
			default: //erro de seleção
			printf("\n\tOpção inválida! Escolha umas das opções disponíveis no Menu.\n\n");
			system("pause");
			break; 
				
		} //fim do switch case / fim da seleção
		
	}
}

