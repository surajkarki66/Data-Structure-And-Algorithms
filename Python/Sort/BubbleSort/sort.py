import sys
import random
import time

class BubbleSort:
    def __init__(self):
        self.temp = 0
        self.swapped = True

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


if __name__ == "__main__":
    num =   int(input("Enter number of integers:"))

    suffled = [x + 1 for x in range(num)]
    random.seed(time.time())
    random.shuffle(suffled) 
    sort = BubbleSort()
    sort.sort(suffled)

            
           

       
