#include "allheaders.h"
void repeat(char * input_str){
    // printf("%s", input_str);
    char* str = (char*)malloc(sizeof(char)*strlen(input_str));
    for(int i = 0; i + 7 < strlen(input_str); i++){
        str[i] = input_str[i+7];
    }
    str[strlen(input_str)-7] = '\0';
    // printf("%s\n", str);
   char* str1 = (char*)malloc(sizeof(char)*strlen(input_str));
   char* str2 = (char*)malloc(sizeof(char)*strlen(input_str));
   int i = 0;
   for(i=0;; i++){
       if(str[i] != ' '){
        str1[i] = str[i];
       } else{
           break;
       }
   }
    str1[i] = '\0';
    // printf("%s\n", str1);
    i++;
    int count=atoi(str1);
    //97 -- 122
    int start=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='a' && str[i]<='z'){break;}
        else{
            start++;
        }
    }
    int len=strlen(str)-start;
    //printf("%d\n",len);
    char str5[len+1];
    for(int i=0;i<len;i++){
        str5[i]=str[start+i];
        //printf("%c\n",str5[i]);
    }
    // printf("%s\n", str5);
    char string[1000];
    // int count = atoi(str1);
    // printf("\ncount = %d\n", count);
    char * add_root;
    char str6[len+1];
    while(count--){
        getcwd(add_root,10000);
        // printf("str = %s\n",str5);
        strcpy(str6,str5);
        command_selector(str6, add_root);
        
    }
}