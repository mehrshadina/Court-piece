#include <stdio.h>
#include <stdlib.h>
#include "shuffle_card.c"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// menue for firs_first time
void menue0(int team1, int team2) {
    printf(
        "                             P3                     \n"
        "        ---------------------------------------------    Team1: %d\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "      P2|                                           |P4\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        |                                           |\n"
        "        ---------------------------------------------    Team2: %d\n"
        "                              P1                     \n",team1,team2
    );
}
// menue function
void menue(
        char* p1_char, char* p2_char,
        char* p3_char, char* p4_char,
        int p1_num, int p2_num,
        int p3_num, int p4_num,
        int team1,
        int team2,
        int player
    ) { //8+21-21
    if (player == 1){
        //printf("1\n");
        printf(
            "                             P3                     \n"
            "        ---------------------------------------------    Team1: %d\n"
            "        |                    %s%d                     |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "      P2|%s%d                                       %s%d|P4\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                     %s%d                    |\n"
            "        ---------------------------------------------    Team2: %d\n"
            "                              P1                     \n",team1,p3_char,p3_num,p2_char,p2_num,p4_char,p4_num,p1_char,p1_num,team2
        );
    } else if (player == 2){
        //printf("2 here ?\n");
        printf(
            "                             P3                     \n"
            "        ---------------------------------------------    Team1: %d\n"
            "        |                    %s%d                     |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "      P2|%s%d                                       %s%d|P4\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        ---------------------------------------------    Team2: %d\n"
            "                              P1                     \n",team1,p3_char,p3_num,p2_char,p2_num,p4_char,p4_num,team2
        );
    } else if (player == 3){
        //printf("3 here ?\n");
        printf(
            "                             P3                     \n"
            "        ---------------------------------------------    Team1: %d\n"
            "        |                    %s%d                     |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "      P2|                                         %s%d|P4\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        ---------------------------------------------    Team2: %d\n"
            "                              P1                     \n",team1,p3_char,p3_num,p4_char,p4_num,team2
        );
    } else {
        //printf("4 here ?\n");
        printf(
            "                             P3                     \n"
            "        ---------------------------------------------    Team1: %d\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "      P2|                                         %s%d|P4\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        |                                           |\n"
            "        ---------------------------------------------    Team2: %d\n"
            "                              P1                     \n",team1,p4_char,p4_num,team2
        );
    }

}

void num_to_str(int array[], char* cards_alphabet[11], int cards_numbers[11]){
    int x;
    for (x=0; x<11; x++) {
        int charr = array[x] / 11;
        char* character;
        if (charr == 0){
            character = "A";
        } else if (charr == 1) {
            character = "B";
        } else if (charr == 2){
            character = "C";
        } else if (charr == 3){
            character = "D";
        }
        cards_alphabet[x] = character;
    }
    int y;
    for (y=0; y<11; y++) {
        cards_numbers[y] = array[y] % 11;
    }
}

void creat_hand(char* cards_alphabet[11], int cards_numbers[11], bool first_time){
    if (first_time == true){
        printf (
            "       ---------------------\n"
            "symbol | %s | %s | %s | %s | %s |\n"
            "       ---------------------\n"
            "symbol | %i | %i | %i | %i | %i |\n"
            "       ---------------------\n"
            "       | 0 | 1 | 2 | 3 | 4 |\n"
            "       ---------------------\n",cards_alphabet[0],cards_alphabet[1],cards_alphabet[2],cards_alphabet[3],cards_alphabet[4],cards_numbers[0],cards_numbers[1],cards_numbers[2],cards_numbers[3],cards_numbers[4]
        );
    } else {
        printf (
            "       -----------------------------------------------\n"
            "symbol | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n"
            "       -----------------------------------------------\n"
            "symbol | %i | %i | %i | %i | %i | %i | %i | %i | %i | %i | %i |\n"
            "       -----------------------------------------------\n"
            "       | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |\n"
            "       -----------------------------------------------\n",cards_alphabet[0],cards_alphabet[1],cards_alphabet[2],cards_alphabet[3],cards_alphabet[4],cards_alphabet[5],cards_alphabet[6],cards_alphabet[7],cards_alphabet[8],cards_alphabet[9],cards_alphabet[10],cards_numbers[0],cards_numbers[1],cards_numbers[2],cards_numbers[3],cards_numbers[4],cards_numbers[5],cards_numbers[6],cards_numbers[7],cards_numbers[8],cards_numbers[9],cards_numbers[10]
        );
    }
}

