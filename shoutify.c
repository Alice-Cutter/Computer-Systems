/*1. Alice Cutter 
   The program will copy the contents of inputfile 
   to outputfile unchanged except that all lowercase Latin 
   letters (ASCII 97-122) should be changed to their uppercase
    equivalents (ASCII 65-90). 

    Sources:
     https://www.programiz.com/c-programming/c-file-input-output
     https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
     https://www.programiz.com/c-programming/library-function/ctype.h/toupper 
*/

#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]){
//Parse command line 
   
    if (argc != 3){
        printf("You have entered the wrong number of arguments! \n");
        return 1; 
    }   
    //Pulling variables from command line
   char *input1 = argv[1];
   char *input2 = argv[2];

    FILE * input_file = fopen(input1, "r");//making a pointer to the file. The r stands for reading 
    if (input_file == NULL){
      return -1;
    }
    FILE * output_file = fopen(input2, "w"); // making a pointer to the output file. The w stands for writing. 
  
    if (output_file == NULL){
        return -1;
    }
    char ch = fgetc(input_file); 
    while (ch != EOF){
        char  changedChar = toupper(ch); 
        fprintf(output_file, "%c", changedChar); 
        ch = fgetc(input_file);
    }  
        fprintf(output_file, "%s", "\0");
    
        fclose(input_file);
        fclose(output_file); 
    return 0; // I am not confident about the return type. I feel like it should be void. 
}

