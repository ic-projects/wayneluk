// exit code: 0
// description: Should support complex recursive calls (quick sort)

/******** IO macros (DON'T CHANGE THIS SECTION) ********/
#define EOF (-1)

/******** Boolean macros (DON'T CHANGE THIS SECTION) ********/
#define TRUE (1)
#define FALSE (0)

/******** Helper macros ********/
#define MAX_LINE_LENGTH (64)
#define MAX_NUM_LINES (256)

/******** Setup the stack (DON'T CHANGE THIS SECTION) ********/
asm("lui $29,0x2400");

/******** IO function defintions (DON'T CHANGE THIS SECTION) ********/
int getc();
void putc(int);

/******** Helper function definitions ********/
void quick_sort(char *list, int first, int last);
int greater_than(char *a, char *b);
void swap(char *a, char *b);

void print(char *buf);
int input(char *buf, int size);

/******** Main entry point ********/
int entry() {
    char lines[MAX_NUM_LINES * MAX_LINE_LENGTH];
    int line_count;
    for (line_count = 0; line_count < MAX_NUM_LINES; line_count++) {
        char* line = &lines[line_count * MAX_LINE_LENGTH];
        int count = input(line, MAX_LINE_LENGTH);
        if (count == EOF) break;
    }
    quick_sort(lines, 0, line_count - 1);
    for (int i = 0; i < line_count; i ++) {
        print(&lines[i * MAX_LINE_LENGTH]);
        print("\n");
    }
    return 0;
}

/******** Helper functions ********/
void quick_sort(char *list, int first, int last) {
    int i, j, pivot;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (!greater_than(&list[i * MAX_LINE_LENGTH], &list[pivot * MAX_LINE_LENGTH]) && i < last)
                i++;
            while (greater_than(&list[j * MAX_LINE_LENGTH], &list[pivot * MAX_LINE_LENGTH]))
                j--;
            if (i < j) {
                swap(&list[i * MAX_LINE_LENGTH], &list[j * MAX_LINE_LENGTH]);
            }
        }
        swap(&list[pivot * MAX_LINE_LENGTH], &list[j * MAX_LINE_LENGTH]);
        quick_sort(list, first, j - 1);
        quick_sort(list, j + 1, last);
    }
}

int greater_than(char *a, char *b) {
    for (int count = 0; count < MAX_LINE_LENGTH; count++) {
        if (a[count] == 0) return FALSE;
        if (a[count] > b[count]) return TRUE;
        if (a[count] < b[count]) return FALSE;
    }
    return FALSE;
}

void swap(char *a, char *b) {
    char tmp[MAX_LINE_LENGTH];
    int count;
    for (count = 0; count < MAX_LINE_LENGTH; count++) {
        tmp[count] = a[count];
    }
    for (count = 0; count < MAX_LINE_LENGTH; count++) {
        a[count] = b[count];
    }
    for (count = 0; count < MAX_LINE_LENGTH; count++) {
        b[count] = tmp[count];
    }
}

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
