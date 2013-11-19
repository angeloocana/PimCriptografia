#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>

int main()
{
	char caractereArquivo;
	char caminhoArquivoAbrir[200];  //vetor para guardar o nome do arquivo
	char caminhoArquivoSalvar[200]; //vetor para guardar o nome do arquivo
	char senha[10];
	FILE *ArquivoParaCriptografar; //ponteiro de irá abrir o arquivo
	FILE *ArquivoParaSalvar; //ponteiro que irá salvar o arquivo
	int opcao;
	int i = 1;
	int nSenha = 0;

	while (1 == 1)
	{
		printf("\n                      \xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB             CRIPTOHARD            \xDB");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB    DIGITE A OPCAO DESEJADA:       \xDB");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB    1 - CRIPTOGRAFAR ARQUIVO       \xDB");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB    2 - DESCRIPTOGRAFAR ARQUIVO    \xDB");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB    3 - SAIR                       \xDB");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB                                   \xDB");
		printf("\n                      \xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB\n\n");


		scanf("%d", &opcao);

		if (opcao == 1)
		{
			printf("\Digite o caminho do arquivo a ser criptografado: \n\n"); //Pede o nome do arquivo
			scanf("%s", caminhoArquivoAbrir); //Le a variável, abre o arquivo que sera criptografado


			printf("\nDigite o caminho para salvar o arquivo a ser criptografado: \n\n"); //Pede o nome do arquivo para salvar
			scanf("%s", caminhoArquivoSalvar); //Le a variável, caminho para salvar o arquivo

			printf("\nDigite a senha de 10 digitos:");
			scanf("%s", senha);

			if (!(ArquivoParaCriptografar = fopen(caminhoArquivoAbrir, "r")))//abre o arquivo no qual o caminho foi digitado acima
			{
				printf("\t\t\tERRO!!!!\a\n\n");//Arquivo não localizado

				printf("Verifique o caminho digitado e tente novamente...");
				getch();
				exit(1);
			}

			ArquivoParaCriptografar = fopen(caminhoArquivoAbrir, "r"); //Abre o arquivo para leitura
			ArquivoParaSalvar = fopen(caminhoArquivoSalvar, "a+"); //Abre o arquivo para escrita


			nSenha = 0;
			while ((fscanf(ArquivoParaCriptografar, "%c", &caractereArquivo)) != EOF) //percorre o arquivo todo
			{

				putc((int) caractereArquivo + nSenha, ArquivoParaSalvar); //Converte o caracter na tabela ASC e corre 23 posições e escreve no arquivo

				nSenha = nSenha + 1;

				if (strlen(senha) == nSenha)
					nSenha = 0;

			}


			fclose(ArquivoParaCriptografar); // fecha o arquivo
			fclose(ArquivoParaSalvar); // fecha o arquivo

			printf("Arquivo criptografado com Sucesso!\n");
		}
		else

			if (opcao == 2)


			{
				printf("\nDigite o caminho do arquivo para descriptogarfar:\n\n"); //Pede o caminho a ser descriptografado
				scanf("%s", caminhoArquivoAbrir); //Le a variável

				printf("\nDigite o caminho do arquivo para salvar:\n\n"); //Pede o caminho para salvar o arquivo descriptografado
				scanf("%s", caminhoArquivoSalvar); //Le a variável

				printf("\nDigite a senha de 10 digitos:");
				scanf("%s", senha);

				if (!(ArquivoParaCriptografar = fopen(caminhoArquivoAbrir, "r")))
				{
					printf("Não foi possível abrir o arquivo");
					getch();
					exit(0);
				}

				ArquivoParaCriptografar = fopen(caminhoArquivoAbrir, "r"); //Abre o arquivo para leitura
				ArquivoParaSalvar = fopen(caminhoArquivoSalvar, "a+"); //Abre o arquivo para escrita



				nSenha = 0;
				while ((fscanf(ArquivoParaCriptografar, "%c", &caractereArquivo)) != EOF) //percorre o arquivo todo
				{

					putc((int) caractereArquivo - nSenha, ArquivoParaSalvar); //Converte o caracter na tabela ASC e corre 23 posições e escreve no arquivo

					nSenha = nSenha + 1;

					if (strlen(senha) == nSenha)
						nSenha = 0;

				}

				fclose(ArquivoParaCriptografar); // fecha o arquivo
				fclose(ArquivoParaSalvar); // fecha o arquivo

				printf("Arquivo descriptografado com sucesso!\n");
			}

			else

				if (opcao == 3)
				{
					exit(0);
				}

	}
	system("PAUSE");
	return(0);


}
