#ifdef PLAYER
#define PLAYER

#include <stdio.h>
#include "arraylist.h"
#define CAPINV 10
#define CANEST 4

typedef struct Player Player;

struct Player{
    char name[5];
    int nInv;
    int inv[CAPINV];
    int Estad[CANEST];




}


#endif