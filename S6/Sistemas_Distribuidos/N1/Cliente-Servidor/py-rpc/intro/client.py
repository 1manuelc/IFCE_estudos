import xmlrpc.client

HOST = 'localhost'
PORT = 8000

s = xmlrpc.client.ServerProxy(f"http://{HOST}:{PORT}")

num1 = 10
num2 = 5
resultado = s.soma(num1, num2)

print(f"A soma de {num1} e {num2} é: {resultado}")