#include "decode.h"
Image load(const char* filename){
	unsigned width, height;
	std::vector<unsigned char> image;
	unsigned error = lodepng::decode(image, width, height, filename);

	if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	return (Image){image,width,height};
}

std::string decodeMessage(Image img){
	int maxlen = img.w * img.h*3/4/8+1;
	char * output = (char*)malloc(sizeof(char) * maxlen);
	for(int i = 0; i < maxlen-1; i++){
		output[i] = 'a';
	}
	output[maxlen-1] = '\0';
	for(int i = 0; i < maxlen-1; i++){
		for(int j = 0; j < 8; j++){
			int bit = img.bytes[bitPosToImageBytePos(8*i+j)] & 1UL << 0;
				output[i] = setBit(output[i], bit, j);
		}
		printf("%c\n", output[i]);
	}
	std::string outstr = output;
	return outstr;
}
