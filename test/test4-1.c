#include <stdio.h>
#include <stdlib.h>
#include "bmpHeader.h"

#define ubyte unsigned char

int main(int argc, char **argv)
{
	FILE *fp;
	BITMAPFILEHEADER bmpHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	ubyte *inimg, *outimg;
	int size, imgSize;
	RGBQUAD *rgbpal;

	if( (fp = fopen(argv[1], "rb")) == NULL ){
		perror("argv[1] not found.");
		return -1;
	}

	fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	int elemSize = bmpInfoHeader.biBitCount / 8 ;
	
	size = bmpInfoHeader.biWidth * elemSize;
	imgSize = size * bmpInfoHeader.biHeight;

	inimg = (ubyte*)malloc(sizeof(ubyte)*imgSize);
	outimg = (ubyte*)malloc(sizeof(ubyte)*imgSize);
	rgbpal = malloc(sizeof(RGBQUAD)*256);
	

	fread(inimg, sizeof(ubyte), imgSize, fp);

	for(int i=0 ; i < imgSize; i++){
		//outimg[i+0] = inimg[i+0];
		*(outimg+i) = *(inimg+i);
		//outimg[i+1] = inimg[i+1];
		//outimg[i+2] = inimg[i+2];
	}


/*
	for(int y = 0; y < bmpInfoHeader.biHeight; y++)
	{
		for(int x = 0; x < bmpInfoHeader.biWidth*elemSize; x+=3){
			outimg[x+y*size+0] = inimg[x+y*size+0];
			outimg[x+y*size+1] = inimg[x+y*size+1];
			outimg[x+y*size+2] = inimg[x+y*size+2];
		}
	}
*/
	fclose(fp);


	if( (fp = fopen(argv[2], "wb")) == NULL ){
		perror("argv[2] not found");
		return -1;
	}



	bmpHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*256;
	bmpHeader.bfSize = bmpHeader.bfOffBits + imgSize;

	/*for(int y = 0; y < bmpInfoHeader.biHeight; y++)
	{
		for(int x = 0; x < bmpInfoHeader.biWidth*elemSize; x+=3){
			outimg[x+y*size+0] = inimg[x+y*size+0];
			outimg[x+y*size+1] = inimg[x+y*size+1];
			outimg[x+y*size+2] = inimg[x+y*size+2];
		}
	}
	*/
	fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	fwrite(rgbpal, sizeof(RGBQUAD), 256, fp);
	fwrite(outimg, sizeof(ubyte), imgSize, fp);
	free(inimg);
	free(outimg);
	free(rgbpal);
	fclose(fp);

	return 0;

}
