#include <fstream>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::fstream fIn("in.txt");
    if (!fIn.is_open()) {
        std::cout << "Ошибка открытия файла!";
    }
    else {

        int size1{}, size2{};

        fIn >> size1;
        int* firstMass = new int[size1];
        for (int i{}; i < size1; ++i) {
            fIn >> firstMass[i];
        }
        fIn >> size2;
        int* secondMass = new int[size2];
        for (int i{}; i < size2; ++i) {
            fIn >> secondMass[i];
        }

        int* firstMassSort = new int[size1];
        for (int i{1}; i < size1; ++i) {
            firstMassSort[i - 1] = firstMass[i];
        }
        firstMassSort[size1 - 1] = firstMass[0];
        delete[] firstMass;

        int* secondMassSort = new int[size2];
        for (int i{}; i < size2 - 1; ++i) {
            secondMassSort[i + 1] = secondMass[i];
        }
        secondMassSort[0] = secondMass[size2 - 1];
        delete[] secondMass;

        std::ofstream fOut("out.txt");
        fOut << size2 << "\n";
        for (int i{}; i < size2; ++i) {
            fOut << secondMassSort[i] << " ";
        }
        fOut << "\n";
        fOut << size1 << "\n";
        for (int i{}; i < size1; ++i) {
            fOut << firstMassSort[i] << " ";
        }

        delete[] firstMassSort;
        delete[] secondMassSort;
    }
    fIn.close();
    return 0;
}




