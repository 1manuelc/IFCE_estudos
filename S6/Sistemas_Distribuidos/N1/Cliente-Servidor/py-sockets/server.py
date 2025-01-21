import socket
import threading

HOST = '127.0.0.1'
PORT = 65432

def handle_client(conn, addr):
    print(f"[NOVA CONEXÃO] {addr} conectado.")
    conectado = True
    while conectado:
        try:
            msg = conn.recv(1024).decode('utf-8')
            if msg:
                if msg.lower() == "exit":
                    conectado = False
                else:
                    broadcast(msg, conn)
            else:
                remove_client(conn)
                conectado = False
        except:
            remove_client(conn)
            conectado = False

def broadcast(msg, conn):
    for client in clients:
        if client != conn:
            try:
                client.send(f"[{conn.getpeername()}] {msg}".encode('utf-8'))
            except:
                remove_client(client)

def remove_client(conn):
    if conn in clients:
        clients.remove(conn)
        print(f"[DESCONEXÃO] {conn.getpeername()} desconectado.")

clients = []

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print(f"[ESCUTANDO] Servidor escutando em {HOST}:{PORT}")

    while True:
        conn, addr = s.accept()
        clients.append(conn)
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[CONEXÕES ATIVAS] {threading.activeCount() - 1}")