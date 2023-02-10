/* Pertenece a Jose Moreno 8-971-845*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
#define n 20
#define TRUE 1
#define FALSE 0

typedef struct pila{
    char ArrPila[n];
    int tope;
}Pila;

struct {
    char items[n];
    int front_c;
    int final_c;
}s_cola;

void IniciaPila(Pila *pila);
int PilaVacia(Pila *pila);
int PilaLlena(Pila *pila);
char Pop(Pila *pila);
void Push(Pila *pila, char dato);
void elementos(Pila *pila);
void ImprimaPila(Pila *pila);
int numOrChar(char c);
int presedencia(char c);
void infijo();

void agregar(char elemento);
char eliminar();
int c_vacia();
int error_underflow();
int c_llena();
int error_overflow();
void mostrar(int num);
void IniciaCola();

int presentacion()//Funcion que solo imprime Presentacion
{
	printf("\n");
	printf("\t |          UNIVERSIDAD TECNOL%cGICA DE PANAM%c         |\n",224,181);
	printf("\t |     FACULTAD DE ING. DE SISTEMAS COMPUTACIONALES   |\n");
	printf("\t |        LIC. EN ING. SISTEMAS COMPUTACIONALES       |\n");
	printf("\t |                                                    |\n");
	printf("\t |                ESTRUCTURAS DE DATOS I              |\n");
	printf("\t |                                                    |\n");
	printf("\t |                     Proyecto N2                    |\n");
	printf("\t |                                                    |\n");
	printf("\t |                   TEMA: PILA Y COLA                |\n");
	printf("\t |                                                    |\n");
	printf("\t |                     Integrantes:                   |\n");
	printf("\t |                                                    |\n");
	printf("\t |                  Jos%c Moreno   8-971-845           |\n",130);
	printf("\t |                 Alex Guizado   8-989-1571          |\n");
	printf("\t |                                                    |\n");
	printf("\t |                     A%co: 2022                      |\n",164);
}

char pila[MAX], cola[MAX],ind=0,idxc=0; // varialbes(palindromo)
void insertar(char d)
{
     if (ind==MAX) {
         printf("Error Pila llena ");
         getch();
     }
     else {
       pila[ind]=d;
       ind++;
       }
 }
 void insertar_c(int d)
{
     if (idxc==MAX) printf("Error Cola llena ");
     else {
       cola[idxc]=d;
       idxc++;
       }
 }

void main(){
	system("color 70");
	//declaracion de variables
    int opcion, opcion2;
    //variables de palindromo
     int x=1,y, p=FALSE, h=FALSE;
     char z,j;
	 //declaracion de variables 
	 char array[n];
	 int num1;
	 int x1;
	 char salidapila[n]; char salidacola[n];
	 Pila pila;
	 
   	while (p==FALSE){
	system("cls");
    printf("\n        ******* MENU PRINCIPAL *******           \n");
    printf("\n\t1. Pantalla de Presentaci%cn \n", 162);
    printf("\t2. PALINDROMO \n");
    printf("\t3. CONVERSI%cN INFIJO - POSFIJO \n", 224);
    printf("\t4. Salir del programa \n\n");
    printf("       *******************************          \n");
    //lectura de opcion seleccionada
    printf("\n\tIngrese su opci%cn: \b", 162);
    scanf("%d", &opcion);
	system("pause");

		//leer switch Menu Principal
        switch(opcion){
        case 1:
        	system("cls");
        	presentacion();
        	printf("\nPress ...[Enter] para Regresar al menu principal");
			getch();

        break;
        case 2:
        	while(h==FALSE){
			
        	system("cls");
			printf("\n\t*********  PALINDROMO  ***********\n");
        	printf("\n\t 1. Cargar la PILA y COLA\n");
			printf("\t 2. Comparaci%cn de PILA y COLA\n",162);
			printf("\t 3. Sacar datos de la PILA y COLA \n");
			printf("\t 4. Regresar al Men%c principal \n",163);
			printf("\n       **********************************\n");

			//entrada al sub-menu de Palindromo
			printf("\n\t Ingrese una opci%cn: \b", 162);
        	scanf("%d", &opcion2);
       		system("pause");
        		switch(opcion2)
				{
        			case 1:
        				system("cls");
        				IniciaPila(&pila);
			    		IniciaCola();
        				printf("\n\t  --- Cargar la PILA y COLA --- \n");
        				printf("\nElemetos a ingresar en la Pila y Cola\n");
        				printf("\nIntroduzca la palabra: ");
					    scanf("%s", &array);
					    num1 = strlen(array);
					
					    for(x1=0; x1<num1; x1++){
					        agregar(array[x1]);
					        Push(&pila, array[x1]);
					    }
        				printf("\nPress ...[Enter] para Regresar al menu principal");
        				getch();

        			break;
        			case 2:
        				system("cls");
        				printf("\n\t  --- Comparacion de PILA y COLA  ---\n");
        				printf("Estado de la pila: ");
        				ImprimaPila(&pila);
        				printf("\nEstado de la cola: ");
						mostrar(num1);
        				printf("\nPress ...[Enter] para Regresar al menu principal:");
        				getch();
        			break;
        			case 3:
        				system("cls");
        				printf("\n\t  --- Sacar datos de la PILA y COLA --- \n");
        				printf("\nSalida de la cola: \n");
					    for (x1=0; x1<=num1; x1++){
					        if(x1<num1){
					        salidacola[x1] = eliminar();
					        printf("[%c]", salidacola[x1]);
					        }
					        else {
					            printf("\nCola vacia");
					        }
    					}
    					printf("\nSalida de la pila: \n");
					    for(x1=0; x1<=num1; x1++){
					        if(x1<num1){
					        salidapila[x1] = Pop(&pila);
					        printf("[%c]", salidapila[x1]);
					        }
					        else {
					            printf("\n");
					            Pop(&pila);
					        }
					    }
					    if(!strcmp(salidapila,salidacola)){
				        printf("Si es Palindromo");
				    }else{
				        printf("No es Palindromo");
				    }
        				printf("\nPress ...[Enter] para Regresar al menu principal");
        				getch();
        			break;
        			case 4:
        				h=TRUE;
        				getch();
        			break;
        			default:
        				printf("Ingreso una opcion 'incorrecta'");
        				break;
				}
				}//fin sub-menu Palindromo
        break;
        case 3:
        	system("cls");
			printf("\n\t ******* CONVERSI%cN DE INFIJO - POSFIJO *******\n\n", 224);
			printf("\t - Cargar operadores en la PILA\n\t - Mostrar procedimiento de la conversi%cn\n\t - Resultado de la conversi%cn\n\t - Resultado de la operación\n\n",162,162,162);
			printf("\t ***********************************************\n");
			infijo();
			printf("\nPress ...[Enter] para Regresar al menu principal");
			getch();
        break;

        case 4:
            system("cls");
        	p = TRUE;
        	printf(". . . Programa terminado . . .\n");
        break;
        default:
            printf("Ingreso una opcion incorrecta");
            break;
        }//fin sub-menu2
    }//fin while
}//fin main

void infijo(){
	//declaracion de variables
	char entrada[n];
    char salida[n],c;
    int num=0;
    int x,h=0, presAnt=0,press,i=FALSE;
    
    Pila pila;
    IniciaPila(&pila);
    printf("\nIntroduzca la expresion: ");
    scanf("%s",&entrada);
    num = strlen(entrada);
    
    for(x=0;x<num;x++){
        if(entrada[x]=='('){
            Push(&pila,entrada[x]);
            presAnt=0;
        }
        else if (entrada[x]==')'){
            Push(&pila,entrada[x]);
            printf("Estado de la pila: ");
            ImprimaPila(&pila);
            Pop(&pila);
            do {
                printf("Estado de la pila: ");
                ImprimaPila(&pila);
                c=Pop(&pila);
                if(c=='('){
                    break;
                }
                salida[h]=c;
                h=h+1;
                getch();
            }while (i==FALSE);
            c=Pop(&pila);
            presAnt=presedencia(c);
            Push(&pila,c);
            getch();
            continue;
        }
        else if(numOrChar(entrada[x])==FALSE){
            salida[h]=entrada[x];
            h=h+1;
        }
        else {
            press=presedencia(entrada[x]);
            if(press>presAnt){
                presAnt=press;
                Push(&pila,entrada[x]);
            }
            else if(press==presAnt){
                salida[h]=Pop(&pila);
                h++;
                Push(&pila,entrada[x]);
            }
            else if(press<presAnt){
                salida[h]=Pop(&pila);
                h++;
                Push(&pila,entrada[x]);
                presAnt=press;
            }
        }
        getch();
        printf("Estado de la pila: ");
        ImprimaPila(&pila);

    }
    while(PilaVacia(&pila)==FALSE){
        salida[h]=Pop(&pila);
        h=h+1;
        printf("Estado de la pila: ");
        ImprimaPila(&pila);
        getch();
    }
        printf("Expresion en postfija: %s",salida);
}

void IniciaPila(Pila *pila){
    pila->tope=-1;
    printf("Pila Iniciada \n");
}
int PilaVacia(Pila *pila){
    if(pila->tope==-1)
        return TRUE;
    else
         return FALSE;
}
int PilaLlena(Pila *pila){
    if(pila->tope == n-1)
            return TRUE;
    else
        return FALSE;
}
char Pop(Pila *pila){
    if(PilaVacia(pila))
        printf("Pila Vacia \n");
    else{
        char dato = pila->ArrPila[pila->tope];
        pila->tope=pila->tope-1;
        return dato;
    }
}
void Push(Pila *pila, char dato){
    if(PilaLlena(pila))
        printf("Pila Llena \n");
    else{
        pila->tope++;
        pila->ArrPila[pila->tope]= dato;
        }
}
void elementos(Pila *pila){
    printf("la pila tiene %d elementos",pila->tope+1);
}
void ImprimaPila(Pila *pila){
 if(PilaVacia(pila))
    printf("Pila Vacia\n");
 else{
    int i;
    for(i=0;i<=pila->tope;i++){
        printf("[%c]",pila->ArrPila[i]);
    }
        printf("\n");
    }
}
int numOrChar(char c){
    if(c=='+'||c=='/'||c=='-'||c=='*'||c=='('||c==')'||c=='^'){
        return TRUE;
    }
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'){
        return FALSE;
    }
}
int presedencia(char c){
    if(c=='/'||c=='*') {
        return 2;
    }
    else if(c=='+'||c=='-') {
        return 1;
    }
    else if(c=='^'){
        return 3;
    }
}

//(Agregar elemento)
void agregar(char elemento){
 s_cola.items[++s_cola.final_c]=elemento;

}
//(Eliminar elemento)
char eliminar(){
 return s_cola.items[++s_cola.front_c];
 }
//Cola Vacía
int c_vacia(){
 if (s_cola.front_c==s_cola.final_c)
 return 1;
 else
 return 0;
}
//Error Underflow (Subdesbordamiento)
int error_underflow(){
 if (c_vacia())
 return 1;
 else
 return 0;
}
//Cola llena
int c_llena(){
 if (s_cola.final_c==n-1)
 return 1;
 else
 return 0;
}
//Error Overflow (Desbordamiento)
int error_overflow(){
 if (c_llena())
 return 1;
 else
 return 0;
}
void mostrar (num){
 int i;
 for (i = 0; i<num; i++)
 printf("[%c]",s_cola.items[i]);
}
void IniciaCola()
{ s_cola.front_c=-1;
 s_cola.final_c=-1;
 printf("Cola Iniciada \n");
}

