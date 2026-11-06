#include <stdio.h>
#include <time.h>

int isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int isValidDate(int d, int m, int y) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y < 1900 || m < 1 || m > 12 || d < 1) return 0;
    if (isLeap(y)) daysInMonth[2] = 29;
    return d <= daysInMonth[m];
}
long countTotalDays(int d, int m, int y) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long total = 0;
    for (int i = 1; i < y; i++) total += isLeap(i) ? 366 : 365;
    if (isLeap(y)) daysInMonth[2] = 29;
    for (int i = 1; i < m; i++) total += daysInMonth[i];
    total += d;
    return total;
}
int main() {
    int dd, mm, yyyy;
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    if (!isValidDate(dd, mm, yyyy)) {
        printf("Invalid Date of Birth entered!\n");
        return 1;
    }
    time_t t = time(NULL);
    struct tm current = *localtime(&t);
    int cur_d = current.tm_mday;
    int cur_m = current.tm_mon + 1;
    int cur_y = current.tm_year + 1900;

    printf("Current System Date: %02d/%02d/%04d\n", cur_d, cur_m, cur_y);

    long days1 = countTotalDays(dd, mm, yyyy);
    long days2 = countTotalDays(cur_d, cur_m, cur_y);

    if (days2 < days1) {
        printf("Error: DOB cannot be in the future!\n");
    } else {
        printf("Total number of days lived: %ld days\n", days2 - days1);
    }
    return 0;
}