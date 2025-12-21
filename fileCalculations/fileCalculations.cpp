#include <iostream>
#include <fstream>

void createFiles() {
    int a, b;
    FILE* fileA = fopen("firstArray.bin", "wb");
    FILE* fileB = fopen("secondArray.bin", "wb");
    for (int i = 0; i < 17; i++) {
        a = rand() % 201 - 100;
        fwrite(&a, sizeof(int), 1, fileA);
    }
    for (int i = 0; i < 17; i++) {
        b = rand() % 201 - 100;
        fwrite(&b, sizeof(int), 1, fileB);

    }
    fclose(fileA);
    fclose(fileB);
}

int main()
{
    int a, b;
    float c;
    createFiles();
    FILE* fileA = fopen("firstArray.bin", "rb");
    FILE* fileB = fopen("secondArray.bin", "rb");
    FILE* fileC = fopen("result.bin", "wb+");
    for (int i = 0; i < 17; i++) {
        fread(&a, sizeof(int), 1, fileA);
        fread(&b, sizeof(int), 1, fileB);
        if (b != 0) {
            c = static_cast<float>(a) / b - 2.0;
        }
        else {
            c = 0;
        }
        fwrite(&c, sizeof(float), 1, fileC);
    }
    rewind(fileA);
    rewind(fileB);
    rewind(fileC);
    std::cout << "File A: ";
    for (int i = 0; i < 17; i++) {
        fread(&a, sizeof(int), 1, fileA);
        std::cout << a << " ";
    }
    std::cout << std::endl << "File B: ";
    for (int i = 0; i < 17; i++) {
        fread(&b, sizeof(int), 1, fileB);
        std::cout << b << " ";
    }
    std::cout << std::endl << "File C: ";
    for (int i = 0; i < 17; i++) {
        fread(&c, sizeof(float), 1, fileC);
        std::cout << c << " ";
    }
}