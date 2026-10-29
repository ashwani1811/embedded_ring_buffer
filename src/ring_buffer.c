#include "ring_buffer.h"

void ring_buffer_init(ring_buffer_t *rb) {
    if (rb != NULL) {
        rb->head = 0U;
        rb->tail = 0U;
        rb->count = 0U;
    }
}

bool ring_buffer_is_full(const ring_buffer_t *rb) {
    return (rb != NULL) && (rb->count >= RING_BUFFER_SIZE);
}

bool ring_buffer_is_empty(const ring_buffer_t *rb) {
    return (rb == NULL) || (rb->count == 0U);
}

bool ring_buffer_put(ring_buffer_t *rb, uint8_t data) {
    bool status = false;
    if ((rb != NULL) && !ring_buffer_is_full(rb)) {
        rb->buffer[rb->head] = data;
        rb->head = (rb->head + 1U) % RING_BUFFER_SIZE;
        rb->count++;
        status = true;
    }
    return status;
}

bool ring_buffer_get(ring_buffer_t *rb, uint8_t *data) {
    bool status = false;
    if ((rb != NULL) && (data != NULL) && !ring_buffer_is_empty(rb)) {
        *data = rb->buffer[rb->tail];
        rb->tail = (rb->tail + 1U) % RING_BUFFER_SIZE;
        rb->count--;
        status = true;
    }
    return status;
}


