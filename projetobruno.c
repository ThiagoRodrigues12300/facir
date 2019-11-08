#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
int id;
char filme[20];
}Tlista;

Tlista listafilme[50];
int x=0;
int y,z;

void cadastro(){
printf("Insira o id do filme: ");
scanf("%d",&listafilme[x].id);
setbuf(stdin,NULL);
printf("Insira o titulo do filme: ");
fgets(listafilme[x].filme,20,stdin);
setbuf(stdin,NULL);
x++;
menu();
}

void listar(){
for (y=0;y<=50;y++){
    if(listafilme[y].id != 0){
printf("Id do filme: %d\n",listafilme[y].id);
printf("Titulo do filme: %s\n", listafilme[y].filme);
setbuf(stdin,NULL);
    }
}
menu();
}

void menu(){

printf("1-Cadastro\n");
printf("2-Listar\n");
printf("3-sair\n");
setbuf(stdin,NULL);
printf("Opcao: ");
scanf("%d",&z);

switch(z){
case 1:
    cadastro();
    break;
case 2:
    listar();
    break;
case 3:
    exit(0);
    }
}

int main(){
menu();
return 0;
}
