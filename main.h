/*
C�digo nosso que est� em C
Santificado seja v�s, console
Venha nos o vosso array[10]
E seja feita, sim, {vossa chave}
Assim no if{
} Como no Else{
} 
O for(nosso;de cada dia;nos da� hoje++)
Debugai as nossas senten�as 
Assim como n�s colocamos o ponto e v�rgula esquecido;
E n�o nos
     Deixeis errar
             Indenta��o
Mas livrai-nos das fun��es recursivas
A main ().
*/

//lib's
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "words.h"
#include "utils.h"

//struct's
typedef struct  {
    char* word;
    char* tip;
    int lenght;
    int countSingleChars;
    bool coutainsChar[255];
} WordInfo;


//function's
WordInfo GetWord();
void RunGame();
void ShowInfos(const char* stats, const char* tip, bool usedLetters[255], int failures);