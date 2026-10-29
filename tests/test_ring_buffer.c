#include "unity.h"
#include "ring_buffer.h"

static ring_buffer_t rb;

void setUp(void) {
    ring_buffer_init(&rb);
}

void tearDown(void) {}

void test_ring_buffer_init_empty(void) {
    TEST_ASSERT_TRUE(ring_buffer_is_empty(&rb));
    TEST_ASSERT_FALSE(ring_buffer_is_full(&rb));
}

void test_ring_buffer_put_get(void) {
    uint8_t read_val = 0U;
    TEST_ASSERT_TRUE(ring_buffer_put(&rb, 0xA5U));
    TEST_ASSERT_FALSE(ring_buffer_is_empty(&rb));
    TEST_ASSERT_TRUE(ring_buffer_get(&rb, &read_val));
    TEST_ASSERT_EQUAL_HEX8(0xA5U, read_val);
    TEST_ASSERT_TRUE(ring_buffer_is_empty(&rb));
}

void test_ring_buffer_overflow(void) {
    for (uint8_t i = 0U; i < RING_BUFFER_SIZE; i++) {
        TEST_ASSERT_TRUE(ring_buffer_put(&rb, i));
    }
    TEST_ASSERT_TRUE(ring_buffer_is_full(&rb));
    TEST_ASSERT_FALSE(ring_buffer_put(&rb, 0xFFU));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_ring_buffer_init_empty);
    RUN_TEST(test_ring_buffer_put_get);
    RUN_TEST(test_ring_buffer_overflow);
    return UNITY_END();
}