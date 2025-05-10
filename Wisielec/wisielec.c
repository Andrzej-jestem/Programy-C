/*
    Gra WISIELEC
    Jest określone słowo do odgadniecia
    Gracz widzi tyle kresek ile liter w hasle
    Pod kreskami napisana jest ilosc pozostalych szans (10 na start)
    Program sprawdza czy zostały jezszcze puste miejsca i czy zostały szanse
    Jeżeli tak, program prosi gracza o wprowadzenie litery
    Program sprawdza czy taka litera jest w hasle, jeżeli tak to zastepuje kreske ta litera. 
    Jeżeli nie, mówi o tym graczowi i odejmuje szanse

    Funkcje:
    - printResult = jezeli sa jeszcze szanse i nie ma pustych miejsc wyswietl graczowi ze wygral
    - printLose = jezeli szanse sie skonczyly wyswietl graczowi ze przegral
    - resetBoard = czysci zawartosc tabeli
    - printBoard = wyswietl kreski oznaczajace litery w hasle oraz ilosc szans
    - checkLetter = popros o wprowadzenie litery i sprawdz czy taka litera zawiera sie w hasle
    - printUsed = wypisz tabele uzytych liter
    - chooseWord = losowanie linijki z pliku .txt i odczytanie znajdujacego sie tam slowa


*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char board[20];
int wordLength;
char playerLetter = ' ';
char usedLetters[24];
char word[20];
int tries = 0;
int lifes = 10;


void chooseWord();  // wylosuj liczbe -> dla i(0; ilosc linijek) {jezeli (i == wylosowana liczba) to przypisz zawartosc do bufora}
void resetBoard();
void printBoard();
void checkLetter();
int checkFreeSpaces();
void sortUsedLetters();
int checkIfUsed();
void printUsed();
void printResult();
void printHangedMan();


int main()
{
    srand(time(0));

    chooseWord();
    resetBoard();
    printBoard();
    
    while (checkFreeSpaces() != 0 && lifes != 0)
    {
        checkLetter();        
    }
    printResult();

    return 0;
}

void resetBoard()
{
    for(int i = 0; i < wordLength; i++)
    {
        board[i] = '_';
    }
}

void printBoard()
{
    printf("********************\n");
    for(int i = 0; i < wordLength; i++)
    {
        printf("%c ", board[i]);
    }
    printf("\n********************\n");

}

void chooseWord()
{
    int line = rand() % 20;
    FILE *pF = fopen("hasla.txt", "r");

    if (pF == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char buffer [20];

    for(int i = 0; i < 20; i++)
    {
        fgets(buffer, 20, pF);

        if(line == i)
        {
            strcpy(word, buffer);
        }
    }
    fclose(pF);

    word[strcspn(word, "\n")] = '\0';  // usunięcie \n
    wordLength = strlen(word);
}

void sortUsedLetters()
{
    for(int i = 0; i < tries; i++)
    {
        for(int j = 0; j < tries - 1; j++)
        {
            if(usedLetters[j] > usedLetters[j+1])
            {
                char temp = usedLetters[j];
                usedLetters[j] = usedLetters[j+1];
                usedLetters[j+1] = temp;
            }
        }
    }
}


void checkLetter()  
{
    int found = 0;        // found letter flag

    do
    {
        printf("Enter a letter: ");
        scanf(" %c", &playerLetter);
        playerLetter = toupper(playerLetter);
        
    } while (checkIfUsed());
    
    usedLetters[tries] = playerLetter;
    tries++;

    for(int i = 0; i < wordLength; i++)
    {
        if(word[i] == playerLetter)
        {
            board[i] = playerLetter;
            found = 1;
        }            
    }

    printBoard();
    
    if(found == 0)
    {
        printf("You missed!\n");
        lifes--;
        //printf("Remaining lifes: %d\n", lifes);
        printHangedMan();
    }
    printUsed();
    
}

int checkFreeSpaces()
{
    int freeSpaces = wordLength;

    for(int i = 0; i < wordLength; i++)
    {
        if(board[i] != '_')
        {
            freeSpaces--;
        }
    }
    return freeSpaces;
}

int checkIfUsed()
{
    int ifUsed = 0;
    for(int i = 0; i < tries; i++)
    {
        if(usedLetters[i] == playerLetter)
        {
            printf("You already used that letter!\n");
            ifUsed = 1;
            break;
        }
    }
    return ifUsed;
}

void printUsed()
{
    sortUsedLetters();

    printf("Used letters: ");
    for(int i = 0; i < tries; i++)
    {
        printf("%c ", usedLetters[i]);
    }
    printf("\n\n");
}

void printResult()
{
    if(checkFreeSpaces() == 0)
    {
        printf("YOU WON!\n");
        printf("Remaining lifes: %d", lifes);
    }
    else
    {
        printf("YOU LOST!\n");
    }
}

void printHangedMan()
{
    switch (lifes)
    {
    case 9:
        printf("\n    ____ ____\n\n");       // floor
        break;
    case 8:
        printf("\n\t|\n\t|\n\t|\n\t|\n    ____|____\n");       // pole
        break;
    case 7:
        printf("\n\t _____\n\t|\n\t|\n\t|\n\t|\n    ____|____\n");      // bar
        break;
    case 6:
        printf("\n\t _____\n\t|     |\n\t|\n\t|\n\t|\n    ____|____\n");      // rope
        break;
    case 5:
        printf("\n\t _____\n\t|     |\n\t|     0\n\t|\n\t|\n    ____|____\n");   // head
        break;
    case 4:
        printf("\n\t _____\n\t|     |\n\t|     0\n\t|     |\n\t|\n    ____|____\n");   // body
        break;
    case 3:
        printf("\n\t _____\n\t|     |\n\t|     0\n\t|    /| \n\t|\n    ____|____\n");   // hand 1
        break;
    case 2:
        printf("\n\t _____\n\t|     |\n\t|     0\n\t|    /|\\ \n\t|\n    ____|____\n");   // hand 1
        break;
    case 1:
        printf("\n\t _____\n\t|     |\n\t|     0\n\t|    /|\\ \n\t|    /\n    ____|____\n");   // leg 1
        break;
    case 0:
        printf("\n\t _____\n\t|     |\n\t|     0\n\t|    /|\\ \n\t|    / \\ \n    ____|____\n");   // leg 1
        break;

    default:
        break;
    }
}