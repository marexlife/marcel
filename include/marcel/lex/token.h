#ifndef MARCEL_TOKEN_H
#define MARCEL_TOKEN_H
#include <stddef.h>
#include <stdint.h>

struct marcel_str {
    const char *chars;
    size_t len;
};

enum marcel_token_tag {
    marcel_token_tag_number,
    marcel_token_tag_indent,
    marcel_token_tag_print,
};

union marcel_token_storage {
    struct marcel_str lexeme;
    int32_t number;
    void *none;
};

struct marcel_token {
    enum marcel_token_tag tag;
    union marcel_token_storage storage;
};

char *marcel_token_tag_str(enum marcel_token_tag tag);
#endif // MARCEL_TOKEN_H
