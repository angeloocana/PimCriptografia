# include <stdio.h>//Bibliotecas para usar comandos de entrada e saída
# include <stdlib.h>//Biblioteca para uso do system("pause")
# include <string.h>//Biblioteca para o usa de strings
# include <conio.h> //Biblioteca para uso do getch()



void menu_opcoes(){

   printf("\n _______________________________________________\n");
   printf("|                                                 |\n");
   printf("|     FACA SUA ESCOLHA                            |\n");
   printf("|                                                 |\n");
   printf("|    1..........CRIPTOGRAFAR UMA MENSAGEM         |\n");
   printf("|    2.........DESCRIPTOGRAFAR UMA MENSAGEM       |\n");
   printf("|    3.........SAIR DO PROGRAMA                   |\n");
   printf("|                                                 |\n");
   printf("|_________________________________________________|\n");


}//fim do cabecalho

void cifrar()
{
    //declaração de variaveis
    char mensagem[100];
    char chave[2];
    int i;
    int tamChave;
    int tamMens;
    char resultado[100];



    //Entrada de dados >>>>mensagem a ser cifrada<<<<<<
        printf("Digite a mensagem: ");
        fflush(stdin); //limpa o buffer do teclado
        gets(mensagem);
        strupr(mensagem);// convertendo a string para maiuscula

    //Entrada de dados >>>Chave<<<
    printf("Informe a chave com tres digitos : ");
    fflush(stdin); //limpa o buffer do teclado
    gets(chave);
    strupr(chave);//convertendo a string para maiuscula

    tamMens = strlen(mensagem);
    tamChave = strlen(chave);
    printf("o tamanho da chave e:  %d", tamChave);


      for (i=0 ; i <strlen(mensagem); i++)
      {
         if(i >= tamChave){
            mensagem[i] = (mensagem[i] + chave[i- tamChave])%26 + 65;


                }else{

                mensagem[i] = (mensagem[i] + chave[i])%26 + 65;
            }

      }
       printf("\nMensagem criptografada    = %s", mensagem);// até aki tá ok
}


int mainnnn(){

    // Definir cor do prompt de comando
    system ("color F5");

    //Declaração de variaveis
    int escolha;

    do
    {
        menu_opcoes();
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
                system("cls"); // limpa o que tem antes
                cifrar();
                getch();//pausa no sistema
            break;

            case 2:
                system("cls");
                //decifrar();
                getch();
            break;

            case 3:
                system("cls");
                printf("Programa finalizado com sucesso");
                getch;
            break;

            default:
                system("cls");
                printf("Opcao invalida");
                getch();
            break;
        }

    }while(escolha != 3);


       system("pause");

}// fim da main
