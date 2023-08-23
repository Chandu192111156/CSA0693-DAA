#include <stdio.h>
#include <string.h>


void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
       
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        
        start++;
        end--;
    }
}

int main() {
    char str[100]; 

    printf("Enter a string: ");
    scanf("%[^\n]%*c", str); 

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

