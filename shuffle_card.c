#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void shuffle_card(int* card) {
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--) {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}

void cards_matrix(int cards[4][11]) {
    int card[44];
    shuffle_card(card);
    int i = 0;
    int a;
    int b;
    // taghsim 5 taee cart ha (dor aval)
    for (a = 0; a<4; a++){
        for (b = 0; b<5; b++){
            cards[a][b] = card[i];
            i ++;
        }
    }
    // taghsim 4 taee cart ha (dor dovom)
    for (a = 0; a<4; a++){
        for (b = 7; b<11; b++){
            cards[a][b] = card[i];
            i ++;
        }
    }
    // taghsim 2 taee cart ha (dor sevom)
    for (a = 0; a<4; a++){
        for (b = 5; b<7; b++){
            cards[a][b] = card[i];
            i ++;
        }
    }
}
