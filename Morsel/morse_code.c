#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "morse_code.h"

static const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

static const char *morse[] = {
    ".-",    "-...",  "-.-.",  "-..",   ".",     "..-.",  "--.",   "....",
    "..",    ".---",  "-.-",   ".-..",  "--",    "-.",    "---",   ".--.",
    "--.-",  ".-.",   "...",   "-",     "..-",   "...-",  ".--",   "-..-",
    "-.--",  "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.",
};

// Helper method
const char *to_morse(char c)
{
    c = toupper(c);

    if (c == 32)
    {
        return "/";
    }

    const char *p = strchr(symbols, c);
    return p ? morse[p - symbols] : NULL;
}

char from_morse(const char *code)
{
    if (strcmp(code, "/") == 0)
    {
        // '/' represents a space
        return 32;
    }

    for (int i = 0; i < 36; i++) {
        if (strcmp(morse[i], code) == 0)
            return symbols[i];
    }

    return '\0';
}

int morse_encrypt(char* text)
{
    int count = 0;
    int size = strlen(text);

    for (int i = 0; i < size; i++)
    {
        char c = text[i];
        const char* value = to_morse(c);
        if (value == NULL) continue;

        printf((i == 0 ? "%s" : " %s"), value);
        count++;
    }

    printf("\n");
    return count;
}

int morse_decrypt(char *morse)
{
    int count = 0;
    char *token = strtok(morse, " ");

    while (token != NULL) {
        putchar(from_morse(token));
        count++;
        token = strtok(NULL, " ");
    }

    printf("\n");
    return count;
}