#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CoadaNod{
    char *elem;
    char secondElem;
    struct CoadaNod *next;
}CoadaNod;

typedef struct Coada{
    CoadaNod *primul;
    CoadaNod *ultimul;
    long size;
} Coada;

Coada *CreareCoada(void) {
    Coada *coada = (Coada*)malloc(sizeof(Coada));
    coada->primul = coada->ultimul = NULL;
    coada->size = 0;
    return coada;
}
CoadaNod *CreareCoadaNod(char *elem) {
    CoadaNod *coadaNod = (CoadaNod*)malloc(sizeof(CoadaNod));
    coadaNod->elem = elem;
    coadaNod->elem = malloc(20);
    strcpy(coadaNod->elem, elem);
    coadaNod->next = NULL;
    return coadaNod;
}


typedef struct ListNod{
    char elem;
    struct ListNod *next;
    struct ListNod *prev;
}ListNod;

typedef struct Lista{
    ListNod *primul;
    ListNod *ultimul;
} Lista;

ListNod *CreareNod(char elem){
    ListNod *NewNod = (ListNod*)malloc(sizeof(ListNod));
    NewNod->elem = elem;
    NewNod->next = NewNod->prev = NULL;
    return NewNod;
}

typedef struct StackNode{
    ListNod *elem;
    struct StackNode *next;
}StackNode;

typedef struct Stack{
    StackNode *head;
    long size;
} Stack;

StackNode *CreareStackNod(ListNod *elem) {
    StackNode *newNod = (StackNode*)malloc(sizeof(StackNode));
    newNod->elem = elem;
    newNod->next = NULL;
    return newNod;
}

Stack *CreareStack(void) {
    Stack *stiva = (Stack*)malloc(sizeof(Stack));
    stiva->head = NULL;
    stiva->size = 0;
    return stiva;
}

void AfisBanda(ListNod *santinela) {
    ListNod *node = santinela;
    while (node->next != NULL) {
        printf("%c", node->elem);
        node = node->next;
    }
    printf("%c\n", node->elem);
}

ListNod *MoveRight(ListNod *finger, Stack *UNDO) {
    if (finger->next == NULL) {
        ListNod *newNode = CreareNod('#');
        newNode->prev = finger;
        finger->next = newNode;
    }
    if (UNDO->size == 0) {
            UNDO->head = CreareStackNod(finger);
            UNDO->head->next = NULL;
            UNDO->size++;
    } else {
        StackNode *newStackNode = CreareStackNod(finger);
        newStackNode->next = UNDO->head;
        UNDO->head = newStackNode;
        UNDO->size++;
    }
    finger = finger->next;
    return finger;
}

ListNod *MoveLeft(ListNod *finger, Lista *mylist, Stack *UNDO) {
    if (mylist->primul->next != finger) {
        if (UNDO->size == 0) {
            UNDO->head = CreareStackNod(finger);
            UNDO->head->next = NULL;
            UNDO->size++;
        } else {
            StackNode *newStackNode = CreareStackNod(finger);
            newStackNode->next = UNDO->head;
            UNDO->head = newStackNode;
            UNDO->size++;
        }
        finger = finger->prev;
    }

    return finger;
}

void Show(Lista *mylist, ListNod *finger, FILE *output) {
    ListNod *iter = mylist->primul->next;
    while (iter != NULL) {
        if (iter == finger) {
            fprintf(output, "|%c|", iter->elem);
        } else {
            fprintf(output, "%c", iter->elem);
        }
        iter = iter->next;
    }
    fprintf(output, "\n");
}

ListNod *InsertRight(ListNod *finger, CoadaNod *coadaNod) {
    ListNod *NewNode = CreareNod(coadaNod->secondElem);
    if (finger->next != NULL) {
        NewNode->next = finger->next;
        NewNode->prev = finger;
        finger->next->prev = NewNode;
        finger->next = NewNode;
        finger = NewNode;
    } else {
        NewNode->prev = finger;
        finger->next = NewNode;
        finger = NewNode;
    }
    return finger;
}

