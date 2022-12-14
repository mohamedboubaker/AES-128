#ifndef SRC_AES_H_
#define SRC_AES_H_
#include <stdint.h>

/**
 *  @brief encrypt_file_aes128 encrypts files using aes128 standard
 *  @param FILE * plain_file is the file that will be encrypted
 *  @param FILE * encrypted_file is the encrypted output file
 *  @param char * key is the encryption key. Length must be from 1 to 16 Bytes
 *  if the key length is less than 16, zeros padding is added.
 */
int encrypt_file_aes128(FILE * plain_file, FILE * encrypted_file, char * key);

/**
 * @brief aes128 encrypts a block of 16 bytes (128 bits)
 * @param uint8_t plaintext[16] is the input block to be encrypted
 * @param uint8_t cyphertext[16] is the encrypted output
 * @param uint8_t key[16] is the encryption key.
 * @return 0 in case of success, 1 otherwise
 */
uint8_t aes128(uint8_t plaintext[16], uint8_t cyphertext[16], uint8_t key[16]);

/**
 * @brief s is a transformation that maps an 8-bit input, c, to an 8-bit output according to the S-Box.
 * the S-Box is a lookup table that represents the The Rijndael substitution box.
 * @param c is the input
 * @return s returns the transformation value
 */
uint8_t s(uint8_t c);

/**
 * @brief shift_rows does a circular left shift on the rows of the input 4x4 matrix.
 * 	1st row is not shifted, 2nd row is shifted 1 element, 3d row is shifted 2 elements, 4th row is shifted 3 elements.
 * @param uint8_t block[16] The 16 bytes length input is regarded as a 4x4 matrix. The rows of this matrix will be shifted as described in the brief section.
 */
void shift_rows(uint8_t block[16]);


/**
 * @brief expand_key generates the next key in the key schedule
 * @param uint8_t previous_key[16] is the starting key
 * @param uint8_t next_key[16] is the newly generated key from the previous_key
 * @param uint8_t round is the round number in the AES algorithm. values = 1-10
 *
 */
void expand_key(uint8_t previous_key[16],uint8_t next_key[16],uint8_t round);

#endif /* SRC_AES_H_ */
