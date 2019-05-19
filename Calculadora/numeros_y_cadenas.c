#include <stdio.h>
#include "general.h"
#include "numeros_y_cadenas.h"


//is_a_number toma el valor de un puntero a char, pensado para strings, en el que recorre el string 
//y decide si ese string corresponde a un numero o no
int is_a_number(char*p){
    int es=1;
    int flag=0;
    int cantdig=0;
    int neg=0;
    while((*p)!='\0'){
        if((*p)=='-'){
            neg=1;  
        }
        if( ((*p) >= '0') && ((*p) <= '9') ){
            cantdig++;
        }else if((*p) == '.'){
            flag++;
        }else if((*p)=='-'){
            if(cantdig>0){
                es=0;
            }
        }else{
            es=0;
        }
        
    p++;
    }
    if(flag>1){
    es=0;
    }
    if(cantdig==0){
        es=0;
    }
    return es;    
}

float str2float(char *p,float *f){
    float num=0;
    float numdec=0;
    int flag=0;
    int counter=0;
    int validacion;
    int numneg;
    validacion = is_a_number(p);
    if(validacion){
        while((*p)!='\0'){

            if((*p)=='.'){
                flag=1;
            }
            if((*p)=='-'){
                numneg=1;
            }

        if( flag==0){
            
            if( (((*p) >= '0') || ((*p) <= '9'))){
                
                switch(*p){
                    case '0':
                    num=  num+0;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0') && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '1':
                    num=  num+1;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '2':
                    num=  num+2;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '3':
                    num=  num+3;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '4':
                    num=  num+4;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '5':
                    num=  num+5;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '6':
                    num=  num+6;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '7':
                    num=  num+7;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '8':
                    num=  num+8;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                    case '9':
                    num=  num+9;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')  && ((*(p+1)) != '.')){
                        //si hay un numero despues, multiplico por 10
                        num=num*10;
                    }
                    break;
                }
                
            }
        }else if(flag==1){
            counter = counter +1;
            switch(*p){

                    case '0':
                    numdec=  numdec+0;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '1':
                    numdec=  numdec+1;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '2':
                    numdec=  numdec+2;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '3':
                    numdec=  numdec+3;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '4':
                    numdec=  numdec+4;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '5':
                    numdec=  numdec+5;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '6':
                    numdec=  numdec+6;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '7':
                    numdec=  numdec+7;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '8':
                    numdec=  numdec+8;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                    case '9':
                    numdec=  numdec+9;
                    if((( (*(p+1)) >= '0') || ((*(p+1)) <= '9')) && ((*(p+1)) != '\0')){
                        //si hay un numero despues, multiplico por 10
                        numdec=numdec*10;
                    }
                    break;
                }

            }
            p++;
        }
        float divisor = 1;
        int i = 1;
        printf("counter= %d\n",counter);
        for(i; i<counter;i++){
            divisor = divisor*10;
        }
        num=num+(numdec/(divisor));
        
        if(numneg){
            num = num*-1;
        }
        *f=num;
    }    
    return validacion;
  }

