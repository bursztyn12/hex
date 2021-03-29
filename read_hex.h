#define WORDS       32768

static unsigned char data[WORDS];

void readHexProgram();
void printHexContents(uint8_t address_locations);
void printData();
void write();
int setupWiringPi();
void setupPins();
