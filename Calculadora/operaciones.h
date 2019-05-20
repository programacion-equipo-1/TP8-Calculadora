/* 
 * File:   operaciones.h
 * Author: tefi
 *
 * Created on May 18, 2019, 7:18 PM
 */

/* 
 * Este módulo contiene las operaciones que podrá realizar la calculadora
 * Serán cargados por el main, mediante las funciones del módulo MANEJO_DE_ARREGLOS
 * 
 * Todas las operaciones tienen el siguiente formato:
 * Reciben dos operandos float
 * Reciben un puntero en donde guardaran la respuesta
 * Devuelven un indicador de error
 * 
 */

#ifndef OPERACIONES_H
#define OPERACIONES_H
//Suma dos nùmeros: op1 + op2
int suma(float op1,float op2,float* rta);
//Resta el segundo operando al primero: op1 - op2
int resta(float op1,float op2,float* rta);
//Divide el primer operando entre el segundo: op1 / op2
int division(float op1,float op2,float* rta);
//Multiplica dos nùmeros: op1 x op2
int multiplicacion(float op1,float op2,float* rta);
//Eleva el primer operando a la potencia indicada por el segundo (casteado a int): op1 ^ (int) op2
int potencia_entera(float op1,float op2,float* rta);

#endif /* OPERACIONES_H */

