/******************************************************************************
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *****************************************************************************/


// === Libraries and header files ===
#include <stdio.h>
#include <stdlib.h>
#include "callib.h"

// This file
//#include "test.h"

/// @privatesection
// === Constants and Macro definitions ===

// === Enumerations, structures and typedefs ===

// === Global variables ===

// === Function prototypes for private functions with file level scope ===

// === ROM Constant variables with file level scope ===

// === Static variables and constant variables with file level scope ===

// === Global function definitions ===
/// @publicsection

void
test(void)
{
    char * p1 [] ={"a.out","-hola","hol","epar","-hello","hell",NULL};
    char* p2[] = { "a.out","-hola","hol","epar","-hello",NULL };
    char * p3 [] ={"a.out","-","hol","epar","-hello","hell",NULL};
    char * p4 [] ={"a.out","epar",NULL};
    char * p5 [] ={"a.out","-hola","hol",NULL};
    char * p6 [] ={"a.out","-altura","150",NULL };
    char* p7[] = { "a.out","-altura","32680",NULL };
    char* p8[] = { "a.out","-altura","150","hola","-g", "debugger",NULL };
        
    printf("OK, the answer should be 3: %d\n",parseCmdLine(6,p1,NULL, NULL));
    printf("Error tipo 1 : %d\n", parseCmdLine(5, p2, NULL, NULL));
    printf("Error tipo 2 : %d\n",parseCmdLine(6,p3,NULL, NULL));
    printf("OK, the answer should be 1: %d\n",parseCmdLine(2,p4,NULL, NULL));
    printf("OK, the answer should be 1: %d\n",parseCmdLine(3,p5,NULL, NULL));
    
}
/// @privatesection
// === Local function definitions ===

