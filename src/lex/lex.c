#include "marcel/lex/lex.h"
#include "marcel/lex/token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const size_t token_grow = 10;

static void lex_iter(const char **last_word,
    size_t *last_word_len,
    const char *current_char,
    struct marcel_token **tokens,
    size_t *tokens_len, size_t *tokens_cap);

void marcel_lex(const char *source_code,
    struct marcel_token **tokens,
    size_t *tokens_len, size_t *tokens_cap)
{
    const char *last_word = source_code;
    size_t previous_word_len = 0;

    for (const char *source_char = source_code;
        *source_char != '\0'; ++source_char) {
        lex_iter(&last_word, &previous_word_len,
            source_char, tokens, tokens_len,
            tokens_cap);
    }
}

static inline void reset_last_word(
    const char **previous_word,
    size_t *previous_word_len,
    const char *current_char)
{
    (*previous_word) = current_char;
    (*previous_word_len) = 0;
}

static void push_token(
    struct marcel_token **tokens,
    size_t *tokens_len, size_t *tokens_cap,
    const char **last_word, size_t last_word_len);

static void lex_iter(const char **last_word,
    size_t *last_word_len,
    const char *current_char,
    struct marcel_token **tokens,
    size_t *tokens_len, size_t *tokens_cap)
{
    switch (*current_char) {
    case ' ':
        push_token(tokens, tokens_len, tokens_cap,
            last_word, *last_word_len);

        reset_last_word(last_word, last_word_len,
            current_char);
        break;
    default:
        ++*last_word_len;
        break;
    }
}

static void push_token(
    struct marcel_token **tokens,
    size_t *tokens_len, size_t *tokens_cap,
    const char **last_word, size_t last_word_len)
{
    ++*tokens_len;

    if (*tokens_cap <= *tokens_len) {
        *tokens_cap *= token_grow;
        *tokens = realloc(tokens, *tokens_cap);
    }

    const char print_comp[] = "print";

    const size_t print_comp_len
        = sizeof(print_comp);

    if (strncmp(*last_word, print_comp,
            last_word_len | print_comp_len)) {
        (*tokens)[*tokens_len].token_tag
            = marcel_token_tag_print;

        return;
    }

    (*tokens)[*tokens_len]
        .token_storage.lexeme.chars = *last_word;
    (*tokens)[*tokens_len].token_tag
        = marcel_token_tag_indent;
}