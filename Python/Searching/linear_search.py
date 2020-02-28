import random
import time


class Data:
    def __init__(self):
        self.items = []
        self.num = None

    def get(self):
        self.num = int(input("Enter how many number:"))
        for i in range(self.num):
            item = int(input("Enter data:"))
            self.insert(item)


    def insert(self, item):
        self.items.append(item)

   

    def random(self):
        self.items = [x+1 for x in range(self.num)]
        random.seed(time.time())
        random.shuffle(self.items)

    def display(self):
        print(f'{self.items}')

    def search(self):
        val = int(input("Enter the data you want to search:"))
        flag = False
        if self.items:
            for index, value in enumerate(self.items):
                if (value == val):
                    flag = True
                    print("Data is found at ",index+1)
                    break

            if flag == False:
                print("Search not found.")

            





    

if __name__ == "__main__":    
    data = Data()
    data.get()
    data.display()
    data.search()
    
        
