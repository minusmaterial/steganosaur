#include "encode.h"

void save(const char* filename, Image img){
  //Encode the image
  unsigned error = lodepng::encode(filename, img.bytes, img.w, img.h);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;

}

void encodeMessage(std::string message, Image * img){
	for(int i = 0; i < message.size(); i++){
		for(int j = 0; j < 8; j++){
			int imageByteLoc = i*8+j;
			if(imageByteLoc > img->bytes.size()){
				return;
			}
			unsigned long messageBit = (message[i] & 1UL << j) >> j;
			img->bytes[imageByteLoc] = setBit(img->bytes[imageByteLoc], messageBit, 0);
			//img->bytes[imageByteLoc] ^=  (-messageBit ^ img->bytes[imageByteLoc]) & (1UL << 0);
		}
	}
	//img.bytes[img.bytes.size()-1] = '\0';
}
