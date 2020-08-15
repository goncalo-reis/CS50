#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    char cypher[26];
    // only 2 arguments
    if (argc == 2)
    {
        //exactly 26 characters
        int n = strlen(argv[1]);
        if (n != 26)
        {
            printf("Please enter precisely 26 characters.\n");
            return 1;
        }
        // get all upper case
        for (int i = 0; i < n; i++)
        {
            cypher[i] = toupper(argv[1][i]);
        }
        // Get only characters
        for (int i = 0; i < n; i++)
        {
            if (cypher[i] >= 'A' && cypher[i] <= 'Z')
            {
                
            }
            else
            {
                printf("Invalid characters.");
                return 1;
            }
        }
        // get all different characters
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (cypher[i] == cypher[i + j + 1])
                {
                    printf("Please do not repeat characters.\n");
                    return 1;
                }
            }
           
        }
    }
    else
    {
        printf("Please enter precisely 2 arguments.\n");
        return 1;
    }

    string input_s = get_string("plaintext: ");
    int m = strlen(input_s);
    char input[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = input_s[i];
    }
    char output[m];
    char alphabet[26];
    
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = 'A' + i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int j = 0;
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            while (input[i] != tolower(alphabet[j]))
            {
                j++;
            }
            output[i] = tolower(cypher[j]);
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            while (input[i] != alphabet[j])
            {
                j++;
            }
            output[i] = (cypher[j]);
        }
        else
        {
            output[i] = input[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < m; i++)
    {
        printf("%c", output[i]);
    }
    printf("\n");
}