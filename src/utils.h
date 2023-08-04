/*
Código nosso que está em C
Santificado seja vós, console
Venha nos o vosso array[10]
E seja feita, sim, {vossa chave}
Assim no if{
} Como no Else{
} 
O for(nosso;de cada dia;nos daí hoje++)
Debugai as nossas sentenças 
Assim como nós colocamos o ponto e vírgula esquecido;
E não nos
     Deixeis errar
             Indentação
Mas livrai-nos das funções recursivas
A main ().
*/

#ifndef INCLUDED_UTILS_H
#define INCLUDED_UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

//macros
#define ClearConsole() system("cls")

//functions
int countSingleChars(const char* source);
bool IsValidCharacter(char character);
void ShowLetterUsed(const bool usedLetterArr[255]);
void InitStats(char* stats, int len);
void UpdateStats(char* source, const char* word, const char character);
void ShowBody(const uint8_t body_part);
#endif