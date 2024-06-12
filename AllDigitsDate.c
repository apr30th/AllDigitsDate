// 0~9까지 모든 숫자를 가지는 날짜 찾기
// 스스로 정의한 문제와 그 해결

#include <stdio.h>
#include <stdbool.h>

void checkDigits(int number, int digits[]) {
    while (number > 0)
    {
        digits[number % 10]++;
        number /= 10;
    }
}

bool is_valid_date(int year, int month, int day, int hour, int minute) {
    int digits[10] = {0};

    checkDigits(year, digits);
    checkDigits(month, digits);
    checkDigits(day, digits);
    checkDigits(hour, digits);
    checkDigits(minute, digits);

    for (int i = 0; i < 10; i++)
        if (digits[i] != 1)
            return false;

    return true;
}

int main()
{
    int i = 0;
    int yearStart, yearEnd;

    while (1) {
        printf("시작 연도와 끝 연도를 입력하세요(예 : 1980 2000) : ");
        scanf("%d %d", &yearStart, &yearEnd);

        if (yearStart <= yearEnd)
            break;
        else
            printf("잘못된 연도를 입력하셨습니다. 다시 입력하세요.\n");
    }

    for (int year = yearStart; year <= yearEnd; year++) {
        for (int month = 1; month <= 12; month++) {
            for (int day = 1; day <= 31; day++) {
                for (int hour = 0; hour <= 23; hour++) {
                    for (int minute = 0; minute <= 59; minute++) {
                        if (is_valid_date(year, month, day, hour, minute)) {
                            i++;
                            printf("%d : ", i);
                            printf("%d/%d/%d %d:%d\n", year, month, day, hour, minute);
                        }
                    }
                }
            }
        }
    }
    if (i == 0)
        printf("조건에 맞는 날짜가 존재하지 않습니다.\n");
    return 0;
}