ListNod *InsertLeft(Lista *mylist, ListNod *finger, CoadaNod *coadaNod, FILE *output) {
    ListNod *NewNode = CreareNod(coadaNod->secondElem);
    if (finger->prev != mylist->primul) {
        NewNode->prev = finger->prev;
        NewNode->next = finger;
        finger->prev->next = NewNode;
        finger->prev = NewNode;
        finger = NewNode;
    } else {
        fprintf(output, "ERROR\n");
    }
    return finger;
}

ListNod *MoveLeftChar(Lista *mylist, ListNod *finger, CoadaNod *coadaNod, FILE *output) {
    ListNod *iter = finger;
    int ok = 0;
    while (iter != mylist->primul) {
        if (iter->elem == coadaNod->secondElem) {
            finger = iter;
            ok = 1;
            break;
        }
        iter = iter->prev;
    }
    if (ok == 0) {
        fprintf(output, "ERROR\n");
    }
    return finger;
}

ListNod *MoveRightChar(Lista *mylist, ListNod *finger, CoadaNod *coadaNod) {
    ListNod *iter = finger;
    int ok = 0;
    while (iter->next != NULL) {
        if (iter->elem == coadaNod->secondElem) {
            finger = iter;
            ok = 1;
            break;
        }
        iter = iter->next;
    }
    if (iter->elem == coadaNod->secondElem) {
            finger = iter;
            ok = 1;
        }
    if (ok == 0) {
        ListNod *newNod = CreareNod('#');
        newNod->prev = iter;
        iter->next = newNod;
        finger = newNod;
    }
    return finger;
}

ListNod *Undo(ListNod *finger, Stack *UNDO, Stack *REDO) {
    
    if (REDO->size == 0) {
        REDO->head = CreareStackNod(finger);
        REDO->head->next = NULL;
        REDO->size++;
    } else {
        StackNode *newStackNode = CreareStackNod(finger);
        newStackNode->next = REDO->head;
        REDO->head = newStackNode;
        REDO->size++;
    }
    finger = UNDO->head->elem;
    StackNode *temp = UNDO->head;
    UNDO->head = UNDO->head->next;
    UNDO->size--;
    free(temp);
    return finger;
}

ListNod *Redo(ListNod *finger, Stack *UNDO, Stack *REDO) {
    printf("am intrat pe redo\n");
    if (UNDO->size == 0) {
        UNDO->head = CreareStackNod(finger);
        UNDO->head->next = NULL;
        UNDO->size++;
    } else {
        StackNode *newStackNode = CreareStackNod(finger);
        newStackNode->next = UNDO->head;
        UNDO->head = newStackNode;
        UNDO->size++;
    }
    finger = REDO->head->elem;
    StackNode *temp = REDO->head;
    REDO->head = REDO->head->next;
    REDO->size--;
    free(temp);
    return finger;
}


ListNod *Execute(Stack *UNDO, Stack *REDO, ListNod *finger, Coada *coada, Lista *mylist, FILE *output) {
    if (strcmp(coada->primul->elem, "MOVE_RIGHT") == 0) {
        finger = MoveRight(finger, UNDO);
    } else {
        if (strcmp(coada->primul->elem, "MOVE_LEFT") == 0) {
            finger = MoveLeft(finger, mylist, UNDO);
        } else {
            if (strcmp(coada->primul->elem, "WRITE") == 0) {
                finger->elem = coada->primul->secondElem;
            } else {
                if (strcmp(coada->primul->elem, "INSERT_RIGHT") == 0) {
                    finger = InsertRight(finger, coada->primul);
                } else {
                    if (strcmp(coada->primul->elem, "INSERT_LEFT") == 0) {
                        finger = InsertLeft(mylist, finger, coada->primul, output);
                    } else {
                        if (strcmp(coada->primul->elem, "MOVE_LEFT_CHAR") == 0) {
                            finger = MoveLeftChar(mylist, finger, coada->primul, output);
                        } else {
                            if (strcmp(coada->primul->elem, "MOVE_RIGHT_CHAR") == 0) {
                                finger = MoveRightChar(mylist, finger, coada->primul);
                            }
                        }
                    }
                }
            }
        }
    }
    CoadaNod *temp = coada->primul;
    coada->primul = coada->primul->next;
    free(temp);
    coada->size--;
    return finger;
}

