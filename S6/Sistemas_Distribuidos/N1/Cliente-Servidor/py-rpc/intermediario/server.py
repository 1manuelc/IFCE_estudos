from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler
import xmlrpc.client

HOST = 'localhost'
PORT = 8000

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

clientes_conectados = []

with SimpleXMLRPCServer((HOST, PORT),
                        requestHandler=RequestHandler) as server:
    server.register_introspection_functions()

    def registra_cliente(endereco):
        clientes_conectados.append(endereco)
        print(f"Cliente {endereco} registrado.")
        return "Cliente registrado com sucesso!"

    server.register_function(registra_cliente, 'registra_cliente')

    def processa_mensagem(msg):
        print(f"Mensagem de {msg['remetente']}: {msg['texto']}")
        for cliente in clientes_conectados:
            try:
                with xmlrpc.client.ServerProxy(f"http://{cliente}") as client:
                    client.recebe_mensagem(msg)
            except Exception as e:
                print(f"Erro ao enviar mensagem para {cliente}: {e}")
        return "Mensagem enviada para todos os clientes."
        
    server.register_function(processa_mensagem, 'processa_mensagem')
    print(f"Servidor intermediário iniciado em http://{HOST}:{PORT}")
    server.serve_forever()



