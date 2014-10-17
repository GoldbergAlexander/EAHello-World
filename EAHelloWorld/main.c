//
//  main.c
//  EAHelloWorld
//
//  Created by Alexander Goldberg on 10/15/14.
//  Copyright (c) 2014 Alexander Goldberg. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define HW "HELLO WORLD"
#define POP 100

char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
char hello[13] = "ALEC MOLINARO";

int main(int argc, const char * argv[]) {
    time_t t;

    //Genisis
    char genePool[POP][sizeof(hello)];
    
    srand((unsigned)time(&t));
    
    for (int i = 0; i < POP; i++) {
        for (int j = 0; j < sizeof(hello); j++) {
            genePool[i][j] = alpha[rand()%27];
        };
       
        printf("String: ");
        for (int k = 0; k < sizeof(hello); k++) {
            printf("%c",genePool[i][k]);
        }
        printf(" (%d)\n", fitness(genePool[i]));
    }
    
    for (int a = 0; a < 100; a++) {
        
    
    for (int i = 0; i < (100 -a); i++) {
        char temp[sizeof(hello)];
        if (fitness(genePool[i]) > fitness(genePool[i+1])){
            for (int j = 0; j < sizeof(hello); j++){
                temp[j] = genePool[i+1][j];
            }
            for (int j = 0; j < sizeof(hello); j++){
                genePool[i+1][j] = genePool[i][j];
            }
            for (int j = 0; j < sizeof(hello); j++){
                genePool[i][j] = temp[j];
            }
            
        }
    }
        
    }
    printf("\n\n**************************\n**************************\n**************************\n**************************\n\n\n");
    for (int i = 0; i < 100; i++) {
        printf("String: ");
        for (int k = 0; k < sizeof(hello); k++) {
            printf("%c",genePool[i][k]);
        }
        printf(" (%d)\n", fitness(genePool[i]));
    }
    int iterations = 0;
    while (fitness(genePool[0]) != 0) {
        iterations++;
        
        
        //Sort Array
        for (int a = 0; a < 100; a++) {
            
            
            for (int i = 0; i < (100 -a); i++) {
                char temp[sizeof(hello)];
                if (fitness(genePool[i]) > fitness(genePool[i+1])){
                    for (int j = 0; j < sizeof(hello); j++){
                        temp[j] = genePool[i+1][j];
                    }
                    for (int j = 0; j < sizeof(hello); j++){
                        genePool[i+1][j] = genePool[i][j];
                    }
                    for (int j = 0; j < sizeof(hello); j++){
                        genePool[i][j] = temp[j];
                    }
                    
                }
            }
            
        }

    
        //"Random" Parent Selections
        int rander = (int)(drand48()*drand48() * 100);
        char child[sizeof(hello)];
        int splice = rand()%sizeof(hello);
    
        for (int i = 0; i < sizeof(hello); i++) {
            child[i] = genePool[rander][i];
        }
    
        for (int i = splice; i < sizeof(hello); i++) {
            child[i] = genePool[rander][i];
        }
    
        //mutate child
        if ((rand()%100) > 50) {
            int mutablePos = (rand()%sizeof(hello));
            char mutable = child[mutablePos];
            int index = 0;
            int newIndex = 0;
            //Find index in aplha string
            for (int g = 0; g < 27; g++) {
                if (alpha[g] == mutable) {
                    index = g;
                }
            }

            if (index == 0) {
                newIndex = 1;
            } else if (index == 27) {
                newIndex = 26;
            } else if((rand()%100) < 49){
                newIndex = index - 1;
            } else {
                newIndex = index + 1;
            }
            
            child[mutablePos] = alpha[newIndex];
        }
        if (fitness(child) < fitness(genePool[99])) {
        for (int i = 0; i < sizeof(hello); i++) {
            genePool[99][i] = child[i];
        }
        }
        
        //for (int i = 0; i < 100; i++) {
            printf("String: ");
            for (int k = 0; k < sizeof(hello); k++) {
                printf("%c",genePool[0][k]);
            }
            printf(" (%d)\n", fitness(genePool[0]));
        //}

        printf("Current Iterations %d\n", iterations);
        
    }
    
    return 0;
    

}


//Determian fitness with an r^2 algrarythym
int fitness(char string[sizeof(hello)]){
    int fitness = 0;
    
    for (int i = 0; i < sizeof(hello); i++) {
        
        fitness += (string[i] - hello[i])* (string[i] - hello[i]);
        //printf("The Letter %c is %d from %c\n", string[i], (string[i]-hello[i]), hello[i]);
    }
    
    return fitness;
}


