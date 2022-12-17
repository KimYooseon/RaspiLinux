#include "bmpHeader.h"
#include <stdio.h>
#include <stdlib.h>

#define ubyte unsigned char

int main(int argc, char **argv)
{
	FILE *fp;
	int r,g,b;
	ubyte *inimg,*outimg; 
	BITMAPFILEHEADER bmpHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	RGBQUAD *palrgb;

	if((fp = fopen(argv[1], "rb")) == NULL){
			perror("cannot found argv[1]\n");
			return -1;
	}


	fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	int elemSize = bmpInfoHeader.biBitCount / 8;
	int size = bmpInfoHeader.biWidth * elemSize;
	int imgSize = bmpInfoHeader.biHeight * size;


	inimg = (ubyte*)malloc(sizeof(ubyte)*imgSize);
	outimg = (ubyte*)malloc(sizeof(ubyte)*imgSize) ;
					
	fread(inimg, sizeof(ubyte), imgSize, fp);

	
	//int count = 0;

	for(int i = 0; i < bmpInfoHeader.biHeight*bmpInfoHeader.biWidth;i++){
		outimg[i*elemSize+0] = inimg[i*elemSize+0]; 
		outimg[i*elemSize+1] = inimg[i*elemSize+1]; 
		outimg[i*elemSize+2] = inimg[i*elemSize+2]; 
	}
/*
	for(int y = 0; y < bmpInfoHeader.biHeight; y++) {
		for(int x = 0; x <bmpInfoHeader.biWidth*3 ; x+=3) {
			outimg[x+y*size+0] = inimg[x+y*size+0];
			outimg[x+y*size+1]  = inimg[x+y*size+1];
			outimg[x+y*size+2] = inimg[x+y*size+2];

		}
	}
*/	
	fclose(fp);


	if((fp = fopen(argv[2], "wb")) == NULL){
		perror("cannot found argv[2]\n");
		return -1;
	}

	palrgb = (RGBQUAD*)malloc(sizeof(RGBQUAD)*256);

	//bmpInfoHeader.biBitCount = 8;
	//bmpInfoHeader.SizeImage = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;
	//bmpInfoHeader.biClrUsed = 256;

	bmpHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*256 + imgSize;
	bmpHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*256;

	fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	fwrite(palrgb, sizeof(RGBQUAD), 256, fp);
	fwrite(outimg, sizeof(ubyte), imgSize,fp);

	fclose(fp);




	return 0; 
}
