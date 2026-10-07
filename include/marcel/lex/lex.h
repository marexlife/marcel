#ifndef MARCEL_LEX_H
#define MARCEL_LEX_H
#include <stddef.h>

struct marcel_token;

void marcel_lex(char *source_code,
    struct marcel_token *restrict tokens,
    size_t *tokens_len);
#endif // MARCEL_LEX_H
