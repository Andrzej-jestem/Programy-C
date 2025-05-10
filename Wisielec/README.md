# 🎮 Wisielec – gra tekstowa w języku C

Prosty terminalowy odpowiednik klasycznej gry *Wisielec*. Gracz ma za zadanie odgadnąć losowo wybrane słowo, podając litery – każda błędna próba zbliża go do przegranej. Projekt zrealizowany w ramach nauki języka C.

## 🔧 Technologie

- C
- Kompilator: GCC
- Środowisko: Linux terminal / Git Bash / VS Code

## ⚙️ Funkcje

- Losowanie słowa z pliku tekstowego (hasla.txt)
- Interaktywne wprowadzanie liter
- Zabezpieczenie przed ponownym wpisaniem tej samej litery
- Graficzna reprezentacja liczby błędów (tekstowa)
- Komunikaty o zwycięstwie lub porażce

## 🚀 Uruchomienie

1. Upewnij się, że plik hasla.txt znajduje się w tym samym katalogu co plik .c i zawiera słowa (po jednym w linii).
2. Skompiluj program:
   ```bash
   gcc wisielec.c -o wisielec

3. Uruchom grę:
./wisielec


📌 Cele projektu
Ćwiczenie pracy z plikami i tablicami znaków
Zarządzanie danymi wejściowymi użytkownika
Tworzenie prostych gier tekstowych


✅ Możliwości rozbudowy
Obsługa polskich znaków
Interfejs graficzny
Licznik rozegranych gier i statystyki gracza


📄 Licencja
Projekt realizowany w celach edukacyjnych – bez ograniczeń licencyjnych.
