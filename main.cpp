#include "encode.h"
#include "decode.h"
#include <string>

std::string lorem =  "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus tellus nunc, placerat nec enim id, blandit ultrices mauris. Donec aliquet tellus placerat vestibulum congue. Cras eu nibh eu nulla ultrices convallis. Aliquam ut nibh leo. Nulla facilisi. Nullam laoreet ultricies porttitor. Praesent malesuada aliquam lacus, eu mollis magna varius eget. Ut pharetra tincidunt mauris, id consectetur nibh hendrerit vel.\n Aliquam erat volutpat. Donec at ex eu magna sagittis ultrices. Mauris in est tempus, imperdiet purus sed, molestie eros. Nulla cursus lectus vel nisi laoreet posuere. Suspendisse nunc sem, maximus id nulla eget, consectetur eleifend ex. Fusce commodo fermentum purus, vel rutrum enim fermentum faucibus. Vivamus tortor quam, lacinia eget ligula ac, fringilla commodo elit. Sed at malesuada elit. Nunc sit amet finibus orci.\n Vivamus fermentum massa a venenatis placerat. Sed et urna libero. Phasellus eros neque, egestas eget tempor eget, sagittis sit amet leo. Cras porttitor justo euismod nisi finibus, sit amet condimentum dolor tempor. Donec eros dui, ultrices ac ex eget, pulvinar posuere tellus. Donec ac tincidunt enim. Duis diam felis, molestie id velit id, lobortis pretium metus. In eget leo dictum, fringilla ligula a, iaculis nisi. Curabitur augue neque, interdum non interdum sit amet, tincidunt eu lectus. Sed placerat maximus rutrum. Morbi lobortis turpis nec sapien porttitor vulputate. Aenean id vestibulum eros. Donec lacinia, mi a finibus lobortis, ante tortor scelerisque nisi, et tristique ante massa eu leo. Sed pellentesque luctus augue vel vestibulum\n Aenean in erat id risus semper luctus volutpat in velit. Maecenas sapien ligula, eleifend sit amet nunc nec, dapibus sagittis turpis. Curabitur consectetur arcu ut lobortis imperdiet. Maecenas volutpat justo sapien, ut consequat nibh auctor sed. Vestibulum venenatis mattis massa a ultrices. Vivamus pretium urna eu enim interdum, vitae pellentesque justo porttitor. Donec feugiat ultrices sem sit amet vulputate.\n Fusce est leo, venenatis ut eleifend nec, molestie vitae enim. Quisque enim diam, placerat ac sagittis ac, tempus ut purus. Integer dignissim ante ante, nec accumsan metus ullamcorper in. Pellentesque sollicitudin purus elementum vulputate faucibus. Integer finibus felis sit amet ex varius euismod. Morbi volutpat volutpat nibh, in aliquam orci elementum nec. Donec quis suscipit diam, nec mattis arcu. Sed gravida consequat augue in euismod. Phasellus et pulvinar neque, eget ullamcorper neque. Donec eu massa ultrices, gravida magna sed, hendrerit nunc. In at tristique risus, non pellentesque sapien. Curabitur dignissim odio et iaculis malesuada. Proin et diam nisl. Integer pellentesque elit ac quam volutpat volutpat. Mauris nec tempus enim. Sed volutpat nec odio quis eleifend.";


int main(int argc, char* argv[])
{
	
	std::string text = lorem;

	Image img = load("data/class_soldierred.png");
	printf("%d,%d, %ld\n", img.w, img.h, sizeof(char));

	
	encodeMessage(text, &img);
	std::string out = decodeMessage(img);
	std::cout << out << "\n";


	save("test.png", img);
	
	return 0;
}
