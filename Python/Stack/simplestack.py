# Simple stack implementation
import sys


class EmptyStackError(Exception):
    def __init__(self):
        super().__init__("OOPs Stack is empty: cannot pop an empty stack")


class StackFullError(Exception):
    def __init__(self):
        super().__init__("OOPs Stack is full")


class Stack:
    def __init__(self, maxsize):
        self.maxsize = maxsize
        self.items = []

    def isEmpty(self):
        if len(self.items) == 0:
            return True

        else:
            return False

    def isFull(self):
        if len(self.items) == self.maxsize:
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

        item = self.items[len(self.items) - 1]
        del self.items[len(self.items) - 1]
        print(f'Top element {item} is deleted')
        return item

    def top_element(self):
        top = self.items[len(self.items) - 1]
        print(f'Top element of the stack is {top}')
        return top

    def all_elements(self):
        print("The elements of the stack are:")
        for item in self.items:
            print(item)


# Menu

class Menu:
    def __init__(self):
        self.stack = Stack(max1)
        self.choices = {
            "1": self.push,
            "2": self.pop,
            "3": self.top,
            "4": self.all,
            "5": self.quit
        }

    def display(self):
        print("""
        MENU 
        1. To push element
        2. To pop element,
        3. To see top element,
        4. To see all elements in a stack,
        5. To exit
        """)

    def run(self):
        while True:
            self.display()
            choice = input("Enter your choice:")
            action = self.choices.get(choice)

            if action:
                action()

            else:
                print("Not a valid input")

    def push(self):
        i = 0
        while (i < int(max1)):
            data = input("Enter the element to push:")
            self.stack.push(data)
            i += 1

    def pop(self):
        self.stack.pop()

    def top(self):
        self.stack.top_element()

    def all(self):
        self.stack.all_elements()

    def quit(self):
        sys.exit(1)


if __name__ == "__main__":
    max1 = input("Ente the size of stack:")
    Menu().run()
