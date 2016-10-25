#include <iostream>
#include <fstream>
#include <stdio.h>
#include "bitmap.h"
using namespace std;

Bitmap::Bitmap(const char* filename) {
	FILE* file;
	file = fopen(filename, "rb");

	std::cout << sizeof(BmpFileHeader) << std::endl;

	if (file != NULL) { // file opened
		BmpFileHeader h;
		size_t x = fread(&h, sizeof(BmpFileHeader), 1, file); //reading the FILEHEADER

		std::cout << x;
		fread(&this->dibHeader, sizeof(BmpDIBHeader), 1, file);

		fclose(file);
	}
}

int main() {
	cout << "it compiled lmao" << endl;

	Bitmap test("test.bmp");

	char wut;
	cin >> wut;
	return 0;
}