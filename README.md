# -First-homework

#include <stdio.h>
#include <string.h>   ---->        مكتبة خاصة للسلاسل المحرفية 
  

#define SIZE 5  ----->                تعريف حجم المصفوفة الحلقية




 typedef struct {              ------->   يعبر عن االمخزن الدائري  struct تعريف 
    char ringbuffer[SIZE];     ----->    الذي تم تعريفه مسبقا  SIZE  تعريف مصفوفة تأخذ الحجم 
    int head;--------->>
    int tail;----------->>  هؤلاء المتغيرات نحتاجها من اجل عمل المصفوفة الحلقية بشكل صحيح  
    int count;  ------>>
} CircularBuffer;
   


void init(CircularBuffer *ptr) {  ------->   ( حتى تكون المخزن الدائري فارغ)   Initialization  تابع التهيئه  
    ptr->head = 0;
    ptr->tail = 0;       
    ptr->count = 0;
}


int Full(CircularBuffer *ptr) {   -------> دالة تفيد في التحقق اذا المخزن الدائري ممتلئ
    int x;
    x=ptr->count == SIZE;
    return x;
}



int Empty(CircularBuffer *ptr) {  -------> دالة بتفيد لتحقق اذا المخزن الدائري فارغ
    int y;
    y=ptr->count == 0;
    return y;
}



void writeinBuffer(CircularBuffer *ptr, char data) {      ---->           اذا السلسلة المدخلة لم تتسع في المخزن الدائري  overflow هذه الدالة تخرج كلمة        
    if (Full(ptr)) {      
        printf("Overflow\n");  
     
        return;
    }

    ptr->ringbuffer[ptr->tail] = data;
    ptr->tail = (ptr->tail + 1) % SIZE;  هذه العملية الاكثر الاهمية لانها هي يلي بتعيد المؤشر الى بداية المخزن (وهذا هو السلوك الدائري)
    ptr->count++;
}


char readfromBuffer(CircularBuffer *ptr) { 
    if (Empty(ptr)) {
        printf("Underflow\n");   ------>                 اذا قمت بادخال سلسلة اصغر من سعة المخزن  unferflow هذه الدالة تطبع كلمة 
        return '\0';                           ---(اي ما يزال هناك فراغ في المخزن)
    }

    char data = ptr->ringbuffer[ptr->head];
    ptr->head = (ptr->head + 1) % SIZE;
    ptr->count--;

    return data;
}

    في دالة ال main يكتب فيها طلب ادخال السلسلة من قبل المستخدم وتجمع السلساة المدخلة الى الكلمة"  CE-ESY "
 ومن ثم التحقق من حالة المخزن 
   

