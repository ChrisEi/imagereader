#pragma once

/* BMP file header structure 
 *  slightly altered from this source:
 *  http://stackoverflow.com/questions/8836017/reading-a-bmp-file-in-c?rq=1
 *  using guidance from the bmp file format wikipedia page
 */

// basic file data
#pragma pack(2) // two byte align header to prevent padding
struct BmpFileHeader {
	unsigned short  bfType;           /* Signature */
	unsigned int    bfSize;           /* Size of file */
	unsigned short  bfReserved1;
	unsigned short  bfReserved2;
	unsigned int    bfOffBits;        /* Offset to pixel data */
};
#pragma pack()

// specific image data
struct BmpDIBHeader {
	unsigned int    headerSize;        /* Size of info header */
	int             imgWidth;          /* Width of image */
	int             imgHeight;         /* Height of image */
	unsigned short  imgPlanes;         /* Number of color planes */
	unsigned short  bitsPerPixel;      /* Number of bits per pixel */
	unsigned int    imgCompression;    /* Type of compression to use */
	unsigned int    imgSize;           /* Size of image data */
	int             xPixelsPerMeter;   /* X pixels per meter (resolution data) */
	int             yPixelsPerMeter;   /* Y pixels per meter */
	unsigned int    colorsInTable;     /* Number of colors used */
	unsigned int    imptColorCount;    /* Number of important colors */
};

// colormap entry struct ?? i have no idea what this is for yet
struct rgbQuad {
	unsigned char	rgbBlue; // This is BGR rather than RGB
	unsigned char	rgbGreen;
	unsigned char	rgbRed;
	unsigned char	rgbReserved;
};

class Bitmap {
public:
	rgbQuad* pixels;
	BmpFileHeader fileHeader;
	BmpDIBHeader dibHeader;

	Bitmap(const char* filename);
	//~Bitmap();
};