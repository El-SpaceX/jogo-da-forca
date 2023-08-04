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

#include "main.h"

int main() {
    do {
        RunGame();
        puts("Deseja jogar novamente? [Y/N] ");
        char response = getchar();
        if(tolower(response) != 'y') break;
    } while(true);

    puts("Obrigado por jogar meu projeto!");
    system("pause");
    return 0;
}






WordInfo GetWord() {
    new_random_index:
    srand(time(NULL));
    int random_index = rand() % sizeof(words)/sizeof(words[0]);
    WordInfo wordInfo;
    if(words[random_index][0] == NULL)
        return wordInfo;

    wordInfo.word = words[random_index][0];
    wordInfo.tip = words[random_index][1];
    wordInfo.lenght = strlen(words[random_index][0]);
    wordInfo.countSingleChars = countSingleChars(words[random_index][0]);
    if(wordInfo.countSingleChars > 6) {
        goto new_random_index;
    }

    int c=0;
    
    //isso evita um bug, que nao lembro qual e, e nem sei oque causa o mesmo, adicionei isso e resolveu, tambem nao sei como cheguei na conclusao que isso ajudaria
    memset(wordInfo.coutainsChar, 0, sizeof(wordInfo.coutainsChar));

    while(words[random_index][0][c] != '\0') {
        wordInfo.coutainsChar[words[random_index][0][c]] = true;
        c++;
    }

    return wordInfo;
};

void ShowInfos(const char* stats, const char* tip, bool usedLetters[255], int failures) {
    ClearConsole();
    printf("DICA: %s\n\n", tip);
    printf("Palavra: %s\n", stats);
    ShowLetterUsed(usedLetters);
    ShowBody(failures);
}




void RunGame() {
    int failures=0, hits = 0;
    bool usedLetters[255] = {false};

    WordInfo wordInfo = GetWord();
    
    //alloca stats de forma dinamica pro tamanho da palavra e formata a string(_ _ _ _)
    char* stats = (char*)malloc(wordInfo.lenght*2*sizeof(char));
    InitStats(stats, wordInfo.lenght);

    ClearConsole();
    ShowInfos(stats, wordInfo.tip , usedLetters, failures);
    
    while(1) {	
	    fflush(stdin);
        printf("Digite uma letra: ");
        char character = getchar(); 
        while (getchar() != '\n');
        character = tolower(character);


        ShowInfos(stats, wordInfo.tip , usedLetters, failures);

        if(!IsValidCharacter(character)) {
            puts("\nDigite uma letra valida: a-z A-Z.\n");
            continue;
        }



        if(usedLetters[character]) {
            puts("\nVoce ja tentou essa letra.\n");
            continue;
        }

        usedLetters[character] = true;
        if(wordInfo.coutainsChar[character]) {
            hits++;
            UpdateStats(stats, wordInfo.word, character);
            
            ShowInfos(stats, wordInfo.tip , usedLetters, failures);

            puts("\nVoce acertou uma letra!\n\n");
            if(hits >= wordInfo.countSingleChars) {
                //ClearConsole();
                printf("PARABENS! Voce ganhou, a palavra era: %s.\nTome uma coca-cola como recompensa.\n", wordInfo.word);
                break;
            }
        } 
        
        else {
            failures++;
            ShowInfos(stats, wordInfo.tip , usedLetters, failures);

            printf("\nA palavra nao contem a letra %c.\n\n\n", character);

            if(failures >= 6) {
                puts("Voce perdeu, quem sabe na proxima...");
                printf("A palavra era: %s\n", wordInfo.word);
                break;
            }
        }
    }
    free(stats);
}

