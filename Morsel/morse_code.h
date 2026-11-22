#ifndef MORSE_CODE_H
#define MORSE_CODE_H

extern char **morse_table;

int morse_encrypt(char* text);
int morse_decrypt(char* morse);

#endif