#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average_value;

    for (int i=0  ;  i < height  ; i++ )
    {

        for (int j = 0 ; j < width ; j++)
        {
            average_value = ( round( (image [i][j].rgbtRed + image [i][j].rgbtGreen +image [i][j].rgbtBlue) / 3.00 ) ) ;

            image [i][j].rgbtRed = average_value;
            image [i][j].rgbtGreen = average_value;
            image [i][j].rgbtBlue = average_value;

        }

    }


    return;
}

int limit (int RGB)
{
    if(RGB>255)
    {
        RGB=255;
    }
    return RGB;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    float rsepia;
    float gsepia;
    float bsepia;

    for (int i=0  ;  i < height  ; i++ )
    {

        for (int j = 0 ; j < width ; j++)
        {
            rsepia = ( limit ( round ( .393 *  image [i][j].rgbtRed + .769 *  image [i][j].rgbtGreen + .189 * image [i][j].rgbtBlue ) ) ) ;
            gsepia = ( limit ( round ( .349 *  image [i][j].rgbtRed + .686 *  image [i][j].rgbtGreen + .168 * image [i][j].rgbtBlue ) ) ) ;
            bsepia = ( limit ( round ( .272 *  image [i][j].rgbtRed + .534 *  image [i][j].rgbtGreen + .131 * image [i][j].rgbtBlue ) ) ) ;



            image [i][j].rgbtRed =  rsepia;
            image [i][j].rgbtGreen =  gsepia;
            image [i][j].rgbtBlue =  bsepia;

        }

    }


    return;
}

// Reflect image horizontally

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmpred;
    int tmpgreen;
    int tmpblue;

    for (int i=0  ;  i < height  ; i++ )
    {

        for (int j = 0 ; j < width /2 ; j++)
        {

           tmpred   = image[i][width - j - 1].rgbtRed ;
           tmpgreen = image[i][width - j - 1].rgbtGreen ;
           tmpblue  = image[i][width - j - 1].rgbtBlue ;

            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed ;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen ;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue ;

            image[i][j].rgbtRed = tmpred;
            image[i][j].rgbtGreen = tmpgreen;
            image[i][j].rgbtBlue = tmpblue;

        }

    }

    return;
}

// Blur image
int get_blur(int i , int j , int height ,int width ,RGBTRIPLE image[height][width] , int color_position)
{
    int sum = 0 ;
    float counter =0;


     for (int k=i-1 ;  k < (i+2)  ; k++ )
    {

        for (int h=j-1 ; h < (j+2)  ; h++)
        {

        if( k<0 || h<0 || k >= height || h >= width )
        {
            continue;
        }

        else if( color_position ==0)
        {
            sum += image[k][h].rgbtRed ;

        }
        else if( color_position ==1)
        {

               sum += image[k][h].rgbtGreen ;
        }
        else
        {
            sum += image[k][h].rgbtBlue ;
        }
        
        counter++ ;

        }


    }

    return round(sum / counter);
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE copy[height][width];

     for (int i=0  ;  i < height  ; i++ )
    {

        for (int j = 0 ; j < width ; j++)
        {

            copy[i][j] = image[i][j];

        }

    }

     for (int i=0  ;  i < height  ; i++ )
    {

        for (int j = 0 ; j < width ; j++)
        {

            image[i][j].rgbtRed = get_blur(i , j , height , width ,copy , 0) ;
            image[i][j].rgbtGreen = get_blur(i , j , height , width ,copy , 1) ;
            image[i][j].rgbtBlue = get_blur(i , j , height , width ,copy , 2) ;

        }

    }


    return;
}
