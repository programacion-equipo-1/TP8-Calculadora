/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   manejo_de_arreglos.h
 * Author: tefi
 *
 * Created on May 18, 2019, 7:23 PM
 */

/* MATI: completar el .c y comentar el .h */

#ifndef MANEJO_DE_ARREGLOS_H
#define MANEJO_DE_ARREGLOS_H

int add_op(char simbolo, int(*funcion)(float,float,float*) );
int existe_op(char simbolo);
int operador(float op1,float op2,char simbolo,float* rta);


#endif /* MANEJO_DE_ARREGLOS_H */

