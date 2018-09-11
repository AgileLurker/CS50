#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Getting user input
    long long cc_number = get_long_long("input your credit card to be verified: ");

    //Checking the length of the credit card
    //Divider for each cases to determine their card types
    long long divider_16 = pow(10, 15);
    long long divider_16_2nd = pow(10, 14);
    long long divider_15 = pow(10, 14);
    long long divider_15_2nd = pow(10, 13);
    long long divider_13 = pow(10, 12);
    long long divider_13_2nd = pow(10, 11);

    //taking 2 first digit of each cards to determine their card types
    long long card_16dgt = (cc_number/divider_16)*10+(cc_number/divider_16_2nd)%10;
    long long card_15dgt = (cc_number/divider_15)*10+(cc_number/divider_15_2nd)%10;
    long long card_13dgt = (cc_number/divider_13)*10+(cc_number/divider_13_2nd)%10;

    //Second digit for the 16 digit card
    int second_digit_16 = card_16dgt%10;
    //Second digit for the 15 digit card
    int second_digit_15 = card_15dgt%10;
    //I didn't need the second digit for the 13 digit card since it's visa and all visa uses the first digit as identifier

    //Checking if it's master card or visa based on the credit card length (16)
    if (card_16dgt/10 == 5 || card_16dgt/10 == 4)
    {
        long long checksum = 0;
        long long divider_loop = 10;

        for (int i = 0; i < 16; i++)
        {
            //Getting the number from card
            if (i%2 == 0)
            {
                checksum = checksum + cc_number%divider_loop;
                cc_number = cc_number/10;
            }
            else if (i%2 == 1)
            {
                int digit_holder = cc_number%divider_loop*2;
                int last_of_digit_holder = digit_holder%10;
                int first_digit_holder = digit_holder/10;
                checksum = checksum + last_of_digit_holder + first_digit_holder;
                cc_number = cc_number/10;
            }
        }

        if (card_16dgt/10 == 5 && checksum%10 == 0)
        {

            switch (second_digit_16)
            {
                case 1 :
                    printf("MASTERCARD\n");
                    break;
                case 2 :
                    printf("MASTERCARD\n");
                    break;
                case 3 :
                    printf("MASTERCARD\n");
                    break;
                case 4 :
                    printf("MASTERCARD\n");
                    break;
                case 5 :
                    printf("MASTERCARD\n");
                    break;
                default:
                    printf("INVALID\n");
            }
        }

        else if(card_16dgt/10 == 4 && checksum%10 == 0)
        {
            printf("VISA\n");
        }
        else (printf("INVALID\n"));
    }

    //Checking if it's AMEX based on credit card length 15
    else if (card_15dgt/10 == 3)
    {
        long long checksum = 0;
        long long divider_loop = 10;

        for (int i = 0; i < 15; i++)
        {
            //Getting the number from card
            if (i%2 == 0)
            {
                checksum = checksum + cc_number%divider_loop;
                cc_number = cc_number/10;
            }
            else if (i%2 == 1)
            {
                int digit_holder = cc_number%divider_loop*2;
                int last_of_digit_holder = digit_holder%10;
                int first_digit_holder = digit_holder/10;
                checksum = checksum + last_of_digit_holder + first_digit_holder;
                cc_number = cc_number/10;
            }
        }

        if (card_15dgt/10 == 3 && checksum%10 == 0)
        {

            switch (second_digit_15)
            {
                case 4 :
                    printf("AMEX\n");
                    break;
                case 7 :
                    printf("AMEX\n");
                    break;
                default:
                    printf("INVALID\n");
            }
        }
    }

    //Checking if the card is VISA that have 13 digits
    else if (card_13dgt/10 == 4)
    {
        long long checksum = 0;
        long long divider_loop = 10;

        for (int i = 0; i < 13; i++)
        {
            //Getting the number from card
            if (i%2 == 0)
            {
                checksum = checksum + cc_number%divider_loop;
                cc_number = cc_number/10;
            }
            else if (i%2 == 1)
            {
                int digit_holder = cc_number%divider_loop*2;
                int last_of_digit_holder = digit_holder%10;
                int first_digit_holder = digit_holder/10;
                checksum = checksum + last_of_digit_holder + first_digit_holder;
                cc_number = cc_number/10;
            }
        }

        if (card_13dgt/10 == 4 && checksum%10 == 0)
        {
            printf("VISA\n");
        }
        else (printf("INVALID\n"));
    }
    else (printf("INVALID\n"));
}
