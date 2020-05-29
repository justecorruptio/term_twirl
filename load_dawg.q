#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char *data;

int traverse(char * data, int ptr, char* buffer, int buf_ptr) {
    unsigned long child_offset;
    char c;
    int end_list, end_word;

    union {
        uint32_t whole;
        struct {
            // IMPORTANT! Never more that 2 ^ 16 nodes
            uint16_t child_offset;
            char high;
        };
    } w;

    while (1) {
        w.whole = ((uint32_t*)(data + ptr))[0];

        //printf("%x [%c] %d %d\n", child_offset, c, end_list, end_word);

        if(w.high & 0x7C) {
            buffer[buf_ptr] = (w.high >> 2) + 'A' - 1;
        }
        if (w.high & 1)
            printf("%s\n", buffer + 1);

        if (w.child_offset)
            traverse(data, w.child_offset * 3, buffer, buf_ptr + 1);

        if(w.high & 2) {
            buffer[buf_ptr] = 0;
            break;
        }

        ptr += 3;
        //printf("DEBUG\n");
    }
    return 0;
}

int main() {

    int c;

    FILE * fh = fopen("output.dawg", "rb");
    data = calloc(10000, 0);

    int ptr = 0;

    while((c = fgetc(fh)) != -1) {
        data[ptr++] = c;
    }

    char * buffer = calloc(8, 1);

    traverse(data, ptr - 3, buffer, 0);
    //printf("%s\n", buffer + 1);
}

