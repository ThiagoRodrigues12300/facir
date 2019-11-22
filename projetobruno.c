#include <stdio.h>
#include <string.h>

typedef struct filme{
    int id;
    int titulo[50];
    char genero[50];
    int ano;
}Tfilme;

typedef struct cliente{
    int id;
    char nome[30];
    char cpf[13];
    char email[30];
}Tcliente;

Tfilme listafilme[50];
Tcliente listacliente[50];
char busca[50];
int x=0,y=0,cont=0,conty=0;

void instrucao(){
    printf("\n INSTRUCAO \n");
    printf("Existem teclas numericas de 1 a 4, navegue digitando elas no espaco necessario.");
    system("pause");
    system("cls");
    menu();
}

void posicao(){
    printf("Insira o ID do filme: ");
    scanf("%d",&x);
        setbuf(stdin,NULL);
    x-=1;
}

void cadastro(){
    if(x>=0){
posicao();
listafilme[x].id = x+1;
printf("Insira o titulo do filme: ");
fgets(listafilme[x].titulo,50,stdin);
setbuf(stdin,NULL);
printf("Insira o genero do filme: ");
fgets(listafilme[x].genero,50,stdin);
setbuf(stdin,NULL);
printf("Insira o ano do filme: ");
scanf("%d",&listafilme[x].ano);
cont++;
system("pause");
system("cls");
menu1();
    }
}

void listar(){
for(x=0;x<cont;x++){
    if(listafilme[x].id !=0){
printf("ID: %d\n",listafilme[x].id);
printf("Titulo: %s",listafilme[x].titulo);
printf("Genero: %s",listafilme[x].genero);
printf("Ano: %d\n\n",listafilme[x].ano);
    }else{
printf("%d - %s\n",x+1,listafilme[x].titulo);
    }
}
system("pause");
system ("cls");
menu1();
}

void atualizar(){
if(x>=0){
    posicao();
    setbuf(stdin,NULL);
    listafilme[x].id = x+1;
    printf("Insira o titulo do filme: ");
    fgets(listafilme[x].titulo,50,stdin);
    setbuf(stdin,NULL);
    printf("Insira o genero do filme: ");
    fgets(listafilme[x].genero,50,stdin);
    setbuf(stdin,NULL);
    printf("Insira o ano do filme: ");
    scanf("%d",&listafilme[x].ano);
    setbuf(stdin,NULL);
system("pause");
system("cls");
menu1();
    }
}

void excluir(){
    posicao();
    listafilme[x].id = 0;
    listafilme[x].ano = 0;
    strcpy(listafilme[x].titulo, "Insira um novo Titulo");
    strcpy(listafilme[x].genero, "Vazio");
    setbuf(stdin,NULL);
    system("cls");
    menu1();
}

void editar(){
    printf("\nEditar\n");
    printf("\t1- Atualizar\n");
    printf("\t2- Excluir\n");
    printf("\t3- Voltar\n");
    printf("Opção: ");
    scanf ("%d", &x);

    switch(x){
    case 1:
        atualizar();
        break;
    case 2:
        excluir();
        break;
    case 3:
        system("cls");
        menu1();
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        system("pause");
        system ("cls");
        editar();
        break;
    }
}

void visualizar(){
    posicao();
    setbuf(stdin,NULL);
    printf("Id: %d\n", listafilme[x].id);
    printf("Titulo: %s",listafilme[x].titulo);
    printf("Genero: %s",listafilme[x].genero);
    printf("Ano: %d\n",listafilme[x].ano);
    system("pause");
    system("cls");
    menu1();
}

void consulta(){
    printf("Insira o Titulo do filme: ");
    fflush(stdout);
    setbuf(stdin,NULL);
    fgets(busca,50,stdin);
    for(x=0;x<=50;x++){
        if(strcmp(busca,listafilme[x].titulo) == 0){
    printf("Id: %d\n",listafilme[x].id);
    printf("Titulo: %s",listafilme[x].titulo);
    printf("Genero: %s",listafilme[x].genero);
    printf("Ano: %d\n",listafilme[x].ano);
        }
    }
    system("pause");
    system("cls");
    menu1();
}

void posicao1(){
    printf("Insira o id do Cliente: ");
    scanf("%d",&y);
    setbuf(stdin,NULL);
    y-=1;
}

void cadastro1(){
	if(cont>=0){
	posicao1();
	listacliente[y].id = y+1;
	printf("Insira o Nome do cliente: ");
	fgets(listacliente[y].nome,50,stdin);
	setbuf(stdin,NULL);
	printf("Insira o CPF do cliente: ");
	fgets(listacliente[y].cpf,50,stdin);
	setbuf(stdin,NULL);
	printf("Insira o E-mail do cliente: ");
	fgets(listacliente[y].email,50,stdin);
	setbuf(stdin,NULL);
	conty++;
	system("pause");
    system ("cls");
	menu2();
	}
}

