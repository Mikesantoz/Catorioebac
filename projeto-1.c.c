#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em m�moria
#include <locale.h> //bibliotecca de aloca��es de texto por regi�o
#include <string.h> //biblioteca para string 


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
{
	printf("No foi possivel abrir o arquivo, n�o localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
}
int deleta()
{
	char cpf[40];
	
	printf("digite o cpf a ser do usuario a ser deletado");
	scanf("%s",cpf);

	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("usuario n�o encontrado no sistema \n");
		system("pause");
	}
	
}



int main()
{
	int opcao = 0; //Definindo as vari�veis
	int laco = 1;
	
	for (laco = 1; laco = 1;)
	{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		system("cls");
		
		
		printf("### cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - sair do sistema\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);  //armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			registro();
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deleta();
			break;
			
			case 4:
			return 0;
			break;
			
			default:
			printf("essa op��o nao est� disponivel!\n");
			system("pause");
		}
	}	
}
