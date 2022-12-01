#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "dlist.h"
#include "list.h"
#include "queue.h"
#include "heap.h"

/*
   Print queue
*/
static void print_dlist (DList list) {//NO
    DListNode *node;
    float data; 
	int i;
	float a;

    fprintf(stdout, "List size is %d\n", dlist_size(&list));

    i = 0;
    node = dlist_head(&list);
	if(node==NULL)
		printf("MALLLLL");
    while (1) {
    	a = *(float *)dlist_data(node);
			printf(" - op %.2f \n", a);
		data = 0;
        i++;

        if (dlist_is_tail(node))
            break;
        if (!dlist_is_tail(node))
            node = dlist_next(node);
        
        fflush(stdin);
    }

   return;
}
char * getline(void) {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
}
int isoperator(char character){
	if(character=='('){
		return 1;
	}else if(character==')'){
		return 1;
	}else if(character=='^'){
		return 1;
	}else if(character=='*'){
		return 1;
	}else if(character=='/'){
		return 1;
	}else if(character=='+'){
		return 1;
	}else if(character=='-'){
		return 1;
	}
	return 0;
}
void changenum (char str1[], char str2[], DList *lista){
	int i, len1=0;
	float* data, temp=0;
	
	for(i=0; str1[i]!='\0'; i++){
		len1+=1;
	}
	for(i=0; str1[i]!='\0'; i++){
		temp+= (str1[i]-'0')*pow(10, len1-(i+1));
		
	}
	for(i=0; str2[i]!='\0'; i++){
		temp+= (str2[i]-'0')*pow(10, -(i+1));	
	}
	data=&temp;
	
	str2[0]='\0';
	
	if(lista->size == 0){
		dlist_ins_next(lista, NULL , data);
	}else{
		dlist_ins_next(lista, lista->tail , data);
	}
}
void changeop (char character, DList *lista){
	float* data,i;
	if(character=='('){
		i=-8; *data=i;
		
	}else if(character==')'){
		i=-7; *data=i;
	
	}else if(character=='^'){
		i=-6; *data=i;
	
	}else if(character=='*'){
		i=-5; *data=i;
	
	}else if(character=='/'){
		i=-4; *data=i;

	}else if(character=='+'){
		i=-3; *data=i;
		
	}else if(character=='-'){
		i=-2; *data=i;
		
	}
	if(lista->size == 0){
		dlist_ins_next(lista, NULL , data);
	}else{
		dlist_ins_next(lista, lista->tail , data);
	}	
}
int isnumber(char character){
	if(character=='1'){
		return 1;
	}
	if(character=='2'){
		return 2;
	}
	if(character=='3'){
		return 3;
	}
	if(character=='4'){
		return 4;
	}
	if(character=='5'){
		return 5;
	}
	if(character=='6'){
		return 6;
	}
	if(character=='7'){
		return 7;
	}
	if(character=='8'){
		return 8;
	}
	if(character=='9'){
		return 9;
	}
	if(character=='0'){
		return 0;
	}
	return 0;
}
int reduce(char* entrada, DListNode *expression,DList *lista){
	
	int size = strlen(entrada)-1, i=0, j=0;
	//sirven para verificar que el numero almacenado en la cadena sea de a lo más dos cadenas y un punto
	char str1[16]={'\0'}, str2[16]={'\0'}, size1=10, size2=10;
	float data;
	int index1=0, index2=0;
	DListNode *cosito;
	
	while(i<size){
		if(entrada[i]==32){
			i++;
			printf("%d -  %d - spc \n", i, size);
		}
		if(isoperator(entrada[i]) ){ //preguntamos si el siguiente caracter es un operador
			changeop(entrada[i], lista); //asigna un valor negativo a cada operador (, ), ^, *, /, +, -, 
			i++; 
			cosito = dlist_tail(lista);
			
			printf("%d -  %d - op %.2f \n", i, size, *(float *)dlist_data(cosito));	//FUNCIONA
		}
		if(isnumber(entrada[i]) || entrada[i]=='.'){//preguntamos si el siguiente caracter es un numero o "."
			
			index1=0; index2=0;
			
			//Un numero puede ser de la forma zzzz.yyyy, .yyyy o zzzz 
			while(isnumber(entrada[i]) ){
				str1[index1]=entrada[i];
				str1[index1+1]='\0';
				i++; index1++;
			}
			
			if(entrada[i]=='.')
				i++;
			
			while(isnumber(entrada[i]) ){
				str2[index2]=entrada[i];
				str2[index2+1]='\0';
				i++; index2++;
			}
			
			changenum(str1, str2, lista);//añade en la posicion j del arreglo expression el valor dado por str1.str2
			cosito = dlist_tail(lista);
			printf("%d -  %d - op %.2f \n", i, size, *(float *)dlist_data(cosito));	//FUNCIONA	//FUNCIONA
			
			for(index1=0; index1<size1; index1++){
				str1[index1]='\0';
			}
			for(index2=0; index2<size2; index2++){
				str1[index2]='\0';
			}
			index1=0;index2=0;
		}else{
			printf("Error en la sintaxis");//añadir funcion que pone cadena despues un momento
			return -1;
		}
		
	}
}

