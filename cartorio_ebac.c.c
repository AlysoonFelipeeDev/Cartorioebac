#include <stdio.h> //traduz a linguagem da maquina pro usuario final
#include <stdlib.h> // salva na memoria do computador 
#include <locale.h> // escolher linguagem de país para acentos
#include <string.h> // responsavel por cuidar das strings

int registro() //Função responsável por cadastrar os usuarios no sistema
{
	//inicio criação de variáveis/string
    char arquivo[40];	
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo,cpf); //responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // criando o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variável 
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo ja criado e atualizando o mesmo "a" significa atualizar
    fprintf(file, ","); 
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando o mesmo
    fprintf(file,nome); //salvando a nova informação do usuário
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); //abrindo arquivo e atualizando o mesmo
    fprintf(file,sobrenome); //salvando nova informação do usuário
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: "); //coletando nova informação do usuário
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando o mesmo
    fprintf(file,cargo);//salvando nova informação do usuario
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da criação das variaveis
	char cpf[40];
	char conteudo[200];
   //fim da criação das variaveis
	printf("Digite o CPF a ser consultado:"); //pedindo informação do usuário para consulta
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo ja criado "r" significa ler
	
	if(file == NULL)//mostrando o que o sistema tera que fazer caso não existir a informação salva 
	{
		printf("Não foi possivel localizar o CPF cadastrado.\n\n");//resposta ao usuário 
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //puxando todas as informaçoes que foram salvas no arquivo 
	{
		printf("Essas são as informações do usuário:\n");//comunicando ao usuário seus dados salvos
		printf("%s", conteudo);
	    printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	//inicio da criação das variáveis
	char cpf[40];
	//fim da criação das variáveis
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);//removendo arquivo salvo 
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo o arquivo e lendo o mesmo para deletar
	
  	if(file == NULL) //mostrando o que o sistema tera que fazer caso não existir a informação salva 
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
}

int main()
{
	int opcao=0; //definindo variáveis
	
	int laco=1;
	for(laco=1;laco=1;) // pedindo pra sempre retornar ao menu 
	{
	     system("cls");
	
	     setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	     printf("\t     *** CARTÓRIO DA EBAC ***\n\n\n"); //inicio do menu
      	 printf("\t      Escolha a opção desejada:\n\n");
	     printf("\t\t1 - Cadastrar Nome:\n\n");
	     printf("\t\t2 - Consultar Nome:\n\n");
	     printf("\t\t3 - Deletar Nome:\n\n\n");
	     
	     printf("Opção:"); // fim do menu
	
	     scanf("%d", &opcao); // armazenando a escolha do usuário
	
	     system("cls"); //responsável por limpar a tela
	
	switch(opcao) //inicio da seleção do menu
	  {
		case 1:
	    registro(); //chamada de funções
        break;
        
        case 2:
        consultar(); //chamada de funções 
        break;
        	
        case 3:
    	deletar(); //chamada de funções
		break;
		//fim da seleção
		
		default: //quando não for nenhuma das opções existentes 
		printf("essa opção não existe!\n\n");
		system("pause");
		break;	
      } 
	}
}



