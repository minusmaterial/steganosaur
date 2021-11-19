#include "utils.h"

int bitPosToImageBytePos(int bitPos){
	return (bitPos/3)*4 + bitPos%3;
};
int setBit(int target, unsigned long bit, int pos){
	bit = !!bit;
	target ^=  (-bit ^ target) & (1UL << pos);
	return target;
}
