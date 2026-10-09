#include "marcel/lex/token.h"

#include <stdio.h>
#include <stdlib.h>

char *marcel_token_tag_str(
    enum marcel_token_tag tag)
{
    switch (tag) {
    case marcel_token_tag_indent:
        return "ident";
    case marcel_token_tag_print:
        return "print";
    case marcel_token_tag_number:
        return "number";
    }

    printf("unreachable");
    exit(EXIT_FAILURE);
}
