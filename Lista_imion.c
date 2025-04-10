#include <stdio.h>
#include <string.h>

void printList(char list[][20], int size)
{
    for(int i = 0; i < size; i++)
        {
           printf("\t%d. %s\n", i+1, list[i]);  
        }
}

void sortList(char list[][20], int size)
{
    char temp[20];      // temporary variable
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(list[j], list [j+1]) > 0)
            {
                strcpy(temp, list[j]);
                strcpy(list[j], list[j+1]);
                strcpy(list[j+1], temp);
            }
        }
    }
}

void showUpdateList(char list[][20], int size)
{
    printf("\nAktualna lista:\n");
    printList(list, size);
}

void changeName( char list[][20], int size)
{
    if(size > 0)
    {
        char name[20];
        int found = 0;

        do {
            printf("\nKtore imie chcesz zmienic?: ");
          scanf(" %s", name);

            for(int i = 0; i < size; i++)
            {
                if(strcmp(name, list[i]) == 0)
                {
                    char newName[20];
                    printf("\nPodaj nowe imie dla %s: ", list[i]);
                    scanf(" %s", newName);

                    strcpy(list[i], newName);

                    showUpdateList(list, size);

                    found = 1;
                    break;
                } 
            }

            if(!found)
            { 
                printf("\nNie ma takiego imienia na liscie\n");
            }
        
        } while (!found);   // Powtarzaj dopoki nie znajdziesz imienia
    }
    else {
        printf("\nBrak imion na liscie\n");
    }
}

void addName(char list[][20], int *size)
{
    if (*size >= 10)
    {    
        printf("\nNie mozna wprowadzic wiecej niz 10 imion!\n");
        return;
    }

    char newName[20];
    printf("Wprowadz nowe imie: ");
    scanf(" %s", newName);

    for (int i = 0; i < *size; i++)
    {
        if(strcmp(newName, list[i]) == 0)
        {
            printf("\nNa twojej liscie juz jest takie imie\n");
            return;
        }
    }

    strcpy(list[*size], newName);
    (*size)++;

    showUpdateList(list, *size);
}

void removeName(char list[][20], int *size)
{
    if(*size > 0)
    {
        char name[20];

        printf("\nKtore imie chcesz usunac?: ");
        scanf(" %s", name);

        int found = 0;

        // Jezeli jest takie imie na liscie, przesun wszystkie powyzej o jedna pozycje do gory
        // zmniejsz size o 1
        for (int i = 0; i < *size; i++)
        {
            if(strcmp(name, list[i]) == 0)
            {
                for(int j = i; j < *size-1; j++)
                {
                    strcpy(list[j], list[j+1]);
                }
                (*size)--;
                found = 1;
            }
        }

        if(!found) 
        {
            printf("\nNie ma takiego imienia na liscie\n");
            return;
        }

        showUpdateList(list, *size);
    }
    else {
        printf("\nBrak imion na liscie\n");
    }

}

void removeList(char list[][20], int *size)
{   
    *size = 0;
    // lub w petli for
    // list[i][0] = \'0';   // ustawia pusty string
    printf("\nLista zostala wyczyszczona\n");
}

int main() 
{
    char list[10][20] = {"Anna", "Maksymilian", "Tomasz", "Mateusz", "Andrzej"};
    int size = 5;
    int operation;

    printf("\n-----Twoja baza imion-----");
    

    do {
        printf("\nJaka operacje chcesz wykonac?\n");
        printf("1 - wyswietl liste\n");
        printf("2 - dodaj imie\n");
        printf("3 - edytuj imie\n");
        printf("4 - usun imie\n");
        printf("5 - segreguj liste alfabetycznie\n");
        printf("6 - wyczysc liste\n");
        printf("0 - zakoncz program\n");
    
        printf("Wprowadz numer operacji: ");
        scanf(" %d", &operation);

        switch (operation)
        {
        case 0:
            printf("--Koniec programu--");
            return 0;
            break;
        
        case 1:
            printList(list, size);
        break;

        case 2:
            addName(list, &size);
            break;

        case 3:
            changeName(list, size);
            break;

        case 4:
            removeName(list, &size);
            break;

        case 5:
            sortList(list, size);
            showUpdateList(list, size);
            break;

        case 6:
            removeList(list, &size);
            break;

        default:
            printf("Bledny numer\n");
            break;
        }
    } while (1);

    return 0;
}