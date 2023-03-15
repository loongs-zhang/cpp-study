#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void myFunction() {
    printf("in myFunction()\n");
    longjmp(buf, 1);

    // not reached
    printf("you will never see this because of longjmp");
}

int main(void) {
    // int i = setjmp(buf);
    // printf("i=%d\n", i);

    // if (i != 0) {
    //     exit(0);
    // }

    // longjmp(buf, 42);
    // printf("Does this line get printed?\n");

    if (setjmp(buf)) {
        printf("back in main\n");
    } else {
        printf("first time through\n");
        myFunction();
    }

    return 0;
}