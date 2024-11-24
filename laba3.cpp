#include <iostream> //библиотека для ввода-вывода (например, std::cout и std::cin)
#include <fstream> // для работы с файлами (чтение и запись)
#include <vector> //для использования динамического массива (векторов)

    } // 
    } // 
std::vector<int> readDataFromFile(const std::string& filename) { //Объявление функции readDataFromFile, которая принимает имя файла как параметр и возвращает вектор целых чисел
    std::ifstream file(filename); //Создание объекта file типа std::ifstream, который открывает файл с именем, переданным в параметре filename
    if (!file) {//
        throw std::runtime_error("Unable to open file: " + filename); //
    } // Проверка, удалось ли открыть файл. Если нет, выбрасывается исключение runtime_error с сообщением об ошибке

    int count; //
    file >> count;  // Считываем количество элементов

    std::vector<int> data(count); //Создание вектора data размером count, который будет содержать считываемые данные
    for (int i = 0; i < count; ++i) { //
        file >> data[i];  // Считываем сами данные. Цикл, в котором считываются элементы из файла и записываются во вектор data
    } //

    file.close(); //Закрытие файла после завершения чтения
    return data; //Возврат вектора данных из функции
} //

std::vector<int> sumVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) { //Объявление функции sumVectors, которая принимает два вектора и возвращает их сумму в виде нового вектора
    size_t size = std::min(vec1.size(), vec2.size()); //пределение минимального размера между двумя векторами для избежания выхода за пределы границ
    std::vector<int> result(size); //Создание результата, вектора result, размером, равным меньшему размеру из входных векторов
    for (size_t i = 0; i < size; ++i) { //
        result[i] = vec1[i] + vec2[i];  // Суммируем соответствующие элементы
    } //
    return result; //Возврат вектора result с суммой элементов
} //

std::vector<int> subtractVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) { //Объявление функции subtractVectors, которая принимает два вектора и возвращает их разность
    size_t size = std::min(vec1.size(), vec2.size()); // 
    std::vector<int> result(size); //Определение минимального размера и создание вектора result
    for (size_t i = 0; i < size; ++i) { //
        result[i] = vec1[i] - vec2[i];  // Цикл для вычисления разности соответствующих элементов векторов
    } //
    return result; //Возврат вектора result с разностью элементов
} //

int multiplicationVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) { //Объявление функции multiplicationVectors, которая принимает два вектора и возвращает скалярное произведение
    size_t size = std::min(vec1.size(), vec2.size()); //
    std::vector<int> result(size); //
    int mp_Vector = 0; //Определение минимального размера, создание вектора result (но он здесь не нужен) и инициализация переменной mp_Vector для хранения результата скалярного произведения
    for (size_t i = 0; i < size; ++i) { //
        mp_Vector += vec1[i] * vec2[i];  //Цикл для вычисления скалярного произведения, складывая произведения соответствующих элементов двух векторов
    } //
    return mp_Vector; //
} //Возврат значения скалярного произведения


void printVector(const std::vector<int>& vec) { //Объявление функции printVector, которая принимает вектор и ничего не возвращает, просто выводит его содержимое
    for (int value : vec) { //
        std::cout << value << " "; //Цикл для вывода каждого значения вектора на экран
    } //
    std::cout << std::endl; //
} //Печать новой строки после вывода всех элементов вектора

int main() { //Объявление основной функции программы
    system("chcp 1251"); //
    system("cls"); //Настройка кодировки консоли для отображения русских символов (Windows) и очистка экрана
    try { //Начало блока try, чтобы отловить возможные исключения из кода
        std::vector<int> data1 = readDataFromFile("file1.txt"); //
        std::vector<int> data2 = readDataFromFile("file2.txt"); //Вызов функции readDataFromFile для считывания данных из двух файлов и сохранение результатов в вектора data1 и data2

        std::vector<int> sum = sumVectors(data1, data2); //
        std::vector<int> subt = subtractVectors(data1, data2);//
        int multuplic = multiplicationVectors(data1, data2);//Вызов функций для получения суммы, разности и скалярного произведения векторов

        std::cout << "Сумма векторов: ";//
        printVector(sum);//
        std::cout << "Разность векторов: ";//
        printVector(subt);//
        std::cout << "Скалярное проивзедение: ";//
        std::cout << multuplic << std::endl;//Вывод результатов вычислений на экран с пояснениями
    }//
    catch (const std::runtime_error& e) {//
        std::cerr << e.what() << std::endl;//Обработка исключений. Если во время выполнения произошла ошибка, выводится сообщение об ошибке
    }//

    return 0;//
}//Завершение функции main. Возврат 0 сигнализирует о нормальном завершении программы
