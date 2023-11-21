#include <iostream>
#include <vector>

// { - 123
// } - 125
// [ - 91
// ] - 93
// ( - 40 
// ) - 41

bool task()
{
    std::vector<char> sas = {};
    int sas_top_index = -1; //индекс последнего заполненного элемента стека ( -1 => стек пустой)
    char s[100] = {}; //пустые ячейки приняли значение 0

    std::cout << "Введите строку: ";
    std::cin >> s;


    for (int i = 0; i < 100; i++)
    {
        if (s[i] == 0) { break; } //проверка на пустой символ(конец строки)         

        if (sas_top_index != -1)
        {
            bool check = 1;

            switch (s[i])
            {
            case 123:
                check = 0;
                break;

            case 125:
                if (static_cast<int>(sas[sas_top_index]) != 123)
                {
                    check = 0;
                }
                break;

            case 91:
                check = 0;
                break;

            case 93:
                if (static_cast<int>(sas[sas_top_index]) != 91)
                {
                    check = 0;
                }
                break;

            case 40:
                check = 0;
                break;

            case 41:
                if (static_cast<int>(sas[sas_top_index]) != 40)
                {
                    check = 0;
                }
                break;


            default:
                sas_top_index = 101; // проверка на другие символы => выход из цикла проверки с возвращением значения фолс
                break;
            }
            if (sas_top_index == 101) { break; }


            if (check) // если текущий символ строки s удовлетворил проверке то удаляем из стека
            {
                sas.pop_back();
                sas_top_index -= 1;
            }
            else
            {
                sas_top_index += 1;
                sas.push_back(s[i]);
            }
        }
        else
        {
            sas_top_index += 1;
            sas.push_back(s[i]);
        }
    }
    if (sas_top_index == -1) { return true; }
    else { return false; }
}

int main()
{
    setlocale(LC_ALL, "rus");
    if (task() == true) { std::cout << "Строка существует"; }
    else { std::cout << "Строка не существует"; }
}