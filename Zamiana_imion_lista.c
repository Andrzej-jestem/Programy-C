#include <stdio.h>
#include <string.h>

void printArray(char list[][20], int size)
{
    for(int i = 0; i < size; i++)
        {
           printf("%s\n", list[i]);  
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
    printArray(list, size);
}

void startView(char list[][20], int size)
{
    char name[20];
    int found = 0;

    printf("---Lista osob--- \n");
    printArray(list, size);

    do {
        printf("Ktore imie chcesz zmienic?: ");
        scanf(" %s", name);

        for(int i = 0; i < size; i++)
        {
            if(strcmp(name, list[i]) == 0)
            {
                char newName[20];
                printf("Podaj nowe imie dla %s: ", list[i]);
                scanf(" %s", newName);

                strcpy(list[i], newName);

                printf("\nAktualna lista:\n");
                printArray(list, size);

                found = 1;
                break;
            } 
        }

        if(!found)
        { 
            printf("Nie ma takiego imienia na liscie\n");
        }
        
    } while (!found);   // Powtarzaj dopoki nie znajdziesz imienia

}

int main() 
{
    char list[5][20] = {"Anna", "Maksymilian", "Tomasz", "Mateusz", "Andrzej"};
    int size = sizeof(list) / sizeof(list[0]);
    char choice;

    startView(list, size);

    printf("Chcesz posegregowac liste alfabetycznie? (T/N): ");
    scanf(" %c", &choice);

    if(choice == 't' || choice == 'T')
    {
        sortList(list, size);
    }


    return 0;
}