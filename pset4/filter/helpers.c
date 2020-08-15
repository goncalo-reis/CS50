#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int value = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = value;
            image[i][j].rgbtGreen = value;
            image[i][j].rgbtRed = value;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, w = width / 2; j < w; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float pixel_count = 0.0;
            int b_count = 0;
            int g_count = 0;
            int r_count = 0;
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    if (i + h >= 0 && i + h <= height - 1 && j + w >= 0 && j + w <= width - 1)
                    {
                        pixel_count += 1.0;
                        b_count += tmp[i + h][j + w].rgbtBlue;
                        g_count += tmp[i + h][j + w].rgbtGreen;
                        r_count += tmp[i + h][j + w].rgbtRed;
                    }
                }
            }
            int b_value = round(b_count / pixel_count);
            int g_value = round(g_count / pixel_count);
            int r_value = round(r_count / pixel_count);
            image[i][j].rgbtBlue = b_value;
            image[i][j].rgbtGreen = g_value;
            image[i][j].rgbtRed = r_value;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    int gx_array[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy_array[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_b = 0;
            int gy_b = 0;
            int gx_g = 0;
            int gy_g = 0;
            int gx_r = 0;
            int gy_r = 0;
            int n = 0;
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    if (i + h < 0 || i + h > height - 1 || j + w < 0 || j + w > width - 1)
                    {
                        n += 1;
                    }
                    else
                    {
                        gx_b += gx_array[n] * tmp[i + h][j + w].rgbtBlue;
                        gy_b += gy_array[n] * tmp[i + h][j + w].rgbtBlue;
                        gx_g += gx_array[n] * tmp[i + h][j + w].rgbtGreen;
                        gy_g += gy_array[n] * tmp[i + h][j + w].rgbtGreen;
                        gx_r += gx_array[n] * tmp[i + h][j + w].rgbtRed;
                        gy_r += gy_array[n] * tmp[i + h][j + w].rgbtRed;
                        n += 1;
                    }
                }
            }
            int b_value = round(sqrt(pow(gx_b, 2) + pow(gy_b, 2)));
            int g_value = round(sqrt(pow(gx_g, 2) + pow(gy_g, 2)));
            int r_value = round(sqrt(pow(gx_r, 2) + pow(gy_r, 2)));
            if (b_value > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = b_value;
            }
            if (g_value > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = g_value;
            }
            if (r_value > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image [i][j].rgbtRed = r_value;
            }
        }
    }
}
