#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机整数或小数
double generateRandomNumber(int max, int withDecimal) {
    if (withDecimal) {
        return (double)rand() / RAND_MAX * max;
    }
    else {
        return rand() % (max + 1);
    }
}

// 生成随机运算符
char generateRandomOperator() {
    char operators[] = { '+', '-', '*', '/' };
    int index = rand() % 4;
    return operators[index];
}

// 生成简单的四则运算表达式（指定运算符、是否有括号、是否有小数）
void generateSimpleExpression(int maxNum, char op, int withParentheses, int withDecimal) {
    double num1 = generateRandomNumber(maxNum, withDecimal);
    double num2 = generateRandomNumber(maxNum, withDecimal);
    double num3 = generateRandomNumber(maxNum, withDecimal);

    if (withParentheses && rand() % 2 == 0) {
        printf("(");
    }

    if (withDecimal) {
        printf("%.2f %c %.2f", num1, op, num2);
    }
    else {
        printf("%.0f %c %.0f", num1, op, num2);
    }

    if (withParentheses && rand() % 2 == 0) {
        printf(")");
    }

    printf(" = \n");
}

// 生成指定数量的简单四则运算题目（指定运算符、是否有括号、是否有小数）
void generateSimpleExpressions(int maxNum, int numQuestions, char op, int withParentheses, int withDecimal) {
    for (int i = 0; i < numQuestions; i++) {
        generateSimpleExpression(maxNum, op, withParentheses, withDecimal);
    }
}

int main() {
    // 设置随机种子
    srand(time(NULL));

    int maxNum, numQuestions;
    char op;
    int withParentheses, withDecimal;

    printf("请输入最大数（如十以内、百以内等）: ");
    scanf_s("%d", &maxNum);

    printf("请输入题目数量：");
    scanf_s("%d", &numQuestions);

    printf("请输入要使用的运算符（+、-、*、/）: ");
    scanf_s(" %c", &op);

    printf("是否使用括号？（1表示是，0表示否）: ");
    scanf_s("%d", &withParentheses);

    printf("是否包含小数？（1表示是，0表示否）: ");
    scanf_s("%d", &withDecimal);

    // 生成指定数量的简单四则运算题目（指定运算符、是否有括号、是否有小数）
    generateSimpleExpressions(maxNum, numQuestions, op, withParentheses, withDecimal);

    return 0;
}