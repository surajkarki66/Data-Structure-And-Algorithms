import sys


class Queue:
    def __init__(self, maxsize, size=0, front=0, rear=0):
        self.maxsize = maxsize
        self.size = size
        self.front = front
        self.rear = rear
        self.queue = [[] for i in range(int(self.maxsize))]
        print(self.queue)

    def isEmpty(self):
        if self.size == 0:
            return True
        else:
            return False

    def isFull(self):
        if self.size == self.maxsize:
            return True
        else:
            return False

    def enqueue(self, data):
        if self.isFull():
            print('Queue is full')
        else:
            self.queue[self.rear] = data
            self.rear = int((self.rear + 1) % int(self.maxsize))
            self.size += 1
            print(self.queue)

    def dequeue(self):
        if self.isEmpty():
            print('Queue is empty.')
        else:
            item = self.queue[self.front]
            print(f'{item} is deleted')
            self.front = int((self.front + 1) % int(self.maxsize))
            self.size -= 1

    def traverse(self):
        print('Queue contents are')
        for i in range(self.size):
            print(self.queue[int((i + self.front) % int(self.maxsize))])


# Menu

class Menu:
    def __init__(self):
        self.queue = Queue(max1)
        self.choices = {
            "1": self.enqueue,
            "2": self.dequeue,
            "3": self.traverse,
            "4": self.quit
        }

    def display(self):
        print("""
        MENU 
        1. To enqueue element
        2. To dequeue element,
        3. To see all element,
        4. To exit
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

    def enqueue(self):
        i = 0
        while i < int(max1):
            data = input("Enter the element:")
            self.queue.enqueue(data)
            i += 1

    def dequeue(self):
        self.queue.dequeue()

    def traverse(self):
        self.queue.traverse()

    @staticmethod
    def quit():
        sys.exit(1)


if __name__ == "__main__":
    max1 = input("Enter the size of queue:")
    Menu().run()
