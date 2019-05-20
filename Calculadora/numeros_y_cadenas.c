#include <stdio.h>
#include "general.h"
#include "numeros_y_cadenas.h"

#define es_cifra(c) ( (c)>='0' && (c)<='9' ) //Esta macro permite identificar si un caracter corresponde
                                                //a un dígito del 0 al 9

int str2float(char* cadena,float* numero){//Convierte una cadena de caracteres a un número float
    
    //Implementacion de FSM
    enum states{INICIAL,LISTO_SIGNO,ENTERO,SIN_ENTERO,DECIMAL,INICIO_EXPO,SIGNO_EXPO,EXPO,SALIR};
    int estado=INICIAL;
    
    //Valores iniciales:
    int signo=POSITIVO;//signo del resultado
    int entero=0;//parte entera del resultado
    int decimal=0;//parte decimal del resultado
    int cifras_dec=0;//cantidad de cifras decimales
    int signo_expo=POSITIVO;//Signo del exponente (notacion científica)
    int expo=0;//Valor del exponente
    float rta=0;//Resultado de la conversion
    int i;//Contador auxiliar
    float temp;//Variable auxiliar para el càlculo del resultado
    
    while(estado!=SALIR){//Hasta que haya acabado de leer la cadena...
        switch (estado){
            
            case INICIAL://El primer caracter puede ser...
                if (es_cifra(*cadena)){//Un nùmero, en cuyo caso esta leyendo un entero
                    entero=(*cadena)-'0';
                    estado=ENTERO;
                } else if (*cadena == '+'){//El signo +: el número es positivo
                    signo=POSITIVO;
                    estado=LISTO_SIGNO;
                } else if (*cadena == '-'){//El signo -: el nùmero es negativo
                    signo=NEGATIVO;
                    estado=LISTO_SIGNO;
                } else if (*cadena == '.'){//Un punto: el nùmero carece de parte entera
                    estado=SIN_ENTERO;
                } else {//de lo contrario, se ingreso un caracter no válido (o bien, una cadena vacia "")
                    return ERROR;
                }
                break;
            
            case LISTO_SIGNO://El primer caracter fue el signo + o -, ahora espera encontra...
                if(es_cifra(*cadena)){//Un nùmero, en cuyo caso esta leyendo un entero
                    entero=(*cadena)-'0';
                    estado=ENTERO;
                } else if (*cadena == '.'){//Un punto: el número carece de parte entera
                    estado=SIN_ENTERO;
                } else{//de lo contrario. se ingreso un caracter inválido
                    return ERROR;
                }
                break;
            
            case ENTERO://Està leyendo la parte entera del nùmero. Entonces, puede recibir...
                if(es_cifra(*cadena)){//Otro entero; el resultado anterior es multiplicado por 10,
                    entero*=10;         //...y se le suma el nuevo dígito ingresado
                    entero+= (*cadena)-'0';
                    estado=ENTERO;
                } else if (*cadena == '.'){//Un punto: pasa a la parte decimal
                    estado=DECIMAL;
                } else if (*cadena == 'E' || *cadena == 'e'){//La letra E: pasara a recibir un exponente
                    estado=INICIO_EXPO;
                } else if (*cadena == '\0'){//Acabo la cadena. El nùmero ya fue ingresado
                    estado=SALIR;//(carece de parte decimal o exponente)
                } else {//de lo contrario, recibio un caracter inválido
                    return ERROR;
                }
                break;
            
            case SIN_ENTERO://Si el nùmero carece de parte entera, entonces...
                if(es_cifra(*cadena)){//DEBE recibir un dìgito para su parte decimal.
                    decimal = (*cadena)-'0';//Coloca el decimal recibido
                    cifras_dec++;//E incrementa (a 1) la cantidad de decimales recibidos
                    estado=DECIMAL;
                } else {//de lo contrario, se ingresó una configuracion inválida
                    return ERROR;
                }
                break;
            
            case DECIMAL://Se està leyendo la parte decimal del nùmero. Entonces, recibe...
                if(es_cifra(*cadena)){//Un nùmero: multiplica por 10 la parte decimal y le suma la nueva
                    decimal *=10; //cifra (al igual que con los enteros)
                    decimal += (*cadena)-'0';
                    cifras_dec++;//incrementa el contador de decimales recibidos (servira para ajustar 
                    estado=DECIMAL;//la parte decimal posteriormente
                } else if(*cadena =='E'||*cadena =='e'){//La letra E: pasara a recibir un exponente
                    estado = INICIO_EXPO;
                } else if(*cadena == '\0'){//Acabò el nùmero. El mismo carece de exponente
                    estado = SALIR;
                } else {//De lo contrario, recibio un caracter invalido
                    return ERROR;
                }
                break;
            
            case INICIO_EXPO://Primer caracter tras la letra E. Puede recibir...
                if(es_cifra(*cadena)){//Un nùmero. Lo ingresa como exponente y sigue leyendo
                    expo = (*cadena)-'0';
                    estado = EXPO;
                }else if(*cadena == '+'){//El signo +: el exponente es positivo
                    signo_expo=POSITIVO;
                    estado=SIGNO_EXPO;
                }else if(*cadena=='-'){//El signo -: el exponente es negativo
                    signo_expo=NEGATIVO;
                    estado=SIGNO_EXPO;//De lo contrario, recibio un caracter invalido
                }else{
                    return ERROR;
                }
                break;
                
            case SIGNO_EXPO://Acaba de recibir el signo del exponente. Por lo tanto, necesita...
                if (es_cifra(*cadena)){//recibir una cifra. La ingresa como exponente
                    expo = (*cadena)-'0';
                    estado=EXPO;
                } else {//Sino, la configuracion no es vàlida
                    return ERROR;
                }
                break;
            
            case EXPO://Està leyendo el exponente (recibio ya al menos una cifra). Puede recibir...
                if (es_cifra(*cadena)){//Otra cifra (igual procedimiento que para el ingreso de enteros)
                    expo*=10;
                    expo+=(*cadena)-'0';
                    estado=EXPO;
                }else if(*cadena =='\0'){//El fin de la cadena. El nùmero termino de leerse
                    estado=SALIR;
                }else{//De lo contrario, la configuracion no es vàlida
                    return ERROR;
                }
                break;  
        }
        cadena++; //Avanza al siguiente caracter a leer
    }
    
    rta = (float) entero; //Primero, coloca la parte entera en la respuesta.
    
    temp = (float) decimal;//La variable temporal toma el valor de la parte decimal (la cual era un int)
    
    for(i=0;i<cifras_dec;i++){//la acomoda, para situarse detras del punto decimal
        temp/=10.;
    }
    rta += temp;//y la añade al resultado
    
    if (signo_expo == POSITIVO){//Si el exponente era positivo...
        for(i=0;i<expo;i++){//Corre el nùmero hacia la izquierda del punto decimal tantas veces como sea necesario
            rta *= 10.;
        }
    }else{ //de lo contrario, el exponente es negativo
        for(i=0;i<expo;i++){//por lo que, en vez de multiplicar por 10, se divide por 10
            rta /= 10.;
        }
    }
    
    if (signo == NEGATIVO){//Si el nùmero era negativo
        rta *= -1.;//transforma la respuesta en negativa
    }
    
    *numero = rta; //guarda el resultado en el puntero dado
    return SIN_ERROR;//informa que no hubo errores en el programa
}



int is_a_number(char* cadena){//Indica si una cadena corresponde a un número válido
    int error; //indicador de error auxiliar
    float aux; //variable float auxiliar (su contenido se perdera, se emplea solo para llamar a la
                //funcion str2float con el formato adecuado)
    
    error = str2float(cadena,&aux); //Determina si el formato de la cadena corresponde a un número válido
    
    if (error==ERROR){ //Informa el resultado (si hubo error, no es un número válido)
        return FALSO;
    }
    return VERDAD;//Si no hubo error, entonces es un número válido
}