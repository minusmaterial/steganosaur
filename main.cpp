#include "encode.h"
#include "decode.h"
#include <string>

void printUsage(){
	printf("Usage:\n    steganosaur [filename] [string] [output filename](optional, default 'out.png'; hides string in .png)\nOR: steganosaur [filename] (reads hidden string from [filename], writes to stdout)\n");
}

int main(int argc, char* argv[])
{
	Image img;
	std::string out;
	switch(argc){
		case 1:
			printUsage();
			return -1;
		case 2:
			img = load(argv[1]);
			out = decodeMessage(img);
			std::cout << out << "\n";
			return 1;
		case 3:
			img = load(argv[1]);
			encodeMessage(argv[2], &img);
			save("out.png", img);
			return 1;
		case 4:
			img = load(argv[1]);
			encodeMessage(argv[2], &img);
			save(argv[3],img);
			return 1;
		default:
			printUsage();
			return -1;
	}
	return 0;
}