void FreeStack(Stack *stak) {

}

int main() {
    char secondElem;
    FILE *file = fopen("tema1.in", "r");
    FILE *output = fopen("tema1.out", "w");
    int nr = 0;
    fscanf(file, "%d", &nr);
    char *command = malloc(20);

    Lista *mylist = (Lista*)malloc(sizeof(Lista));
    Stack *UNDO = (Stack*)malloc(sizeof(Stack));
    Stack *REDO = (Stack*)malloc(sizeof(Stack));
    ListNod *santinela = CreareNod('\0');
    ListNod *init = CreareNod('#');
    mylist->primul = santinela;
    mylist->ultimul = init;
// legaturi santinela-primul nod '#'
    santinela->prev = NULL;
    santinela->next = init;
    init->prev = santinela;
    init->next = NULL;
    
    ListNod *finger = init;
    Coada *coada = CreareCoada();
    CoadaNod *coadaNod = NULL;
    CoadaNod *lastNode = NULL;

    fscanf(file, "%s", command);
    if (strcmp(command, "SHOW") == 0) {
        ListNod *iter = mylist->primul->next;
        while (iter != NULL) {
            if (iter->elem == finger->elem) {
                fprintf(output, "|%c|", iter->elem);
            } else {
                fprintf(output, "%c", iter->elem);
            }
            iter = iter->next;
        }
        fscanf(file, "%s", command);
        fprintf(output, "\n");
        nr--;
    }
    coada->primul = CreareCoadaNod(command);
    coada->ultimul = coada->primul;
    coada->size++;
    if (strncmp(command, "WRITE", 5) == 0 
        || strncmp(command, "INSERT", 6) == 0 
        || strncmp(command, "MOVE_RIGHT_CHAR", 15) == 0
        || strncmp(command, "MOVE_LEFT_CHAR", 14) == 0) {
        fscanf(file, " %c", &secondElem);
        coada->primul->secondElem = secondElem;
    }
    lastNode = coada->primul;

    for (int i = 0; i < nr - 1; i++) {
        fscanf(file, "%s", command);
        if (strcmp(command, "EXECUTE") != 0 
            && strcmp(command, "SHOW") != 0 
            && strcmp(command, "SHOW_CURRENT") != 0
            && strcmp(command, "UNDO") != 0) {
            coadaNod = CreareCoadaNod(command);
            if (coada->size == 0) {
                coada->primul = coadaNod;
                coada->ultimul = coada->primul;
            }
            coada->size++;
            lastNode->next = coadaNod;
            lastNode = lastNode->next;
            if (strncmp(command, "WRITE", 5) == 0 
                || strncmp(command, "INSERT", 6) == 0 
                || strncmp(command, "MOVE_RIGHT_CHAR", 15) == 0
                || strncmp(command, "MOVE_LEFT_CHAR", 14) == 0) {
                fscanf(file, " %c", &secondElem);
                coadaNod->secondElem = secondElem;
            }
            coada->ultimul = coadaNod;
            coadaNod = coadaNod->next;
        } else {
            if (strcmp(command, "SHOW") == 0) {
                Show(mylist, finger, output);
            } else {
                if (strcmp(command, "SHOW_CURRENT") == 0) {
                    fprintf(output, "%c\n", finger->elem);
                } else {
                    if (strcmp(command, "UNDO") == 0) {
                        finger = Undo(finger, UNDO, REDO);
                    } else {
                        if (strcmp(command, "REDO") == 0) {
                            finger = Redo(finger, UNDO, REDO);
                        } else {
                            finger = Execute(UNDO, REDO, finger, coada, mylist, output);
                        }
                    }
                }
            }
        }
    }

    fclose(file);
    fclose(output);
    free(command);
    free(UNDO);
    free(REDO);
    free(coada);
    ListNod *iter = mylist->primul->next;
    while (iter != NULL) {
        ListNod *temp = iter;
        iter = iter->next;
        free(temp);
    }
    free(mylist->primul);
    free(mylist);
}

    
    


