#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <ctype.h>

const int COUNT = 1;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int sum = 0;
        for (int i = 0, n = strlen(argv[COUNT]); i < n; i++)
        {
            int c = (int) argv[COUNT][i];
            if (!(isalnum(c)))
            {
                printf("Usage: ./crack hash\n");
                return 1;
            }
        }
        char salt[3]  = {argv[COUNT][0], argv[COUNT][1], '\0'};
        printf("Salt: %s\n", salt); 
        char key[6] = {'A', '\0', '\0', '\0', '\0', '\0'};
        char *password = "AB";
        printf("Key: %s\n", key); 
        for (int i = 0, j = 0, k = 0, l = 0, m = 0, z = 0; m < 53;)
        {
            if (i == 26)
            {
                key[z] = 'a';
            }
            if (j == 26)
            {
                key[z - 1] = 'a';
            }
            if (k == 26)
            {
                key[z - 2] = 'a';
            }
            if (l == 26)
            {
                key[z - 3] = 'a';
            }
            if (m == 26)
            {
                key[z - 3] = 'a';
            }
            if (i == 52)
            {
                i = 0;
                key[z] = 'A';
                if (key[1] == '\0')
                {
                    key[1] = 'A';
                    z += 1;
                }
                else
                {
                    key[z - 1] += 1;
                }
                j += 1;
            }
            if (j == 52)
            {
                j = 0;
                key[z] = 'A';
                key[z - 1] = 'A';
                if (key[2] == '\0')
                {
                    key[2] = 'A';
                    z += 1;
                }
                else
                {
                    key[z - 2] += 1;
                }
                k += 1;
            }
            if (k == 52)
            {
                k = 0;
                key[z] = 'A';
                key[z - 1] = 'A';
                key[z - 2] = 'A';
                if (key[3] == '\0')
                {
                    key[3] = 'A';
                    z += 1;
                }
                else
                {
                    key[z - 3] += 1;
                }
                l += 1;
            }
            if (l == 52)
            {
                l = 0;
                key[z] = 'A';
                key[z - 1] = 'A';
                key[z - 2] = 'A';
                key[z - 3] = 'A';
                if (key[4] == '\0')
                {
                    key[4] = 'A';
                    z += 1;
                }
                else
                {
                    key[z - 4] += 1;
                }
                m += 1;
            }
            int ret = strcmp(crypt(key, salt), argv[COUNT]);
            if (ret == 0)
            {
                printf("%s\n", key);
                return 0;
            }
            else
            {
                key[z] += 1;
                i += 1;
                
            }
        }
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
}
