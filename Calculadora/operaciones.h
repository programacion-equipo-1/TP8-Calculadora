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

int suma(float op1,float op2,float* rta);
int resta(float op1,float op2,float* rta);
int division(float op1,float op2,float* rta);
int multiplicacion(float op1,float op2,float* rta);
int potencia_entera(float op1,float op2,float* rta);

#endif /* OPERACIONES_H */

