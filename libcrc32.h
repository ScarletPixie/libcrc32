#ifndef LIB_CRC_32_H
#define LIB_CRC_32_H

///@brief Calculates CRC-32 checksum.
///param data The raw bytes to be calculated.
///param size The size of `data`.
///note `data` must not be NULL.
///return Returns a value between 0 and the maximum number for an unsigned 32bit integer.
unsigned long crc32(const char* data, unsigned long size);

///@brief Calculates CEC-32 checksum by parts.
///param data The current data as raw bytes to he calculated.
///param size The number of bytes in `data`. If 0 is passed, the current crc32 value is returned.
///return Returns a valid CRC-32 value when `size` is 0 or returns 0 while `size` is not 0.
///note If `size` is 0, `data` can be passed as NULL.
///note This function is NOT thread or reentrant safe.
unsigned long crc32_stream(const char* data, unsigned long size);

#endif
