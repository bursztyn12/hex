#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <read_hex.h>


int main(){
    setupWiringPi();
    setupPins();
    readHexProgram();
    //printHexContents(WORDS);
    //write(16);
    writeAddress(0xfff);
}
