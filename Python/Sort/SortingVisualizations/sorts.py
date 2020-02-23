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