// compare
static int compare(const void *float1, const void *float2) {

    if ( *(const float *)float1 > *(const float *)float2 )
        return 1;
    else if ( *(const float *)float1 < *(const float *)float2 )
        return -1;
    else
        return 0;
}
int evaluarp(float opi){
	
	if(opi == -6){
		return 3;
	}
	if(opi == -5){
		return 2;
	}
	if(opi == -4){
		return 2;
	}
	if(opi == -3){
		return 1;
	}
	if(opi == -2){
		return 1;
	}else if(opi == -7){
		return 0;
	}else{
		return -1;
	}
		
}
void traduccion (DList *lista){
	DListNode *nodo;
	ListNode *nodi;
	Heap pila;
	heap_init(&pila, compare, NULL);
	List list;
	int temp = 0;
	list_init(&list,free);
	nodo = dlist_head(lista);
	nodi = list_head(&list);
	void **bus;
	while (1) {
    	
    	if(nodo->data >= 0){
    		list_ins_next(&list,nodi,nodo->data);
		}
    	if(nodo->data < 0){
    		if(heap_size(&pila) == 0){
    			heap_insert(&pila,nodo->data);
    			temp = evaluarp(*(float*)dlist_data(nodo));
    		}else{
    			
    			if(temp < evaluarp(*(float *)dlist_data(nodo))){
    				heap_insert(&pila,nodo->data);
    			
				}else{
					
					heap_extract(&pila,bus);
					list_ins_next(&list,nodi,(float *)bus);
					temp = evaluarp(*(float *)dlist_data(nodo));	
				}
			}
		}
    	
        if (dlist_is_tail(nodo)){
			break;
		   
       	}else{  
            nodo = nodo->next;
            nodi = nodi->next;
        }
    }
}

void solucion(List lista){ 
	ListNode *nodi;
	nodi = list_head(&lista);
	float sumita,valor2; 
	int operador;
	while (1){
    	
    	if(list_is_head(&lista,nodi)){
    		sumita = *(float *)list_data(nodi);
    		valor2 = *(float *)list_data(list_next(nodi));
    		operador = *(int *)list_data(list_next(list_next(list_next(nodi))));
    		nodi = list_next(list_next(nodi));
		}else{
			valor2 = *(float *)list_data((nodi));
			operador = *(int *)list_data(list_next(nodi));
		}
		
		switch (operador){
			case -6:
				sumita=pow(sumita,valor2);
			break;
			
			case -5:
				sumita=sumita*valor2;
			break;
			
			case -4:
				sumita=sumita/valor2;
			break;
			
			case -3:
				sumita=sumita+valor2;
			break;
			
			case -2:
				sumita=sumita-valor2;
			break;
		}
    	 
    	 
        if (list_is_tail(nodi))
            break;
        else
            nodi = list_next(nodi);
    }
}

int main(int argc, char const *argv[]) {
	char *entrada;
	DList lista;
	dlist_init(&lista,free);//esta linea rompe el programa
	DListNode *expression;
	expression = dlist_head(&lista);//aqui tambien
	
	printf("Porfavor digite la operacion infija: \n >>");
	entrada = getline();
	reduce(entrada,expression,&lista);
	
	
	print_dlist(lista);
}
