import requests
import threading

def makerequest(url):
    while 1:
        requests.get(url)

threads = []

url = input('Enter URL: ')
count = int(input('Number of Threads: '))

print(f'Now running {count} threads at {url}')

for i in range(count):
    t = threading.Thread(target=makerequest, args=[url])
    threads.append(t)

for i in range(count):
    threads[i].start()

for i in range(count):
    threads[i].join()