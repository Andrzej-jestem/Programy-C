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
    - printWin = jezeli sa jeszcze szanse i nie ma pustych miejsc wyswietl graczowi ze wygral
    - printLose = jezeli szanse sie skonczyly wyswietl graczowi ze przegral
    - resetBoard = czysci zawartosc tabeli
    - printBoard = wyswietl kreski oznaczajace litery w hasle oraz ilosc szans
    - checkLetter = popros o wprowadzenie litery i sprawdz czy taka litera zawiera sie w hasle
    - printUsed = wypisz tabele uzytych liter

    W przyszlosci:
    - chooseWord = losowanie linijki z pliku .txt i odczytanie znajdujacego sie tam slowa


*/


#include <stdio.h>
#include <ctype.h>

char board[7];
char playerLetter = ' ';
char usedLetters[24];
char word[7] = {'T', 'R', 'A', 'K', 'T', 'O', 'R'};
int tries = 0;
int lifes = 10;


char chooseWord();

void resetBoard();
void printBoard();
void checkLetter();
int checkFreeSpaces();
void printUsed();
void printResult();



int main()
{
    resetBoard();
    printBoard();

    while (checkFreeSpaces() != 0 && lifes != 0)
    {
        printf("Remaining lifes: %d\n", lifes);

        checkLetter();        
    }
    printResult();

    return 0;
}

void resetBoard()
{
    for(int i = 0; i < 7; i++)
    {
        board[i] = '_';
    }
}

void printBoard()
{
    printf("********************\n");
    for(int i = 0; i < 7; i++)
    {
        printf("%c ", board[i]);
    }
    printf("\n********************\n");

}

void checkLetter()
{
    int found = 0;        // found letter flag
    printf("Enter a letter: ");
    scanf(" %c", &playerLetter);
    playerLetter = toupper(playerLetter);
    
    usedLetters[tries] = playerLetter;
    tries++;

    for(int i = 0; i < 7; i++)
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
        printf("Remaining lifes: %d\n", lifes);
    }
    printUsed();
    
}

int checkFreeSpaces()
{
    int freeSpaces = 7;

    for(int i = 0; i < 7; i++)
    {
        if(board[i] != '_')
        {
            freeSpaces--;
        }
    }
    return freeSpaces;
}

void printUsed()
{
    printf("Used letters: ");
    for(int i = 0; i < tries; i++)
    {
        printf("%c ", usedLetters[i]);
    }
    printf("\n");
}

void printResult()
{
    if(checkFreeSpaces() == 0)
    {
        printf("YOU WON!\n");
    }
    else
    {
        printf("YOU LOST!\n");
    }
}
