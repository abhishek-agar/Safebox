/**
 * @file safebox.c
 *
 * @author Abhishek Agarwal
 * @brief Safe Box - A Reverse Engineering challenge which involves
 * finding the key by decrypting a pre-key & bypassing anti-debugging technique.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

static const int key_length = 22;

/**
 * XOR key for decryption.
 */
static const int decryption_key[] = {
    0x4b, 0x0d, 0x0d, 0x39, 0x5f, 0x0c, 0x58, 0x6c, 0x27, 0x0d, 0x7b,
    0x28, 0x42, 0x1e, 0x29, 0x55, 0x77, 0x62, 0x6d, 0x41, 0x7d, 0x00};
/**
 * Failure message to be printed when the challenge is not solved.
 */
static const char failure_message[] =
    "\nOops! Seems like you have got the wrong key. Must be an honest mistake.\nYou can try again if you would like to.\n";

/**
 * @brief Checks if the program is being debugged.
 * @return True if the program is being debugged, False otherwise.
 */
bool is_being_debugged()
{
    if (ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1)
    {
        return true;
    }
    return false;
}

/**
 * @brief Prints the failure message and exits.
 * This function is called when the challenge is not solved.
 */
void error_exit()
{
    printf(failure_message);
    exit(1);
}

/**
 * @brief Builds the pre-key.
 * The pre-key is used to check the entered key.
 * @return Pre-key.
 */
char *build_pre_key()
{

    char *encrypted_key = (char *)malloc(key_length + 1);

    encrypted_key[0] = '[';
    encrypted_key[1] = 'U';
    encrypted_key[2] = 'I';
    encrypted_key[3] = 'k';
    encrypted_key[4] = '4';
    encrypted_key[5] = 'E';
    encrypted_key[6] = '`';
    encrypted_key[7] = encrypted_key[1];
    encrypted_key[8] = 'B';
    encrypted_key[9] = 'O';
    encrypted_key[10] = encrypted_key[4];
    encrypted_key[11] = 'u';
    encrypted_key[12] = 's';
    encrypted_key[13] = encrypted_key[8];
    encrypted_key[14] = encrypted_key[11];
    encrypted_key[15] = 'd';
    encrypted_key[16] = encrypted_key[9];
    encrypted_key[17] = '[';
    encrypted_key[18] = '3';
    encrypted_key[19] = encrypted_key[14];
    encrypted_key[20] = encrypted_key[2];
    encrypted_key[21] = 'm';

    return encrypted_key;
}

/**
 * @brief Checks if the entered key is correct.
 * @param input Key entered by the user.
 * @param encrypted_key Pre-key.
 * @return True if the key is correct, False otherwise.
 */
void checkKey(char *input, char *encrypted_key)
{

    // Check input length
    int input_length = strlen(input);
    if (input_length != key_length)
    {
        error_exit();
    }

    // Check input characters
    for (int i = 0; i < input_length; i++)
    {
        if (input[i] != (char)(0x10 ^ encrypted_key[i]))
        {
            error_exit();
        }
    }
}

/**
 * @brief Prints the flag.
 * @param flag The key used to retrieve the flag.
 */
void printFlag(char *key)
{

    char *flag = (char *)malloc(key_length + 1);
    if (!flag)
    {
        exit(1);
    }

    printf("\nThere you go. Pleasure doing business with you.\n");
    flag[key_length] = '\0';
    for (int i = 0; i < key_length; i++)
    {
        flag[i] = key[i] ^ decryption_key[i];
        printf("%c", flag[i]);
    }

    printf("\n\n");
    free(flag);
}

int main(void)
{

    // Input
    char key[key_length + 1];

    puts(" ______________ \n"
         "|  __________  |\n"
         "| |          | |\n"
         "| | Safe Box | |\n"
         "| |__________| |\n"
         "|______________|\n");

    printf("Welcome! valued customer. What a good day to make a withdrawl indeed!\n");
    printf("To access your box, please enter your key: ");
    scanf("%s", key);

    // Check for debugging
    if (is_being_debugged())
    {
        error_exit();
    }

    // Build key
    char *encrypted_key = build_pre_key();

    // Check Key
    checkKey(key, encrypted_key);

    // Print Flag
    printFlag(key);

    // Deallocate memory
    free(encrypted_key);

    return 0;
}