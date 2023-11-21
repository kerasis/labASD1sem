#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& mas)
{
    for (int j = 1; j < mas.size(); j++)
    {
        T temp = mas[j];
        int i = j - 1;
        while (i >= 0 && mas[i] > temp)
        {
            mas[i + 1] = mas[i];
            i = i - 1;
        }
        mas[i + 1] = temp;
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
    insertionSort(mas);
    std::cout << "sorted: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
}