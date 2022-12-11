#include "bmpHeader.h"
#include <stdio.h>
#include <stdlib.h>

#define ubyte unsigned char

int main(int argc, char **argv)
{
	FILE *fp;
	//int n;
	int r,g,b;
	int inimgSize;
	ubyte* inimg; 
	BITMAPFILEHEADER bmpHeader;
	BITMAPINFOHEADER bmpInfoHeader;

	if((fp = fopen(argv[1], "rb")) == NULL){
			perror(argv[1]);
			return -1;
	}

	fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	inimgSize = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3;

	inimg = (ubyte*)malloc(sizeof(ubyte)*inimgSize);

	fread(inimg, sizeof(ubyte), inimgSize, fp);

	int size =bmpInfoHeader.biWidth*3;
	
	int count = 0;

	for(int y = 0; y < bmpInfoHeader.biHeight; y++) {
		for(int x = 0; x <bmpInfoHeader.biWidth*3 ; x+=3) {
			b = inimg[x+y*size+0];
			g = inimg[x+y*size+1];
			r = inimg[x+y*size+2];

			printf("%d => B: %d, G: %d, R: %d\n", count, b, g, r); 
			count++;	
		}
	}
	

	fclose(fp);

	//scanf("%s", filename);
	//printf("%s", filename);



	return 0; 
}
