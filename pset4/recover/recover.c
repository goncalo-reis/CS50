#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Only one command-line argument.");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File cannot be opened.");
        return 2;
    }
    
    typedef uint8_t BYTE;
    BYTE *buffer = malloc(512);
    FILE *img = NULL;
    char *filename = NULL;
    int jpg_count = 0;
    
    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_count != 0)
            {
                fclose(img);
            }
            filename = malloc(8);
            sprintf(filename, "%03i.jpg", jpg_count);
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            jpg_count += 1;
        }
        else if (jpg_count > 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    if (jpg_count > 0)
    {
        free(buffer);
        fclose(img);
        fclose(file);
    }
}
