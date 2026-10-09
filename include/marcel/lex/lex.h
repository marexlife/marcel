#ifndef MARCEL_LEX_H
#define MARCEL_LEX_H
#include <stddef.h>

struct marcel_token;

void marcel_lex(const char *source_code,
    struct marcel_token **tokens,
    size_t *tokens_len, size_t *tokens_cap);
#endif // MARCEL_LEX_H
