#include "FrameFinder.h"
#include "Finder.h"

FrameFinder* frame; 
int main(int argc, char *argv[]) {
	frame = new FrameFinder();
	frame->saveBinaryImg();
	return 0;
}