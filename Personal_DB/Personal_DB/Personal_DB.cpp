#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Student {
private:
    int id;
    std::string name;
    int age;
    float marks;
public:
    Student(){}
    Student(int id, std::string name, int age, float marks) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->marks = marks;
    }
    int getID() {
        return this->id;
    }
    std::string getName() {
        return this->name;
    }
    int getAge() {
        return this->age;
    }
    float getMarks() {
        return this->marks;
    }
};

std::vector<Student> students_list;
std::string bash = "--> ";
int id = 1;
std::ofstream DBRead("students.txt", std::ios::app);




Student creat_student_ellement(int id, std::string name, int age, float marks) {
    Student s(id, name, age, marks);
    return s;
}
std::vector <std::string> splitting(std::string text) {
    std::vector <std::string> tokens;
    std::string intermediate;
    std::stringstream check1(text);
    while (std::getline(check1, intermediate, '|')) {
        tokens.push_back(intermediate);
    }
    return tokens;
}

void read_db_file() {
    std::string line;
    std::vector <std::string> tokens;
    std::ifstream Read("students.txt");
    while (std::getline(Read, line)) {
        int age = 0;
        int this_id;
        float marks = 0;
        tokens = splitting(line);
        std::stringstream string_ID(tokens[0]);
        std::stringstream string_age(tokens[2]);
        std::stringstream astring_marks(tokens[3]);
        string_ID >> this_id;
        string_age >> age;
        astring_marks >> marks;
        Student s = creat_student_ellement(this_id, tokens[1], age, marks);
        students_list.push_back(s);
        id++;
    }
}

void creat_student_vector() {
    std::string name;
    int age;
    float marks;
    std::cout << "Student name:" << std::endl;
    std::cout << bash;
    std::cin >> name;
    std::cout << "Student age:" << std::endl;
    std::cout << bash;
    std::cin >> age;
    std::cout << "Student marks:" << std::endl;
    std::cout << bash;
    std::cin >> marks;
    Student s = creat_student_ellement(id, name, age, marks);
    if (DBRead.is_open()) {
        DBRead << id << "|" << name << "|" << age << "|" << marks << "\n";
    }
    id++;
    students_list.push_back(s);
}

void add_in_DB() {
    creat_student_vector();
}

std::vector<Student> search_by_ID(int id) {
    std::vector<Student> serch_ell;
    for (int i = 0; i < students_list.size(); i++) {
        if (students_list[i].getID() == id) {
            serch_ell.push_back(students_list[i]);
        }
    }
    return serch_ell;
}

std::vector<Student> search_by_name(std::string name) {
    std::vector<Student> serch_ell;
    for (int i = 0; i < students_list.size(); i++) {
        if (students_list[i].getName() == name) {
            serch_ell.push_back(students_list[i]);
        }
    }
    return serch_ell;
}

std::vector<Student> search_by_age(int age) {
    std::vector<Student> serch_ell;
    for (int i = 0; i < students_list.size(); i++) {
        if (students_list[i].getAge() == age) {
            serch_ell.push_back(students_list[i]);
        }
    }
    return serch_ell;
}

std::vector<Student> search_by_mark(float marks) {
    std::vector<Student> serch_ell;
    for (int i = 0; i < students_list.size(); i++) {
        if (students_list[i].getMarks() == marks) {
            serch_ell.push_back(students_list[i]);
        }
    }
    return serch_ell;
}

void print_elements(std::vector<Student> list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << "ID: " << list[i].getID()
            << "| name: "<< list[i].getName()
            << "| age: " << list[i].getAge()
            << "| marks: " << list[i].getMarks()
            <<std::endl;
    }
}

int main()
{   
    read_db_file();
    bool loop = true;
    std::cout << "Show all commands 'help'" << std::endl;
    std::cout << "If you can exit 'exit'" << std::endl;
    while (loop) {
        std::string command;
        int id;
        std::string name;
        int age;
        float marks;
        std::cout << bash;
        std::cin >> command;
        if (command == "add") {
            add_in_DB();
            std::cout << "saved" << std::endl;
        }
        else if (command == "search_by_id") {
            std::cout << bash;
            std::cin >> id;
            print_elements(search_by_ID(id));
        }
        else if (command == "search_by_name") {
            std::cout << bash;
            std::cin >> name;
            print_elements(search_by_name(name));
        }
        else if (command == "search_by_age") {
            std::cout << bash;
            std::cin >> age;
            print_elements(search_by_age(age));
        }
        else if (command == "search_by_marks") {
            std::cout << bash;
            std::cin >> marks;
            print_elements(search_by_mark(marks));
        }
        else if (command == "show_all") {
            print_elements(students_list);
        }
        else if (command == "help") {
            std::cout << "If you can add ellement write 'add'" << std::endl;
            std::cout << "If you can show all ellement write 'show_all'" << std::endl;
            std::cout << "If you can search by id write 'search_by_id'" << std::endl;
            std::cout << "If you can search by name write 'search_by_name'" << std::endl;
            std::cout << "If you can search by age write 'search_by_age'" << std::endl;
            std::cout << "If you can search by marks write 'search_by_marks'" << std::endl;
        }
        else if (command == "exit") {
            DBRead.close();
            loop = false;
        }
        else {
            std::cout << "I undstand you" << std::endl;
        }
    }

}
