//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
//* Modul : 03 - SRUCTURES
//* Hari dan Tanggal : Senin, 27 April 2026
//* Nama (NIM) : Hasan Al Mutawakkil (13224080)
//* Nama File : PMP_03.c
//* Deskripsi : Melakukan SORTING sensor badai dinamis


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *temp = NULL;
    int input;
    int length = 0;

    while (1) {
        scanf("%d", &input);
        
        if (input == -1) {
            break; 
        }

        temp = (int *) realloc(temp, (length + 1) * sizeof(int));
        
        if (temp == NULL) {
            printf("Gagal\n");
            return 1;
        }

        temp[length] = input;
        length++;
    }
    
    if (length > 0) {
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (temp[j] < temp[i]) {
                    int temp3 = temp[i];
                    temp[i] = temp[j];
                    temp[j] = temp3;
                }
            }
        }
        
        printf("COUNT %d", length);
        printf(" SORTED");
        for (int i = 0; i < length; i++) {
            printf(" %d", temp[i]);
        }

        
        if (length % 2 != 0) {
            printf(" MEDIAN %d", temp[length / 2]);
        } else {
            int median = temp[(length / 2) - 1];
            int median2 = temp[length / 2];
            float tot = median + median2;
            
            if ((median +median2) %2 == 1) {
                printf(" MEDIAN %.2f", tot / 2.0);
            } else {
                printf(" MEDIAN %.2f", tot / 2);
            }


        }
    }
    



    free(temp);
    
    return 0;
}
