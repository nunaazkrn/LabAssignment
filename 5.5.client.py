import socket
import tqdm
import os

SEPARATOR = "<SEPARATOR>"
BUFFER_SIZE = 4096

s = socket.socket()
host = "192.168.53.3"
port = 5001
print(f"[+] Cuba untuk connect dengan.. {host}:{port}")
s.connect((host, port))
print("[+] Dah connect dengan ", host)
filename = input("File to Transfer : ")
filesize = os.path.getsize(filename)
s.send(f"{filename}{SEPARATOR}{filesize}".encode())
#file = open(filename, 'wb') 

progress = tqdm.tqdm(range(filesize), f"Jap, tengah hantar {filename}", unit="B", unit_scale=True, unit_divisor=1024)
with open(filename, "rb") as f:
    while True:
        bytes_read = f.read(BUFFER_SIZE)
        if not bytes_read:
            break
        s.sendall(bytes_read)
        progress.update(len(bytes_read))
s.close()
