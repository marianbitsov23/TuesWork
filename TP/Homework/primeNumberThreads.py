import threading
import time

class PrimeNumbers(threading.Thread):
    
    def __init__(self, name, start, end):
        threading.Thread.__init__(self)
        self.name = name
        self.startNumber = start + 1
        self.endNumber = end

    def run(self):
        print("Starting ", self.name, "\n")
        while self.startNumber != self.endNumber:
            for i in range(2, self.startNumber + 1):
                if self.startNumber % i == 0:
                    break
            if self.startNumber == i:
                print(self.name, " : ", self.startNumber)
            self.startNumber += 1
        print("Exiting ", self.name, "...\n")

thread1 = PrimeNumbers("Thread 1", 1, 100)
thread2 = PrimeNumbers("Thread 2", 100, 200)
thread3 = PrimeNumbers("Thread 3", 200, 300)
thread4 = PrimeNumbers("Thread 4", 300, 400)
thread5 = PrimeNumbers("Thread 5", 400, 500)
thread6 = PrimeNumbers("Thread 6", 500, 600)
thread7 = PrimeNumbers("Thread 7", 600, 700)
thread8 = PrimeNumbers("Thread 8", 700, 800)
thread9 = PrimeNumbers("Thread 9", 800, 900)
thread10 = PrimeNumbers("Thread 10", 900, 1000)

timestart = time.time()
thread1.start()
thread2.start()
thread3.start()
thread4.start()
thread5.start()
thread6.start()
thread7.start()
thread8.start()
thread9.start()
thread10.start()

thread1.join()
thread2.join()
thread3.join()
thread4.join()
thread5.join()
thread6.join()
thread7.join()
thread8.join()
thread9.join()
thread10.join()
timeend = time.time() - timestart
print("time required: ", timeend)

longthread = PrimeNumbers("Long Thread", 1, 1000)
timestart = time.time()
longthread.start()

longthread.join()
timeend = time.time() - timestart
print("time required: ", timeend)
