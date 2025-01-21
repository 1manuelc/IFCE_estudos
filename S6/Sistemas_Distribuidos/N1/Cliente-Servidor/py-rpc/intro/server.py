from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler

HOST = 'localhost'
PORT = 8000

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

with SimpleXMLRPCServer((HOST, PORT),
                        requestHandler=RequestHandler) as server:
    server.register_introspection_functions()

    def soma(x, y):
        return x + y

    server.register_function(soma, 'soma')

    print(f"Servidor iniciado em http://{HOST}:{PORT}")
    server.serve_forever()