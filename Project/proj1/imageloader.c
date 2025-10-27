/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{
	//YOUR CODE HERE
	int rows = 0;
	int cols = 0;
	int max = 0;
	FILE *fp;
	fp = fopen("filename.ppm", "w+");
	fscanf(fp, "P3 %d %d %d", rows, cols, max);
	//开始分配内存，先分整块，再分行指针，再分具体内存
	Image *ima = (Image *)malloc(sizeof(Image));
	if (ima == NULL) {
		perror("Error allocating structure memory");
		return NULL;
	}
	ima->cols = cols;
	ima->rows = rows;
	ima->image = (Color **)malloc(rows * sizeof(Color *));
	if (ima->image == NULL) {
		perror("Error allocating row pointers");
		free(ima);
		return NULL;
	}
	for (int r = 0; r < rows; r++) {
		ima->image[r] = (Color *)malloc(cols * sizeof(Color));
		if (ima->image[r] == NULL) {
			for (int c = 0; c < r; c++) {
				free(ima->image[c]);
			}
			free(ima->image);
			free(ima);
			return NULL;
		}
	}
	for (int i = 0; i < (cols * rows); i++) {
		Color *pixel = ima->image[i];
		fscanf(fp, "%d %d %d", pixel->R, pixel->G, pixel->B);
	}
	fclose(fp);
	return ima;
}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	//YOUR CODE HERE
	printf("P3\n");
	printf("%d\n%d\n", image->rows, image->cols);
	for (int i = 0; i < image->rows; i++) {
		for (int j = 0; j < image->cols; j++) {
			int cur_pix = i * image->cols + j;
			Color *cur = image->image[cur_pix];
			printf("%d %d %d", cur->R, cur->G, cur->B);
		}
		printf("\n");
	}
}

//Frees an image
void freeImage(Image *image)
{
	//YOUR CODE HERE
	if (image == NULL) return;
	int rows = image->rows;
	if (image->image != NULL) {
		for (int i = 0; i < rows; i++) {
			free(image->image[i]);
		}
		free(image->image);
	}
	free(image);
	return;
}