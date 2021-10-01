from random import randint
from time import sleep
from threading import Thread

threads = []
results = []

def foo(i, alist):
    duration=randint(1,5)
    sleep(duration)
    alist.append(duration)
    print("Thread "+str(i)+" finished!")

for i in range(10):
    threads.append(Thread(target=foo, args=(i, results)))

for thread in threads:
    thread.start()

for i in range(len(threads)):
    threads[i].join() #join stops main process to wait for the threads to finish

print(str(results))
