#include <stdio.h>
#include <stdlib.h>

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
            int mid1 = temp[(length / 2) - 1];
            int mid2 = temp[length / 2];
            int sum = mid1 + mid2;
            
            if (sum % 2 != 0) {
                printf("MEDIAN %.2f", sum / 2.0);
            } else {
                printf("MEDIAN %d", sum / 2);
            }
        }
    }
    
    free(temp);
    
    return 0;
}
