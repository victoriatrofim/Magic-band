TROFIM VICTORIA, 313CD

- LISTA DUBLU INLANTUITA CU SANTINELA
- STIVA
- COADA
- 
1 Descriere bandă magică

Initial, degetul se află pe pozitia 1. El nu se poate muta mai la stânga de pozitia 1, în
schimb se poate muta cel mult cu o pozitie mai la dreapta fat,ă de ultimul caracter existent
pe bandă. Cu alte cuvinte, considerăm că banda magică este limitată la stânga s, i infinită la
dreapta. Uneori, poate decide să scrie alte caractere.
Deoarece are multe astfel de operatii de făcutvă roagă pe voi să îl ajutati. În vederea unei
implementări cât mai eficiente, banda va fi abstractizată ca o listă dublu înlănt,uită cu santinelă
cu elemente de tip caracter (pentru santinela informatia nu este luată în considerare).
O posibilă reprezentare pentru banda magică:
! 0 b 2 9 a # · · ·
deget
Această bandă o să fie modelată utilizând următoarea listă dublu înlănttuită cu santinelă:
! 0 b 2 9 a #
santinela nod curent
NULL NULL
Pentru a evidentia simbolul marcat de degetla afisare, acesta va fi precedat s, i succedat
de caracterul | (bară verticală). Spre exemplu, pentru exemplul anterior vom avea următoarea
afis,are: !0b|2|9a#
Banda are initial un singur caracter pe ea, caracterul #, dar are proprietatea că se poate
extinde la dreapta oricât de mult (la stânga nu se poate extinde).
1
Observatie
Caracterele # si | nu se vor folosi niciodată în testele efectuate. Caracterul # este folosit
doar pentru a indica o pozitie alocată din banda, iar caracterul | este utilizat pentru a
marca, în afisare, simbolul pe care este pozitionat degetul.
Pentru a întelege mai bine cum se poate prelucra continutul acestei benzi magice, David vă
propune următorul exemplu:
1. Pornim de la continutul initial al benzii.
# · · ·
deget
#
santinela nod curent
NULL NULL
2. David alege să îsi mute cu o pozitie mai la dreapta degetul.
# # · · ·
deget
# #
santinel˘a nod curent
NULL NULL
3. David alege să scrie caracterul !
# ! · · ·
deget
# !
santinel˘a nod curent
NULL NULL
2 Prezentare operatii posibile
Există mai multe operatii care pot fi executate de către David. Acestea sunt împărtite în
următoarele categorii: UPDATE, QUERY, UNDO / REDO, EXECUTE. În continuare, vom
prezenta fiecare categorie în parte, specificând pentru fiecare ce particularităti prezintă si care
sunt operaiile incluse.
2
2.1 Operatii de tip UPDATE
Operatiile de tip UPDATE permit deplasarea cu o pozitie pe banda (stânga / dreapta), deplasarea pana la în anumit caracter (stânga / dreapta). În cazul operatiilor de deplasare, se
poate modifica numai pozitia degetului, fără a modifica continutul benzii. De asemenea, în
cadrul acestor operatii există posibilitatea de a modifica continutul benzii, prin suprascrierea
caracterului din pozitia degetului (fără a se modifica pozitia degetului). O altă operatie posibilă
constă în posibilitatea de a insera un caracter în stânga, respectiv dreapta pozitiei degetului
caz în care se va realiza si deplasarea acestuia.
Observatie
Este important de remarcat faptul că aceste operatii nu sunt executate direct. Atunci
când întâlnim o astfel de comandă doar o adaugăm într-o coadă.
Operatiile posibile de tip UPDATE sunt:
• Deplasare deget cu o pozitie la stânga / dreapta: "MOVE_LEFT" sau "MOVE_RIGHT". Dacă
ne aflăm la prima pozi ie s, i întâlnim operatia "MOVE_LEFT" nu se întâmplă nimic, dar
dacă ne aflăm la ultima pozitie s, i întâlnim "MOVE_RIGHT" mutăm degetul cu o pozitie mai
la dreapta, iar în celula respectivă scriem caracterul #
• Deplasare dreapta / stânga până la primul caracter egal cu un anumit simbol: "MOVE_LEFT_CHAR
<C>", "MOVE_RIGHT_CHAR <C>", unde <C> este un caracter. Căutarea începe de la pozitia
curentă a degetului.
– În cazul operatiei "MOVE_LEFT_CHAR <C>" – dacă se ajunge în marginea din stânga
a benzii s, i nu s-a găsit caracterul căutatse va afis,a ERROR iar pozitia degetului nu
se modifică.
– În cazul operatiei "MOVE_RIGHT_CHAR <C>" – dacă se ajunge la limita din dreapta a
benzii care contine caractere s, i nu s-a găsit caracterul căutatse inserează # la final
s, i poziia degetului va fi pe #-ul inserat.
• Actualizarea caracterului curent: "WRITE <C>"
• Inserare caracter în stânga / dreapta pozitiei degetului (implică inserare s, i deplasarea
degetului pe noua pozitie inserată): "INSERT_LEFT <C>", "INSERT_RIGHT <C>". Dacă
degetul se află pe prima pozi ie, nu se poate insera la stânga – se afis,ează mesajul ERROR,
banda ramâne nemodificată s, i pozitia degetului rămâne nemis,cată.
2.2 Operatii de tip QUERY
Operatiile de tip QUERY permit afis,area caracterului curent (din pozitia curentă a degetului),
respectiv afis,area continutului benzii, cu marcarea pozitiei curente pe banda.
Observatie
Aceste operatii sunt executate direct atunci când sunt întâlnite.
• Determinare caracter din pozitia degetului: "SHOW_CURRENT"
• Afis,are continut bandă: "SHOW". Caracterul pe care se află degetul va fi pus între |. De
exemplu, abc|d|e semnifică faptul că degetul se află pe caracterul d.
3
2.3 Operatii de tip UNDO / REDO
Important
Pentru fiecare din operatiile UNDO / REDO se va folosi câte o stivă / comandă care va fi
implementată pornind de la o listă.
Operatiile de tip UNDO / REDO permit anularea ultimei operatii aplicate, respectiv refacerea ultimei operatii aplicate.
Observatie
Aceste operatii sunt executate direct atunci când sunt întâlnite s, i ele nu modifică în vreun
fel continutul benzii. Cu alte cuvinte, acestea vor modifica doar pozitia degetului. De
aceea, este suficient să retinem în stivele pentru cele două operatii doar un pointer la
pozitia curentă.
Dacă este executată comanda MOVE_RIGHT s, i în urma executiei se adăugă simbolul # la
finalul benzii, atunci când vom apela comanda UNDO vom schimba doar pozitia degetului,
fără a elimina simbolul inserat la final.
Se garantează că operatiile de UNDO s, i de REDO se vor da doar pentru operatiile de "MOVE_LEFT",
"MOVE_RIGHT" , nu vor fi pentru operatii de "WRITE <C>" s, i "INSERT_LEFT <C>", "INSERT_RIGHT
<C>" - nu trebuie făcute verificări suplimentare pentru a verifica acest lucru (se garantează că
operatiile de UNDO s, i de REDO nu vor modifica banda).
Observatie
Atunci când executăm operatia UNDO, extragem pointerul retinut în vârful stivei pentru
UNDO, adăugăm acest pointer pointerul la pozitia curentă a degetului în vârful stivei
pentru REDO, după care modificăm pozitia degetului astfel încât să indice către pointerul
extras din stiva pentru UNDO.
Atunci când executăm operatia REDO, extragem pointerul retinut în vârful stivei pentru
REDO, adăugăm acest pointer pointerul la pozitia curentă a degetului în vârful stivei
pentru UNDO, după care modificăm pozitia degetului astfel încât să indice către pointerul
extras din stiva pentru REDO.
După o operatie de WRITE stivele de UNDO / REDO e util să fie golite, pentru că se garantează
că nu se vor da operatii de UNDO / REDO peste cele de WRITE.
2.4 Operatia EXECUTE
Important
Pentru comanda EXECUTE se va folosi o coadă implementată pornind de la o listă.
Pentru a face lucrurile mai interesante, operatiile de tip UPDATE nu se vor executa pe
măsură ce se citesc. Ele se vor adăuga într-o coadă, iar în cadrul testelor, în lista cu queryuri vor fi intercalate comenzi de tip EXECUTE. O comandă EXECUTE va lua prima operatie de
UPDATE disponibilă din coadă s, i o va executa. Până nu se dă EXECUTE, banda rămâne în
starea originală (”#”).
4
Observatie
Dacă operatia curentă care urmează să fie executată este una dintre MOVE_LEFT,
MOVE_RIGHT, MOVE_LEFT_CHAR sau MOVE_RIGHT_CHAR, se va retine pointerul la nodul
curent din listă, se va încerca aplicarea operatiei, iar dacă aceasta este realizată cu succes, atunci pointerul retinut anterior este adăugat în stiva pentru UNDO.  

  
IMPLEMENTARE :

Pentru inceput am scris toate structurile necesare pentru coada, stiva si lista dublu inlantuita precum si pentru nodurile acestora, dar si structurile de creare a acestora
Urmeaza functiile pentru indeplinirea comenzile: avem cate o functie pentru mutare la dreapta/stanga in care pornind de la finger= pozitia curenta ne mutam cu o pozitie mai la dreapta formand un nod nou la necesitate
sau ne mutam mai la stanga(daca nu suntem pe primul element desigur)
Aici sunt prezente si unele implementari ale lui UNDO si REDO, pe care le am utilizat sub foarma de stive
Avem la dispozitie si o coada in care memoram toate comenzile pe care va trebui sa le executam re rand excluzandu-le pe cele ce le facem instant precum show, show_current, undo, redo
functia show afiseaza continutul listei iar la momentul in care intalneste finger, il arata intre | | asa cum este mentionat in cerinta
funtiile de inserare la stanga sau la dreapta le am facut cu creare de nod nou, iar valoarea (litera/semnul) pe care il inseram il citim separat fiind second element
functiile de move left/right char muta degetul curent pana la valoarea <C> mentionata, pentru asta avem un iterator care cauta prin toate elementele listei in directia mentionata pana gaseste elementul cautat
Functiile redo/undo sunt 2 stive care la momentul in care se executa o mutare la stanga sau dreapta, memoreaza creand un nod nou in stiva, iar pentru a extrage mai usor ultimul element facem head-ul sa fie mereu ultimul element adaugat
functia execute este cea mai principala si pune in actiune comenzile care nu sunt facute instant, pentru implementare am utilizat if...else si strcmp pentru a determina pentru ce comanda care este actiunea potrivita, iar degetul memoreaza pozitia la care trebuie sa se mute dupa fiecare comanda executata
citirea se face din fisier si se trimite in tema1.out
la final eliberez memoria alocata cu free()
