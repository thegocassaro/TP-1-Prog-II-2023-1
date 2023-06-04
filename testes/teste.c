#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char oizinho[10];
    char matheus[10];
    scanf(" %[^\n]\n", oizinho);
    printf("%s\n", oizinho);
    scanf(" %s\n", matheus);
    printf("%s\n", matheus);

    // char* str = "hello";
    // char c = 'z';

    // //printf("%d\n", (int)c );

    // int i = -1;

    // //printf("%d\n", !i);


    // typedef struct cocozinho{
    //     int xuxu;
    //     char ameixa[3];
    // }Coco;

    // Coco* coco = calloc(1, sizeof(Coco));

    // //printf("%d %s\n", coco->xuxu, coco->ameixa);


    // char j = ('0' + 2);
    // //printf("%c\n", j);



    // int k = strlen("oiii");
    // //printf("%d\n", k);


    // int *v = (int*)calloc(3, sizeof(int));
    // for(int i=0; i<3; i++){
    //     printf("%d ", v[i]);
    // }
    // printf("\n");
    // v = (int*)realloc(v, sizeof(int) * 6);
    // for(int i=0; i<6; i++){
    //     printf("%d ", v[i]);
    // }
    // printf("\n");
    // int *g = (int*)malloc(3 * sizeof(int));
    // for(int i=0; i<3; i++){
    //     printf("%d ", g[i]);
    // }
    // printf("\n");
    // g = (int*)realloc(g, sizeof(int) * 6);
    // for(int i=0; i<6; i++){
    //     printf("%d ", g[i]);
    // }

    return 0;
}