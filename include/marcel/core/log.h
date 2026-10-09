#ifndef MAREX_CORE_LOG_H
#define MAREX_CORE_LOG_H
#define MARCEL_DEBUG 1

#if MARCEL_DEBUG
#define MARCEL_LOG(message, ...)                 \
    printf(message, __VA_ARGS__)
#else
#define MARCEL_LOG(message, ...)
#endif

#endif // MAREX_CORE_LOG_H
