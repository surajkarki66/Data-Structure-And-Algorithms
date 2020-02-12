class Toh:
    def __init__(self):
        self.count = 0



    def TOH(self, n, source, destination, temp):
        if n == 1:
            print(f'Move Disc {n} from {source} to {destination}')
            self.count += 1
            return
        
        self.TOH(int(n-1), source, destination, temp)
        print(f'Move Disc {n} from {source} to {destination}')
        self.TOH(int(n-1), temp, source, destination)


t = Toh()
num = input("Enter number of disc:")

t.TOH(int(num), 'A', 'B', 'C')

