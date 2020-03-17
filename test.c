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
parseCallback(char* key, char* value, void* userData);      //Prototipo de callback que guarda opciones y par�metros.

// === ROM Constant variables with file level scope ===

// === Static variables and constant variables with file level scope ===

// === Global function definitions ===


/// @publicsection
int
main(int argc, char* argv [])
{   
    args_t argStruc[10];                                    //Define un arreglo de estructuras para guardar la data.
    int cantidad;
    
    char * p1[]={"/a.out","-","no","deberia","seguir"};
    char * p2[]={ "/a.out","-altura",NULL};
    char * p3[]={"/a.out","-peso","120"};
    char * p4[]={"/a.out","pesaje","-peso","120"};
    char * p5[]={"/a.out","-altura","10","-peso","299"};
    char * p6[]={"/a.out","-peso","500"};
    
        
    //TEST 1:error tipo 2
    printf("TEST 1:error tipo 2\n");
    printf("Linea de comandos: %s  %s\n",p1[0],p1[1]);
    cantidad=parseCmdLine(2,p1,parseCallback,argStruc);
    printf("\n");
    
    //TEST 2:error tipo 1
    printf("TEST 2:error tipo 1\n");
    printf("Linea de comandos: %s  %s\n",p2[0],p2[1]);
    cantidad=parseCmdLine(2,p2,parseCallback,argStruc);
    printf("\n");
    
    //TEST 3:1 opcion
    printf("TEST 3:1 opcion\n");
    printf("Linea de comandos: %s  %s  %s\n",p3[0],p3[1],p3[2]);
    cantidad=parseCmdLine(3,p3,parseCallback,argStruc);
    printf("OPCIONES:%d\n clave:%s valor:%s\n",cantidad,argStruc[0].key,argStruc[0].value);
    printf("\n");
    
    //TEST 4:1 opcion y un parametro
    printf("TEST 4: 1 opcion y 1 paramtro\n");
    printf("Linea de comandos: %s  %s  %s  %s \n",p4[0],p4[1],p4[2],p4[3]);
    cantidad=parseCmdLine(4,p4,parseCallback,argStruc);
    printf("OPCIONES:%d\n clave:%s valor:%s\n",cantidad-1,argStruc[0].key,argStruc[0].value);
    printf("PARAMTRO:%s\n",argStruc[1].value);
    printf("\n");
    
    //TEST 5:2 opciones
    printf("TEST 5:2 opciones\n");
    printf("Linea de comandos: %s  %s  %s  %s  %s\n",p5[0],p5[1],p5[2],p5[3],p5[4]);
    cantidad=parseCmdLine(5,p5,parseCallback,argStruc);
    printf("OPCIONES:%d\n clave1:%s valor1:%s\n clave2:%s valor2:%s\n",cantidad,argStruc[0].key,argStruc[0].value,argStruc[1].key,argStruc[1].value);
    printf("\n");
    
    //TEST 6:1 opcion con error de contenido
    printf("TEST 6:1 opcion con error de contenido\n");
    printf("Linea de comandos: %s  %s  %s\n",p6[0],p6[1],p6[2]);
    cantidad=parseCmdLine(3,p6,parseCallback,argStruc);
    printf("\n");
    
    

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

        if (!strcmp(key, "altura") || !strcmp(key,"peso")) {                

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
    
    if (valid==0){
        printf("ERROR DE CONTENIDO\n");
    }
    
    return valid;
}