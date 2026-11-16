#pragma once
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include <string>

void menu(
    int action,
    std::unordered_map<int, Pipe>& pipes,
    std::unordered_map<int, Station>& css,
    std::ofstream& logfile
);

class redirect_output_wrapper {
private:
    std::ostream& stream;
    std::streambuf* const old_buf;
public:
    redirect_output_wrapper(std::ostream& src)
        :stream(src), old_buf(src.rdbuf()) {
    } // rdbuf() - возращает указатель на текущий буфер поток ввод-вывода
    ~redirect_output_wrapper() {
        stream.rdbuf(old_buf);
    } // rdbuf(new_buf) - устанавливает новый буфер потока и возвращает указатель на предыдущий буфер потока ввода-вывода
    void redirect(std::ostream& target)
    {
        stream.rdbuf(target.rdbuf());
    }
};