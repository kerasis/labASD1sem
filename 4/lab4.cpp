
#include <iostream>
#include <vector>

template <typename T>
void combSort(std::vector<T>& mas)
{
    int step = mas.size() - 1; //шаг
    while (step >= 1)
    {
        for (int i = 0; i + step < mas.size(); i++)
        {
            if (mas[i] > mas[i + step])
            {
                std::swap(mas[i], mas[i + step]);
            }
        }
        step = static_cast<int>(step / 1.3f);
    }
}

int main()
{
    int n;
    std::vector<int> mas;
    std::cout << "Enter len mas: ";
    std::cin >> n;
    std::cout << std::endl << "enter mas: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        mas.push_back(temp);
    }
    combSort(mas);
    std::cout << "sorted: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
}
