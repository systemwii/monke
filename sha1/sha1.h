#pragma once
#pragma GCC visibility push(hidden)

// sha1 hashing is used by the Wii for file integrity checks
// hash size bytes at *ptr and store result in *outbuf (must have size 20)
void SHA1(unsigned char *ptr, unsigned int size, unsigned char *outbuf);

#pragma GCC visibility pop
