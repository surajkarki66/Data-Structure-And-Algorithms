import random
import time
import math

class Data:
    def __init__(self):
        self.items = []
        self.num = None
        self.temp = 0
        self.swapped = True

    def get(self):
        self.num = int(input("Enter how many number:"))
        for i in range(self.num):
            item = int(input("Enter data:"))
            self.insert(item)


    def insert(self, item):
        self.items.append(item)

   

    def random(self):
        self.num = int(input("Enter how many number:"))
        item = [x+1 for x in range(self.num)]
        for i in item:
            self.items.append(i)
        random.seed(time.time())
        random.shuffle(self.items)

    def display(self):
        print(f'{self.items}')

       

    def swap(self, items, i, j):
        if i != j:
            items[i], items[j] = items[j], items[i]



    def sort(self, items):
        if len(items) == 1:
            print(items)
            return           # Exit from function

        self.swapped = True
        for i in range(len(items)-1):
            if not self.swapped:
                break
            self.swapped = False
            for j in range(len(items)-1-i):
                if (items[j] > items[j+1]):
                    self.swap(items, j, j+1)
                    self.swapped = True
                print(items)


    def search(self):
        self.sort(self.items)
        val = int(input("Enter the data you want to search:"))
        beg = 0
        end = len(self.items) -1
        pos = -1

        while(beg <= end):
            mid = (beg+end)/ 2
            mid = math.ceil(mid)
            if (val == self.items[mid]):
                pos = mid
                print(f'{val} is present at {pos+1}')
                break

            elif (self.items[mid] > val):
                end = mid - 1

            else:
                beg = mid + 1


        if (pos == -1):
            print("Search not found")
        

            





    

if __name__ == "__main__":    
    data = Data()
   # data.get()
    data.random()
    data.display()
    data.search()
    
        
