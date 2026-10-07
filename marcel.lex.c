#include "marcel.lex.h"
#include <stddef.h>
#include <stdio.h>

void marcel_lex_iter(
    const char *restrict *previous_word,
    size_t *restrict previous_word_len,
    const char *current_char);

void marcel_lex(char *source_code)
{
    const char *previous_word = source_code;
    size_t previous_word_len = 0;

    for (char *source_char = source_code;
        *source_char != '\0'; ++source_char) {
        marcel_lex_iter(&previous_word,
            &previous_word_len, source_char);
    }
}

void marcel_lex_iter(
    const char *restrict *previous_word,
    size_t *restrict previous_word_len,
    const char *current_char)
{
    switch (*current_char) {
    case ' ': {
        (*previous_word) = current_char;
        (*previous_word_len) = 0;
    } break;
    default: {
        ++(*previous_word_len);
    } break;
    }
}