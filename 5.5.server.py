import socket

s = socket.socket()
print("Berjaya buat socket")

port = 8888

s.bind(('',port))
print("Berjaya bind socket di port: "+str(port))

s.listen(5)
print("Socket tengah menunggu client!")

file = open("file.txt","wb") 

while True:
    c, addr = s.accept()
    print("Dapat capaian dari: "+str(addr))
    c.send(b'Terima Kasih!')
    
    RecvFile = c.recv(1024)
    while RecvFile:
        file.write(RecvFile)
        RecvFile = c.recv(1024)
    file.close()
    print("\n File berjaya di copy \n")

    c.close()
    break
