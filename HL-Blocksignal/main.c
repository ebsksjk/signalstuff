// generates one or more Signalbilder
//
// usage: ./a.out 1 ... 255
//
// . = simple permanent light
// x = blinking light

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define OFF 		0
#define RED 		1
#define GREEN 		2
#define YELLOW		4
#define E_RED		8
#define RED_B		16
#define GREEN_B		32
#define YELLOW_B	64
#define E_RED_B		128



int main(int c, char** v){

	for(int i = 1; i < c; i++){
		char signals[] = "0|0\n---\n0|0\n";
		int state = atoi(v[i]);
		printf("\n\nnumber: %d\n", state);

		//first, the normal states:
		bool red = (state & RED);
		bool green = (state & GREEN) >> 1;
		bool yellow = (state & YELLOW) >> 2;
		bool ered = (state & E_RED) >> 3;

		if(red){
			signals[0] = '.';
		}
		if(green){
			signals[2] = '.';
		}
		if(yellow){
			signals[8] = '.';
		}
		if(ered){
			signals[10] = '.';
		}

		red = (state & RED_B);
		green = (state & GREEN_B) >> 4;
		yellow = (state & YELLOW_B) >> 5;
		ered = (state & E_RED_B) >> 6;

		if(red){
			signals[0] = 'x';
		}
		if(green){
			signals[2] = 'x';
		}
		if(yellow){
			signals[8] = 'x';
		}
		if(ered){
			signals[10] = 'x';
		}

		printf("%s", signals);
	}

	
}
