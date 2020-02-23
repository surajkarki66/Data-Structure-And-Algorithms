from playsound import playsound
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






