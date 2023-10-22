#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em mémoria
#include <locale.h> //bibliotecca de alocações de texto por região
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
	printf("No foi possivel abrir o arquivo, não localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas são as informações do usuario: ");
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
		printf("usuario não encontrado no sistema \n");
		system("pause");
	}
	
}



int main()
{
	int opcao = 0; //Definindo as variáveis
	int laco = 1;
	
	for (laco = 1; laco = 1;)
	{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		system("cls");
		
		
		printf("### cartório da EBAC ###\n\n"); //inicio do menu
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - sair do sistema\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);  //armazenando a escolha do usuário
	
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
			printf("essa opção nao está disponivel!\n");
			system("pause");
		}
	}	
}
