#include "helpers.h"
#include <math.h>
#include <stdio.h>

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

// limit pixel color to 255 as maximum
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed,sepiaGreen,sepiaBlue;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            sepiaRed = limit(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiaBlue = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            // print("%d\n",sepiaRed);
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for(int i=0;i<height;i++){
        for(int j=0;j<width/2;j++){
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][width-j-1].rgbtRed = temp[0];
            image[i][width-j-1].rgbtGreen = temp[1];
            image[i][width-j-1].rgbtBlue = temp[2];

        }
    }
    return;
}

// Blur image
int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width] , int colour){

    int count=0, sum=0;
    for(int k=i-1;k<(i+2);k++){
        for(int l=j-1;l<(j+2);l++){
            if(k<0 || l<0 || k>=height || l>=width){
                continue;
            }
            if(colour==0){
                sum+=image[k][l].rgbtRed;
            }
            if(colour==1){
                sum+=image[k][l].rgbtGreen;
            }
            if(colour==2){
                sum+=image[k][l].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum/count);
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE img[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            img[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, img, 0);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, img, 1);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, img, 2);
        }
    }
    return;
}