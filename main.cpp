/*
 * created by Danil Kireev, PFUR NFI-201, 8.11.18, 09:00
 */
#include <cmath>
#include <iostream>
using namespace std;

/*
 *  №2
 *  Напишите метод, который будет
 *  подсчитывать количество цифр «2»,
 *  используемых в записи чисел от 0 до n (включительно)
 */

int how_many_2s(int num);

int main() {
    int n, c;
    cout << "программа подсчитывает количество цифр 2 в записи чисел от 0 до n" << endl;
    cout << "Введите число n: ";
    cin >> n;
    while(n <= 0) {
        cout << "Введите натуральное число n";
        cin >> n;
    }
    c = how_many_2s(n);
    cout << "количество цифр 2 в записи чисел от 0 до " << n << ": " << c << endl;
    return 0;
}

int how_many_2s(int num) {
    int count = 0, cur_pow, next_pow, digit;
    unsigned long len = to_string(num).length();
    for(int rank = 0; rank < len; ++rank) {
        cur_pow = int(pow(10, rank));
        next_pow = cur_pow * 10;
        digit = (num / cur_pow) % 10;
        if      (digit < 2)   {count += (num - (num % next_pow))/10;}                       //т.к. цифра меньше 2, она добавляет количество двоек как число с цифрой справа на той же позиции, все остальные 0
        else if (digit == 2)  {count += (num - (num % next_pow))/10 + (num % cur_pow) + 1;} //так же как выше 2, добавляется остаток справа +1, чтобы включить 0
        else if (digit > 2)   {count += (num - (num % next_pow))/10 + next_pow;}            //т.к. цифра меньше 2, она добавляет количество двоек как число с цифрой справа + 1 на той же позиции, все остальные 0
    }
    return count;
}