#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RING_BUFFER_SIZE 16U

typedef struct {
    uint8_t buffer[RING_BUFFER_SIZE];
    size_t head;
    size_t tail;
    size_t count;
} ring_buffer_t;

void ring_buffer_init(ring_buffer_t *rb);
bool ring_buffer_put(ring_buffer_t *rb, uint8_t data);
bool ring_buffer_get(ring_buffer_t *rb, uint8_t *data);
bool ring_buffer_is_full(const ring_buffer_t *rb);
bool ring_buffer_is_empty(const ring_buffer_t *rb);

#endif /* RING_BUFFER_H */