#ifndef _SHA1_H_
#define _SHA1_H_

// sha1 hashing is used by the Wii for file integrity checks
// hash size bytes at *ptr and store result in *outbuf (must have size 20)
void SHA1(unsigned char *ptr, unsigned int size, unsigned char *outbuf);

#endif
