#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca�a� de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	    //inicio da cria��o de vari�veis/string
        char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		 //Final da cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: ");//Coletando informa��es dos usu�rios
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
		
		FILE *file; // Cria o arquivo
		file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); // Salva o valor da variavel
		fclose(file); // Fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");//Coletando informa��es dos usu�rios
		scanf("%s",nome); //%s refere-se a string
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
    	file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa��es dos usu�rios
		scanf("%s" ,sobrenome); //%s refere-se a string
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
    	file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");//Coletando informa��es dos usu�rios
		scanf("%s" ,cargo); //%s refere-se a string
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;// Cria o arquivo
	file = fopen (cpf, "r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");
	}
	
	system("pause");
	
}

int excluir()
{
	    char cpf[40];
	    
	    printf("Digite o CPF do usu�rio a ser deletado: ");
	    scanf("%s", cpf); //%s refere-se a string
	    
	    remove(cpf);
	    
	    FILE *file;// Cria o arquivo
	    file = fopen(cpf, "r");
	    
	    if(file == NULL)
	    {
	    	printf("O usu�rio foi deletado e n�o se encontra no sistema!.\n");
	    	system("pause");
		}
}

int main()
{
	int opcao=0; // definindo vari�veis
	int looping=1;
	
	for(looping=1;looping=1;)
	{
	
    	system("cls");//Responsavel por limpar a tela
	
    	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	    printf(" \tMenu Inicial\n\n "); // inicio do menu
    	printf("Escolha a op��o desejada do Menu:\n\n");
    	printf("\t1 - Registrar Nomes\n");
     	printf("\t2 - Consultar Nomes\n");
     	printf("\t3 - Excluir Nomes\n\n");
     	printf("\t4 - Sair do Sistema\n\n");
     	printf("Op��o: "); //fim do menu
		
    	scanf("%d", &opcao); // arnazenando a escolho do usu�rio
	
     	system("cls"); //Responsavel por limpar a tela
     	
     	switch(opcao) // inicio da sele��o do menu
     	{
     		case 1:
     		registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta();
    		break;
			
			case 3:
			excluir();
			break;
			
			case 4:
			printf("Obriado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa Opc�o N�o Existe!\n");
    		system("pause");
    		break;
    
        } //fim da sele��o
       
    }
}
