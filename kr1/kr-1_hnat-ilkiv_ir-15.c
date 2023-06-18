#include <stdio.h>
#include <math.h>
// Функція 1 шкуає найбілше число по модулю
int function_1(int arr[], int n){
    int max=0;
    for(int i = 0; i < n; i++) {
        if (fabs(max) < fabs(arr[i])) max = arr[i];
    }
    return max;
}
// Функція 2 шукає суму чисел між двома першим і другим додатнім числом
int function_2(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            for(int j = i+1; j < n - i; j++) {
                if (arr[j] > 0) {
                    break;
                }
                else {
                    sum += arr[j];
                }
            }
            break;
        }
    }
    return sum;
};

int main() {
    // Створення масиву  n-кількості елементів
    int n;
    printf("Ведіть кількість елементів в масиві: ");
    scanf("%d", &n);
    int arr[n];
    // Заповнення масиву значеннями
    for ( int i = 0; i < n; i++) {
        printf("Ведіть елемент масиву %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Максимальне число в масиві: %d\n", function_1(arr, n));
    printf("Сума чисел між першим і другим додатнім числом: %d\n", function_2(arr, n));
    
    return 0;
}
