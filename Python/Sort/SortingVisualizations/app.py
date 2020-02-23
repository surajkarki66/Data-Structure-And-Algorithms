import time
import sys
import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation


from sorts import Sort


if __name__ == "__main__":
    method_msg = """

                                    Welcome to Sorting Visualizations!!
                                        powered by: Matplot lib

                                        MENU:

                                        Press b for Bubble Sort
                                        Press s for Selection Sort
                                        Press i for insertion Sort
                                        Press m for merge Sort

                 """
    method = input(method_msg)
    num = int(input("Enter number of integers: "))
    items = [x + 1 for x in range(num)]
    random.seed(time.time())
    random.shuffle(items)
    sort = Sort()

    fig, ax = plt.subplots()

    if method == "b":
        title = "Bubble Sort"
        bar_rects = ax.bar(range(len(items)), items, align="edge", color="red", edgecolor="blue")
        generator = sort.bubble_sort(items)

    
        ax.set_xlim(0, num)
        ax.set_ylim(0, int(1.07 * num))

        # Place a text label in the upper-left corner of the plot to display
        # number of operations performed by the sorting algorithm (each "yield"
        # is treated as 1 operation).
        text = ax.text(0.02, 0.95, "", transform=ax.transAxes)
        iteration = [0]
        def update_fig(items, rects, iteration):
            for rect, val in zip(rects, items):
                rect.set_height(val)
            iteration[0] += 1
            text.set_text("# of operations: {}".format(iteration[0]))
        anim = animation.FuncAnimation(fig, func=update_fig,
            fargs=(bar_rects, iteration), frames=generator, interval=1,
            repeat=False)
        plt.show()
      




    if method == "s":
        title = "Selection Sort"
        bar_rects = ax.bar(range(len(items)), items, align="edge", color="blue", edgecolor="red")
        generator = sort.selection_sort(items)

  
        ax.set_xlim(0, num)
        ax.set_ylim(0, int(1.07 * num))

        # Place a text label in the upper-left corner of the plot to display
        # number of operations performed by the sorting algorithm (each "yield"
        # is treated as 1 operation).
        text = ax.text(0.02, 0.95, "", transform=ax.transAxes)
        iteration = [0]
        def update_fig(items, rects, iteration):
            for rect, val in zip(rects, items):
                rect.set_height(val)
            iteration[0] += 1
            text.set_text("# of operations: {}".format(iteration[0]))

        anim = animation.FuncAnimation(fig, func=update_fig,
            fargs=(bar_rects, iteration), frames=generator, interval=1,
            repeat=False)
       
        plt.show()
       
    if method == "i":
        title = "Insertion Sort"
        bar_rects = ax.bar(range(len(items)), items, align="edge", color="black", edgecolor="white")
        generator = sort.insertion_sort(items)

  
        ax.set_xlim(0, num)
        ax.set_ylim(0, int(1.07 * num))

        # Place a text label in the upper-left corner of the plot to display
        # number of operations performed by the sorting algorithm (each "yield"
        # is treated as 1 operation).
        text = ax.text(0.02, 0.95, "", transform=ax.transAxes)
        iteration = [0]
        def update_fig(items, rects, iteration):
            for rect, val in zip(rects, items):
                rect.set_height(val)
            iteration[0] += 1
            text.set_text("# of operations: {}".format(iteration[0]))

        anim = animation.FuncAnimation(fig, func=update_fig,
            fargs=(bar_rects, iteration), frames=generator, interval=1,
            repeat=False)
       
        plt.show()

    if method == "m":
        title = "Merge Sort"
        bar_rects = ax.bar(range(len(items)), items, align="edge", color="blue", edgecolor="green")
        generator = sort.mergesort(items,0,num-1)

  
        ax.set_xlim(0, num)
        ax.set_ylim(0, int(1.07 * num))

        # Place a text label in the upper-left corner of the plot to display
        # number of operations performed by the sorting algorithm (each "yield"
        # is treated as 1 operation).
        text = ax.text(0.02, 0.95, "", transform=ax.transAxes)
        iteration = [0]
        def update_fig(items, rects, iteration):
            for rect, val in zip(rects, items):
                rect.set_height(val)
            iteration[0] += 1
            text.set_text("# of operations: {}".format(iteration[0]))

        anim = animation.FuncAnimation(fig, func=update_fig,
            fargs=(bar_rects, iteration), frames=generator, interval=1,
            repeat=False)
       
        plt.show()

       



    else:
        sys.exit()
        

