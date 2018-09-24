#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "Startup_Dense.h"


int main(int argc, char *argv[]){
    const char* input_file_name = matrix_file_name_csv; 
    const char* output_file_name = vector_file_name_bin; 

    FILE* in_file =fopen(input_file_name, "r");
    FILE* out_file =fopen(output_file_name, "wb");

    char reading_buffer[128];
    int int_buffer[128];
    char* pt;
    int i=0;


    while(1)
    {   
        if(fgets(reading_buffer,sizeof(reading_buffer),in_file)!=NULL)
        {
            pt = strtok(reading_buffer,",");

            i=0;
            while(pt!=NULL)
            {
                int_buffer[i] = atoi(pt);
                pt=strtok(NULL,",");
                i++;
            }
            fwrite(int_buffer,sizeof(int),i,out_file);
        }
        else
            break;
    }

    fclose(in_file);
    fclose(out_file);
    return 0;

}


