# Simple stack implementation
import sys

class EmptyStackError(Exception):
    def __init__(self):
        super().__init__("OOPs Stack is empty: cannot pop an empty stack")


class StackFullError(Exception):
    def __init__(self):
        super().__init__("OOPs Stack is full")


class Stack():
    def __init__(self,maxsize):
        self.maxsize = maxsize
        self.items = []

    def isEmpty(self):
        if (len(self.items)==0):
            return True

        else:
            return False

    def isFull(self):
        if (len(self.items)==self.maxsize):
            return True

        else:
            return False

    def push(self, data):
        if self.isFull():
            raise StackFullError()

        self.items.append(data)
        return data

    
    def pop(self):
        if self.isEmpty():
            raise EmptyStackError()

        item = self.items[len(self.items)-1]
        del self.items[len(self.items)-1]
        print(f'Top element {item} is deleted')
        return item

    def top_element(self):
        top = self.items[len(self.items)-1]
        print(f'Top element of the stack is {top}')
        return top

    def all_elements(self):
        print("The elements of the stack are:")
        for item in self.items:
            print(item)


class PostFixEvaluation:
    def __init__(self):
        s = self.Stack(10)
        

    def evaluate(self,exp):
        for e in exp:
            

        

