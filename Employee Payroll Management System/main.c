#include <stdio.h>

enum Department { HR, IT, FINANCE, ADMIN };

struct Date { int d, m, y; };
struct Address { char city[20]; int pin; };

union ID {
    char passport[15];
    char license[15];
};

struct Status {
    unsigned int isPermanent : 1;
    unsigned int isActive : 1;
    unsigned int onLeave : 1;
};

struct Employee {
    int empId;
    char name[20];
    enum Department dept;
    float basic, allowance, gross, deduction, net;
    struct Date joinDate;
    struct Address addr;
    union ID idDetail;
    struct Status stat;
};

void calculatePay(struct Employee *e) {
    e->gross = e->basic + e->allowance;
    e->deduction = e->basic * 0.10; // 10% tax/PF
    e->net = e->gross - e->deduction;
}

int main() {
    struct Employee emp[2] = {
        {101, "Amit", IT, 50000, 10000, 0, 0, 0, {12, 5, 2022}, {"Delhi", 110001}, {"P1234567"}, {1, 1, 0}},
        {102, "Neha", HR, 40000, 8000, 0, 0, 0, {1, 8, 2023}, {"Noida", 201301}, {"DL987654"}, {0, 1, 1}}
    };

    const char *deptNames[] = {"HR", "IT", "FINANCE", "ADMIN"};

    printf("--- DEPARTMENT-WISE PAYROLL REPORT ---\n");
    for (int i = 0; i < 2; i++) {
        struct Employee *ptr = &emp[i];
        calculatePay(ptr);
        printf("ID: %d | Name: %s | Dept: %s | Joined: %02d/%02d/%d | City: %s\n",
               ptr->empId, ptr->name, deptNames[ptr->dept], ptr->joinDate.d, ptr->joinDate.m, ptr->joinDate.y, ptr->addr.city);
        printf("Gross: %.2f | Ded: %.2f | Net Salary: %.2f | Perm: %d | Active: %d\n\n",
               ptr->gross, ptr->deduction, ptr->net, ptr->stat.isPermanent, ptr->stat.isActive);
    }

    printf("--- MEMORY COMPARISON ---\n");
    printf("Size of Employee Structure: %lu bytes (Sum of all members + structure padding)\n", sizeof(struct Employee));
    printf("Size of ID Union: %lu bytes (Size of largest member only)\n", sizeof(union ID));
    printf("Size of Bit-field Status: %lu bytes (Compressed into single integer unit)\n", sizeof(struct Status));
    return 0;
}