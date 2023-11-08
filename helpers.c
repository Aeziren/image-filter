#include <math.h>
#include <stdlib.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    // Os 2 for garantem que cada pixel da imagem vai ser percorrido
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            // Pega a media dos valores R, G e B do pixel atual e aplica em R, G e B.
            avg = round((image[y][x].rgbtBlue + image[y][x].rgbtGreen + image[y][x].rgbtRed) / 3.0);
            image[y][x].rgbtBlue = avg;
            image[y][x].rgbtGreen = avg;
            image[y][x].rgbtRed = avg;
        }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepia_blue, sepia_green, sepia_red;
    // Os 2 for garantem que cada pixel da imagem vai ser percorrido
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            // Adiciona a variavel o novo valor de RGB de acordo com a formula Sepia.
            sepia_red = round((.393 * image[y][x].rgbtRed) + (.769 * image[y][x].rgbtGreen) + (.189 * image[y][x].rgbtBlue));
            sepia_green = round((.349 * image[y][x].rgbtRed) + (.686 * image[y][x].rgbtGreen) + (.168 * image[y][x].rgbtBlue));
            sepia_blue = round((.272 * image[y][x].rgbtRed) + (.534 * image[y][x].rgbtGreen) + (.131 * image[y][x].rgbtBlue));

            // Verifica se nenhum valor é maior que 255.
            if (sepia_red > 255)
                sepia_red = 255;
            if (sepia_green > 255)
                sepia_green = 255;
            if (sepia_blue > 255)
                sepia_blue = 255;

            // Aplica os novos valores a RGB.
            image[y][x].rgbtRed = sepia_red;
            image[y][x].rgbtGreen = sepia_green;
            image[y][x].rgbtBlue = sepia_blue;
        }
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Variavel que armazena um pixel temporariamente
    RGBTRIPLE temp;
    int pos_inversa;
    // Os 2 for garantem que cada pixel da imagem vai ser percorrido
    for (int y = 0; y < height; y++)
        for (int x = 0; x < round(width / 2) ; x++)
        {
            // Troca de lugar o primeiro pixel com o último, o segundo com o penúltimo e etc... Até a imagem ser invertida.
            pos_inversa = width - x - 1;
            temp = image[y][x];
            image[y][x] = image[y][pos_inversa];
            image[y][pos_inversa] = temp;
        }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Cria uma copia da imagem.
    RGBTRIPLE copy[height][width];
    int avg_red, avg_green, avg_blue;
    int cont_media;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            copy[y][x] = image[y][x];

    // Os dois for garantem que cada pixel da imagem será percorrido.
    for (int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            // Variaveis de media de RGB e contador de vezes que um pixel do quadrado foi adicionado à conta.
            avg_red = 0;
            avg_green = 0;
            avg_blue = 0;
            cont_media = 0;
            // Esses dois for garantem que todos os tres pixels vizinhos ao pixel principal serão adicionado a conta.
            for(int box_y = (y - 1); box_y <= (y + 1); box_y++)
            {
                for(int box_x = (x - 1); box_x <= (x + 1); box_x++)
                {
                    // O pixel só é levado em consideração se ele estiver dentro da imagem.
                    if (!(box_y < 0 || box_y > height - 1|| box_x < 0 || box_x > width - 1))
                    {
                        avg_red += copy[box_y][box_x].rgbtRed;
                        avg_green += copy[box_y][box_x].rgbtGreen;
                        avg_blue += copy[box_y][box_x].rgbtBlue;
                        cont_media++;
                    }
                }
            }
            if (cont_media > 0)
            {
                // Calcula a média e adiciona ao pixel principal, já na imagem principal.
                avg_red = round(avg_red / (float)cont_media);
                avg_green = round(avg_green / (float)cont_media);
                avg_blue = round(avg_blue / (float)cont_media);
                image[y][x].rgbtRed = avg_red;
                image[y][x].rgbtGreen = avg_green;
                image[y][x].rgbtBlue = avg_blue;
            }
        }
    }
}
