#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[] )
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n =strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    int plain_char = plaintext[i];
                    int cipher_char = plain_char - 65;
                    int cipher_char_final = ((cipher_char + key)%26+65);
                    char ciphertext = cipher_char_final;
                    printf("%c", ciphertext);
                }

                if (islower(plaintext[i]))
                {
                    int plain_char = plaintext[i];
                    int cipher_char = plain_char - 97;
                    int cipher_char_final = ((cipher_char + key)%26+97);
                    char ciphertext = cipher_char_final;
                    printf("%c", ciphertext);
                }
            }
            else (printf("%c", plaintext[i]));
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

}
