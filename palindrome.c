/**
 * @file palindrome.c
 * @brief Program to check if a given string is a palindrome, ignoring non-alphanumeric characters and case.
 *
 * This file contains the implementation of functions to check for palindrome strings
 * and a main function to interact with the user.
 *
 * Author: Akash V
 * Date: July 9, 2025
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* forward declarations *****************************************************/

int isPalindrome(const char *str);
int hasAlnum(const char *str);
int hasDuplicate(const char *str);

/****************************************************************************\
|
|   Function: isPalindrome
|
|   Purpose:    Checks if the given string is a palindrome, ignoring
|               non-alphanumeric characters and case.
|
|   Parameters:
|       str     pointer to the input string
|
|   Returns:
|       1 if the string is a palindrome, 0 otherwise
|
\****************************************************************************/
int isPalindrome(const char *str)
    {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right)
        {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;
        if (tolower(str[left]) != tolower(str[right]))
            return 0;
        left++;
        right--;
        }
    return 1;
    }

/****************************************************************************\
|
|   Function: hasAlnum
|
|   Purpose:    Checks if the given string contains at least one alphanumeric character.
|
|   Parameters:
|       str     pointer to the input string
|
|   Returns:
|       1 if the string contains an alphanumeric character, 0 otherwise
|
\****************************************************************************/
int hasAlnum(const char *str)
    {
    while (*str)
        {
        if (isalnum((unsigned char)*str))
            return 1;
        str++;
        }
    return 0;
    }

/****************************************************************************\
|
|   Function: hasDuplicate
|
|   Purpose:    Checks if the given string contains any duplicate alphanumeric characters,
|               ignoring case and non-alphanumeric characters.
|
|   Parameters:
|       str     pointer to the input string
|
|   Returns:
|       1 if the string contains duplicate alphanumeric characters, 0 otherwise
|
\****************************************************************************/
int hasDuplicate(const char *str)
    {
    int seen[256] = {0};
    while (*str)
        {
        if (isalnum((unsigned char)*str))
            {
            unsigned char ch = (unsigned char)tolower(*str);
            if (seen[ch])
                return 1;
            seen[ch] = 1;
            }
        str++;
        }
    return 0;
    }

/****************************************************************************\
|
|   Function: main
|
|   Purpose:    Main function to read input and check for palindrome.
|
|   Returns:
|       0 on successful execution
|
\****************************************************************************/
int main(void)
    {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    if (!hasAlnum(str))
        {
        printf("The entered string does not contain any alphanumeric characters.\n");
        return 0;
        }

    if (hasDuplicate(str))
        {
        printf("The entered string contains duplicate alphanumeric characters.\n");
        }
    else
        {
        printf("The entered string does not contain duplicate alphanumeric characters.\n");
        }

    if (isPalindrome(str))
        printf("The entered string is a palindrome.\n");
    else
        printf("The entered string is not a palindrome.\n");
    return 0;
    }