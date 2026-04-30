#include <stdio.h>
#include <string.h>

#define SIZE 20 //  underflow   حجم اكبر من الكلمة الاختبار

// تعريف المخزن الدائري
typedef struct {
    char ringbuffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

// التهيئة
void init(CircularBuffer *ptr) {
    ptr->head = 0;
    ptr->tail = 0;
    ptr->count = 0;
}

// التحقق من الامتلاء
int Full(CircularBuffer *ptr) {
    int x;
    x=ptr->count == SIZE;
    return x;
}

// التحقق من الفراغ
int Empty(CircularBuffer *ptr) {
    int y;
    y=ptr->count == 0;
    return y;
}

// الإدخال (الكتابة)
void writeinBuffer(CircularBuffer *ptr, char data) {
    if (Full(ptr)) {
        printf("Overflow\n");
        return;
    }

    ptr->ringbuffer[ptr->tail] = data;
    ptr->tail = (ptr->tail + 1) % SIZE;
    ptr->count++;
}

// الإزالة (القراءة)
char readfromBuffer(CircularBuffer *ptr) {
    if (Empty(ptr)) {
        printf("Underflow\n");
        return '\0';
    }

    char data = ptr->ringbuffer[ptr->head];
    ptr->head = (ptr->head + 1) % SIZE;
    ptr->count--;

    return data;
}

int main() {
    CircularBuffer ptr;
    init(&ptr);

    char name[100];

    // إدخال الاسم من Standard Input
    printf("Enter your name: ");
    scanf("%s", name);

    // إضافة "CE-ESY"
    strcat(name, "CE-ESY");

    // تخزين داخل المخزن الدائري
    for (int i = 0; i < strlen(name); i++) {
        writeinBuffer(&ptr, name[i]);
    }

    // قراءة البيانات من المخزن
    printf("Output: ");
    while (!Empty(&ptr)) {
        printf("%c", readfromBuffer(&ptr));
    }
    printf("\n");

    // التأكد أن المخزن فارغ
    if (Empty(&ptr)) {
        printf("Buffer is empty\n");
    }

    return 0;
}
