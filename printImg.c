#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void centerImg(Coordinates const imgSize, Coordinates const consoleSize, Frame *imgFrame)
{
	imgFrame->xmin = (consoleSize.x - imgSize.x) / 2;

	imgFrame->ymin = (consoleSize.y - imgSize.y) / 2;

	imgFrame->xmax = (consoleSize.x - imgSize.x) / 2 + imgSize.x;

	imgFrame->ymax = (consoleSize.y - imgSize.y) / 2 + imgSize.y; //créer un cadre pour l'image.
}

void printImg(Coordinates const consoleSize, Coordinates const imgSize, Frame const imgFrame, int imgPixel[imgSize.x][imgSize.y])
{
	Coordinates i, j;

	j.x = 0;
	j.y = 0;

	for(i.y = 0; i.y < consoleSize.y; i.y++) //double for parcourant le terminal visible.
	{
		if(i.y < imgFrame.ymin || i.y >= imgFrame.ymax)
		{
			for(i.x = 0; i.x <= consoleSize.x; i.x++)
			{
				printf(" ");
			}
		}
		else
		{
			for(i.x = 0; i.x <= consoleSize.x; i.x++)
			{
				if(i.x < imgFrame.xmin || i.x >= imgFrame.xmax) //si dans le cadre, l'image est affichée et parcourue par j.
				{
					printf(" ");
				}
				else
				{
					if(imgPixel[j.x][j.y] == 1)
					{
						printf("\u2588");
					}
					else
					{
						printf(" ");
					}
					j.x++;
				}
			}
			j.x = 0;
			j.y++;
		}
		printf("\n");
	}
}