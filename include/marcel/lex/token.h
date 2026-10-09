#ifndef MARCEL_TOKEN_H
#define MARCEL_TOKEN_H
#include <stddef.h>
#include <stdint.h>

struct str {
    const char *chars;
    size_t len;
};

enum marcel_token_tag {
    marcel_token_tag_number,
    marcel_token_tag_indent,
    marcel_token_tag_print,
};

union marcel_token_storage {
    struct str lexeme;
    int32_t number;
    void *none;
};

struct marcel_token {
    enum marcel_token_tag token_tag;
    union marcel_token_storage token_storage;
};
#endif // MARCEL_TOKEN_H
