#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <read_hex.h>
#include <wiringPi.h>

#define SHIFT_DATA      21
#define SHIFT_CLK       20
#define SHIFT_RSCLK     16

int setupWiringPi(){
  if (wiringPiSetupGpio() == -1){
      printf("Error,can't start wiringPi!\n");
      return 1;
  }

  printf("Succes,library wiringPi loaded!\n");
  return 0;
}

void setupPins(){
    pinMode(SHIFT_DATA, OUTPUT);
    pinMode(SHIFT_CLK, OUTPUT);
    pinMode(SHIFT_RSCLK, OUTPUT);
}

void readHexProgram(){
    FILE *hex_file;
    hex_file = fopen("a.out", "rb");

    if(hex_file == NULL) {
        fprintf(stderr, "can't open %s\n", "a.out");
        exit(1);
    }

    uint8_t r = fread(data, 1, WORDS, hex_file);
    printf("Read %d chars.\n", r);
}

void printHexContents(uint8_t address_locations){
    for(uint8_t base = 0; base < address_locations; base += 16){
        unsigned char r_data[16];
        for(uint8_t offset = 0; offset < 16; offset++){
            r_data[offset] = data[base + offset];
        }

        char buf[80];
        sprintf(buf, "%03x: %02x %02x %02x %02x %02x %02x %02x %02x     %02x %02x %02x %02x %02x %02x %02x %02x",
            base, r_data[0], r_data[1], r_data[2], r_data[3], r_data[4], r_data[5], r_data[6], r_data[7],
            r_data[8], r_data[9], r_data[10], r_data[11], r_data[12], r_data[13], r_data[14], r_data[15]);
        printf("%s \n", buf);
    }
}

void write(uint8_t size){
    int val = 0;
    for(uint8_t i=0;i < size; i++){
        unsigned char cmd = data[i];
        printf("cmd: %02x\n", cmd);
        for(uint8_t j=0; j<12; j++){
            val = cmd & 1;
            printf("bit: %d     ", val);
            cmd = cmd >> 1;
            printf("cmd: %d", cmd);
            printf("\n");
            
            digitalWrite(SHIFT_DATA, val);
            digitalWrite(SHIFT_CLK, HIGH);
            delay(1);
            digitalWrite(SHIFT_CLK, LOW);
            delay(1);
            
            digitalWrite(SHIFT_RSCLK, HIGH);
            digitalWrite(SHIFT_RSCLK, LOW);
        }
        delay(500);
    }
}

void printHexData(uint8_t size){
    for(uint8_t i=0; i < size; i++){
        printf("%02x\n", data[i]);
    }
}
