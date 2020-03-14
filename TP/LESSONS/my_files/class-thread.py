import threading
import datetime

class MyThread(threading.Thread):
    def __init__(self, name, counter):
        threading.Thread.__init__(self)
        self.threadID = counter
        self.name = name
        self.counter = counter

    def run(self):
        print("\nStartng " + self.name)
        i = 0
        while i < 50:
            print_date(self.name, self.counter)
            i = i + 1

        print("Exiting " + self.name)

def print_date(thread_name, counter):
    datafields = []
    today = datetime.datetime.now()
    datafields.append(today)
    print("{}[{}]: {}".format(thread_name, counter, datafields[0]))

thread1 = MyThread("Thread", 1)
thread2 = MyThread("Thread", 2)

thread1.start()
thread2.start()

thread1.join()
thread2.join()
print("\nExiting the Program!!!")
