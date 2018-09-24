// File:    CSVtoBin_Sparse.c
// Name:    Oscar Huang
// Desc:    Convert csv file to binary file. The output file is shuffled by transform.
// Input:   Csv file
// Output:  Transformed binary file. Each node was recorded as (row, col, value)
// Keypoints: Binary file creating


#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "Startup_Sparse.h"

int main(int argc, char *argv[]){

    FILE* in_file =fopen(csv_file_name, "r");
    FILE* out_file =fopen(matrix_bin_file_name, "wb");

    char* reading_buffer = malloc(ncol*(sizeof(int)+sizeof(char)));
    char* pt;
    int buffer;

    for(int row=0; row<nrow; row++)
    {
        fgets(reading_buffer,ncol*(sizeof(int)+sizeof(char)),in_file);
        pt = strtok(reading_buffer,",");

        for(int col=0; col<ncol; col++)
        {
            if(atoi(pt)!=0)
                {
                    buffer = atoi(pt);
                        fwrite(&col,sizeof(int),1,out_file);//Using transform to shuffle
                        fwrite(&row,sizeof(int),1,out_file);
                        fwrite(&buffer,sizeof(int),1,out_file);
                }
            pt=strtok(NULL,",");
        }
    }
    
    free(reading_buffer);
    free(pt);
    fclose(in_file);
    fclose(out_file);
    return 0;
}



