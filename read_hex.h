#include <stdint.h>

#define WORDS       32768

static unsigned char data[WORDS];

void readHexProgram();
void printHexContents(uint8_t address_locations);
void printHexData(uint8_t size);
void writeData(uint8_t size);
void writeAddress(uint32_t size);
int setupWiringPi();
void setupPins();
