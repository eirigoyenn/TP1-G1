/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/


#ifndef CALLIB_H
#    define CALLIB_H

// === Libraries and header files ===

// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

typedef int (*pCallback) (char*, char*, void*);     //Puntero a funci�n de callbacks.

typedef struct {

    char* key;
    char* value;

}args_t;                                            //Estructura donde se guardan los resultados v�lidos.

// === Global variables ===

// === ROM Constant variables ===

// === Global function definitions ===

int parseCmdLine(int argc, char* argv[], pCallback p, void* userData);  //Prototipo de funci�n que analiza la sintaxis del los datos ingresados

#endif /* CALLIB_H */
