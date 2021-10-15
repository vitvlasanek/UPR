#include <stdio.h>

int compute_grade( int points ) {
    int grade = 4;

    if ( points > 85 ) {
        grade = 1;
    } else if ( points > 65 ) {
        grade = 2;
    } else if ( points > 50 ) {
        grade = 3;
    } else {
        grade = 4;
    }

    return grade;
}

int main(){
    int x;
    while (scanf("%d", &x) == 1){
        if (x < 0){
            break;
        }
        else if (x > 100){
            printf("NA\n");
        }
        else{
        printf("%d\n", compute_grade(x));
        }
    return 0;
}   