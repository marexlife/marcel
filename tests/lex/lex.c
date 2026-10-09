#include "marcel/lex/lex.h"
#include "marcel/lex/token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
    int err_code = 0;
    const char *source_code = "print hi";
    const size_t tokens_start_cap = 100;
    size_t tokens_cap = tokens_start_cap;
    size_t tokens_len = 0;

    struct marcel_token *actual_result = malloc(
        sizeof(struct marcel_token) * tokens_cap);

    marcel_lex(source_code, &actual_result,
        &tokens_len, &tokens_cap);

    const enum marcel_token_tag expected_result[]
        = {
              marcel_token_tag_print,
              marcel_token_tag_indent,
          };

    for (size_t i = 0;
        i < (tokens_len | sizeof expected_result);
        ++i) {
        if (actual_result[i].token_tag
            != expected_result[i]) {
            err_code = -1;
            goto end;
        }
    }

end:
    free(actual_result);
    return err_code;
}
