#include <stdio.h> // biblioteca de comunica��o de usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis/strings
 
    printf("\nDigite o CPF a ser cadastrado:\n"); //coletando info do us�ario  
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
    
    FILE *file; // Cria o arquivo Banco de Dados
    file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
    fprintf(file,cpf); // salva o valor da vari�vel
    fclose(file); // Fechar� o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
    

}

int consulta()
{
	setlocale(LC_ALL,"portuguese");
	char cpf[40];
	char conteudo[350];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); 
	
	FILE *file;
	file = fopen(cpf, "r"); 
	
	if (file == NULL)
	{
	    printf("O arquivo n�o est� no banco de dados!"); 
	}
	
	while (fgets(conteudo, 350, file) != NULL) 
	{
	    printf("\nEssas s�o as informa��es do usu�rio: "); 
	    printf("%s", conteudo);
	    printf("\n\n");
	}
	system("pause");
	}

int deletar()
{

	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no cadastro!. \n");
		system("pause");
	}
    
}


int main()
{
    int opcao = 0; //definindo as variaveis
    int loop = 1; 
    char senhadigitada[10] = "a";
    int comparacao;
    
    printf("\n### Registros da EBAC ###\n\n");
    printf("Login de Administrador Digite sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
    	system("cls");
        for (loop = 1; loop == 1;) //Loop Retorno sempre vai ser 1 e come�ar� de novo
        { 
            system("cls"); //Limpa o sistema
            setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
            printf("\n### Registros da EBAC ###\n\n");
            printf("~~ Escolha a op��o desejada do menu ~~ \n\n");
            printf("\n\t1-Registrar Nomes\n");
            printf("\n\t2-Consultar Nomes\n");
            printf("\n\t3-Deletar Nomes\n");
            printf("\n\t4- Sair do menu\n");
            printf("Op��o: ");
            scanf("%d", &opcao);
            
            system("cls");
            
            switch (opcao) { //chamada das fun��es
                case 1:
                    registro();
                    system("pause");
                    break;
                
                case 2:
                    consulta();
                    system("pause");
                    break;
                
                case 3:
                    deletar();
                    system("pause");
                    break;
                    
                case 4:
                    printf("Obrigado pela prefer�ncia e volte sempre!\n");
                    system("pause");
                    return 0;
                    break;
                
                default:
                    printf("\nErro!: Essa op��o n�o existe!\n");
                    system("pause");
                    break;
                    
            }
        }
    }
    return 16;
}
