#include "greatest.h"
#include "../libcrc32.h"
GREATEST_MAIN_DEFS();

TEST test_basic_hash_returns_correct_value(void);
TEST test_additional_hashes(void);
TEST test_different_arrangements_of_word_returns_different_results(void);
TEST test_streaming_crc32(void);

int main(int argc, char** argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_TEST(test_basic_hash_returns_correct_value);
    RUN_TEST(test_additional_hashes);
    RUN_TEST(test_different_arrangements_of_word_returns_different_results);
    RUN_TEST(test_streaming_crc32);
    GREATEST_MAIN_END();
}

TEST test_streaming_crc32(void)
{
    const char* data = "abc";
    ASSERT_EQ(0x00000000, crc32_stream(data + 0, 1));
    ASSERT_EQ(0x00000000, crc32_stream(data + 1, 1));
    ASSERT_EQ(0x00000000, crc32_stream(data + 2, 1));
    ASSERT_EQ(0x352441C2, crc32_stream(NULL, 0));

    // buffer is reset.
    ASSERT_EQ(0x00000000, crc32_stream(NULL, 0));
    PASS();
}
TEST test_different_arrangements_of_word_returns_different_results(void)
{
    ASSERT_NEQ(crc32("abc", 3), crc32("bac", 3));
    ASSERT_NEQ(crc32("bac", 3), crc32("cba", 3));
    PASS();
}
TEST test_basic_hash_returns_correct_value(void)
{
    ASSERT_EQ(0xCBF43926, crc32("123456789", 9));
    ASSERT_EQ(0x00000000, crc32("", 0));
    ASSERT_EQ(0xE8B7BE43, crc32("a", 1));
    PASS();
}
TEST test_additional_hashes(void)
{
    ASSERT_EQ(0x352441C2, crc32("abc", 3));
    ASSERT_EQ(0x20159D7F, crc32("message digest", 14));
    ASSERT_EQ(0x414FA339, crc32("The quick brown fox jumps over the lazy dog", 43));
    ASSERT_EQ(0x519025E9, crc32("The quick brown fox jumps over the lazy dog.", 44));
    ASSERT_EQ(0xABF77822, crc32("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26));
    PASS();
}
