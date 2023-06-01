TROFIM VICTORIA, 313CD


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