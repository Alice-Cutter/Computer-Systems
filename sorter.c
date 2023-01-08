/*
Alice Cutter 
Assignment #1 
January 5th  


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX_CHAR_COUNT 200
//#define MAX_WORD_COUNT 500
void printWords (int rows, char grid [200][500]){
    for (int w = 0; w < rows; w ++){
       printf("%s", grid[w]);
    }
}
void swap_rows(char grid [] [500], int row_index1, int row_index2, int column_count){
    int word1len = strlen(grid[row_index1]); 
    int word2len = strlen(grid[row_index2]); 
    int looplen = 0; 
    if (word1len > word2len){
        looplen = word1len;
    }
    else{
        looplen = word2len;
    }
    
    for(int column = 0; column < looplen; column++){
        char tempChar = grid[row_index1][column]; 

        //printf("Swapping %c\n", tempChar); 
        grid[row_index1][column] = grid[row_index2][column];
        grid[row_index2] [column] = tempChar; 
    } //how far over to go
    
}



int main (int argc, char *argv[]){
    //Get file name from command line 
    if (argc != 2){
    printf("UH Oh I am having a hard time reading your file"); 
    return -1; 
    }
    char *fileName = argv[1]; 
    
    //Reading from file 
    FILE * input_file = fopen(fileName, "r"); 
    
    //checking if input file is null
    if (input_file == NULL){
        printf("I think you forgot to add in a file to sort from");
        return -1; 
    }
    
    char grid[200][500]; //THIS IS THE 2D ARRAY WHERE I WILL PUT THE LETTERS AND WORDS INTO 
    char ch = fgetc(input_file); 
    int row = 0; 
    int col = 0; 
    while(ch != EOF){
         
         grid[row][col] = ch; 
       
        if(ch == '\n'){// We have reached the end of the word
            //printf("moving to next word\n"); 
            grid[row][col +1] = '\0';
            //put null terminator at collumn +1
            row++; 
            col = 0; 

        }
        else{
            col ++ ; 
        }
       
        ch = fgetc(input_file);
    }
    grid[row][col] = '\0';

    //printWords(row, grid); 


    int i; 
    int j; 
    int mindex; 

    for(i = 0; i <row-1; i++ ){// boundary of unsorted array
        mindex = i; // seting mindex to boundary of unsorted
        
        for( j = i +1; j< row; j++){
            
            if(strcmp(grid[j], grid[mindex]) < 0){
                //These should swap
                mindex = j; 
            }
            if(mindex != i){

                //NEED TO SWAP ELEMENTS
                //void swap_rows(char grid [] [500], int row_index1, int row_index2, int column_count){
               

            
            }
            
        }
        swap_rows(grid, i, mindex, strlen(grid[mindex])); 
    }
    //printf("SortedWords\n"); 
    printWords(row, grid); 


}



