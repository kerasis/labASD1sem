#include <iostream>
#include <vector>
// проходим по несортированной части массива. выбираем наименьший элемент ставим меняем его с первым несортированным элементом
template <typename T>
void selectSort(std::vector<T>& mas)
{  
    T min_elem;
    int cur_ind = 0;
    for (int i = 0; i < mas.size() - 1; i++)
    {
        min_elem = 999999;   
        cur_ind = i;
        for (int j = i+ 1; j < mas.size(); j++)
        {       
            if (mas[j] < mas[cur_ind])
            {
                min_elem = mas[j];
                cur_ind = j;
                
            }
        } 
        std::swap(mas[i], mas[cur_ind]);
    }
}

int main()
{
    int n;
    std::vector<int> mas;
    std::cout << "Enter len mas: ";
    std::cin >> n;
    std::cout << std::endl << "cur mas: ";
    for (int i = 0; i < n; i++)
    {
        mas.push_back(rand() % 100);
        std::cout << mas[i] << " ";
    }
    selectSort(mas);
    std::cout << '\n' << "sorted: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
}