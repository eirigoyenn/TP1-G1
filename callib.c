/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/



// === Libraries and header files ===
#include <stdio.h>
#include <stdlib.h>

// This file
#include "callib.h"

/// @privatesection
// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

// === Global variables ===

// === Function prototypes for private functions with file level scope ===

// === ROM Constant variables with file level scope ===

// === Static variables and constant variables with file level scope ===


// === Global function definitions ===
/// @publicsection

int 
parseCmdLine(int argc, char *argv[],pCallback (p), void *userData)
{
    int result=0, i,valid=1;
    char *clave;
    char *valor;
    
    for(i = 1; i < argc; i++)
    {
        if((*(argv[i]) == '-')&&(*((argv[i])+1)== '\0'))        //Error de tipo 2.
        {   
            printf("ERROR TIPO 2:opcion sin clave\n");                                                   //Encontro opci�n con clave vac�a.
            result=-EXIT_FAILURE;
            i=argc;
        }
        else if((*(argv[i]) == '-')&&( argv[i+1] == NULL))      //Error de tipo 1.
        {    
             printf("ERROR TIPO 1:opcion sin valor\n");                               //Encontro opci�n sin valor.
            result=-EXIT_FAILURE;
            i=argc;
        }
        else if((*(argv[i]) == '-')&&(argv[i] != NULL))         //Encontro opci�n.
        {   
            clave=argv[i++];                                    //Avanza dos(este m�s el del for())
            valor=argv[i];
            
            valid=p(clave+1,valor,((args_t*)userData)+result);  //Llama al callback y le pasa el userdata donde guardar
               if (!valid){                                     //(a clave le suma uno para que no pase el '-').
                   i=argc;                                      //Al user data le sumo result para que siempre guarde en la siguiente struct.
                   result=-EXIT_FAILURE;
                }                                               //si callback devuelve 0 hubo un error entonces corto
            result++;
        }
        else                                                    //Encuentra un par�metro.
        {   
            valor=argv[i];
            valid=p(NULL,valor,((args_t*)userData)+result);      //Hace lo mismo que con opciones pero aplicado a par�metros.
            
                if (!valid){
                    i=argc;
                    result=-EXIT_FAILURE;
                }
                  
            result++;
        }
    
    }
    return result;
}

/// @privatesection
// === Local function definitions ===
