#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    if(argc != 2)
    {
        printf("usage: ./recover filename\n");
        return 1;
    }

    //opening the memory card
    char *nameofrawfile = argv[1];

    FILE *rawfile = fopen("nameofrawfile" , "r");

    if (rawfile== NULL )
    {
        printf("the image cannot be opened \n");
        return 1;
    }

    BYTE buffer[512];
    int counter =0;
    char imgname[8];
    FILE *img_recovered;

    //repeat the process of 1-reading from the memory card into the buffer 2-checking for jpeg

    while ( fread ( &buffer , 512 , 1 , rawfile ) ==1 )
    {

        if( buffer[0]== 0xff  &&  buffer[1]==0xd8  &&  buffer[2]==0xff  && ( buffer[3] & 0xf0 )==0xe0 )
        {
               if(counter !=0)
                  {
                      fclose(img_recovered);
                      return 0;
                  }

                sprintf(imgname , "%03i.jpg" , counter++);



                img_recovered = fopen(  imgname , "w");

                fwrite( &buffer , 512 ,1 , img_recovered);
                return 1;

        }

        else if(counter > 0)
        {
            FILE *image = fopen(imgname, "a");
            fwrite( &buffer , 512 ,1 , img_recovered);

        }

     }

fclose(rawfile);
fclose(img_recovered);
return 0;

}
