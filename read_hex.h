#define WORDS       32768

static unsigned char data[WORDS];

void readHexProgram();
void printHexContents(uint8_t address_locations);
void printData();
void write(uint8_t size);
int setupWiringPi();
void setupPins();
