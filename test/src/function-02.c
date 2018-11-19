// exit code: 0
// description: Should support input function

/******** IO macros (DON'T CHANGE THIS SECTION) ********/
#define EOF -1

/******** Setup the stack (DON'T CHANGE THIS SECTION) ********/
asm("lui $29,0x2400");

/******** IO function defintions (DON'T CHANGE THIS SECTION) ********/
int getc();
void putc(int);

/******** Helper function definitions ********/
void print(char *buf);
int input(char *buf, int size);

/******** Main entry point ********/
int entry() {
    char line[1024];
    while (1) {
        int count = input(line, 1024);
        if (count == EOF) break;
        print(line);
        print("\n");
    }
    return 0;
}

/******** Helper functions ********/
int input(char *buf, int size) {
    int count;
    for (count = 0; count < size - 1; count++) {
        int c = getc();
        if (c == EOF && count == 0) return -1;
        if (c == EOF || c == '\n') break;
        buf[count] = (char) c;
    }
    buf[count] = 0;
    return count;
}

void print(char *buf) {
    while(*buf) {
        putc(*buf);
        buf++;
    }
}

/******** IO functions (DON'T CHANGE THIS SECTION) ********/
int getc() {
    volatile int *p = (int *) 0x30000000;
    return *p;
}

void putc(int x) {
    volatile int *p = (int *) 0x30000004;
    *p = x;
}
