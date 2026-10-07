#include "marcel/lex/lex.h"
#include <stddef.h>
#include <stdio.h>

static void marcel_lex_iter(
    const char *restrict *previous_word,
    size_t *restrict previous_word_len,
    const char *current_char,
    struct marcel_token *restrict tokens,
    size_t *tokens_len);

void marcel_lex(char *source_code,
    struct marcel_token *restrict tokens,
    size_t *tokens_len)
{
    const char *previous_word = source_code;
    size_t previous_word_len = 0;

    for (char *source_char = source_code;
        *source_char != '\0'; ++source_char) {
        marcel_lex_iter(&previous_word,
            &previous_word_len, source_char,
            tokens, tokens_len);
    }
}

static inline void reset_last_word(
    const char *restrict *previous_word,
    size_t *restrict previous_word_len,
    const char *current_char)
{
    (*previous_word) = current_char;
    (*previous_word_len) = 0;
}

static void marcel_lex_iter(
    const char *restrict *previous_word,
    size_t *restrict previous_word_len,
    const char *current_char,
    struct marcel_token *restrict tokens,
    size_t *tokens_len)
{
    switch (*current_char) {
    case ' ': {
        reset_last_word(previous_word,
            previous_word_len, current_char);
    } break;
    default: {
        ++(*previous_word_len);
    } break;
    }
}