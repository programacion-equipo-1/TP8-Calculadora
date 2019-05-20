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

// Funciones encargadas del manejo de los arreglos de operaciones y punteros a funciones

#ifndef MANEJO_DE_ARREGLOS_H
#define MANEJO_DE_ARREGLOS_H

// ADD_OP
// Recibe:
//  -Un símbolo que representa una operacion (ejemplo: + representa una suma)
//  -Un puntero a una funcion encargada de realizar dicha operacion
//      (Estas funciones, a su vez, reciben 2 float como operandos, y la dirección
//      de un float donde deben guardar el resultado. Devuelven un indicador de error)
// Devuelve:
//  -Un indicador de error (en caso de repetirse un mismo símbolo para dos operaciones, o
//   haberse quedado sin espacio en los arreglos)
// Funcion:
//  Añade en el arreglo de operaciones el símbolo entregado, y en el de punteros, la dirección
//  de la funcion correspondiente a dicha operación
int add_op(char simbolo, int(*funcion)(float,float,float*) );
//  EXISTE_OP
//  Recibe:
//  -Un símbolo representativo de una operacion
//  Devuelve:
//  -Indicador que informa si dicho símbolo corresponde a una funcion ya ingresada en los arreglos
int existe_op(char simbolo);
//  OPERADOR
//  Recibe:
//  -Dos operandos (float)
//  -Símbolo que define la operación a realizar (buscada dentro de los arrelgos)
//  -Puntero a un float donde almacenar el resultado
//  Devuelve:
//  -Indicador de error
int operador(float op1,float op2,char simbolo,float* rta);


#endif /* MANEJO_DE_ARREGLOS_H */

