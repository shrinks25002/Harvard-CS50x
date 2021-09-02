#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    char filename[8]="";
    int count=0;
    BYTE buffer[512];

    FILE *img = NULL;

    while(1){
        fread(buffer,512,1,file);
        if(feof(file)){
            break;
        }
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0){
            if(img==NULL){
                sprintf(filename,"%03i.jpg",count);
                img = fopen(filename,"w");

                fwrite(buffer, 512, 1, img);
            }
            else{
                fclose(img);
                count++;
                sprintf(filename,"%03i.jpg",count);
                img = fopen(filename,"w");

                fwrite(buffer, 512, 1, img);
            }
        }
        else{
            if(img != NULL){
                fwrite(buffer, 512, 1, img);
            }
        }
    }
    fclose(img);
    fclose(file);
}