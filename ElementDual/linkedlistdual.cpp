#include "linkedlistdual.h"
#include<math.h>
#include<string>
bool linkedlistdual::addHead(ElementDual* a)
{
    if (head == nullptr) {
        head = tail = a;
    }
    else {
        a->setNext(head);
        head->setPrev(a);
        head = a;
    }
    return true;
}

bool linkedlistdual::addTail(ElementDual* a)
{
    if (head == nullptr) {
        head = tail = a;
    }
    else {
        a->setPrev(tail);
        tail->setNext(a);
        tail = a;
    }
    return true;
}

void linkedlistdual::display()
{
    ElementDual* p = head;
    bool firstTerm = true;

    while (p != nullptr) {
        float data = p->getData();
        int exponent = p->getExponent();

        if (data != 0) {
            if (!firstTerm) {
                if (data > 0) {
                    std::cout << " + ";
                }
                else {
                    std::cout << " - ";
                }
            }
            firstTerm = false;

            std::cout << std::abs(data); // Display the absolute value of the coefficient.

            if (exponent != 0) {
                std::cout << "x";
                if (exponent != 1) {
                    std::cout << "^" << exponent;
                }
            }
        }

        p = p->getNext();
    }

    if (firstTerm) {
        std::cout << "0"; // If all terms were zero, print "0".
    }

    std::cout << std::endl;
}

double linkedlistdual::evaluate(int inputValue) {
    double value = 0.0;
    ElementDual* p = head;

    while (p != nullptr) {
        value += p->getData() * pow(inputValue, p->getExponent());
        p = p->getNext(); // Di chuyển đến phần tử tiếp theo trong danh sách
    }

    return value;
}

void linkedlistdual::inputPolynomial() {
    int n; // Số lượng hạng tử của đa thức
    float x; // Hệ số
    int y; // Số mũ

    std::cout << "Nhap so luong phan tu cua da thuc: ";
    std::cin >> n;

    std::cout << "Nhap he so va so mu cho tung hang tu:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "He so: ";
        std::cin >> x;
        std::cout << "So mu: ";
        std::cin >> y;

        ElementDual* a = new ElementDual();
        a->setData(x);
        a->setExponent(y);
        addTail(a); // Thêm hạng tử vào danh sách liên kết kép
    }
}

linkedlistdual* linkedlistdual::add(linkedlistdual* a) {
    linkedlistdual* sum = new linkedlistdual();
    ElementDual* p = this->head;
    ElementDual* q = a->head;

    while (p != nullptr && q != nullptr) {
        // Tạo một đối tượng ElementDual mới cho mỗi phần tử kết quả
        ElementDual* resultElement = new ElementDual();

        if (p->getExponent() == q->getExponent()) {
            resultElement->setData(p->getData() + q->getData());
            resultElement->setExponent(p->getExponent());
            p = p->getNext();
            q = q->getNext();
        }
        else if (p->getExponent() > q->getExponent()) {
            resultElement->setData(p->getData());
            resultElement->setExponent(p->getExponent());
            p = p->getNext();
        }
        else {
            resultElement->setData(q->getData());
            resultElement->setExponent(q->getExponent());
            q = q->getNext();
        }

        sum->addTail(resultElement); // Thêm đối tượng mới vào danh sách kết quả
    }

    // Xử lý các phần tử còn lại nếu có

    while (p != nullptr) {
        ElementDual* resultElement = new ElementDual();
        resultElement->setData(p->getData());
        resultElement->setExponent(p->getExponent());
        sum->addTail(resultElement);
        p = p->getNext();
    }

    while (q != nullptr) {
        ElementDual* resultElement = new ElementDual();
        resultElement->setData(q->getData());
        resultElement->setExponent(q->getExponent());
        sum->addTail(resultElement);
        q = q->getNext();
    }

    return sum;
}

linkedlistdual* linkedlistdual::multiply(linkedlistdual* a)
{
    linkedlistdual* b = new linkedlistdual();
    ElementDual* p = this->head;
    ElementDual* q = a->head;

    while (p != nullptr) {
        while (q != nullptr) {
            ElementDual* tmp = new ElementDual();
            tmp->setData(p->getData() * q->getData());
            tmp->setExponent(p->getExponent() + q->getExponent());
            b->addTail(tmp);
            q = q->getNext();
        }
        q = a->head; // Đặt lại con trỏ q cho vòng lặp ngoài cùng
        p = p->getNext();
    }

    // Sao chép các phần tử còn lại từ danh sách gốc
    while (p != nullptr) {
        ElementDual* tmp = new ElementDual();
        tmp->setData(p->getData());
        tmp->setExponent(p->getExponent());
        b->addTail(tmp);
        p = p->getNext();
    }

    while (q != nullptr) {
        ElementDual* tmp = new ElementDual();
        tmp->setData(q->getData());
        tmp->setExponent(q->getExponent());
        b->addTail(tmp);
        q = q->getNext();
    }

    b->rutgon();
    return b;
}

bool linkedlistdual::deleteMiddle(ElementDual* a)
{
    if (a == nullptr) {
        return false; // Không có phần tử để xóa
    }

    ElementDual* prev = a->getPrev();
    ElementDual* next = a->getNext();

    if (prev != nullptr) {
        prev->setNext(next);
    }
    else {
        // Nếu prev là nullptr, a là phần tử đầu danh sách
        // Cập nhật con trỏ head
        head = next;
    }

    if (next != nullptr) {
        next->setPrev(prev);
    }

    delete a; // Giải phóng bộ nhớ của phần tử bị xóa
    return true;
}

void linkedlistdual::rutgon()
{
    ElementDual* current = head;
    while (current != nullptr) {
        ElementDual* next = current->getNext();
        while (next != nullptr) {
            if (current->getExponent() == next->getExponent()) {
                current->setData(current->getData() + next->getData());
                // Loại bỏ hạng tử next sau khi đã cộng
                deleteMiddle(next);
                next = current->getNext(); // Di chuyển next đến phần tử tiếp theo
            }
            else {
                next = next->getNext();
            }
        }
        current = current->getNext();
    }
}



