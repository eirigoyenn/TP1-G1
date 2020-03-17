/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/

// === Libraries and header files ===
#include <stdio.h>
#include <stdlib.h>

#include "callib.h"
#include <string.h>


/// @privatesection
// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

// === Global variables ===

// === Function prototypes for private functions with file level scope ===

int 
parseCallback(char* key, char* value, void* userData);      //Prototipo de callback que guarda opciones y parámetros.

// === ROM Constant variables with file level scope ===

// === Static variables and constant variables with file level scope ===

// === Global function definitions ===


/// @publicsection
int
main(int argc, char* argv [])
{   
    args_t argStruc[10];                                    //Define un arreglo de estructuras para guardar la data.
    int cantidad;
    
    char *prueba[]={"hola","-altura","150"};
    
    cantidad=parseCmdLine(3,prueba,parseCallback,argStruc);
    
    //test();
    printf("%d\n",cantidad);
    
    printf("%s\n",argStruc[0].key);
    printf("%s\n",argStruc[0].value);

    return (EXIT_SUCCESS);
}


/// @privatesection
// === Local function definitions ===

int parseCallback(char* key, char* value, void* userData)   //Toma un key con su value y lo guarda en memoria.
{

    args_t* argStruc = (args_t*)userData;            //Castea la struc donde debe guardar.
    int valid = 1, num;

    if (key == NULL) {                               //Si fue parametro lo guarda.

        argStruc->key = value;
    }

    else {                                           //Si fue opcion, verifica que sea la clave correcta.

        if (!strcmp(key, "altura")) {                

            argStruc->key = key;
        }
        else {
            valid = 0;                               //Si no fue correcta devuelvo 0
        }

        num = atoi(value);


        if (num < 300 && valid == 1) {               //Verifica que el valor sea el rango que espero, sino devuelve 0

            argStruc->value = value;
        }
        else {
            valid = 0;
        }
    }
    printf("HECHO\n");
    return valid;
}