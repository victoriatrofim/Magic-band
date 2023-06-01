TROFIM VICTORIA, 313CD

- LISTA DUBLU INLANTUITA CU SANTINELA
- STIVA
- COADA

1 Descriere bandă magică

  Initial, degetul se află pe pozitia 1. El nu se poate muta mai la stânga de pozitia 1, în
schimb se poate muta cel mult cu o pozitie mai la dreapta fată de ultimul caracter existent
pe bandă. Cu alte cuvinte, considerăm că banda magică este limitată la stânga si infinită la
dreapta.
  Există mai multe operat, ii care pot fi executate. Acestea sunt împărtite în
următoarele categorii: UPDATE, QUERY, UNDO / REDO, EXECUTE. 

Operatiile de tip UPDATE permit deplasarea cu o pozit, ie pe banda (stânga / dreapta), deplasarea pana la în anumit caracter (stânga / dreapta). În cazul operat, iilor de deplasare, se
poate modifica numai pozit, ia degetului, fără a modifica cont, inutul benzii. De asemenea, în
cadrul acestor operat, ii există posibilitatea de a modifica cont, inutul benzii, prin suprascrierea
caracterului din pozit, ia degetului (fără a se modifica pozit, ia degetului). O altă operat, ie posibilă
constă în posibilitatea de a insera un caracter în stânga, respectiv dreapta pozit, iei degetului
caz în care se va realiza s, i deplasarea acestuia.

- Actualizarea caracterului curent: "WRITE <C>"
- Inserare caracter în stânga / dreapta pozit, iei degetului (implică inserare s, i deplasarea
degetului pe noua pozit, ie inserată): "INSERT_LEFT <C>", "INSERT_RIGHT <C>"
  Deplasare deget cu o pozit, ie la stânga / dreapta: "MOVE_LEFT" sau "MOVE_RIGHT"
  Deplasare dreapta / stânga până la primul caracter egal cu un anumit simbol: "MOVE_LEFT_CHAR
<C>", "MOVE_RIGHT_CHAR <C>", unde <C> este un caracter. Căutarea începe de la pozit, ia
curentă a degetului.

Operatiile de tip QUERY permit afis,area caracterului curent (din pozit, ia curentă a degetului),
respectiv afis,area cont, inutului benzii, cu marcarea pozit, iei curente pe banda.
 Pentru fiecare din operatiile UNDO / REDO se va folosi câte o stivă / comandă care va fi
implementată pornind de la o listă.
  
  Pentru a face lucrurile mai interesante, operat, iile de tip UPDATE nu se vor executa pe
măsură ce se citesc. Ele se vor adăuga într-o coadă, iar în cadrul testelor, în lista cu queryuri vor fi intercalate comenzi de tip EXECUTE. O comandă EXECUTE va lua prima operat, ie de
UPDATE disponibilă din coadă s, i o va executa. Până nu se dă EXECUTE, banda rămâne în
starea originală (”#”).
  
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
