#include <stdio.h>
#include "general.h"
#include "numeros_y_cadenas.h"

#define es_cifra(c) ( (c)>='0' && (c)<='9' )

int str2float(char* cadena,float* numero){
    enum states{INICIAL,LISTO_SIGNO,ENTERO,SIN_ENTERO,DECIMAL,INICIO_EXPO,SIGNO_EXPO,EXPO,SALIR};
    int estado=INICIAL;
    
    int signo=POSITIVO;
    int entero=0;
    int decimal=0;
    int cifras_dec=0;
    int signo_expo=POSITIVO;
    int expo=0;
    float rta=0;
    int i;
    float temp;
    
    while(estado!=SALIR){
        switch (estado){
            
            case INICIAL:
                if (es_cifra(*cadena)){
                    entero=(*cadena)-'0';
                    estado=ENTERO;
                } else if (*cadena == '+'){
                    signo=POSITIVO;
                    estado=LISTO_SIGNO;
                } else if (*cadena == '-'){
                    signo=NEGATIVO;
                    estado=LISTO_SIGNO;
                } else if (*cadena == '.'){
                    estado=SIN_ENTERO;
                } else {
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
            
            case LISTO_SIGNO:
                if(es_cifra(*cadena)){
                    entero=(*cadena)-'0';
                    estado=ENTERO;
                } else if (*cadena == '.'){
                    estado=SIN_ENTERO;
                } else{
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
            
            case ENTERO:
                if(es_cifra(*cadena)){
                    entero*=10;
                    entero+= (*cadena)-'0';
                    estado=ENTERO;
                } else if (*cadena == '.'){
                    estado=DECIMAL;
                } else if (*cadena == 'E' || *cadena == 'e'){
                    estado=INICIO_EXPO;
                } else if (*cadena == '\0'){
                    estado=SALIR;
                } else {
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
            
            case SIN_ENTERO:
                if(es_cifra(*cadena)){
                    decimal = (*cadena)-'0';
                    cifras_dec++;
                    estado=DECIMAL;
                } else {
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
            
            case DECIMAL:
                if(es_cifra(*cadena)){
                    decimal *=10;
                    decimal += (*cadena)-'0';
                    cifras_dec++;
                    estado=DECIMAL;
                } else if(*cadena =='E'||*cadena =='e'){
                    estado = INICIO_EXPO;
                } else if(*cadena == '\0'){
                    estado = SALIR;
                } else {
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
            
            case INICIO_EXPO:
                if(es_cifra(*cadena)){
                    expo = (*cadena)-'0';
                    estado = EXPO;
                }else if(*cadena == '+'){
                    signo_expo=POSITIVO;
                    estado=SIGNO_EXPO;
                }else if(*cadena=='-'){
                    signo_expo=NEGATIVO;
                    estado=SIGNO_EXPO;
                }else{
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
                
            case SIGNO_EXPO:
                if (es_cifra(*cadena)){
                    expo = (*cadena)-'0';
                    estado=EXPO;
                } else {
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;
            
            case EXPO:
                if (es_cifra(*cadena)){
                    expo*=10;
                    expo+=(*cadena)-'0';
                    estado=EXPO;
                }else if(*cadena =='\0'){
                    estado=SALIR;
                }else{
                    printf("Str2Float: ERROR\n");
                    return ERROR;
                }
                break;  
        }
        cadena++; 
    }
    
    rta = (float) entero;
    
    temp = (float) decimal;
    
    for(i=0;i<cifras_dec;i++){
        temp/=10.;
    }
    rta += temp;
    
    if (signo_expo == POSITIVO){
        for(i=0;i<expo;i++){
            rta *= 10.;
        }
    }else{
        for(i=0;i<expo;i++){
            rta /= 10.;
        }
    }
    
    if (signo == NEGATIVO){
        rta *= -1.;
    }
    
    *numero = rta;
    return SIN_ERROR;
}



int is_a_number(char* cadena){
    
}