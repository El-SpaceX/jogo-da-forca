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

#include "utils.h"

//macro's
void ShowLetterUsed(const bool usedLetterArr[255]) {
    printf("Letras usadas: ");
    for(int i=0; i < 255; i++) {
        if(usedLetterArr[i])
            printf("%c ", tolower(i));
    }
    puts("\n\n");
}

bool IsValidCharacter(char character) {
    if((character >= 'a' && character <= 'z')) {
        return true;
    }
    return false;
}


void InitStats(char* stats, int len) {

    int c = 0;
    stats[c] = '_';
    c++;
    while(c < len*2-1) {
        stats[c] = ' ';
        stats[c+1] = '_';
        c+=2;
    }
    stats[len*2-1] = '\0';
    return;
}


void UpdateStats(char* source, const char* word, const char character) {

    int c = 0, n = 0;
    while(source[c] != '\0') {
        if(source[c] != ' ') {
            if(word[n] == character) {
                source[c] = (n == 0) ? toupper(character) : character;
            } 
            n++;
        }
        c++;
    }
}

int countSingleChars(const char* source) {
    if(source == NULL)
        return 0;
    
    bool chars_detected[255] = {false};
    int count = 0, c=0;
    while(source[c] != '\0') {

        chars_detected[(uint8_t)source[c]] = true; 
        c++;
    }
    for(int i=0; i < sizeof(chars_detected); i++) {
        if(chars_detected[i]) count++;
    }
    return count;
}


void ShowBody(const uint8_t body_part) {
    switch(body_part) {
        case 0: {
            puts("--------|");
            break;
        }
        case 1: {
            puts("--------|\n\tO");
            break;
        }
        case 2: { 
            puts("--------|\n\tO\n\t|");
            break;
        }
        case 3: {
            puts("---------|\n\t O\n\t-|");
            break;
        }
        case 4: {
            puts("---------|\n\t O\n\t-|-");
            break;
        }
        case 5: {
            puts("---------|\n\t O\n\t-|-\n\t/");
            break;
        }
        case 6: {
            puts("---------|\n\t O\n\t-|-\n\t/\\");
            break;
        }
    }
}