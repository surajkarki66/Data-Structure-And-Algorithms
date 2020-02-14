import sys
import random
import time

class SelectionSort:
    def __init__(self):
        self.temp = 0
        
    def swap(self, items, i, j):
        if i!= j:
            items[i], items[j] = items[j], items[i]

    def sort(self, items):
        if len(items) == 1:
            return

        for i in range(len(items)):
            min_idx = i  # index for min value
            for j in range(i, len(items)):
                if (items[j] < items[min_idx]):
                    min_idx = j
    
            self.swap(items, i, min_idx)
            print(items)

    
if __name__ == "__main__":
    num = int(input("\nHow many integers?"))
    shuffled = [x+1 for x in range(num)]

    random.seed(time.time())
    random.shuffle(shuffled)
    
    sort = SelectionSort()
    sort.sort(shuffled)




    