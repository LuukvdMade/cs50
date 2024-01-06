#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("provide 2 arguments\n");
        return 1;
    }

    FILE*input = fopen(argv[1], "r");

    if(input == NULL)
    {
        printf("no valid file\n");
        return 2;
    }

    FILE* output = NULL;

    BYTE buffer[512];

    int jpeg = 0;

    char filename[8];

    while(fread(buffer, sizeof(BYTE)*512, 1, input) == 1)
    {

        if(buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            if(output != NULL)
            {
                fclose(output);
            }
                sprintf(filename, "%03d.jpg", jpeg++);

                output = fopen(filename, "w");
        }

       if(output != NULL)
       {
            fwrite(buffer, sizeof(BYTE)*512, 1, output);
       }
    }


     if (output != NULL)
     {
      fclose(output);
     }

      fclose(input);

    return 0;

}