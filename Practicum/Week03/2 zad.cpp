#include <iostream>
#include <fstream>

namespace Constants {
	constexpr size_t nameSize = 50;
}
struct StudentC {
	int id;
	double grade;
	char name[Constants::nameSize];
};
namespace FreeNS {
	void freeStudentArr(StudentC* ptr) {
		delete[] ptr;
	}
}
size_t getFileSize(std::istream& ifs) {
	size_t size = 0;
	ifs.seekg(0, std::ios::end);
	size = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	return size;
}
void createStudent(StudentC& student) {

	std::cout << "id:" << std::endl;
	std::cin >> student.id;
	if (std::cin.fail()) {
		std::cout << "error";
		return;
	}

	std::cout << "grade:" << std::endl;
	std::cin >> student.grade;
	if (std::cin.fail()) {
		std::cout << "error";
		return;
	}

	std::cout << "name:" << std::endl;
	std::cin.ignore();
	std::cin.getline(student.name, Constants::nameSize);
}

void writeStudentToBinary(StudentC& student) {

	std::ofstream ofs("Binary.dat", std::ios::app, std::ios::binary);

	if (!ofs.is_open()) {
		std::cout << "error";
		return;
	}

	ofs.write((const char*)&student, sizeof(student));
	ofs.close();
}

StudentC* loadStudents(size_t& dynArrSize) {
	std::ifstream ifs("Binary.dat", std::ios::binary);

	if (!ifs.is_open()) {
		std::cout << "error";
		return nullptr;
	}

	dynArrSize = getFileSize(ifs) / sizeof(StudentC);
	StudentC* arr = new StudentC[dynArrSize];

	ifs.read((char*)arr, getFileSize(ifs));

	ifs.close();
	return arr;
}
void sortByGrade(StudentC* arr, size_t& dynArrSize) {
	for (int i = 0; i < dynArrSize; i++) {
		for (int j = i; j < dynArrSize; j++) {
			if (arr[i].grade < arr[j].grade) std::swap(arr[i], arr[j]);
		}
	}
}
void print(std::ostream& os, StudentC* arr, size_t& dynArrSize) {
	for (int i = 0; i < dynArrSize; i++) {
		os << arr[i].id << " " << arr[i].grade << " " << arr[i].name;
		os << std::endl;
	}
}

int main() {
	StudentC student;
	StudentC* ptr;
	size_t dynArrSize = 0;
	ptr = loadStudents(dynArrSize);
	sortByGrade(ptr, dynArrSize);
	print(std::cout, ptr, dynArrSize);
	FreeNS::freeStudentArr(ptr);
}
