# 스택(Stack ADT)

> Author: 경희대학교 컴퓨터공학부 배승호<br>
> Date: 20220419 Tue

## 목표
* 스택(Stack)의 기본 연산을 이해한다.<br>
* C++를 이용하여 스택(Stack)을 구현할 수 있다.

## 스택(Stack)의 개념
한 쪽으로만 데이터를 넣고 뺄 수 있는 **후입선출**(Last In First Out) 형식의 자료 구조<br>

## 스택(Stack)의 연산
스택(Stack)은 가장 최근에 스택에 추가한 데이터가 가장 먼저 제거될 항목이다.<br>

* isEmpty(): 스택이 비어 있을 경우 True를 반환한다
* isFull(): 스택이 꽉 차 있을 경우 True를 반환한다
* push(item): item을 스택의 가장 윗 부분에 추가한다
* pop(): 가장 나중에 추가한 데이터를 제거한다
* top(): 가장 나중에 추가한 데이터를 반환한다
* print(): 스택의 요소들을 출력한다


## 스택(Stack)의 구현
스택은 링크드리스트를 이용하여 구현할 수 있다.

### 스택(Stack) 명세
```C++

class EmptyStack{}; // 빈 스택 예외 처리
class FullStack{}; // 풀 스택 예외 처리

template <class itemType>
struct NodeType{
    itemType info; // 데이터가 저장되는 변수
    NodeType* next; // 다음 요소를 가리키는 포인터 변수
}

template <class itemType>
class stack{
private:
    NodeType* topPtr; // 스택의 가장 윗 요소를 가리키는 포인터 변수

public:
    bool isEmpty();
    bool isFull();
    void push(item);
    itemType pop();
    itemType top();
    void print();
}
```

### isEmpty() 함수
```C++
bool stack::isEmpty(){
    return (topPtr == NULL)
}
```

### isFull() 함수
```C++
bool stack::isFull(){
    try{
        NodeType* temp = new NodeType;
        delete temp;
        return False
    }
    catch(bad_alloc){
        return True;
    }
}
```

### push(item) 함수
```C++
void stack::push(item){
    if(isFull())
        throw FullStack();

    NodeType* newItem = new NodeType;
    newItem -> info = item;
    if(isEmpty()){
        newItem -> next = NULL;
        topPtr = newItem;
    }
    else{
        newItem -> next = topPtr;
        topPtr = newItem;
    }
}
```

### pop() 함수
```C++
itemType stack::pop(){
    if(isEmpty())
        throw EmptyStack();

    NodeType* temp = topPtr;

    popValue = temp.info;
    topPtr = topPtr -> next;
    delete temp;

    return popValue;
}
```

### top() 함수
```C++
itemType stack::top(){
    if(isEmpty())
        throw EmptyStack();
    
    return topPtr -> info;
}
```

### print() 함수
```C++
void stack::print(){
    if(isEmpty()){
        throw EmptyStack();
    }

    NodeType* location = topPtr;

    while(location != NULL){
        cout << location -> info << ' ';
        location = location -> next;
    }
    cout << '\n';
}
```
