#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机数
int generateRandomNumber(int max) {
    return rand() % max + 1;
}

// 生成一年级题目：加法和减法，结果小于20
void generateFirstGradeQuestions(int num) {
    for (int i = 0; i < num; i++) {
        int a = generateRandomNumber(20);
        int b = generateRandomNumber(20);
        int op = rand() % 2; // 0为加法，1为减法
        if (op == 0) {
            printf("%d + %d = \n", a, b);
        } else {
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            printf("%d - %d = \n", a, b);
        }
    }
}

// 生成二年级题目：加法、减法混合，结果小于50
void generateSecondGradeQuestions(int num) {
    for (int i = 0; i < num; i++) {
        int a = generateRandomNumber(50);
        int b = generateRandomNumber(50);
        int op = rand() % 2; // 0为加法，1为减法
        if (op == 0) {
            printf("%d + %d = \n", a, b);
        } else {
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            printf("%d - %d = \n", a, b);
        }
    }
}

// 生成三年级题目：加法、减法、乘法混合，结果小于1000
void generateThirdGradeQuestions(int num) {
    for (int i = 0; i < num; i++) {
        int a = generateRandomNumber(1000);
        int b = generateRandomNumber(1000);
        int op = rand() % 3; // 0为加法，1为减法，2为乘法
        if (op == 0) {
            printf("%d + %d = \n", a, b);
        } else if (op == 1) {
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            printf("%d - %d = \n", a, b);
        } else {
            printf("%d * %d = \n", a, b);
        }
    }
}

// 生成四到六年级题目：带有括号的混合运算式
void generateFourthToSixthGradeQuestions(int num) {
    for (int i = 0; i < num; i++) {
        int a = generateRandomNumber(100);
        int b = generateRandomNumber(100);
        int c = generateRandomNumber(100);
        int op1 = rand() % 4; // 0为加法，1为减法，2为乘法，3为除法
        int op2 = rand() % 4;
        int op3 = rand() % 4;
        printf("(%d ", a);
        if (op1 == 0) {
            printf("+ ");
        } else if (op1 == 1) {
            printf("- ");
        } else if (op1 == 2) {
            printf("* ");
        } else {
            printf("/ ");
        }
        printf("%d) ", b);
        
        if (op2 == 0) {
            printf("+ ");
        } else if (op2 == 1) {
            printf("- ");
        } else if (op2 == 2) {
            printf("* ");
        } else {
            printf("/ ");
        }
        printf("%d ", c);
        

        printf(" = \n");
    }
}

int main() {
    int grade, num;
    
    printf("请输入年级（1-6）：");
    scanf("%d", &grade);
    printf("请输入题目数量：");
    scanf("%d", &num);

    srand(time(NULL)); // 用于初始化随机数种子
    
    switch (grade) {
        case 1:
            generateFirstGradeQuestions(num);
            break;
        case 2:
            generateSecondGradeQuestions(num);
            break;
        case 3:
            generateThirdGradeQuestions(num);
            break;
        case 4:
        case 5:
        case 6:
            generateFourthToSixthGradeQuestions(num);
            break;
        default:
            printf("请输入1到6之间的整数！\n");
            break;
    }

    return 0;
}