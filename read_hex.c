#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <read_hex.h>

void readHexProgram(){
    FILE *hex_file;
    hex_file = fopen("a.out", "rb");

    if(hex_file == NULL) {
        fprintf(stderr, "can't open %s\n", "a.out");
        exit(1);
    }

    int r = fread(data, 1, WORDS, hex_file);
    printf("Read %d chars.\n", r);
}

void printHexContents(int address_locations){

    for(int base = 0; base < address_locations; base += 16){
        unsigned char r_data[16];
        for(int offset = 0; offset < 16; offset++){
            r_data[offset] = data[base + offset];
        }

        char buf[80];
        sprintf(buf, "%03x: %02x %02x %02x %02x %02x %02x %02x %02x     %02x %02x %02x %02x %02x %02x %02x %02x",
            base, r_data[0], r_data[1], r_data[2], r_data[3], r_data[4], r_data[5], r_data[6], r_data[7],
            r_data[8], r_data[9], r_data[10], r_data[11], r_data[12], r_data[13], r_data[14], r_data[15]);
        printf("%s \n", buf);
    }
}

void write(int size){
    int val = 0;
    for(int i=0;i < size; i++){
        unsigned char cmd = data[i];
        printf("cmd: %02x\n", cmd);
        for(int j=0; j<8; j++){
            val = cmd & 1;
            printf("bit: %d     ", val);
            cmd = cmd >> 1;
            printf("cmd: %d", cmd);
            printf("\n");
        }
    }
}

void printData(){
    for(int i=0; i < 16; i++){
        printf("%02x\n", data[i]);
    }
}
