#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            avg = round(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.00;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE img[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            img[i][j] = image[i][width-j-1];
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[i][j] = img[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE img[height][width];
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int rSum = 0, gSum = 0, bSum = 0, sum = 0;

            for (int k = (i - 1) ; k < (i + 2) ; k++)
            {
                for (int l = (j - 1) ; l < (j + 2) ; l++)
                {
                    // If trying to get value for non-existent pixel, skip
                    if (k == -1 || k == height || l == -1 || l == width)
                    {
                        continue;
                    }
                    rSum += image[k][l].rgbtRed;
                    gSum += image[k][l].rgbtGreen;
                    bSum += image[k][l].rgbtBlue;

                    sum++;
                }
            }

            img[i][j].rgbtRed = round(rSum /sum);
            img[i][j].rgbtGreen = round(gSum / sum);
            img[i][j].rgbtBlue = round(bSum / sum);
        }
    }

    // Copy blurred image array to normal image array
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = img[i][j];
        }
    }
    return;
}

// Detect edges
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int Gy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};

    RGBTRIPLE img[height][width];

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int GxR=0,GyR=0,GxG=0,GyG=0,GxB=0,GyB=0;

            for(int k=i-1;k<(i+2);k++){
                for(int l=j-1;l<(j+2);l++){
                    if(k==-1 || l==-1 || k==height ||l==width){
                        continue;
                    }
                    GxR += image[k][l].rgbtRed*Gx[k-(i-1)][l-(j-1)];
                    GxG += image[k][l].rgbtGreen*Gx[k-(i-1)][l-(j-1)];
                    GxB += image[k][l].rgbtBlue*Gx[k-(i-1)][l-(j-1)];

                    GyR += image[k][l].rgbtRed*Gy[k-(i-1)][l-(j-1)];
                    GyG += image[k][l].rgbtGreen*Gy[k-(i-1)][l-(j-1)];
                    GyB += image[k][l].rgbtBlue*Gy[k-(i-1)][l-(j-1)];
                }
            }
            int red = limit(round(sqrt(GxR*GxR + GyR*GyR)));
            int green = limit(round(sqrt(GxG*GxG + GyG*GyG)));
            int blue = limit(round(sqrt(GxB*GxB + GyB*GyB)));

            img[i][j].rgbtRed = red;
            img[i][j].rgbtGreen = green;
            img[i][j].rgbtBlue = blue;
        }
    }
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = img[i][j];
        }
    }
    return;
}
