
class Sort:
    def __init__(self):
        self.temp = 0
        self.swapped  = True

    def swap(self, i, j, items):
        print(items)
        #playsound('pop.wav')
        if i != j:
            items[i], items[j] = items[j], items[i]

    def bubble_sort(self, items):
        if items == 1:
            return

        self.swapped = True
        for i in range(len(items)-1):
            if not self.swapped:
                break
            self.swapped = False
            for j in range(len(items) - i - 1):
                if items[j] > items[j+1]:
                    self.swap(j, j+1, items)
                    self.swapped = True
                yield items


    def selection_sort(self, items):
        if len(items) == 1:
            return

        for i in range(len(items)):
            min_val = items[i]
            min_idx = i
            for j in range(i, len(items)):
                if items[j] < min_val:
                    min_val = items[j]
                    min_idx = j
                   
                yield items
            self.swap(i, min_idx, items)
            yield items

    def insertion_sort(self, items):
         for i in range(1, len(items)):
            temp = items[i]
            j = i - 1
            while ((temp < items[j] and j >= 0)):
                items[j], items[j+1] = items[j+1], items[j]
                j -= 1
                print(items)
                yield items



    def mergesort(self,A, start, end):
        """Merge sort."""

        if end <= start:
            return

        mid = start + ((end - start + 1) // 2) - 1
        yield from self.mergesort(A, start, mid)
        yield from self.mergesort(A, mid + 1, end)
        yield from self.merge(A, start, mid, end)
        yield A

    def merge(self, A, start, mid, end):
        """Helper function for merge sort."""
        
        merged = []
        leftIdx = start
        rightIdx = mid + 1

        while leftIdx <= mid and rightIdx <= end:
            if A[leftIdx] < A[rightIdx]:
                merged.append(A[leftIdx])
                leftIdx += 1
            else:
                merged.append(A[rightIdx])
                rightIdx += 1

        while leftIdx <= mid:
            merged.append(A[leftIdx])
            leftIdx += 1

        while rightIdx <= end:
            merged.append(A[rightIdx])
            rightIdx += 1

        for i, sorted_val in enumerate(merged):
            A[start + i] = sorted_val
            yield A

    def partition(self, items, start, end):
        loc = left = start
        right = end
        flag = False
        while flag != True:
            while((items[loc] <= items[right]) and (loc !=right)):
                right -= 1       
            
            if (loc == right):
                flag = True
               

            elif (items[loc] > items[right]):
                items[loc], items[right] = items[right], items[loc]
                loc = right
                
            if (flag != 1):
                while((items[loc] >= items[left] and (loc != left))):
                    left += 1
                    

                if (left == loc):
                    flag = True

                elif (items[loc] < items[left]):
                    items[loc], items[left] = items[left], items[loc]
                    loc = left
                    
        return loc

    def quicksort(self, items, start, end):
        if (start < end):
            loc = self.partition(items, start, end)
            yield items
            yield from self.quicksort(items, start, loc-1)
            yield from self.quicksort(items, loc+1, end)
            yield items


    

"""
    def quicksort(self, items, start, end):
        if start >= end:
            return

        pivot = items[end]
        pivotIdx = start

        for i in range(start, end):
            if items[i] < pivot:
                items[i], items[pivotIdx] = items[pivotIdx], items[i]
                pivotIdx += 1
            yield items
        items[end], items[pivotIdx] = items[pivotIdx], items[end]
        yield items

        yield from self.quicksort(items, start, pivotIdx - 1)
        yield from self.quicksort(items, pivotIdx + 1, end)
"""


            






