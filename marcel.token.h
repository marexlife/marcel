#ifndef MARCEL_TOKEN_H
#define MARCEL_TOKEN_H
#include <stdint.h>

enum marcel_token_tag {
    marcel_token_tag_number,
    marcel_token_tag_indent,
    marcel_token_tag_print,
};

union marcel_token_storage {
    char *lexeme;
    int32_t number;
    void *none;
};

struct marcel_token {
    enum marcel_token_tag token_tag;
    union marcel_token_storage token_storage;
};
#endif // MARCEL_TOKEN_H
