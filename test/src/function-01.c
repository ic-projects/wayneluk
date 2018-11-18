// exit code: 0
// description: Should support print function

/******** Setup the stack (DON'T CHANGE THIS SECTION) ********/
asm("lui $29,0x2400");

/******** IO function defintions (DON'T CHANGE THIS SECTION) ********/
int getc();
void putc(int);

/******** Helper function definitions ********/
void print(char *string);

/******** Main entry point ********/
int entry() {
    print("Hello world!");
    return 0;
}

/******** Helper functions ********/
void print(char *string) {
    while(*string) {
        putc(*string);
        string++;
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
