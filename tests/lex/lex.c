#include "marcel.lex.h"

int main(void)
{
    char *source_code = "print hi";

    marcel_lex(source_code);

    return 0;
}
