#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для нахождения длины наибольшего палиндрома
int longestPalindromeDP(const string& s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Базовый случай: палиндром из одной буквы
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Заполнение таблицы
    for (int len = 2; len <= n; ++len) { // длина подстроки
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // конец подстроки
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // Длина наибольшего палиндрома
    return dp[0][n - 1];
}

// Основная функция
int main() {
    setlocale(LC_ALL, "rus");
    string s;
    cout << "Введите строку из заглавных букв: ";
    cin >> s;

    // Нахождение результата
    int result = longestPalindromeDP(s);
    cout << "Длина наибольшего палиндрома: " << result << endl;

    return 0;
}
