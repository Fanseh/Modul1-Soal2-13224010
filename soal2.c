//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2026/2027
// *   Modul               : 1
// *   Hari dan Tanggal    : Rabu, 4 November 2026
// *   Nama (NIM)          : Hezkiel Tarutung Harianja (13224010)
// *   Nama File           : soal2_modul1_sem5.c
// *   Deskripsi           : Program Space Station 
// * 
// */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
typedef struct Space {
    int idx;
    char K2[100];
} Space;
//fungsi buat reverse character di string
void reverse(char str[]){
    size_t left = 0;
    size_t right = strlen(str);
    while (left < right){
        right--;
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
    }
}
//fungsi biar bisa buat fungsi sorting ascending
void swap(Space *a, Space *b) {
    Space temp = *a;
    *a = *b;
    *b = temp;
}
//fungsi sorting ascending
void sorting(Space paket[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (paket[i].idx > paket[j].idx) {
                swap(&paket[i], &paket[j]);
            }
        }
    }
}
int main() {
    int N;
    char K[100];
    scanf("%d %99s", &N, K);
    Space *paket = malloc(N * sizeof(Space));
    if (paket == NULL) {
        return 1;
    }
    int total_valid = 0;
    for (int i = 0; i < N; i++) {
        int idx;
        char key[100];
        char K2[100];
        if (scanf("%d %99s %99s", &idx, key, K2) != 3) {
        break;
        }
        if (strcmp(key, K) == 0) {
            paket[total_valid].idx = idx;
            strcpy(paket[total_valid].K2, K2);
            reverse(paket[total_valid].K2);
            total_valid++;
        }
    }
    if (total_valid == 0) {
        printf("000\n");
        free(paket);
        return 0;
    }
    sorting(paket, total_valid);
    int total_char = 0;
    for (int i = 0; i < total_valid; i++) {
        printf("%s", paket[i].K2);
        total_char += strlen(paket[i].K2);
        if (i < total_valid - 1) {
            printf(" ");
        }
    }
    printf("\nLENGTH %d\n", total_char);
    free(paket);
    return 0;
}
//Reference: 
//1. https://www.geeksforgeeks.org/c/reverse-string-in-c/
//2. https://www.geeksforgeeks.org/c/c-program-to-find-the-length-of-a-string/
//3. https://www.geeksforgeeks.org/c/pattern-matching-in-a-string-in-c/
//4. https://www.geeksforgeeks.org/c/scansets-in-c/
//5. https://www.geeksforgeeks.org/c/structures-c/
//6. https://stackoverflow.com/questions/46592887/swapping-two-structures-in-c
//7. https://www.geeksforgeeks.org/dsa/sorting-algorithms/
//8. https://www.geeksforgeeks.org/c/string-functions-in-c/
//9. https://www.geeksforgeeks.org/c/strings-in-c/


