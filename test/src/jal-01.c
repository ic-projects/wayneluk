// exit code: 2
// description: JAL should support returns by jumping to RA register

/******** Setup the stack (DON'T CHANGE THIS SECTION) ********/
asm("lui $29,0x2400");

/******** IO function defintions (DON'T CHANGE THIS SECTION) ********/
int getc();
void putc(int);

/******** Helper function definitions ********/
int two();

/******** Main entry point ********/
int entry() {
    int x = 1;
    x = two();
    return x;
}

/******** Helper functions ********/
int two() {
    return 2;
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
