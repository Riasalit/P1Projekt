# Gruppedannelse i gymnasiet
## Kompilering af programmet 
For at kompilere programmet skal du bruge en kompiler der kan kompilere ANSI C89. <br />
Vi har selv blot kompileret med GNU's Compiler Collection (GCC). Derfor kompileret med koden: `gcc p1-groupSorting.c`

## Input fil
Programmet kræver at der ligger en fil med navnet "dataset" uden nogen fil extension sammen med det kompilerede program.
Filen skal have data med eleverne i, i følgende form: 

**Navn (muligvis evernavn): rolle1 rolle2 rolle3**

Bemærk at alt før ":" vil blive indført som en string i programmet, så antallet af navne gør ingen forskel.<br />
(OBS: alt efter de første 30 chars bliver tabt)

Rollerne er:
* ideskaber
* specialist
* analysator
* organisator
* opstarter
* afslutter
* formidler
* koordinator
* kontaktskaber 

hvis man kun har 2 roller erstatter man blot rolle3 med "ingenting"
#### BEMÆRK!!! 
**Alle roller skal være stavet PRÆCIS som skrevet ovenover, og rollerne SKAL starte med små bogstaver.**

## Vejledning til det kørende program
Det første programmet gør hvis et dataset er lagt med programmet, er at spørge om hvor mange elever der er i sættet, efterfulgt af hvor mange elever der max må være i hver gruppe (helst mellem 4-6, da dette er størrelsen på grupper foreslået af Belbin).
Hvis det angivne antal ikke er hvad programmet kan se i filen vil der blive givet en fejlmeddelelse, og man får muligheden for at taste et nyt antal i tilfælde af at der skete en tastefejl. 
Hvis ikke programmet kommer videre så tjek antallet af elever i filen, samt at de står i korrekt format.

## Efter programmet har kørt
Når programmet har udregnet de bedst mulige grupper med det givne dataset, vil der blive udskrevet en fil til destinationen programmet ligger i kaldet "Groups-Complete.txt".
I tilfælde af at .exe filen er kørt i Windows vil vinduet blot lukke igen.
Hvis programmet er kørt i en terminal vil man kunne se "gruppe kvaliteten" af hver gruppe, samt 3 tal der symboliserer elevernes rolle ud for dem.

## Test af program
De 3 tests der er lavet i rapporten omkring programmet, er lavet med de 3 datasæt fra dette repository under samme navne (for at ændre hvilket dataset der bruges, skal for eksempel "dataset2" blot navngives "dataset"). For at få de resultater er programmet kørt med de angivne dataset, og gruppestørelsen er sat til 4. 
Resultaterne er ikke garenteret at blive præcis det samme. Gruppekvaliteten bør dog altid blive det samme. Men rækkefølgen eleverne bliver sat i grupper er tilfældig, så hvis 2 elever kan byttes om på uden at antallet af grupper med samme antal roller ændres kan eleverne sidde i forskellige grupper. Men hvis der var 2 grupper med 8 unikke roller i den ene og 7 unikke roller i den anden, er der stadig en gruppe med 8 og en anden med 7.
