#include <stdio.h>
#include "general.h"
#include "numeros_y_cadenas.h"


//is_a_number toma el valor de un puntero a char, pensado para strings, en el que recorre el string 
//y decide si ese string corresponde a un numero o no
int is_a_number(char*p){
    int es=1; //es indica la variable que guarda 1 si efectivamente es un numero
    int flag=0;
    int cantdig=0;
    while((*p)!='\0'){
        if( ((*p) >= '0') && ((*p) <= '9')){    //si es un numero el char actual incremento cuantos numeros me enontre y es sigue en 1
            cantdig++;
        }else if((*p) == '.'){
            flag++;
        }else{          //si no es un numero o un punto entonces no es un numero y es =0 para siempre.
            es=0;
        }
    p++;
    }
    if(flag>1){ //si hay mas de un punto es=0
    es=0;
    }
    if(cantdig==0){ //si no se introducen numeros es=0
        es=0;
    }
    return es;    
}

//le paso un puntero a char p donde inicia mi string y un puntero a float donde colocare en memoria
//el valor del float correspondiente al string. SI NO ES VALIDO EL STRING NO SE MODIFICA MEMORIA.
float str2float(char *p,float *f){
    float num=0;
    float numdec=0;
    int flag=0;
    int counter=0;
    int validacion;
    validacion = is_a_number(p);
    if(validacion){
        while((*p)!='\0'){

            if((*p)=='.'){  //Se introduce este flag para distinguir con que parte del numero se trabaja
                flag=1;
            }

        if( flag==0){    //para la parte del numero mayor  a 1 voy agregando los valores fijandome donde deben quedar
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
        }else if(flag==1){//si trabajo con la parte menor a 1 tomo un contador de cuantos digitos para saber por que potencia de 10 dividir el numero restante
            //habiendo dicho esto trabajo igual que con numeros mayores a 1 solo que al final divido y sumo.
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
        *f=num;
    }    
    return validacion;
  }