void round1(
    int shomare_bakhshname,
    char* char_bakhshname,
    char* cards_alphabet_p1[11], int cards_numbers_p1[11],
    char* cards_alphabet_p2[11], int cards_numbers_p2[11],
    char* cards_alphabet_p3[11], int cards_numbers_p3[11],
    char* cards_alphabet_p4[11], int cards_numbers_p4[11],
    int team1, int team2
){
    sleep(5);
    system("clear");

    int q;
    for (q=0; q<11; q++){
        printf("%s%d ",cards_alphabet_p1[q],cards_numbers_p1[q]);
    };
    printf("\n");
    for (q=0; q<11; q++){
        printf("%s%d ",cards_alphabet_p2[q],cards_numbers_p2[q]);
    };
    printf("\n");
    for (q=0; q<11; q++){
        printf("%s%d ",cards_alphabet_p3[q],cards_numbers_p3[q]);
    };
    printf("\n");
    for (q=0; q<11; q++){
        printf("%s%d ",cards_alphabet_p4[q],cards_numbers_p4[q]);
    };
    printf("\n");

    menue0(0, 0);
    creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
    printf("Wich card do you want to play? ");

    int p1_select;
    scanf("%d", &p1_select);
    printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
    printf("Wait 5 seconds\n");
    sleep(5);
    team1 += cards_numbers_p1[p1_select];


    // p2_play
    int x;
    int p2_select;
    int biggest_num_p2 = 0;
    int smallest_num_p2 = 45;
    bool there_is_p2 = false;
    for (x=0; x<11; x++) {
        // check p1_card_character is in cards_alphabet_p2
        if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
            there_is_p2 = true;
            //finding biggest number
            if (cards_numbers_p2[x] > biggest_num_p2){
                biggest_num_p2 = cards_numbers_p2[x];
                p2_select = x;
            }
        }
    }
    if (there_is_p2 == false) {
        //check ((bakhshname)) is in cards_numbers_p2
        bool there_is_p2_1 = false;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] == char_bakhshname) {
                there_is_p2_1 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // finding smallest number in cards
        if (there_is_p2_1 == false) {
            for (x=0; x<11; x++) {
                if (cards_numbers_p2[x] < smallest_num_p2){
                    smallest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
    }
    if (biggest_num_p2 != 0) {
        team2 += biggest_num_p2;
    } else {
        team2 += smallest_num_p2;
    }


    // p3_play
    int y;
    int p3_select;
    int biggest_num_p3 = 0;
    int smallest_num_p3 = 45;
    bool there_is_p3 = false;
    for (y=0; y<11; y++) {
        // check p1_card_character is in cards_alphabet_p2
        if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
            there_is_p3 = true;
            //finding biggest number
            if (cards_numbers_p3[y] > biggest_num_p3){
                biggest_num_p3 = cards_numbers_p3[y];
                p3_select = y;
            }
        }
    }
    if (there_is_p3 == false) {
        //check ((bakhshname)) is in cards_numbers_p2
        bool there_is_p3_1 = false;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] == char_bakhshname) {
                there_is_p3_1 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // finding smallest number in cards
        if (there_is_p3_1 == false) {
            for (y=0; y<11; y++) {
                if (cards_numbers_p3[y] < smallest_num_p3){
                    smallest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
    }
    if (biggest_num_p3 != 0){
        team1 += biggest_num_p3;
    } else {
        team1 += smallest_num_p3;
    }


    // p4_play
    int z;
    int p4_select;
    int biggest_num_p4 = 0;
    int smallest_num_p4 = 45;
    bool there_is = false;
    for (z=0; z<11; z++) {
        // check p1_card_character is in cards_alphabet_p2
        if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
            there_is = true;
            //finding biggest number
            if (cards_numbers_p4[z] > biggest_num_p4){
                biggest_num_p4 = cards_numbers_p4[z];
                p4_select = z;
            }
        }
    }
    if (there_is == false) {
        //check ((bakhshname)) is in cards_numbers_p2
        bool there_is_1 = false;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] == char_bakhshname) {
                there_is_1 = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }

        }
        // finding smallest number in cards
        if (there_is_1 == false) {
            for (z=0; z<11; z++) {
                if (cards_numbers_p4[z] < smallest_num_p4){
                    smallest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
    }

    if (biggest_num_p4 != 0){
        team2 += biggest_num_p4;
    } else {
        team2 += smallest_num_p4;
    }
    //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


    //its time to update game board
    //har bazikon yek card entekhab karde ast vaght update terminal hast

    system("clear");
    if (team1 > team2){
        team1 = 1;
        team2 = 0;
    } else {
        team1 = 0;
        team2 = 1;
    }
    menue(
        cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
        cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
        cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
        cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
        team1 ,team2, 1
    );
    cards_alphabet_p1[p1_select] = "-";
    cards_alphabet_p2[p2_select] = "-";
    cards_alphabet_p3[p3_select] = "-";
    cards_alphabet_p4[p4_select] = "-";
    cards_numbers_p1[p1_select] = 0;
    cards_numbers_p2[p2_select] = 0;
    cards_numbers_p3[p3_select] = 0;
    cards_numbers_p4[p4_select] = 0;
    creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
    char* next_player;
    if (team1 > team2){
        printf("Team 1 won this round\n");
        //if card was bakhshname
        if(cards_alphabet_p1[p1_select] == char_bakhshname) {
            if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            } else {
                next_player = "p1";
            }
        // if card wasn't bakhshname
    } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
            next_player = "p3";
        } else {
            if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                next_player = "p1";
            } else {
                next_player = "p3";
            }
        }
    } else {
        printf("Team 2 won this round\n");
        if(cards_alphabet_p2[p2_select] == char_bakhshname) {
            if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            } else {
                next_player = "p2";
            }
        // if card wasn't bakhshname
    } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                next_player = "p4";
        } else {
            if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                next_player = "p2";
            } else {
                next_player = "p4";
            }
        }
    }
    sleep(5);
    int main_team1 = team1;
    int main_team2 = team2;





    //
    // round 2
    //
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }





    //
    // round 3
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }





    //
    // round 4
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }




    //
    // round 5
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }







    //
    // round6
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p2[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }




    //
    // round 7
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }





    //
    // round 8
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }






    //
    // round 9
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p2[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }




    //
    // round 10
    //
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }





    //
    // round 11
    //
    team1 = 0;
    team2 = 0;
    if (next_player == "p1"){
        system("clear");
        team1 = 0;
        team2 = 0;
        menue0(main_team1, main_team2);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }
        //printf("%s%d",cards_alphabet_p2[p2_select],cards_numbers_p2[p2_select]);


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p1_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }
        //printf("%s%d",cards_alphabet_p3[p3_select],cards_numbers_p3[p3_select]);
        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p1_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);

    } else if (next_player == "p2") {
        // p2_play
        biggest_num_p2 = 0;
        for (x=0; x<11; x++){
            if (cards_alphabet_p2[x] != char_bakhshname && cards_alphabet_p2[x] != "-") {
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2) {
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p2 == 0) {
            for (x=0; x<11; x++) {
                if (cards_alphabet_p2[x] == char_bakhshname && cards_alphabet_p2[x] != "-") {
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        team2 += biggest_num_p2;


        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p2_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast

        // p1 p2_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 2
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else if (next_player == "p3") {
        // p3_play
        biggest_num_p3 = 0;
        for (y=0; y<11; y++){
            if (cards_alphabet_p3[y] != char_bakhshname && cards_alphabet_p3[y] != "-") {
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3) {
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p3 == 0) {
            for (y=0; y<11; y++) {
                if (cards_alphabet_p3[y] == char_bakhshname && cards_alphabet_p3[y] != "-") {
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        team1 += biggest_num_p3;


        // p4_play
        biggest_num_p4 = 0;
        smallest_num_p4 = 45;
        there_is = false;
        for (z=0; z<11; z++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p4[z] == cards_alphabet_p1[p3_select]){
                there_is = true;
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4){
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        if (there_is == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_1 = false;
            for (z=0; z<11; z++){
                if (cards_alphabet_p4[z] == char_bakhshname) {
                    there_is_1 = true;
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_1 == false) {
                for (z=0; z<11; z++) {
                    if (cards_numbers_p4[z] < smallest_num_p4){
                        smallest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }

        if (biggest_num_p4 != 0){
            team2 += biggest_num_p4;
        } else {
            team2 += smallest_num_p4;
        }
        //printf("%s%d",cards_alphabet_p4[p4_select],cards_numbers_p4[p4_select]);


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 3
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];


        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p3_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }


        //its time to update game board
        //har bazikon yek card entekhab karde ast vaght update terminal hast
        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);


    } else {
        // p4_play
        biggest_num_p4 = 0;
        for (z=0; z<11; z++){
            if (cards_alphabet_p4[z] != char_bakhshname && cards_alphabet_p4[z] != "-") {
                //finding biggest number
                if (cards_numbers_p4[z] > biggest_num_p4) {
                    biggest_num_p4 = cards_numbers_p4[z];
                    p4_select = z;
                }
            }
        }
        // If all the cards are ((bakhshname)), the biggest ((bakhshname)) will be choose
        // trough down code
        if (biggest_num_p4 == 0) {
            for (z=0; z<11; z++) {
                if (cards_alphabet_p4[z] == char_bakhshname && cards_alphabet_p4[z] != "-") {
                    //finding biggest number
                    if (cards_numbers_p4[z] > biggest_num_p4) {
                        biggest_num_p4 = cards_numbers_p4[z];
                        p4_select = z;
                    }
                }
            }
        }
        team2 += biggest_num_p4;


        // p1_play
        system("clear");
        team1 = 0;
        team2 = 0;
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 4
        );
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        printf("Wich card do you want to play? ");
        scanf("%d", &p1_select);
        printf("You chose %s%d\n",cards_alphabet_p1[p1_select], cards_numbers_p1[p1_select]);
        printf("Wait 5 seconds\n");
        sleep(5);
        team1 += cards_numbers_p1[p1_select];

        // p2_play
        biggest_num_p2 = 0;
        smallest_num_p2 = 45;
        there_is_p2 = false;
        for (x=0; x<11; x++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p2[x] == cards_alphabet_p1[p1_select]){
                there_is_p2 = true;
                //finding biggest number
                if (cards_numbers_p2[x] > biggest_num_p2){
                    biggest_num_p2 = cards_numbers_p2[x];
                    p2_select = x;
                }
            }
        }
        if (there_is_p2 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p2_1 = false;
            for (x=0; x<11; x++){
                if (cards_alphabet_p2[x] == char_bakhshname) {
                    there_is_p2_1 = true;
                    //finding biggest number
                    if (cards_numbers_p2[x] > biggest_num_p2) {
                        biggest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p2_1 == false) {
                for (x=0; x<11; x++) {
                    if (cards_numbers_p2[x] < smallest_num_p2){
                        smallest_num_p2 = cards_numbers_p2[x];
                        p2_select = x;
                    }
                }
            }
        }
        if (biggest_num_p2 != 0) {
            team2 += biggest_num_p2;
        } else {
            team2 += smallest_num_p2;
        }

        // p3_play
        biggest_num_p3 = 0;
        smallest_num_p3 = 45;
        there_is_p3 = false;
        for (y=0; y<11; y++) {
            // check p1_card_character is in cards_alphabet_p2
            if (cards_alphabet_p3[y] == cards_alphabet_p1[p2_select]){
                there_is_p3 = true;
                //finding biggest number
                if (cards_numbers_p3[y] > biggest_num_p3){
                    biggest_num_p3 = cards_numbers_p3[y];
                    p3_select = y;
                }
            }
        }
        if (there_is_p3 == false) {
            //check ((bakhshname)) is in cards_numbers_p2
            bool there_is_p3_1 = false;
            for (y=0; y<11; y++){
                if (cards_alphabet_p3[y] == char_bakhshname) {
                    there_is_p3_1 = true;
                    //finding biggest number
                    if (cards_numbers_p3[y] > biggest_num_p3) {
                        biggest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
            // finding smallest number in cards
            if (there_is_p3_1 == false) {
                for (y=0; y<11; y++) {
                    if (cards_numbers_p3[y] < smallest_num_p3){
                        smallest_num_p3 = cards_numbers_p3[y];
                        p3_select = y;
                    }
                }
            }
        }
        if (biggest_num_p3 != 0){
            team1 += biggest_num_p3;
        } else {
            team1 += smallest_num_p3;
        }

        system("clear");
        if (team1 > team2){
            main_team1 += 1;
        } else {
            main_team2 += 1;
        }
        menue(
            cards_alphabet_p1[p1_select], cards_alphabet_p2[p2_select],
            cards_alphabet_p3[p3_select], cards_alphabet_p4[p4_select],
            cards_numbers_p1[p1_select], cards_numbers_p2[p2_select],
            cards_numbers_p3[p3_select], cards_numbers_p4[p4_select],
            main_team1 ,main_team2, 1
        );
        cards_alphabet_p1[p1_select] = "-";
        cards_alphabet_p2[p2_select] = "-";
        cards_alphabet_p3[p3_select] = "-";
        cards_alphabet_p4[p4_select] = "-";
        cards_numbers_p1[p1_select] = 0;
        cards_numbers_p2[p2_select] = 0;
        cards_numbers_p3[p3_select] = 0;
        cards_numbers_p4[p4_select] = 0;
        creat_hand(cards_alphabet_p1, cards_numbers_p1, false);
        if (team1 > team2){
            printf("Team 1 won this round\n");
            //if card was bakhshname
            if(cards_alphabet_p1[p1_select] == char_bakhshname) {
                if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                    if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                        next_player = "p1";
                    } else {
                        next_player = "p3";
                    }
                } else {
                    next_player = "p1";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p3[p3_select] == char_bakhshname) {
                next_player = "p3";
            } else {
                if (cards_numbers_p1[p1_select] > cards_numbers_p3[p3_select]) {
                    next_player = "p1";
                } else {
                    next_player = "p3";
                }
            }
        } else {
            printf("Team 2 won this round\n");
            if(cards_alphabet_p2[p2_select] == char_bakhshname) {
                if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                        next_player = "p2";
                    } else {
                        next_player = "p4";
                    }
                } else {
                    next_player = "p2";
                }
            // if card wasn't bakhshname
        } else if (cards_alphabet_p4[p4_select] == char_bakhshname) {
                    next_player = "p4";
            } else {
                if (cards_numbers_p2[p2_select] > cards_numbers_p4[p4_select]) {
                    next_player = "p2";
                } else {
                    next_player = "p4";
                }
            }
        }
        sleep(5);
    }




    system("clear");
    if (main_team1 > main_team2){
        printf("Team1 is winner\n" );
    } else {
        printf("Team2 is winner\n" );
    }

}






int main() {
    system("clear");
    printf(
        "Hi wellcome to my game\n"
        "Do you like to play with me? [y/n] "
    );
    char input[1];
    scanf("%s", input);
    printf("%s\n",input);

    if (input != "y") {
        int cards[4][11];
        cards_matrix(cards);
        char* cards_alphabet_p1[11];
        int cards_numbers_p1[11];
        num_to_str(cards[0], cards_alphabet_p1, cards_numbers_p1);
        char* cards_alphabet_p2[11];
        int cards_numbers_p2[11];
        num_to_str(cards[1], cards_alphabet_p2, cards_numbers_p2);
        char* cards_alphabet_p3[11];
        int cards_numbers_p3[11];
        num_to_str(cards[2], cards_alphabet_p3, cards_numbers_p3);
        char* cards_alphabet_p4[11];
        int cards_numbers_p4[11];
        num_to_str(cards[3], cards_alphabet_p4, cards_numbers_p4);

        int shomare_bakhshname;
        char* char_bakhshname;

        system("clear");

        int q;
        for (q=0; q<11; q++){
            printf("%s%d ",cards_alphabet_p1[q],cards_numbers_p1[q]);
        };
        printf("\n");
        for (q=0; q<11; q++){
            printf("%s%d ",cards_alphabet_p2[q],cards_numbers_p2[q]);
        };
        printf("\n");
        for (q=0; q<11; q++){
            printf("%s%d ",cards_alphabet_p3[q],cards_numbers_p3[q]);
        };
        printf("\n");
        for (q=0; q<11; q++){
            printf("%s%d ",cards_alphabet_p4[q],cards_numbers_p4[q]);
        };
        printf("\n");

        menue0(0, 0);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, true);
        printf("please choose index of ((bakhshname))? ");
        int bakhshname;
        scanf("%d", &bakhshname);
        system("clear");
        menue0(0, 0);
        creat_hand(cards_alphabet_p1, cards_numbers_p1, true);
        printf("You chose %s%d\n",cards_alphabet_p1[bakhshname],cards_numbers_p1[bakhshname]);
        shomare_bakhshname = cards_numbers_p1[bakhshname];
        char_bakhshname = cards_alphabet_p1[bakhshname];
        printf("Wait 5 seconds\n");
        sleep(5);



        int team1 = 0;
        int team2 = 0;
        round1(
            shomare_bakhshname, char_bakhshname,
            cards_alphabet_p1, cards_numbers_p1,
            cards_alphabet_p2, cards_numbers_p2,
            cards_alphabet_p3, cards_numbers_p3,
            cards_alphabet_p4, cards_numbers_p4,
            team1, team2
        );
        printf("Wait 5 seconds\n");
        sleep(5);


    } else {
        printf("Bye my friend :)\n" );
    }
    return 0;
}
