import socket

HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    
    while True:
        msg = input("Digite a mensagem (ou 'exit' para sair): ")
        if msg.lower() == "exit":
            break
        s.sendall(msg.encode('utf-8'))
        
        data = s.recv(1024)
        print(f"Mensagem recebida: {data.decode('utf-8')!r}")