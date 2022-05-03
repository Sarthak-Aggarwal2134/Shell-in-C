#include "allheaders.h"

void pwd()
{
    //char add_curd[10000];
    char* add_curd =(char*)calloc(10000,sizeof(char));

    getcwd(add_curd,10000);
    printf("%s",add_curd);
    printf("\n");
}
