#include <iostream>
#include <string>

// Базовий клас "Фігура"
class Figure {
public:
    virtual void draw() const = 0; //метод
    virtual void delet() const = 0; // метод
    virtual ~Figure() {} // деструктор
};

// Дочірній клас 
class Rectangle : public Figure {
private:
    int x1, y1; 
    int x2, y2; 

public:
    // Конструктор класу
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    // Метод малювання прямокутника
    virtual void draw() const override {
        int width = x2 - x1;
        int height = y2 - y1;

        for (int i = 0; i < y1; ++i) {
            std::cout << std::endl;
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < x1; ++j) {
                std::cout << " ";
            }
            for (int j = 0; j < width; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    // Метод видалення прямокутника
    virtual void delet() const override {
        
        for (int i = 0; i <= y2 - y1; ++i) {
            std::cout << std::string(x2 - x1 + 1, '\b');
            std::cout << std::string(x2 - x1 + 1, ' ');
            std::cout << std::string(x2 - x1 + 1, '\b');
            std::cout << std::endl;
        }
    }
};

int main() {
    int x1, y1, x2, y2;

    do {
        std::cout << "Enter the coordinates of the upper left corner of the rectangle (x1 y1): ";
        std::cin >> x1 >> y1;

        std::cout << "Enter the coordinates of the lower right corner of the rectangle (x2 y2): ";
        std::cin >> x2 >> y2;

        Rectangle rect(x1, y1, x2, y2);
        rect.draw(); 

        std::string del;
        std::cout << "Delete rectangle (yes/no): ";
        std::cin >> del;

        if (del == "yes") {
            rect.delet(); 
            break;
        }
    } while (true);

    return 0;
    
}
