# P1 Projekt
## Kompilering af programmet 
For at kompilere programmet skal du bruge en kompiler der kan compilere ansi C. 
Vi har selv blot kompileret med 
`gcc p1-groupSorting.c'`

## Input fil
Programmet kræver at der ligger en fil med navnet "dataset" uden nogen fil extension sammen med det kompilerede program.
Filen skal have data med eleverne i, i følgene form: 

**Navn (muligvis evernavn): rolle1 rolle2 rolle3**

Bemærk at alt før ":" vil blive indført som en string i programmet, så antallet af navne gør ingen forskel.
Ydermere, hvis man kun har 2 roller erstatter man blot rolle3 med "ingenting"

## Vejledning til det kørende program
Det første programmet gør hvis et dataset er lagt med programmet, er at spørge om hvor mange elever der er i sættet, efterfulgt af hvor mange elever der max må være i hver gruppe.
Hvis det angivne antal ikke er hvad programmet kan se i filen vil der blive givet en fejlmeddelelse, og man får muligheden for at taste et nyt antal i tilfælde af at der skete en tastefejl. 
Hvis ikke programmet kommer videre så check antallet af elever i filen, samt at de står i korrekt format.

## Efter programmet har kørt
Når programmet har udregnet de bedst mulige grupper med det given dataset, vil der blive udskrevet en fil til destinationen programmet ligger i kaldet "Groups-Comple.txt".
I tilfælde af at .exe filen er kørt i windows vil vinduet også blot lukke igen.
Hvis programmet er kørt i en terminal vil man kunne se "gruppe kvaliteten" af hver gruppe, samt 3 tal der symbolisere elevernes rolle ud for dem.
