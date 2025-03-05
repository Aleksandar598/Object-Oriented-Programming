#include <iostream>
#include <fstream>
void printArr(const int* arr, size_t size) {
	if (!arr) return;
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void writeToFile(const int* array, size_t size) {
	std::ofstream ofs("file.dat", std::ios::out | std::ios::binary);
	if (!ofs.is_open()) return;
	ofs.write((const char*)array, sizeof(int)*size);
	ofs.close();
}
void createDynamicArray(size_t size) {
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
	}
	printArr(array, size);
	writeToFile(array, size);
	delete[] array;
}
int getFileSize(std::ifstream& ifs) {
	ifs.seekg(0, std::ios::end);
	int pos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	return pos / sizeof(int);

}
int* readFromFile() {
	std::ifstream ifs("file.dat", std::ios::in | std::ios::binary);
	if (!ifs.is_open()) return 0;
	int size = getFileSize(ifs);
	int* arr = new int[size];
	ifs.read((char*)arr, sizeof(int)*size);
	printArr(arr, size);
	ifs.close();
	return arr;
}

int main()
{
	int size = 0;
	std::cin >> size;
	createDynamicArray(size);
	delete[] readFromFile();
}

