/* 
 * File:   calculador_recursivo.h
 * Author: tefi
 *
 * Created on May 18, 2019, 8:18 PM
 */

#ifndef CALCULADOR_RECURSIVO_H
#define CALCULADOR_RECURSIVO_H

/*
 *      CALCULADOR RECURSIVO
 * 
 *  Recibe: -La dirección de un puntero, idealmente definido en la función usuaria de este módulo,
 *           el cual apunta a un arreglo de punteros, cada uno de los cuales apunta a una cadena
 *           de caracteres. Dichas cadenas corresponderán con números y operaciones, y estarán
 *           ordenadas por el arreglo de punteros empleando notación polaca.
 *          -Puntero a un float, donde se guardará la respuesta
 *  Devuelve: -Indicador de error
 * 
 *  Funcion:
 *      El calculador recursivo es la funcion encargada de traducir los parámetros
 *  ingresados por línea de comando, recuperando tanto los valores numéricos ingresados
 *  como los símbolos de las operaciones. Realiza las operaciones ingresadas en formato de notación
 *  polaca, y devuelve un indicador de error, en caso de realizarse una operación inválida
 *  (tal como dividir por 0), ingresar un símbolo desconocido, o si falta un operando.
 * 
 *  Por ejemplo,
 *      + - 5 3 x 2 4
 *  Se traduce a
 *  (5-3)x(2*4) = 10
 * 
 * NOTA: deben de haberse inicializado los arreglos del módulo MANEJO_DE_ARREGLOS antes de su uso
 * NOTA: el puntero al arreglo de punteros se verá modificado en cada llamado a esta función.
 */

int calculador_recursivo(char*** primer_argumento,float* rta);

#endif /* CALCULADOR_RECURSIVO_H */

