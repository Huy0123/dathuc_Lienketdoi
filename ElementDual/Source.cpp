#include"ElementDual.h"
#include"linkedlistdual.h"
#include<iostream>
using namespace std;
int main() {
    linkedlistdual* myList = new linkedlistdual();
    int choice;
    double result;
    linkedlistdual* secondList = new linkedlistdual();
    linkedlistdual* value;
while (true) {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Nhap da thuc" << std::endl;
    std::cout << "2. In da thuc" << std::endl;
    std::cout << "3. Cho x tinh gia tri da thuc" << std::endl;
    std::cout << "4. Cong 2 da thuc" << std::endl;
    std::cout << "5. Nhan 2 da thuc" << std::endl;
    std::cout << "6. Thoat" << std::endl;
    std::cout << "Nhap lua chon cua ban: ";
    std::cin >> choice;

    switch (choice) {
    case 1:// Nhap da thuc
        myList->inputPolynomial();
        break;
    case 2: // In da thuc
        myList->display();
        break;
    case 3: // Cho x tinh gia tri da thuc
        int inputValue;
        std::cout << "Nhap gia tri x: ";
        std::cin >> inputValue;
        // Gọi hàm tính giá trị đa thức tại x ở đây
        result = myList->evaluate(inputValue);
        cout << "f(" << inputValue << ") = " << result<<endl;
        break;
    case 4: // Cong 2 da thuc
        
        // Nhập và thêm các hạng tử vào secondList
        secondList->inputPolynomial();
        // Gọi hàm cộng hai đa thức ở đây
        value = myList->add(secondList);
        value->display();
        delete secondList;
        delete value;
        break;
    case 5: // Nhan 2 da thuc
        // Nhập và thêm các hạng tử vào secondList
        secondList->inputPolynomial();
        // Gọi hàm nhân hai đa thức ở đây
        value = myList->multiply(secondList);
        value->display();
        delete secondList;
        delete value;
        break;
    case 6: // Thoat
        delete myList;
        return 0;
    default:
        std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
    }
}

return 0;
}