void listar1(){
    for(y=0;y<conty;y++){
        if(listacliente[y].id!=0){
            printf("ID: %d\n",listacliente[y].id);
            fflush(stdout);
            printf("Nome: %s",listacliente[y].nome);
            fflush(stdout);
            printf("CPF: %s",listacliente[y].cpf);
            fflush(stdout);
            printf("E-mail: %s",listacliente[y].email);
            fflush(stdout);
            }else{
                printf("%dº - %s\n",y+1,listacliente[y].nome);
        }
    }
    system("pause");
    system ("cls");
    menu2();
}

void atualizar1(){
    if(conty>=0){
	posicao1();
	listacliente[y].id = y+1;
	printf("Insira o Nome do cliente: ");
	fgets(listacliente[y].nome,30,stdin);
	setbuf(stdin,NULL);
	printf("Insira o CPF do cliente: ");
	fgets(listacliente[y].cpf,13,stdin);
	setbuf(stdin,NULL);
	printf("Insira o E-mail do cliente: ");
	fgets(listacliente[y].email,30,stdin);
	setbuf(stdin,NULL);
	system("pause");
    system ("cls");
	menu2();
    }
}

void excluir1(){
    posicao1();
    listacliente[y].id = 0;
    strcpy(listacliente[y].nome, "Cadastre um novo Cliente");
    strcpy(listacliente[y].email, "Vazio");
    strcpy(listacliente[y].cpf, "Vazio");
    setbuf(stdin,NULL);
    system ("cls");
    menu2();
}

void editar1(){
    printf("\nEditar\n");
    printf("\t1- Atualizar\n");
    printf("\t2- Excluir\n");
    printf("\t3- Voltar\n");
    printf("Opção: ");
    scanf("%d", &y);

    switch(y){
    case 1:
        atualizar1();
        break;
    case 2:
        excluir1();
        break;
    case 3:
        system("cls");
        menu2();
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        system("pause");
        system ("cls");
        editar1();
        break;
    }
}

void visualizar1(){
    posicao1();
    printf("ID: %d\n",listacliente[y].id);
    printf("Nome: %s",listacliente[y].nome);
    printf("CPF: %s",listacliente[y].cpf);
    fflush(stdout);
    printf("E-mail: %s",listacliente[y].email);
    fflush(stdout);
    system("pause");
    system ("cls");
    menu2();
}

void consulta1(){
    printf("Insira o nome do cliente: ");
    fflush(stdout);
    setbuf(stdin,NULL);
    fgets(busca,30,stdin);
    for(y=0;y<=30;y++){
        if(strcmp(busca, listacliente[y].nome) == 0){
    printf("ID: %d\n",listacliente[y].id);
    printf("Nome: %s",listacliente[y].nome);
    printf("CPF: %s",listacliente[y].cpf);
    printf("E-mail: %s",listacliente[y].email);
        }
    }
    system("pause");
    system("cls");
    menu2();
}
void menu1(){
printf("Locadora de Filmes NoGroup\n");
    printf("\t1-Cadastrar\n");
    printf("\t2-Editar\n");
    printf("\t3-Listar\n");
    printf("\t4-Visualizar\n");
    printf("\t5-Consulta por Titulo\n");
    printf("\t6-Voltar\n");
    printf("Opção: ");
    scanf("%d", &x);
setbuf(stdin,NULL);
switch(x){
case 1:
    cadastro();
    break;
case 2:
    editar();
    break;
case 3:
    listar();
    break;
case 4:
    visualizar();
    break;
case 5:
    consulta();
    break;
case 6:
    system("cls");
    menu();
    break;
default:
    printf("\nComando inválido, tente novamente!\n\n");
    setbuf(stdin,NULL);
    system("pause");
    system("cls");
    menu1();
    break;
    }
}

void menu2(){
printf("Locadora de Filmes NoGroup\n");
    printf("\t1- Cadastrar\n");
    printf("\t2- Editar\n");
    printf("\t3- Listar\n");
    printf("\t4- Visualizar\n");
    printf("\t5- Consulta por nome\n");
    printf("\t6- Voltar\n");
    printf("Opção: ");
scanf("%d",&x);
    switch(x){
    case 1:
        cadastro1();
        break;
    case 2:
        editar1();
        break;
    case 3:
        listar1();
        break;
    case 4:
        visualizar1();
        break;
    case 5:
        consulta1();
        break;
    case 6:
        system("cls");
        menu();
        break;
    default:
        printf("\nComando inválido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        system("pause");
        system("cls");
        menu2();
        break;
        }
    }

void menu(){
    printf("Locadora de Filmes NoGroup\n");
    printf("\t1- Filmes\n");
    printf("\t2- Clientes\n");
    printf("\t3- Instruções\n");
    printf("\t4- Sair\n");
    printf("Opção: ");
    scanf ("%d", &x);
    switch(x){
    case 1:
        system("cls");
        menu1();
        break;
    case 2:
        system("cls");
        menu2();
        break;
    case 3:
        instrucao();
        break;
    case 4:
        printf("\nFinalizando o Programa...\n\n");
	exit(0);
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        system("pause");
        system("cls");
        menu();
        break;
    }
}


int main(){
menu();
return 0;
}
