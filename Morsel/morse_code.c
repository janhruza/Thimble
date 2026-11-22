#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "morse_code.h"

char **morse_table = {
    // letters A-Z
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",

    // numbers 0-9
    "-----", ".----", "..---", "...--", "....-", ".....", "-....",
    "--...", "---..", "----."
};

int morse_encrypt(char* text)
{
    // TODO missing implementation
    return 0;
}

int morse_decrypt(char* morse)
{
    // TODO missing implementation
    return 0;
}