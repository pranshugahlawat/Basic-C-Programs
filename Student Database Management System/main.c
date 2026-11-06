#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[30], course[15];
    int sem;
    float marks[5], total, perc;
    char grade;
};
void calc(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->perc = s->total / 5.0;
    if (s->perc >= 80) s->grade = 'A';
    else if (s->perc >= 60) s->grade = 'B';
    else s->grade = 'C';
}
void sortByPerc(struct Student *s, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((s + j)->perc < (s + j + 1)->perc) {
                struct Student temp = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = temp;
            }
        }
    }
}
int main() {
    struct Student *db = NULL;
    int count = 0, choice, r, found;
    FILE *fp;
    do {
        printf("\n1.Insert  2.Display  3.Search/Update  4.Delete  5.Sort  6.Save/Load File  7.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                db = (struct Student *)realloc(db, (count + 1) * sizeof(struct Student));
                if (db == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }
                printf("Enter roll number: ");
                scanf("%d", &db[count].roll);
                printf("Enter name (single word or with spaces): ");
                scanf(" %[^\n]", db[count].name);
                printf("Enter course: ");
                scanf(" %[^\n]", db[count].course);
                printf("Enter semester: ");
                scanf("%d", &db[count].sem);
                printf("Enter marks for 5 subjects:\n");
                for (int i = 0; i < 5; i++) {
                    printf("  Subject %d: ", i + 1);
                    scanf("%f", &db[count].marks[i]);
                }
                calc(&db[count]);
                count++;
                printf("Student record inserted successfully!\n");
                break;
            case 2:
                if (count == 0) {
                    printf("No records found!\n");
                } else {
                    printf("\n--- Student Records ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("Roll: %d | Name: %s | Course: %s | Sem: %d | Total: %.1f | Perc: %.1f%% | Grade: %c\n",
                               db[i].roll, db[i].name, db[i].course, db[i].sem,
                               db[i].total, db[i].perc, db[i].grade);
                    }
                }
                break;
            case 3:
                printf("Enter Roll to Search & Update: ");
                scanf("%d", &r);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (db[i].roll == r) {
                        found = 1;
                        printf("Found %s! Enter new 5 marks:\n", db[i].name);
                        for (int j = 0; j < 5; j++) {
                            printf("  Subject %d: ", j + 1);
                            scanf("%f", &db[i].marks[j]);
                        }
                        calc(&db[i]);
                        printf("Record updated successfully!\n");
                        break;
                    }
                }
                if (!found) printf("Roll number %d not found!\n", r);
                break;
            case 4:
                printf("Enter Roll to Delete: ");
                scanf("%d", &r);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (db[i].roll == r) {
                        found = 1;
                        for (int j = i; j < count - 1; j++) {
                            db[j] = db[j + 1];
                        }
                        count--;
                        if (count > 0) {
                            db = (struct Student *)realloc(db, count * sizeof(struct Student));
                        } else {
                            free(db);
                            db = NULL;
                        }
                        printf("Record deleted successfully.\n");
                        break;
                    }
                }
                if (!found) printf("Roll number %d not found!\n", r);
                break;

            case 5:
                sortByPerc(db, count);
                printf("Records sorted by Percentage!\n");
                break;

            case 6:
                // Save using fwrite()
                fp = fopen("students.dat", "wb");
                if (fp != NULL) {
                    fwrite(db, sizeof(struct Student), count, fp);
                    fclose(fp);
                    printf("Saved %d records to 'students.dat' using fwrite().\n", count);
                }
                // Retrieve using fread()
                fp = fopen("students.dat", "rb");
                if (fp != NULL) {
                    fread(db, sizeof(struct Student), count, fp);
                    fclose(fp);
                    printf("Retrieved %d records from 'students.dat' using fread().\n", count);
                }
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while (choice != 7);

    free(db);
    return 0;
}