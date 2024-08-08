#include <stdio.h> //traduz a linguagem da maquina pro usuario final
#include <stdlib.h> // salva na memoria do computador 
#include <locale.h> // escolher linguagem de pa�s para acentos
#include <string.h> // responsavel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usuarios no sistema
{
	//inicio cria��o de vari�veis/string
    char arquivo[40];	
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo,cpf); //responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // criando o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da vari�vel 
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo ja criado e atualizando o mesmo "a" significa atualizar
    fprintf(file, ","); 
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando o mesmo
    fprintf(file,nome); //salvando a nova informa��o do usu�rio
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); //abrindo arquivo e atualizando o mesmo
    fprintf(file,sobrenome); //salvando nova informa��o do usu�rio
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: "); //coletando nova informa��o do usu�rio
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando o mesmo
    fprintf(file,cargo);//salvando nova informa��o do usuario
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da cria��o das variaveis
	char cpf[40];
	char conteudo[200];
   //fim da cria��o das variaveis
	printf("Digite o CPF a ser consultado:"); //pedindo informa��o do usu�rio para consulta
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo ja criado "r" significa ler
	
	if(file == NULL)//mostrando o que o sistema tera que fazer caso n�o existir a informa��o salva 
	{
		printf("N�o foi possivel localizar o CPF cadastrado.\n\n");//resposta ao usu�rio 
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //puxando todas as informa�oes que foram salvas no arquivo 
	{
		printf("Essas s�o as informa��es do usu�rio:\n");//comunicando ao usu�rio seus dados salvos
		printf("%s", conteudo);
	    printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	//inicio da cria��o das vari�veis
	char cpf[40];
	//fim da cria��o das vari�veis
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);//removendo arquivo salvo 
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo o arquivo e lendo o mesmo para deletar
	
  	if(file == NULL) //mostrando o que o sistema tera que fazer caso n�o existir a informa��o salva 
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
}

int main()
{
	int opcao=0; //definindo vari�veis
	
	int laco=1;
	for(laco=1;laco=1;) // pedindo pra sempre retornar ao menu 
	{
	     system("cls");
	
	     setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	     printf("\t     *** CART�RIO DA EBAC ***\n\n\n"); //inicio do menu
      	 printf("\t      Escolha a op��o desejada:\n\n");
	     printf("\t\t1 - Cadastrar Nome:\n\n");
	     printf("\t\t2 - Consultar Nome:\n\n");
	     printf("\t\t3 - Deletar Nome:\n\n\n");
	     
	     printf("Op��o:"); // fim do menu
	
	     scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
	     system("cls"); //respons�vel por limpar a tela
	
	switch(opcao) //inicio da sele��o do menu
	  {
		case 1:
	    registro(); //chamada de fun��es
        break;
        
        case 2:
        consultar(); //chamada de fun��es 
        break;
        	
        case 3:
    	deletar(); //chamada de fun��es
		break;
		//fim da sele��o
		
		default: //quando n�o for nenhuma das op��es existentes 
		printf("essa op��o n�o existe!\n\n");
		system("pause");
		break;	
      } 
	}
}



