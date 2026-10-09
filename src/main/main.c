#include "marcel/lex/lex.h"
#include "marcel/lex/token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *source_code = "print hi";
    const size_t tokens_start_cap = 100;
    size_t tokens_cap = tokens_start_cap;
    size_t tokens_len = 0;

    struct marcel_token *tokens = malloc(
        sizeof(struct marcel_token) * tokens_cap);

    marcel_lex(source_code, &tokens, &tokens_len,
        &tokens_cap);

    for (size_t i = 0; i < tokens_len; ++i) {
        printf("%s\n",
            marcel_token_tag_str(tokens[i].tag));
    }

    free(tokens);
}
