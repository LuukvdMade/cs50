#include "helpers.h"
#include <stdlib.h>
#include <cs50.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // check foor each pixel if ther're the same
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            if(image[column][row].rgbtBlue == 0
            && image[column][row].rgbtGreen == 0
            && image[column][row].rgbtRed == 0)
            {
                image[column][row].rgbtBlue = 10;
                image[column][row].rgbtGreen = 10;
                image[column][row].rgbtRed = 10;
            }
        }
    }
}
