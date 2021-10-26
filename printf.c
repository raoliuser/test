#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    double a = 2.56e+5;
    double b = 2.56e5;
    double c = 2.56e-5;
    printf("%f %f %f \n", a, b, c);

    int i2 = 0b10011001;
    int i8 = 077;
    int i10 = 456;
    int i16 = 0xff;

    printf("%#x %#x %#x %#x\n", i2, i8, i10, i16);

    
    printf("hello\n");
    fprintf(stdout, "hello\n");

    puts("hello\n");
    fputs("hello\n",stdout);

    // putc('x', stdout);
    // fputc('x', stdout);

    // putchar('x');
    
    write(STDOUT_FILENO, "hello", 5);
    fwrite("hello", 5, 1 , stdout);
    return 0;
}
